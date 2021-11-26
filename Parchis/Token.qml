import QtQuick 2.0

Image {
    property var contextObject;
    property string a: contextObject.getColorStr()

    source: "qrc:///images/" + a + "_token.png"
    width: implicitWidth * parent.paintedWidth / parent.sourceSize.width
    height: implicitHeight * parent.paintedHeight / parent.sourceSize.width
    x: (-implicitWidth / 2 + contextObject.x_coordinate) * parent.paintedWidth / parent.sourceSize.width
    y: (-implicitHeight / 2  + contextObject.y_coordinate) * parent.paintedHeight / parent.sourceSize.width + (parent.height - parent.paintedHeight)/2
    horizontalAlignment: Image.AlignHCenter
    verticalAlignment: Image.AlignVCenter
    focus: true

    MouseArea {
        anchors.fill: parent

        onClicked: function(mouse) {
            if (mouse.button === Qt.LeftButton) {
                var new_board_position = contextObject.calculateMove(dice.getLastRoll(), board.getCurrentPlayerCells())
                if (contextObject.getColor() === board.getCurrentPlayerColor() && new_board_position !== -1) {
                    contextObject.move(new_board_position, board.getCurrentPlayerCells())
                    board.nextTurn()
                }
            }
        }
    }
}
