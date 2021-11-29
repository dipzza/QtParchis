function scaledXCoordinate(x) {
    return (-tokenImg.implicitWidth / 2 + x) * boardImg.paintedWidth / boardImg.sourceSize.width
}

function scaledYCoordinate(y) {
    return (-tokenImg.implicitHeight / 2  + y) * boardImg.paintedHeight / boardImg.sourceSize.width + (boardImg.height - boardImg.paintedHeight)/2
}
