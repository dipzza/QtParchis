import QtQuick
import QtQuick.Window
import QtQuick.Layouts

import "./constants.js" as Cons
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

            Image {
                id: testToken
                source: "qrc:///images/yellow_token.png"
                width: implicitWidth * parent.paintedWidth / Cons.og_size
                height: implicitHeight * parent.paintedHeight / Cons.og_size
                x: (-implicitWidth / 2 + boardPos.getXCoordinate(test_token.getColor(), test_token.passedCellsToBoardPosition())) * parent.paintedWidth / Cons.og_size
                y: (-implicitHeight / 2 + boardPos.getYCoordinate(test_token.getColor(), test_token.passedCellsToBoardPosition())) * parent.paintedHeight / Cons.og_size
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                focus: true
                Keys.onPressed: (event)=> {
                    if (event.key === Qt.Key_Space) {
                        console.log("Si" + test_token.passed_cells)
                        test_token.passed_cells += 1;
                        x = (-implicitWidth / 2 + boardPos.getXCoordinate(test_token.getColor(), test_token.passedCellsToBoardPosition())) * parent.paintedWidth / Cons.og_size
                        y = (-implicitHeight / 2 + boardPos.getYCoordinate(test_token.getColor(), test_token.passedCellsToBoardPosition())) * parent.paintedHeight / Cons.og_size
                    }
                }
            }
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
