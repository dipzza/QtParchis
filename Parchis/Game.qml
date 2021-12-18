import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects

import com.fit.boardpositions 1.0


RowLayout {
    property int current_player: 0
    id: layout
    anchors.fill: parent
    spacing: 6

    ColumnLayout {
        Layout.fillWidth: true
        Layout.minimumWidth: 150
        Layout.minimumHeight: 150

        Text {
            id: redPlayerText
            text: textField.text
            color : current_player == 0 ? "white" : "black"
            styleColor: "red"
            style: current_player == 0 ? Text.Outline : Text.Normal
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
            text: "Player 2"
            color: current_player == 1 ? "white" : "black"
            styleColor: "green"
            style: current_player == 1 ? Text.Outline : Text.Normal
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
        state: "new_turn"

        states: [
            State {
                name: "new_turn"
                StateChangeScript {
                    script: {
                        current_player = board.getCurrentPlayerColor()
                    }
                }
            },
            State {
                name: "rolling_die"
            },
            State {
                name: "move_token"
            }
        ]


        AnimatedImage {
            id: rollingDie
            visible: boardImg.state == "rolling_die"
            playing: boardImg.state == "rolling_die"
            source: "qrc:///images/die_roll.gif"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            smooth: false
            width: implicitWidth * 4 * boardImg.paintedWidth / boardImg.sourceSize.width
            height: implicitHeight * 4 * boardImg.paintedHeight / boardImg.sourceSize.width
        }

        Image {
            id: dieResult
            visible: boardImg.state != "rolling_die"
            source: "qrc:///images/die_6.png"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            smooth: false
            width: implicitWidth * 4 * boardImg.paintedWidth / boardImg.sourceSize.width
            height: implicitHeight * 4 * boardImg.paintedHeight / boardImg.sourceSize.width

            MouseArea {
                id: dieMouseArea
                anchors.fill: parent
                hoverEnabled: true


                onClicked: function(mouse) {
                    if (boardImg.state == "new_turn") {
                        boardImg.state = "rolling_die";
                        rollDie.start()
                    }
                }
            }
        }

        SequentialAnimation {
            id: rollDie
            PauseAnimation {duration: 500}

            onFinished: {
                dieResult.source = "qrc:///images/die_" + board.rollDie() + ".png"
                boardImg.state = board.getState()
            }
        }

        Glow {
            anchors.fill: dieResult
            source: dieResult
            visible: boardImg.state == "new_turn"
            spread: 1
            radius: 0
        }

        BrightnessContrast {
            visible: boardImg.state == "new_turn" && dieMouseArea.containsMouse
            anchors.fill: dieResult
            source: dieResult
            brightness: 0.3
        }

        BrightnessContrast {
            visible: boardImg.state == "new_turn" && dieMouseArea.containsPress
            anchors.fill: dieResult
            source: dieResult
            brightness: -0.2
        }

        Repeater {
            model: 4
            Repeater {
                model: 4
                property int i: index
                Token {contextObject: board.getToken(i, index)}
            }
        }
    }

    ColumnLayout {
        Layout.fillWidth: true
        Layout.minimumWidth: 150
        Layout.minimumHeight: 150

        Text {
            text: textField3.text
            color: current_player == 3 ? "white" : "black"
            styleColor: "blue"
            style: current_player == 3 ? Text.Outline : Text.Normal
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
            text: textField2.text
            color: current_player == 2 ? "white" : "black"
            styleColor: "yellow"
            style: current_player == 2 ? Text.Outline : Text.Normal
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

    BoardPositions {
        id: boardPos
    }
}
