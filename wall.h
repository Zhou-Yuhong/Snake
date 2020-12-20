#ifndef WALL_H
#define WALL_H
#include "config.h"
#include <QImage>
#include <time.h>
#include <stdlib.h>
class Wall{
public:
    QImage S_wall;
    int wall_x;   //一个墙块的位置（左上角）
    int wall_y;
    QRect W_rect;
    Wall();
    void initial_position(bool flag);

};
class Wallgroup
{
public:
    Wall wall_group[WALL_NUM];
    Wallgroup();
};

#endif // WALL_H
