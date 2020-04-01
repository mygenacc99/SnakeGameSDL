//
// Created by colab on 30/03/2020.
//

#ifndef SNAKEGAMESDL_SNAKECELL_H
#define SNAKEGAMESDL_SNAKECELL_H

class SnakeCell{
public:
    int posX, posY;
    int state;
    int angle;
    int roundAngle;
    explicit SnakeCell(int posX = 0, int posY = 0, int state = 0, int angle = 0);

};

#endif // SNAKEGAMESDL_SNAKECELL_H
