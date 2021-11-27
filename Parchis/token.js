function scaledXCoordinate(x) {
    return (-token.implicitWidth / 2 + x) * boardImg.paintedWidth / boardImg.sourceSize.width
}

function scaledYCoordinate(y) {
    return (-token.implicitHeight / 2  + y) * boardImg.paintedHeight / boardImg.sourceSize.width + (boardImg.height - boardImg.paintedHeight)/2
}
