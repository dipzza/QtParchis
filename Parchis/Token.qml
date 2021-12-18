import QtQuick 2.0
import Qt5Compat.GraphicalEffects
import "token.js" as Logic

Item {
    id: token
    property var contextObject;
    property bool can_move: false;

    states: [
        State {
            name: "maybe_movable"
            when: (boardImg.state === "move_token")
            StateChangeScript {
                script: {
                    token.can_move = contextObject.canMove()
                    if (token.can_move) {
                        fakeToken.x = Logic.scaledXCoordinate(boardPos.getXCoordinate(contextObject.getColor(), contextObject.next_board_position, contextObject.getIdx()))
                        fakeToken.y = Logic.scaledYCoordinate(boardPos.getYCoordinate(contextObject.getColor(), contextObject.next_board_position, contextObject.getIdx()))
                    }
                }
            }
        },
        State {
            name: "not_movable"
            when: (boardImg.state !== "move_token")
            StateChangeScript {
                script: {
                    token.can_move = false
                }
            }
        }
    ]

    Image {
        property var orig_coordinate_x: boardPos.getXCoordinate(contextObject.getColor(), contextObject.getBoardPosition(), contextObject.getIdx())
        property var orig_coordinate_y: boardPos.getYCoordinate(contextObject.getColor(), contextObject.getBoardPosition(), contextObject.getIdx())

        id: tokenImg
        source: "qrc:///images/" + contextObject.getColorStr() + "_token.png"
        width: implicitWidth * boardImg.paintedWidth / boardImg.sourceSize.width
        height: implicitHeight * boardImg.paintedHeight / boardImg.sourceSize.width
        x: Logic.scaledXCoordinate(orig_coordinate_x)
        y: Logic.scaledYCoordinate(orig_coordinate_y)

        MouseArea {
            id: tokenMouseArea
            anchors.fill: parent
            hoverEnabled: true

            onClicked: function(mouse) {
                if (token.can_move) {
                    board.moveCurrentPlayerToken(contextObject.getIdx())
                    tokenImg.orig_coordinate_x = boardPos.getXCoordinate(contextObject.getColor(), contextObject.getBoardPosition(), contextObject.getIdx())
                    tokenImg.orig_coordinate_y = boardPos.getYCoordinate(contextObject.getColor(), contextObject.getBoardPosition(), contextObject.getIdx())
                    boardImg.state = board.getState()
                }
            }
        }
    }

    DropShadow {
        id: drop_shadow
        visible: (!tokenMouseArea.containsPress || !token.can_move)
        anchors.fill: tokenImg
        source: tokenImg
        horizontalOffset: 2.5
        verticalOffset: 2.5
    }

    BrightnessContrast {
        visible: token.can_move && tokenMouseArea.containsMouse
        anchors.fill: tokenImg
        source: tokenImg
        brightness: 0.3
    }

    BrightnessContrast {
        visible: !token.can_move
        anchors.fill: tokenImg
        source: tokenImg
        brightness: -0.25
        contrast: -0.1
    }

    Image {
        id: fakeToken
        visible: false
        source: "qrc:///images/" + contextObject.getColorStr() + "_token.png"
        width: implicitWidth * boardImg.paintedWidth / boardImg.sourceSize.width
        height: implicitHeight * boardImg.paintedHeight / boardImg.sourceSize.width
    }

    BrightnessContrast {
        id: fake_token_highlight
        visible: token.can_move && tokenMouseArea.containsMouse
        anchors.fill: fakeToken
        source: fakeToken
        brightness: -0.3
        contrast: -0.2
    }
}
