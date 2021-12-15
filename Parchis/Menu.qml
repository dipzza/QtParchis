import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import QtQuick.Controls 2.15

Item {
    width: 1600
    height: 900
    property int selectedPlayers: 4


    Button {
        id: button
        x: 227
        y: 237
        width: 300
        height: 80
        text: qsTr("2 PLAYERS")
        autoExclusive: true
        checkable: true
        font.pointSize: 20
        font.bold: true
        onClicked: {
            textField1.visible = true
             textField2.visible = false
             textField3.visible = false
             textField.visible = true
            label3.visible=true
            label4.visible=true
            label5.visible=false
            label6.visible=false
            label2.visible=true
            label3.visible=true
            label4.visible=false
            label5.visible=true
            button3.visible=true

        }

    }

    Button {
        id: button1
        x: 671
        y: 237
        width: 300
        height: 80
        text: qsTr("3 PLAYERS")
        autoExclusive: true
        checkable: true
        font.pointSize: 20
        font.bold: true
        onClicked: {
            textField1.visible = true
             textField2.visible = true
             textField3.visible = false
             textField.visible = true
            label3.visible=true
            label4.visible=true
            label5.visible=true
            label6.visible=false
            label2.visible=true
            label3.visible=true
            label4.visible=true
            label5.visible=true
            button3.visible=true

        }


    }

    Button {
        id: button2
        x: 1130
        y: 237
        width: 300
        height: 80
        text: qsTr("4 PLAYERS")
        autoExclusive: true
        checkable: true
        font.pointSize: 20
        font.bold: true
        onClicked: {
            textField1.visible = true
             textField2.visible = true
             textField3.visible = true
             textField.visible = true
            label3.visible=true
            label4.visible=true
            label5.visible=true
            label6.visible=true
            label2.visible=true
            label3.visible=true
            label4.visible=true
            label5.visible=true
            button3.visible=true
        }
    }

    TextField {
        id: textField
        x: 227
        y: 486
        width: 300
        height: 70
        font.pointSize: 15
        text: "Player 1"
        placeholderText: qsTr("Insert name of Player 1")
        visible: false
    }

    TextField {
        id: textField1
        x: 733
        y: 486
        width: 300
        height: 70
        font.pointSize: 15
        text: "Player 2"
        placeholderText: qsTr("Insert name of player 2")
        visible:false
    }

    TextField {
        id: textField2
        x: 227
        y: 642
        width: 300
        height: 70
        font.pointSize: 15
        text: "Player 3"
        placeholderText: qsTr("Insert name of player 3")
        //visible: selectedPlayers >= 3
        visible: false

    }

    TextField {
        id: textField3
        x: 733
        y: 642
        width: 300
        height: 70
        font.pointSize: 15
        text: "Player 4"
        placeholderText: qsTr("Insert name of player 4")
        visible: false
    }

    Label {
        id: label
        x: 136
        y: 159
        width: 590
        height: 52
        text: qsTr("1- Select how many players are going to play:")
        font.italic: true
        font.family: "Tahoma"
        font.pointSize: 20
    }

    Label {
        id: label1
        x: 462
        y: 61
        width: 319
        height: 81
        text: qsTr("LUDO GAME")
        horizontalAlignment: Text.AlignHCenter
        font.underline: true
        font.italic: true
        font.bold: true
        font.pointSize: 35
        font.family: "Times New Roman"
    }

    Image {
        id: image
        x: 822
        y: 15
        width: 100
        height: 100
        source: "/images/board.png"
        fillMode: Image.PreserveAspectFit
    }

    Label {
        id: label2
        x: 136
        y: 374
        width: 620
        height: 70
        text: qsTr("2- Write the name of the players:")
        font.family: "Tahoma"
        font.italic: true
        font.pointSize: 20
        visible: false
    }

    Button {
        id: button3
        x: 1162
        y: 564
        width: 210
        height: 54
        text: qsTr("START GAME")
        font.pointSize: 20
        font.family: "Tahoma"
        visible: false

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
        y: 435
        width: 216
        height: 63
        text: qsTr("Player 1 Name:")
        font.pointSize: 20
        visible:false

    }

    Label {
        id: label4
        x: 227
        y: 588
        width: 300
        height: 48
        text: qsTr("Player 3 Name:")
        font.pointSize: 20
        visible : false
    }

    Label {
        id: label5
        x: 733
        y: 435
        width: 256
        height: 42
        text: qsTr("Player 2 Name:")
        font.pointSize: 20
        font.family: "Tahoma"
        visible : false
    }

    Label {
        id: label6
        x: 742
        y: 593
        width: 336
        height: 39
        text: qsTr("PLayer 4 Name")
        font.pointSize: 20
        font.family: "Tahoma"
        visible:false
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
        onClicked: {
            menu.visible = false
            settings.visible = true
        }

    }

    Button {
        id: button6
        x: 1043
        y: 61
        width: 134
        height: 47
        text: qsTr("Help")
        onClicked: {
            menu.visible = false
            help.visible = true
        }
    }

}
