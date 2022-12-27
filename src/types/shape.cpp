#include "shape.hpp"

Shape::Shape()
{
    // list of all possible shapes in the default rotation
    // 0 I       1 S     2 Z     3 T     4 O   5 L     6 J
    // . . . .   . . .   . . .   . X .   X X   . . X   X . .
    // X X X X   . O X   X O .   X O X   X X   X O X   X O X
    // . .o. .   X X .   . X X   . . .         . . .   . . .
    // . . . .
    shape_I.set(iXY(0, 1), 1);
    shape_I.set(iXY(1, 1), 1);
    shape_I.set(iXY(2, 1), 1);
    shape_I.set(iXY(3, 1), 1);

    shape_J.set(iXY(0, 0), 1);
    shape_J.set(iXY(0, 1), 1);
    shape_J.set(iXY(1, 1), 1);
    shape_J.set(iXY(2, 1), 1);

    shape_L.set(iXY(2, 0), 1);
    shape_L.set(iXY(0, 1), 1);
    shape_L.set(iXY(1, 1), 1);
    shape_L.set(iXY(2, 1), 1);

    shape_O.set(iXY(0, 0), 1);
    shape_O.set(iXY(1, 0), 1);
    shape_O.set(iXY(0, 1), 1);
    shape_O.set(iXY(1, 1), 1);

    shape_S.set(iXY(0, 2), 1);
    shape_S.set(iXY(1, 1), 1);
    shape_S.set(iXY(1, 2), 1);
    shape_S.set(iXY(2, 1), 1);

    shape_T.set(iXY(1, 0), 1);
    shape_T.set(iXY(0, 1), 1);
    shape_T.set(iXY(1, 1), 1);
    shape_T.set(iXY(2, 1), 1);

    shape_Z.set(iXY(0, 1), 1);
    shape_Z.set(iXY(1, 1), 1);
    shape_Z.set(iXY(1, 2), 1);
    shape_Z.set(iXY(2, 2), 1);
};
