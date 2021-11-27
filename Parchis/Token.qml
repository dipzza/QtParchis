import QtQuick 2.0
import Qt5Compat.GraphicalEffects

Item {
    property var contextObject;

    Image {
        id: fakeToken
        visible: false
        source: "qrc:///images/" + contextObject.getColorStr() + "_token.png"
        width: implicitWidth * boardImg.paintedWidth / boardImg.sourceSize.width
        height: implicitHeight * boardImg.paintedHeight / boardImg.sourceSize.width
        x: 0
        y: 0
    }

    BrightnessContrast {
        id: fake_token_highlight
        visible: false
        anchors.fill: fakeToken
        source: fakeToken
        brightness: -0.2
        contrast: -0.2
    }

    Image {
        id: token
        source: "qrc:///images/" + contextObject.getColorStr() + "_token.png"
        width: implicitWidth * boardImg.paintedWidth / boardImg.sourceSize.width
        height: implicitHeight * boardImg.paintedHeight / boardImg.sourceSize.width
        x: (-implicitWidth / 2 + contextObject.x_coordinate) * boardImg.paintedWidth / boardImg.sourceSize.width
        y: (-implicitHeight / 2  + contextObject.y_coordinate) * boardImg.paintedHeight / boardImg.sourceSize.width + (boardImg.height - boardImg.paintedHeight)/2
        horizontalAlignment: Image.AlignHCenter
        verticalAlignment: Image.AlignVCenter
        focus: true

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onEntered: function(mouse) {
                var new_passed_cells = contextObject.calculateMove(dice.getLastRoll(), board.getCurrentPlayerCells())
                var new_board_position = contextObject.calculateBoardPosition(new_passed_cells)
                if (contextObject.getColor() === board.getCurrentPlayerColor() && new_board_position !== -1) {
                    fakeToken.x = (-fakeToken.implicitWidth / 2 + boardPos.getXCoordinate(contextObject.getColor(), new_board_position, contextObject.getIdx())) * boardImg.paintedWidth / boardImg.sourceSize.width
                    fakeToken.y = (-fakeToken.implicitHeight / 2  + boardPos.getYCoordinate(contextObject.getColor(), new_board_position, contextObject.getIdx())) * boardImg.paintedHeight / boardImg.sourceSize.width + (boardImg.height - boardImg.paintedHeight)/2
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
                    var new_passed_cells = contextObject.calculateMove(dice.getLastRoll(), board.getCurrentPlayerCells())
                    if (contextObject.getColor() === board.getCurrentPlayerColor() && new_passed_cells !== -1) {
                        contextObject.move(new_passed_cells, board.getCurrentPlayerCells())
                        board.nextTurn()
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
        brightness: 0.2
    }
}
