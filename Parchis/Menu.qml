import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import QtQuick.Controls 2.15

Item {
    width: 1500
    height: 800
    property int selectedPlayers: 4

    Button {
        id: button
        x: 227
        y: 314
        width: 300
        height: 80
        text: qsTr("2 PLAYERS")
        autoExclusive: true
        checkable: true
        font.pointSize: 20
        font.bold: true

    }

    Button {
        id: button1
        x: 673
        y: 314
        width: 300
        height: 80
        text: qsTr("3 PLAYERS")
        autoExclusive: true
        checkable: true
        font.pointSize: 20
        font.bold: true
    }

    Button {
        id: button2
        x: 1134
        y: 314
        width: 300
        height: 80
        text: qsTr("4 PLAYERS")
        autoExclusive: true
        checkable: true
        font.pointSize: 20
        font.bold: true
    }

    TextField {
        id: textField
        x: 227
        y: 527
        width: 300
        height: 70
        font.pointSize: 15
        placeholderText: qsTr("Insert name of Player 1")
    }

    TextField {
        id: textField1
        x: 742
        y: 527
        width: 300
        height: 70
        font.pointSize: 15
        placeholderText: qsTr("Insert name of player 2")
    }

    TextField {
        id: textField2
        x: 227
        y: 659
        width: 300
        height: 70
        font.pointSize: 15
        placeholderText: qsTr("Insert name of player 3")
        visible: selectedPlayers >= 3
    }

    TextField {
        id: textField3
        x: 742
        y: 659
        width: 300
        height: 70
        font.pointSize: 15
        placeholderText: qsTr("Insert name of player 4")
    }

    Label {
        id: label
        x: 136
        y: 243
        width: 590
        height: 52
        text: qsTr("Select how many players are going to play:")
        font.family: "Tahoma"
        font.pointSize: 20
    }

    Label {
        id: label1
        x: 462
        y: 72
        width: 319
        height: 81
        text: qsTr("LUDO GAME")
        horizontalAlignment: Text.AlignHCenter
        font.italic: true
        font.bold: true
        font.pointSize: 35
        font.family: "Times New Roman"
    }

    Image {
        id: image
        x: 822
        y: 10
        width: 187
        height: 183
        source: "../../Pictures/parchis.jpg"
        fillMode: Image.PreserveAspectFit
    }

    Label {
        id: label2
        x: 136
        y: 432
        width: 620
        height: 70
        text: qsTr("Write the name of the players:")
        font.pointSize: 20
    }

    Button {
        id: button3
        x: 1204
        y: 630
        width: 182
        height: 46
        text: qsTr("START GAME")
        font.pointSize: 20
        font.family: "Tahoma"

        onClicked: {
            board.initialize(selectedPlayers)
            var gameComponent = Qt.createComponent("Game.qml")
            var gameInstance = gameComponent.createObject(window)
            mainLoader.state = "game"
        }
    }

    Label {
        id: label3
        x: 227
        y: 479
        width: 216
        height: 63
        text: qsTr("Player 1 Name:")
        font.pointSize: 20
    }

    Label {
        id: label4
        x: 227
        y: 612
        width: 300
        height: 48
        text: qsTr("Player 3 Name:")
        font.pointSize: 20
    }

    Label {
        id: label5
        x: 742
        y: 479
        width: 256
        height: 42
        text: qsTr("Player 2 Name:")
        font.pointSize: 20
        font.family: "Tahoma"
    }

    Label {
        id: label6
        x: 742
        y: 612
        width: 336
        height: 39
        text: qsTr("PLayer 4 Name")
        font.pointSize: 20
        font.family: "Tahoma"
    }

    Button {
        id: button4
        x: 97
        y: 61
        width: 134
        height: 47
        text: qsTr("EXIT GAME")
        onClicked: {
            Qt.quit();

        }
    }

    Button {
        id: button5
        x: 1252
        y: 61
        width: 134
        height: 47
        text: qsTr("Settings")

    }

}
