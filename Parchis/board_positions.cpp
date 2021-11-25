#include "board_positions.h"
#include "color.h"

BoardPositions::BoardPositions( QObject * parent ) :
    QObject( parent )
{
}

int BoardPositions::getXCoordinate(Color color, int board_position, int idx) {
    if (board_position >= 0 && board_position <= 67) {
        return BOARD_X[board_position];
    }
    else if (board_position < 0) {
        board_position -= idx;
        switch(color) {
            case Color::Red:
                return NEST_X_LEFT[board_position + 4];
            break;
            case Color::Blue:
                return NEST_X_RIGHT[board_position + 4];
            break;
            case Color::Green:
                return NEST_X_LEFT[board_position + 4];
            break;
            case Color::Yellow:
                return NEST_X_RIGHT[board_position + 4];
            break;
            default:
            break;
        }
    } else {
        switch(color) {
            case Color::Red:
                return BASE_MIDDLE;
            break;
            case Color::Blue:
                return BASE_BOTTOM_RIGHT[board_position - 68];
            break;
            case Color::Green:
                return BASE_TOP_LEFT[board_position - 68];
            break;
            case Color::Yellow:
                return BASE_MIDDLE;
            break;
            default:
            break;
        }
    }
}

int BoardPositions::getYCoordinate(Color color, int board_position, int idx) {
    if (board_position >= 0 && board_position <= 67) {
        return BOARD_Y[board_position];
    }
    else if (board_position < 0) {
        board_position -= idx;
        switch(color) {
            case Color::Red:
                return NEST_Y_TOP[board_position + 4];
            break;
            case Color::Blue:
                return NEST_Y_TOP[board_position + 4];
            break;
            case Color::Green:
                return NEST_Y_BOT[board_position + 4];
            break;
            case Color::Yellow:
                return NEST_Y_BOT[board_position + 4];
            break;
            default:
            break;
        }
    } else {
        switch(color) {
            case Color::Red:
                return BASE_TOP_LEFT[board_position - 68];
            break;
            case Color::Blue:
                return BASE_MIDDLE;
            break;
            case Color::Green:
                return BASE_MIDDLE;
            break;
            case Color::Yellow:
                return BASE_BOTTOM_RIGHT[board_position - 68];
            break;
            default:
            break;
        }
    }
}
