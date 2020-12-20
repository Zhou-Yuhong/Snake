#include"wall.h"

Wall::Wall()
{

    initial_position(true);

}

void Wall::initial_position(bool flag)            //flag为true时为创建对象时使用的，flag为false为调整位置使用的
{
    QRect S1(468,320,24,96);      //三个蛇初始化的位置
    QRect S2(308,320,24,96);
    QRect S3(628,320,24,96);
    if(flag){                      //只需在构造函数中执行一次的代码
    S_wall.load(WALL_PATH);
    wall_x=rand()%(GAME_WIDTH-S_wall.width());
    wall_y=rand()%(GAME_HEIGHT-S_wall.height());
    W_rect.setWidth(S_wall.width());
    W_rect.setHeight(S_wall.height());
    W_rect.moveTo(wall_x,wall_y);
    }
    while(W_rect.intersects(S1)||W_rect.intersects(S2)||W_rect.intersects(S3)){      //如果初始化的位置与蛇相撞，则换位置
        wall_x=rand()%(GAME_WIDTH-S_wall.width());
        wall_y=rand()%(GAME_HEIGHT-S_wall.height());
        W_rect.moveTo(wall_x,wall_y);
    }
}

Wallgroup::Wallgroup()
{    for(int i=1;i<WALL_NUM;i++){
        for(int j=0;j<i;j++){
            if(wall_group[i].W_rect.intersects(wall_group[j].W_rect)) wall_group[i].initial_position(false);
        }
    }

}
