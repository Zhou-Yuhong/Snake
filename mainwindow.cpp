#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   srand(time(NULL));
    ui->setupUi(this);
    ui->pause_group->hide();     //隐藏开始页面不需要的界面
    ui->groupBox->hide();
    //美化
    /************************************************************************************************************************************/
    QFont ft("Microsoft YaHei", 12); //设置字体字号
    QPalette pa;
    pa.setColor(QPalette::WindowText,QColor("#bb8877"));//设置颜色
    ui->fail_label->setFont(ft);
    ui->fail_label->setPalette(pa);
    ui->llabel->setFont(ft);
    ui->llabel->setPalette(pa);
    ui->pause_label->setFont(ft);
    ui->pause_label->setPalette(pa);
    ui->rlabel->setFont(ft);
    ui->rlabel->setPalette(pa);

    ui->pushButton->setStyleSheet("QPushButton{  background-color:rgba(255,178,0,100%);\
                                                color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
            "QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
            "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色
    ui->pushButton_2->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
                                            color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
        "QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色
    ui->pushButton_3->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
                                            color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
        "QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色
    ui->pushButton_4->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
                                                color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
            "QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
            "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色
    ui->ai_button->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
                                                color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
            "QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
            "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色
    ui->begin_read->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
                                                color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
            "QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
            "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色
    ui->fail_restart->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
                                                color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
            "QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
            "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色
    ui->pause_quit->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
                                                color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
            "QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
            "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色
    ui->stop_restart->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
                                                color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
            "QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
            "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色
    ui->stop_save->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
                                                color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
            "QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
            "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色
    ui->continue_2->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
                                                color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
            "QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
            "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色
/**********************************************************************************************************************************************/
    setFocusPolicy(Qt::StrongFocus);
    fd=new food();
    initScene();
    S_timer.setInterval(GAME_RATE);
    connect(ui->pushButton,&QPushButton::clicked,[=](){      //单蛇模式
        Snake *mode0=new Snake(0);
        mysnake.push_back(mode0);
        ui->initwindow->close();
        model=0;
        playGame();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){      //双蛇模式
        Snake *mode1=new Snake(1);
        Snake *mode2=new Snake(2);
        mysnake.push_back(mode1);
        mysnake.push_back(mode2);
        ui->initwindow->close();
        model=1;
        playGame();
    });
    connect(ui->ai_button,&QPushButton::clicked,[=](){      //AI蛇
        Snake *mode0=new Snake(0);
        mysnake.push_back(mode0);
        ui->initwindow->close();
        model=0;
        if_ai=true;
        playGame();
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=]
            (){
        close();
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        close();
    });
    connect(ui->pause_quit,&QPushButton::clicked,[=](){
       close();
    });
    connect(ui->continue_2,&QPushButton::clicked,[=](){     //继续游戏
       S_timer.start();
       ui->pause_group->hide();
       if_pause=false;
    });
    connect(ui->fail_restart,&QPushButton::clicked,[=](){    //失败界面的重新开始
       restart();
       S_timer.start();
       ui->groupBox->hide();
    });
    connect(ui->stop_restart,&QPushButton::clicked,[=](){      //暂停界面的重新开始
       restart();
    });
    connect(ui->stop_save,&QPushButton::clicked,[=](){      //存档
        write_to_file();
    });
    connect(ui->begin_read,&QPushButton::clicked,[=](){
        readfile();
        ui->initwindow->close();
        playGame();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fd;
    for(int i=0;i<mysnake.size();i++){
        delete mysnake[i];
    }
}

void MainWindow::initScene()
{   if_pause=true;
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    scene.load(BEGIN_MAP_PATH);


}

void MainWindow::playGame()
{   if_pause=false;
    scene.load(MAP_PATH);
    S_timer.start();       
    connect(&S_timer,&QTimer::timeout,[=](){           //计时器
       if(if_ai) ai_mode();
       updatePosition();
       collision();
       update();
       updatelable();
       endgame();   //检测是否结束
    });
}

void MainWindow::updatePosition()
{
    for(int i=0;i<mysnake.size();i++){
        mysnake[i]->update_snake();

    }
    updatefood();
    //fd->update_food();
}
void MainWindow::updatelable()
{
    if(mysnake.size()==1){
        QString str=QString("生命为%1,得分为%2").arg(mysnake[0]->getlife()).arg(mysnake[0]->getpoint());
        ui->rlabel->setText(str);
    }
    if(mysnake.size()==2){
        QString str=QString("右蛇生命为%1,得分为%2").arg(mysnake[1]->getlife()).arg(mysnake[1]->getpoint());
        ui->rlabel->setText(str);
        QString str2=QString("左蛇生命为%1,得分为%2").arg(mysnake[0]->getlife()).arg(mysnake[0]->getpoint());
        ui->llabel->setText(str2);
    }
}

void MainWindow::endgame()
{     if(model==0) {
        if(mysnake[0]->getlife()<=0){
            S_timer.stop();
            ui->fail_label->setText("you lose!");
            ui->groupBox->show();
        }
       }
      if(model==1){
          if(mysnake[0]->getlife()<=0){
              S_timer.stop();
              ui->fail_label->setText("the right win!");
              ui->groupBox->show();
          }
          if(mysnake[1]->getlife()<=0){
              S_timer.stop();
              ui->fail_label->setText("the left win!");
              ui->groupBox->show();
          }
      }

}

void MainWindow::restart()
{   if(model==0){
        Snake *p=mysnake[0];
        delete p;
        p=NULL;
        mysnake.clear();
        Snake *mode0=new Snake(0);
        mysnake.push_back(mode0);
    }
    if(model==1){
        Snake  *p=mysnake[1];
        delete p;
        p=mysnake[0];
        delete p;
        p=NULL;
        mysnake.clear();
        Snake *mode1=new Snake(1);
        Snake *mode2=new Snake(2);
        mysnake.push_back(mode1);
        mysnake.push_back(mode2);
    }
    update();
}

void MainWindow::write_to_file()
{
      std::ofstream outfile("gamedata.txt");
      outfile<<model<<std::endl;    //写入游戏模式
      for(int i=0;i<mysnake.size();i++){
          Snake *p=mysnake[i];
          outfile<<p->getlife()<<' '<<p->getpoint()<<' '<<p->head->speed<<' '<<p->head->node_x<<' '<<p->head->node_y<<' '<<p->head->direc<<std::endl;  //写入蛇头数据
          node *q=p->head->next;
          while(q!=NULL){ //写入蛇头后的每一个节点
              outfile<<q->speed<<' '<<q->node_x<<' '<<q->node_y<<' '<<q->direc<<std::endl;
              q=q->next;
          }
          outfile<<0<<' '<<0<<' '<<0<<' '<<0<<std::endl;   //标示一条蛇的写入结束
      }
      for(int i=0;i<WALL_NUM;i++){             //写入每个墙块的位置
          outfile<<mywall.wall_group[i].wall_x<<' '<<mywall.wall_group[i].wall_y<<std::endl;
      }
      outfile<<fd->type<<' '<<fd->food_x<<' '<<fd->food_y;
}

void MainWindow::readfile()
{
    std::ifstream infile("gamedata.txt");
    std::stringstream ss;
    std::string line;
    std::getline(infile,line);
    ss<<line;
    int Model;
    int num1,num2,num3,num4,num5,num6;
    ss>>Model;
    model=Model;
    ss.clear();
    for(int i=0;i<Model+1;i++){
        std::getline(infile,line);
        ss<<line;
        ss>>num1>>num2>>num3>>num4>>num5>>num6;
        Snake* f=new Snake(num1,num2,num3,num4,num5,direction(num6));
        node *q=f->head;
        while(true){
            std::getline(infile,line);
            ss.clear();
            ss<<line;
            ss>>num1>>num2>>num3>>num4;
            if(num1==0)
                break;
            node*p=new node(num1,num2,num3,direction(num4));
            q->next=p;
            p->prev=q;
            f->tail=p;
            q=q->next;
        }
        mysnake.push_back(f);
    }
    for(int i=0;i<WALL_NUM;i++){
        std::getline(infile,line);
        ss.clear();
        ss<<line;
        ss>>num1>>num2;
        mywall.wall_group[i].wall_x=num1;
        mywall.wall_group[i].wall_y=num2;
        mywall.wall_group[i].W_rect.moveTo(num1,num2);
    }
    std::getline(infile,line);
    ss.clear();
    ss<<line;
    ss>>num1>>num2>>num3;
    fd->type=typeoffood(num1);
    fd->food_x=num2;
    fd->food_y=num3;
    fd->f_Rect.moveTo(fd->food_x,fd->food_y);
    switch(fd->type){              //enum typeoffood{apple,heart,ice,energy,mushroom};
      case 0:
        fd->m_food.load(FOOD_APPLE_PATH);
        break;
      case 1:
        fd->m_food.load(FOOD_HEART_PATH);
        break;
      case 2:
        fd->m_food.load(FOOD_ICE_PATH);
        break;
      case 3:
        fd->m_food.load(FOOD_ENERGY_PATH);
        break;
      case 4:
        fd->m_food.load(FOOD_MUSHROOM_PATH);
        break;
    }
}
//void shift_to_up();       //蛇蛇转头
//void shift_to_down();
//void shift_to_left();
//void shift_to_right();
void MainWindow::ai_mode()
{    if(mysnake.empty()) return;
    switch(ai_give_dirc(*mysnake[0])){
       case 0:
        break;
       case 1:
        mysnake[0]->shift_to_up();
        break;
       case 2:
        mysnake[0]->shift_to_down();
        break;
       case 3:
        mysnake[0]->shift_to_left();
       case 4:
        mysnake[0]->shift_to_right();
        break;
    }
}

bool MainWindow::ai_closer(Snake s)
{   int node_x=s.head->node_x+s.head->S_Rect.width()/2;
    int node_y=s.head->node_y+s.head->S_Rect.height()/2;
    int food_x=fd->food_x+fd->f_Rect.width()/2;
    int food_y=fd->food_y+fd->f_Rect.height()/2;
    int disdance=(node_x-food_x)*(node_x-food_x)+(node_y-food_y)*(node_y-food_y);
    s.update_snake();
     node_x=s.head->node_x+s.head->S_Rect.width()/2;
     node_y=s.head->node_y+s.head->S_Rect.height()/2;
     food_x=fd->food_x+fd->f_Rect.width()/2;
     food_y=fd->food_y+fd->f_Rect.height()/2;
    int new_disdance=(node_x-food_x)*(node_x-food_x)+(node_y-food_y)*(node_y-food_y);
    if(new_disdance<disdance) return true;
    else return false;
}

bool MainWindow::ai_crash(Snake s)
{
    bool flag=false;
    for(int i=0;i<AI_RATE;i++){
        s.update_snake();
    }
    for(int i=0;i<WALL_NUM;i++){
        if(s.head->S_Rect.intersects(mywall.wall_group[i].W_rect)){
            flag=true;
            break;
        }
    }
    if(flag==false){
    node *p=s.head->next->next;
     while(p!=NULL&&p->next!=NULL){                    //咬到最后一节似乎不会死
         if(s.head->S_Rect.intersects(p->S_Rect)){
            flag=true;
            break;
         }
      p=p->next;
     }
    }
    return flag;
}

int MainWindow::ai_give_dirc(Snake s)
{
    if(!ai_crash(s)&&ai_closer(s)) return 0;
    std::vector<int> tmp;
    Snake s_up=s;
    Snake s_down=s;
    Snake s_left=s;
    Snake s_right=s;
    s_up.shift_to_up();
    s_down.shift_to_down();
    s_left.shift_to_left();
    s_right.shift_to_right();
      switch(s.head->direc){
         case 0:
          if(!ai_crash(s_left)) tmp.push_back(3);
          if(!ai_crash(s_right)) tmp.push_back(4);
          break;
         case 1:
          if(!ai_crash(s_left)) tmp.push_back(3);
          if(!ai_crash(s_right)) tmp.push_back(4);
          break;
         case 2:
          if(!ai_crash(s_up)) tmp.push_back(1);
          if(!ai_crash(s_down)) tmp.push_back(2);
          break;
         case 3:
          if(!ai_crash(s_up)) tmp.push_back(1);
          if(!ai_crash(s_down)) tmp.push_back(2);
          break;
      }

//    if(!ai_crash(s_up)) tmp.push_back(1);
//    if(!ai_crash(s_down)) tmp.push_back(2);
//    if(!ai_crash(s_left)) tmp.push_back(3);
//    if(!ai_crash(s_right)) tmp.push_back(4);
    if(tmp.size()==1) return tmp[0];
    for(int i=0;i<tmp.size();i++){
        switch(tmp[i]){
         case 1:
            if(ai_closer(s_up)) return 1;
            break;
         case 2:
            if(ai_closer(s_down)) return 2;
            break;
         case 3:
            if(ai_closer(s_left)) return 3;
            break;
         case 4:
            if(ai_closer(s_right)) return 4;
        }
    }
    if(tmp.empty()) return 3;
    else return tmp[0];
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0,0,scene);    //绘制背景
    for(int i=0;i<mysnake.size();i++){      //画蛇
        painter.drawImage(mysnake[i]->head->node_x,mysnake[i]->head->node_y,mysnake[i]->head->S_node);
        node *p=mysnake[i]->head->next;
        while(p!=NULL){
            //if(p==mysnake[i]->tail) break;
            painter.drawImage(p->node_x,p->node_y,p->S_node);
            p=p->next;

        }
    }
    painter.drawImage(fd->food_x,fd->food_y,fd->m_food);  //画食物
    for(int i=0;i<WALL_NUM;i++){
        painter.drawImage(mywall.wall_group[i].wall_x,mywall.wall_group[i].wall_y,mywall.wall_group[i].S_wall);
    }
}

void MainWindow::collision()        //碰撞检测
{
    for(int i=0;i<mysnake.size();i++){                 //进行与食物的碰撞检测
        mysnake[i]->eatfood(fd);
    }
    for(int i=0;i<mysnake.size();i++){
        mysnake[i]->crash(mywall);
    }
}

void MainWindow::updatefood()        //bug
{   if(fd->f_free) return;
    while(true){
        fd->update_food();
        bool flag=true;
        for(int i=0;i<WALL_NUM;i++){
            if(fd->f_Rect.intersects(mywall.wall_group[i].W_rect)) {
                flag=false;
                fd->f_free=false;
                break;
            }
        }
    for(int i=0;i<mysnake.size();i++){
        if(flag==false) break;
        node *p=mysnake[i]->head;
        while(p!=NULL){
            if(fd->f_Rect.intersects(p->S_Rect)){
                flag=false;
                fd->f_free=false;
                break;
            }
            else p=p->next;
         }
      }
    if(flag) break;

    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(mysnake.empty()) return;
    if(event->key()==KEYBOARD_SPACE){
        S_timer.stop();
        ui->pause_group->show();
        ui->pause_group->setTitle("暂停");
        ui->pause_label->setText("此时可以编辑墙块和食物");
        if_pause=true;
    }
    if(event->key()==KEYBOARD_ENTER){
        if_ai=!if_ai;
    }
    if(mysnake.size()==1){
        if(event->key()==KEYBOARD_UP) mysnake[0]->shift_to_up();
        if(event->key()==KEYBOARD_DOWN) mysnake[0]->shift_to_down();
        if(event->key()==KEYBOARD_LEFT) mysnake[0]->shift_to_left();
        if(event->key()==KEYBOARD_RIGHT) mysnake[0]->shift_to_right();
    }
    if(mysnake.size()==2){
        if(event->key()==KEYBOARD_UP) mysnake[1]->shift_to_up();
        if(event->key()==KEYBOARD_DOWN) mysnake[1]->shift_to_down();
        if(event->key()==KEYBOARD_LEFT) mysnake[1]->shift_to_left();
        if(event->key()==KEYBOARD_RIGHT) mysnake[1]->shift_to_right();
        if(event->key()==KEYBOARD_W) mysnake[0]->shift_to_up();
        if(event->key()==KEYBOARD_S) mysnake[0]->shift_to_down();
        if(event->key()==KEYBOARD_A) mysnake[0]->shift_to_left();
        if(event->key()==KEYBOARD_D) mysnake[0]->shift_to_right();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(if_pause){
        if(fd->f_Rect.contains(event->x(),event->y())){
           offset_x=fd->food_x-event->x();
           offset_y=fd->food_y-event->y();
           choice=1;
           return;
         }
        for(int i=0;i<WALL_NUM;i++){
            if(mywall.wall_group[i].W_rect.contains(event->x(),event->y())){
                target=&(mywall.wall_group[i]);
                offset_x=target->wall_x-event->x();
                offset_y=target->wall_y-event->y();
                choice=2;
                break;
             }
            }
        }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{   switch(choice){
    case 0:
        break;
    case 1:
        if(if_pause&&(event->buttons()==Qt::LeftButton)){
         fd->food_x=offset_x+event->x();
         fd->food_y=offset_y+event->y();
         fd->f_Rect.moveTo(fd->food_x,fd->food_y);
         update();
          }
        break;
    case 2:
        if(if_pause&&(event->buttons()==Qt::LeftButton)){
         target->wall_x=offset_x+event->x();
         target->wall_y=offset_y+event->y();
         target->W_rect.moveTo(target->wall_x,target->wall_y);
         update();
          }
        break;
    }
}

