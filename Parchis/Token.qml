import QtQuick 2.0
import Qt5Compat.GraphicalEffects
import "token.js" as Logic

Item {
    id: item
    property var contextObject;

    Image {
        id: fakeToken
        visible: false
        source: "qrc:///images/" + contextObject.getColorStr() + "_token.png"
        width: implicitWidth * boardImg.paintedWidth / boardImg.sourceSize.width
        height: implicitHeight * boardImg.paintedHeight / boardImg.sourceSize.width
    }

    BrightnessContrast {
        id: fake_token_highlight
        visible: false
        anchors.fill: fakeToken
        source: fakeToken
        brightness: -0.3
        contrast: -0.2
    }

    Image {
        property var orig_coordinate_x: boardPos.getXCoordinate(contextObject.getColor(), contextObject.getBoardPosition(), contextObject.getIdx())
        property var orig_coordinate_y: boardPos.getYCoordinate(contextObject.getColor(), contextObject.getBoardPosition(), contextObject.getIdx())

        id: token
        source: "qrc:///images/" + contextObject.getColorStr() + "_token.png"
        width: implicitWidth * boardImg.paintedWidth / boardImg.sourceSize.width
        height: implicitHeight * boardImg.paintedHeight / boardImg.sourceSize.width
        x: Logic.scaledXCoordinate(orig_coordinate_x)
        y: Logic.scaledYCoordinate(orig_coordinate_y)

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onEntered: function(mouse) {
                if (contextObject.getColor() === board.getCurrentPlayerColor() && contextObject.canMove()) {
                    fakeToken.x = Logic.scaledXCoordinate(boardPos.getXCoordinate(contextObject.getColor(), contextObject.next_board_position, contextObject.getIdx()))
                    fakeToken.y = Logic.scaledYCoordinate(boardPos.getYCoordinate(contextObject.getColor(), contextObject.next_board_position, contextObject.getIdx()))
                    token_highlight.visible = true
                    fake_token_highlight.visible = true
                }
            }

            onExited: function(mouse) {
                token_highlight.visible = false
                fake_token_highlight.visible = false
            }

            onClicked: function(mouse) {
                if (mouse.button === Qt.LeftButton) {
                    if (contextObject.getColor() === board.getCurrentPlayerColor() && contextObject.canMove()) {
                        contextObject.move(board.getCurrentPlayerCells())
                        board.nextTurn()

                        token.orig_coordinate_x = boardPos.getXCoordinate(contextObject.getColor(), contextObject.getBoardPosition(), contextObject.getIdx())
                        token.orig_coordinate_y = boardPos.getYCoordinate(contextObject.getColor(), contextObject.getBoardPosition(), contextObject.getIdx())
                    }
                }
            }
        }
    }

    BrightnessContrast {
        id: token_highlight
        visible: false
        anchors.fill: token
        source: token
        brightness: 0.3
    }
}
