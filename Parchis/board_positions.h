#ifndef BOARD_POSITIONS_H
#define BOARD_POSITIONS_H

#include <QObject>
#include "color.h"

// Red and Yellow X, Blue and Green Y
const int BASE_MIDDLE = 399;

// Green X and Red Y
const int BASE_TOP_LEFT[] =
{
    54,
    90,
    126,
    162,
    198,
    234,
    270,
    306,
};

// Blue X and Yellow Y
const int BASE_BOTTOM_RIGHT[] =
{
    744,
    708,
    672,
    636,
    600,
    564,
    528,
    492,
};

// Center 125, 125
const int NEST_X_LEFT[] =
{
    75,
    175,
    75,
    175
};

const int NEST_X_RIGHT[] =
{
    623,
    723,
    623,
    723
};

const int NEST_Y_TOP[] =
{
    75,
    75,
    175,
    175
};

const int NEST_Y_BOT[] =
{
    623,
    623,
    723,
    723
};

const int BOARD_X[] =
{
    497,
    497,
    497,
    497,
    497,
    497,
    497,
    497, // position 8
    528,
    564,
    600,
    636,
    672,
    708,
    744,
    780, // 16
    780,
    780,
    744,
    708,
    672,
    636,
    600,
    564, // 24
    528,
    497,
    497,
    497,
    497,
    497,
    497,
    497, // 32
    497,
    399,
    301,
    301,
    301,
    301,
    301,
    301, // 40
    301,
    301,
    270,
    234,
    198,
    162,
    126,
    90,
    54,
    18,
    18,
    18,
    54,
    90,
    126,
    162,
    198,
    234,
    270,
    301,
    301,
    301,
    301,
    301,
    301,
    301,
    301,
    399,
};

// 18, 54, 90, 126, 162, 198, 234, 270, 301, 399,
// 497, 528, 564, 600, 636, 672, 708, 744, 780

const int BOARD_Y[] =
{
    780,
    744,
    708,
    672,
    636,
    600,
    564,
    528, // Position 8
    497,
    497,
    497,
    497,
    497,
    497,
    497,
    497, // 16
    399,
    301,
    301,
    301,
    301,
    301,
    301,
    301,
    301, // 25
    270,
    234,
    198,
    162,
    126,
    90,
    54,
    18,
    18,
    18,
    54,
    90,
    126,
    162,
    198,
    234,
    270, // 42
    301,
    301,
    301,
    301,
    301,
    301,
    301,
    301,
    399,
    497,
    497,
    497,
    497,
    497,
    497,
    497,
    497,
    528,
    564,
    600,
    636,
    672,
    708,
    744,
    780,
    780
};

class BoardPositions : public QObject
{
    Q_OBJECT
public:
    explicit BoardPositions(QObject *parent = 0);

    Q_INVOKABLE static int getXCoordinate(Color color, int board_position);
    Q_INVOKABLE static int getYCoordinate(Color color, int board_position);

};

#endif
