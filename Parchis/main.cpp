#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QLocale>
#include <QTranslator>
#include <QDebug>

#include "token.h"
#include "board_positions.h"
#include "board.h"
#include "dice.h"

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ParchisQtQuick_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    // Initialize game with 2 players
    Board board(2);
    set<Color> playing_colors;

    // Pass tokens to QML as object context properties with the name "color_idx"
    // We pass the active tokens of the players
    for (auto& player : board.getPlayers()) {
        for (auto token : player->getTokens()) {
            playing_colors.insert(token->getColor());
            string str_color = colorToString(token->getColor());
            engine.rootContext()->setContextProperty((str_color + "_" + to_string(token->getIdx())).c_str(), token);
        }
    }
    // We create and pass the tokens that are not gonna move
    for (unsigned int i = 0; i < 4; ++i) {
       Color color = static_cast<Color>(i);

       if (playing_colors.find(color) == playing_colors.end()) {
           string str_color = colorToString(color);
           for (int j=0; j < 4; ++j) {
               Token *token = new Token(j, color);
               engine.rootContext()->setContextProperty((str_color + "_" + to_string(j)).c_str(), token);
           }
       }
    }

    qmlRegisterType<BoardPositions>( "com.fit.boardpositions", 1, 0, "BoardPositions" );
    // Pass dice and board to QML
    engine.rootContext()->setContextProperty("board", &board);
    engine.load(url);

    return app.exec();
}
