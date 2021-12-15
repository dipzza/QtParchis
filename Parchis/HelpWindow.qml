import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import QtQuick.Controls 2.15


Item {
    width: 1500
    height: 800

    Label {
        id: label
        x: 609
        y: 34
        width: 230
        height: 78
        text: qsTr("HELP")
        font.family: "Times New Roman"
        font.underline: true
        font.italic: true
        font.bold: true
        font.pointSize: 30
    }

    Button {
        id: button
        x: 65
        y: 34
        width: 151
        height: 39
        text: qsTr("Back to Menu")
        font.pointSize: 13

        onClicked: {
            help.visible = false
            menu.visible = true
        }
    }

    Label {
        id: label1
        x: 165
        y: 132
        width: 170
        height: 54
        text: qsTr("How to play Ludo:")
        font.pointSize: 20
        font.family: "Tahoma"
    }

    TextArea {
        id: textArea
        x: 178
        y: 200
        width: 1227
        height: 44
        text: "1- We have to choose the number of players and then write the name of the players in each text field available"
        font.pointSize: 18
        placeholderText: qsTr("Text Area")
    }

    TextArea {
        id: textArea1
        x: 178
        y: 266
        width: 926
        height: 40
        text: "2- We start the game pressing the botton \"Start Game\""
        font.pointSize: 18
        font.family: "Tahoma"
        placeholderText: qsTr("Text Area")
    }

    TextArea {
        id: textArea2
        x: 178
        y: 322
        width: 926
        text: "3- You will have to roll a 5 on the die to be able to remove a token from the box\n        where they are and in this way be able to start advancing through the board "
        font.pointSize: 18
        font.family: "Tahoma"
        placeholderText: qsTr("Text Area")
    }

    TextArea {
        id: textArea3
        x: 178
        y: 401
        width: 999
        height: 83
        text: "4- for move the tokens to each place you have to roll on the dice first and then press
        in the token that you want to move "
        font.pointSize: 18
        font.family: "Tahoma"
        placeholderText: qsTr("Text Area")
    }


    TextArea {
        id: textArea4
        x: 178
        y: 476
        width: 942
        height: 92
        text: "5- The winner of the game is going to be the first person to achieve carry the four tokens
        to the centre of the board "
        font.pointSize: 18
        font.family: "Tahoma"
        placeholderText: qsTr("Text Area")
    }

    Image {
        id: image
        x: 771
        y: 15
        width: 100
        height: 89
        source: "/images/help.png"
        fillMode: Image.PreserveAspectFit
    }


}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:1}D{i:2}D{i:3}D{i:4}D{i:5}D{i:6}D{i:7}D{i:8}
}
##^##*/
