import QtQuick
import QtQuick.Window
import QtQuick.Layouts

import com.fit.boardpositions 1.0

Window {
    width: 1600
    height: 900
    color: "brown"
    visible: true
    title: qsTr("Super Parchís")

    RowLayout {
        id: layout
        anchors.fill: parent
        spacing: 6

        ColumnLayout {
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.minimumHeight: 150

            Text {
                text: "Player1"
                Layout.fillWidth: true
                Layout.fillHeight: true
                padding: 30
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                fontSizeMode: Text.Fit
                minimumPointSize: 1
                font.pointSize: 30
            }

            Text {
                text: "Player2"
                Layout.fillWidth: true
                Layout.fillHeight: true
                padding: 30
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                fontSizeMode: Text.Fit
                minimumPointSize: 1
                font.pointSize: 30
            }
        }

        Image {
            id: boardImg
            source: "qrc:///images/board.png"
            fillMode: Image.PreserveAspectFit
            Layout.minimumWidth: 300
            Layout.maximumWidth: parent.height - 8
            Layout.preferredWidth: parent.width - 312
            Layout.preferredHeight: parent.height - 8

            Token {contextObject: yellow_0}
            Token {contextObject: yellow_1}
            Token {contextObject: yellow_2}
            Token {contextObject: yellow_3}
            Token {contextObject: red_0}
            Token {contextObject: red_1}
            Token {contextObject: red_2}
            Token {contextObject: red_3}
            Token {contextObject: blue_0}
            Token {contextObject: blue_1}
            Token {contextObject: blue_2}
            Token {contextObject: blue_3}
            Token {contextObject: green_0}
            Token {contextObject: green_1}
            Token {contextObject: green_2}
            Token {contextObject: green_3}

        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.minimumHeight: 150

            Text {
                text: "Player3"
                Layout.fillWidth: true
                Layout.fillHeight: true
                padding: 30
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                fontSizeMode: Text.Fit
                minimumPointSize: 1
                font.pointSize: 30
            }

            Text {
                text: "Player4"
                Layout.fillWidth: true
                Layout.fillHeight: true
                padding: 30
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                fontSizeMode: Text.Fit
                minimumPointSize: 1
                font.pointSize: 30
            }
        }
    }

    BoardPositions {
        id: boardPos
    }
}
