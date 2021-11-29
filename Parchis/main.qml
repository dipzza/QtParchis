import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects

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
            state: "new_turn"

            states: [
                State {
                    name: "new_turn"
                    StateChangeScript {
                        script: {
                            board.clearMoves()
                            board.nextTurn()
                        }
                    }
                },
                State {
                    name: "rolling_die"
                    StateChangeScript {
                        script: {
                            board.rollDie()
                            dieResult.source = "qrc:///images/die_" + board.getLastRoll() + ".png"
                        }
                    }

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
                    var can_move = board.calculateMoves()
                    if(can_move) {
                        boardImg.state = "move_token"
                    } else {
                        boardImg.state = "new_turn"
                    }
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
