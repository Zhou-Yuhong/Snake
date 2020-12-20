#ifndef SNAKE_H
#define SNAKE_H
#include <QPixmap>
#include <QImage>
#include "config.h"
#include "food.h"
#include "wall.h"

enum direction{up,down,left,right};
class node{
  private:


  public:
    int speed;
    int node_x;        //节点的x坐标
    int node_y;        //节点的y坐标(也是矩形框左上角)
    QImage S_node;    //一节蛇资源
    direction direc;   //节点前进方向
    QRect S_Rect;      //一个节点的矩形边框
    node *prev,*next;  //前后节点
    node(node* &pre_node);     //用于构建身子节点
    node(int mode);        //专门用于初始化蛇头,根据mode的值定义初始位置（用于多蛇游戏）
    node(int Speed,int x,int y,direction dir);   //用于读档时初始化一个节点
    void updatenode();  //更新节点位置
};
class Snake{
  private:
    int life;
    int point=0;
    bool flag=false;   //碰撞辅助变量
  public:
    //int numofnode;
    int getpoint() const{
        return point;
    }
    int getlife() const{
        return life;
    }
    node *tail;         //尾结点
    node *head;         //头结点
    void add_life();    //加命
    bool decrease_life(); //减命,当死亡时返回true
    void addnode();  //增加节点(在tail后面)
    Snake(int mode);
    Snake(int Life,int Point,int Speed,int x,int y,direction dir);       //用于读档时的初始化
    void update_snake();     //更新蛇蛇状态
    void shift_to_up();       //蛇蛇转头
    void shift_to_down();
    void shift_to_left();
    void shift_to_right();
    void eatfood(food* fd);    //做碰撞检测，同时改变蛇状态和食物状态
    void crash(Wallgroup W_group);    //蛇撞墙撞块撞自己撞边际
    void add_speed(int num);   //增加蛇速度
    void decrease_speed(int num);//减小蛇速度
    void delete_last();        //删除最后的节点
    Snake(const Snake &snake);     //自定义复制构造函数，用于Ai蛇的辅助设计
    ~Snake();
};

#endif // SNAKE_H
