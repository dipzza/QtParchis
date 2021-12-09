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
#include <vector>
#include <memory>
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
    Board board;
    board.initialize(2);

    // Register BoardPositions to instance it on the UI
    qmlRegisterType<BoardPositions>( "com.fit.boardpositions", 1, 0, "BoardPositions" );
    // Pass board to QML
    engine.rootContext()->setContextProperty("board", &board);
    engine.load(url);

    return app.exec();
}
