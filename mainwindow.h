#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QKeyEvent>
#include "snake.h"
#include <QTimer>
#include <QTime>
#include <QWidget>
#include <QString>
#include <QPainter>
#include "wall.h"
#include <QMouseEvent>
#include <fstream>
#include <sstream>
#include <iostream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initScene(); //初始化游戏场景
    QTimer S_timer;   //定时器
    void playGame(); //启动游戏
    void updatePosition(); //更新游戏坐标
    void paintEvent(QPaintEvent *event); //绘图事件
    void collision();    //碰撞检测函数
    void updatefood();    //更新食物
    void updatelable();    //更新标签内容
    void endgame();     //游戏结束的判断
    void restart();     //重新开始游戏
    void write_to_file();  //存档
    void readfile();     //读档
    void ai_mode();     //ai模式
    bool ai_closer(Snake s);       //判断是否接近食物
    bool ai_crash(Snake s);    //ai模式辅助碰撞检测,返回true则发生了碰撞
    int  ai_give_dirc(Snake s);    //给出最优方向，0->方向不变，1->上，2->下，3->左，4->右
private:
    int model=-1;   //初始化为-1，如果进入单蛇模式，modle为0，如果进入双蛇模式，model为1
    bool if_pause=false;  //判断是否处于暂停状态
    bool if_ai=false;     //是否处于ai状态
    QImage scene;
    Wallgroup mywall;   //墙块对象
    int choice=0;         //记录暂停时选中的是食物还是墙块，食物为1，墙为2
    Wall* target=NULL;    //记录暂停时鼠标指向的墙块
    int offset_x=0;       //记录移动墙块的x与鼠标的x的偏移量
    int offset_y=0;       //记录移动墙块的y与鼠标的y的偏移量
    food *fd;
    Ui::MainWindow *ui;
    std::vector<Snake*> mysnake;
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
