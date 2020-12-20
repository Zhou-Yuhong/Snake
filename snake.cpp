#include "snake.h"
node::node(node *&pre_node){
    //QPixmapCache::setCacheLimit(1);
    direc=pre_node->direc;
    speed=pre_node->speed;
    switch(direc){                         //根据前一个节点的运动方向初始化新节点
       case 0:
        S_node.load(BODY_UP_PATH);
        node_x=pre_node->node_x;
        node_y=pre_node->node_y+(S_node.height()+pre_node->S_node.height())/2;
        S_Rect.setWidth(S_node.width());
        S_Rect.setHeight(S_node.height());
        S_Rect.moveTo(node_x,node_y);
        prev=pre_node;
        next=NULL;
        pre_node->next=this;
        break;
      case 1:
       S_node.load(BODY_UP_PATH);
       node_x=pre_node->node_x;
       node_y=pre_node->node_y-(S_node.height()+pre_node->S_node.height())/2;
       S_Rect.setWidth(S_node.width());
       S_Rect.setHeight(S_node.height());
       S_Rect.moveTo(node_x,node_y);
       prev=pre_node;
       next=NULL;
       pre_node->next=this;
       break;
     case 2:
       S_node.load(BODY_LEVEL_PATH);
       node_y=pre_node->node_y;
       node_x=pre_node->node_x+(S_node.width()+pre_node->S_node.width())/2;
       S_Rect.setWidth(S_node.width());
       S_Rect.setHeight(S_node.height());
       S_Rect.moveTo(node_x,node_y);
       prev=pre_node;
       next=NULL;
       pre_node->next=this;
       break;
     case 3:
      S_node.load(BODY_LEVEL_PATH);
      node_y=pre_node->node_y;
      node_x=pre_node->node_x-(S_node.width()+pre_node->S_node.width())/2;
      S_Rect.setWidth(S_node.width());
      S_Rect.setHeight(S_node.height());
      S_Rect.moveTo(node_x,node_y);
      prev=pre_node;
      next=NULL;
      pre_node->next=this;
      break;

    }

}
node::node(int mode){                       //mode为0->单蛇游戏，mode为1->双蛇游戏左边的蛇，mode为2->双蛇游戏右边的蛇
    speed=SNAKE_SPEED;
    //QPixmapCache::setCacheLimit(1);
    S_node.load(HEAD_UP_PATH);
    direc=up;
    switch(mode){
     case 0:
       node_x=GAME_WIDTH/2-S_node.width()/2;
       node_y=GAME_HEIGHT/2;
       break;
     case 1:
        node_x=GAME_WIDTH/3-S_node.width()/2;
        node_y=GAME_HEIGHT/2;
        break;
     case 2:
        node_x=(GAME_WIDTH*2)/3-S_node.width()/2;
        node_y=(GAME_HEIGHT)/2;
        break;

    }
    S_Rect.setWidth(S_node.width());
    S_Rect.setHeight(S_node.height());
    S_Rect.moveTo(node_x,node_y);
    prev=next=NULL;

}

node::node(int Speed, int x, int y, direction dir)
{
    speed=Speed;
    node_x=x;
    node_y=y;
    direc=dir;
    switch(dir){
    case 0:
     S_node.load(BODY_UP_PATH);
     S_Rect.setWidth(S_node.width());
     S_Rect.setHeight(S_node.height());
     S_Rect.moveTo(node_x,node_y);
     prev=NULL;
     next=NULL;
     break;
    case 1:
     S_node.load(BODY_UP_PATH);
     S_Rect.setWidth(S_node.width());
     S_Rect.setHeight(S_node.height());
     S_Rect.moveTo(node_x,node_y);
     prev=NULL;
     next=NULL;
     break;
    case 2:
     S_node.load(BODY_LEVEL_PATH);
     S_Rect.setWidth(S_node.width());
     S_Rect.setHeight(S_node.height());
     S_Rect.moveTo(node_x,node_y);
     prev=NULL;
     next=NULL;
     break;
    case 3:
     S_node.load(BODY_LEVEL_PATH);
     S_Rect.setWidth(S_node.width());
     S_Rect.setHeight(S_node.height());
     S_Rect.moveTo(node_x,node_y);
     prev=NULL;
     next=NULL;
     break;
    }

}
void node::updatenode(){            //更新节点状态
    if(prev==NULL) return;
    switch(direc){
     case 0:
        node_y-=speed;
        if(node_y<=(prev->node_y)){ //如果在运动方向坐标上追上了前一个节点的坐标，意味着前一个节点发生了转向，此时调整节点运动方向，同时改变图片
            direc=prev->direc;      //调整运动方向
            node_y=prev->node_y;    //重新对齐节点
            if(prev->direc==left){
                node_x=prev->node_x+(S_node.width()+prev->S_node.width())/2;       //运动方向的对齐只在一个方向上弄，不然容易出问题
            }
            if(prev->direc==right){
                node_x=prev->node_x-(S_node.width()+prev->S_node.width())/2;
            }
            S_node.load(BODY_LEVEL_PATH); //换图片
        }
        S_Rect.moveTo(node_x,node_y);
        break;
     case 1:
        node_y+=speed;
        if(node_y>=(prev->node_y)){
            direc=prev->direc;
            node_y=prev->node_y;
            if(prev->direc==left){
                node_x=prev->node_x+(S_node.width()+prev->S_node.width())/2;
            }
            if(prev->direc==right){
                node_x=prev->node_x-(S_node.width()+prev->S_node.width())/2;
            }
            S_node.load(BODY_LEVEL_PATH);
        }
        S_Rect.moveTo(node_x,node_y);
        break;
    case 2:
       node_x-=speed;
       if(node_x<=(prev->node_x)){
           direc=prev->direc;
           node_x=prev->node_x;
//           if(prev->direc==up){
//               node_y=prev->node_y+(S_node.height()+prev->S_node.height())/2;
//           }
//           if(prev->direc=down){
//               node_y=prev->node_y-(S_node.height()+prev->S_node.height())/2;
//           }
           S_node.load(BODY_UP_PATH);
       }
       S_Rect.moveTo(node_x,node_y);
       break;
    case 3:
       node_x+=speed;
       if(node_x>=(prev->node_x)){
           direc=prev->direc;
           node_x=prev->node_x;
//           if(prev->direc==up){
//               node_y=prev->node_y+(S_node.height()+prev->S_node.height())/2;
//           }
//           if(prev->direc=down){
//               node_y=prev->node_y-(S_node.height()+prev->S_node.height())/2;
//           }
           S_node.load(BODY_UP_PATH);
       }
       S_Rect.moveTo(node_x,node_y);
       break;
    }
}

void Snake::add_life()
{
    life++;
}

bool Snake::decrease_life()
{    life--;
     if(life==0)  return true;
     else return false;
}

void Snake::addnode(){
//    node *p=NULL;
    tail=new node(tail);
//    if(p==NULL) {
//        int i=0;
//    }
//    tail=p;
//    tail->next=NULL;
//    switch(tail->prev->direc){
//     case 0:
//     tail->node_x=tail->prev->node_x;
//     tail->node_y=tail->prev->node_y+(tail->S_Rect.height()+tail->prev->S_Rect.height())/2;
//     case 1:
//        tail->node_x=tail->prev->node_x;
//        tail->node_y=tail->prev->node_y-(tail->S_Rect.height()+tail->prev->S_Rect.height())/2;
//     case 2:
//        tail->node_y=tail->prev->node_y;
//        tail->node_x=tail->prev->node_x+(tail->S_Rect.width()+tail->prev->S_Rect.width())/2;
//     case 3:
//        tail->node_y=tail->prev->node_y;
//        tail->node_x=tail->prev->node_x-(tail->S_Rect.width()+tail->prev->S_Rect.width())/2;
//    }

    //numofnode++;
}

Snake::Snake(int mode){
    //QPixmapCache::setCacheLimit(1);
    life=ORIGIN_LIFE;
    //numofnode=0;
    head=new node(mode);
    tail=head;
    for(int i=0;i<INITIAL_NODE_NUM;i++){
        addnode();
    }
}

Snake::Snake(int Life, int Point, int Speed, int x, int y, direction dir)
{
    life=Life;
    point=Point;
    head=new node(Speed,x,y,dir);
    tail=head;
    switch(dir){
    case 0:
        head->S_node.load(HEAD_UP_PATH);
        break;
    case 1:
        head->S_node.load(HEAD_DOWN_PATH);
        break;
    case 2:
        head->S_node.load(HEAD_LEFT_PATH);
        break;
    case 3:
        head->S_node.load(HEAD_RIGHT_PATH);
        break;
    }
}

void Snake::shift_to_up()
{   if(head->direc==0||head->direc==1){                 //如果原来蛇头就是上下走的，不对蛇头做处理
     return;
    }
    head->direc=up;
    head->S_node.load(HEAD_UP_PATH);
}

void Snake::shift_to_down()
{
    if(head->direc==0||head->direc==1){
        return;
    }
    head->direc=down;
    head->S_node.load(HEAD_DOWN_PATH);
}

void Snake::shift_to_left()
{
    if(head->direc==2||head->direc==3)  return;     //如果蛇头原来左右走，不做处理
    head->direc=left;
    head->S_node.load(HEAD_LEFT_PATH);
}

void Snake::shift_to_right()
{
    if(head->direc==2||head->direc==3) return;
    head->direc=right;
    head->S_node.load(HEAD_RIGHT_PATH);
}
void Snake::add_speed(int num)
{    if(head->speed>=MAX_SPEED) return;
     head->speed+=num;
     node *p=head->next;
     while(p!=NULL){
        p->speed+=num;
        p=p->next;
     }
}

void Snake::decrease_speed(int num)
{    if(head->speed<=MIN_SPEED) return;
     head->speed-=num;
     node *p=head->next;
     while(p!=NULL){
        p->speed-=num;
        p=p->next;
     }
}

void Snake::delete_last()
{
    node *p=tail;
    tail=tail->prev;
    delete p;
    tail->next=NULL;
}

Snake::Snake(const Snake &snake)
{
    life=snake.getlife();
    point=snake.getpoint();
    flag=false;
    node *q=snake.head;
    head=new node(q->speed,q->node_x,q->node_y,q->direc);         //不需要特别针对蛇头加载图片，这个复制的蛇并不绘制
    tail=head;
    node* r=head;
    q=q->next;
    while(q!=NULL){
        node *p=new node(q->speed,q->node_x,q->node_y,q->direc);
        r->next=p;
        p->prev=r;
        tail=p;
        r=r->next;
        q=q->next;
    }

}



Snake::~Snake()
{ node* p=head->next;
   node *q=p;
   while(q!=NULL){
       q=p->next;
       delete p;
       p=q;
   }
   delete head;

}
void Snake::eatfood(food *fd)
{  if(head->S_Rect.intersects(fd->f_Rect)){
        switch(fd->type){
        case 0:
            addnode();
            point++;
            break;
        case 1:
            add_life();
            break;
        case 2:
            decrease_speed(ICE_VALUE);
            break;
        case 3:
            add_speed(ENERGY_VALUE);
            break;
        case 4:
            delete_last();
            break;
        }
     fd->f_free=false;
     fd->food_x=-100;    //把食物移到窗口外，相当于消失不见
     fd->food_y=-100;
     fd->f_Rect.moveTo(fd->food_x,fd->food_y);
    }

}

void Snake::crash(Wallgroup W_group)     //失去一条命但是没GG的话，解决方案是除了tail指向的节点，其他所有节点位置退到后一节点的位置，之后删除tail指向的节点
{

    if(flag) return;
//     if(head->node_x<=0||head->node_x>=(GAME_WIDTH)||head->node_y<=0||head->node_y>=(GAME_HEIGHT-head->S_Rect.height())){
//         life--;
//         flag=true;
//     }
    static QRect l_line(-1,0,1,GAME_HEIGHT);
    static QRect r_line(GAME_WIDTH,0,1,GAME_HEIGHT);
    static QRect up_line(0,-1,GAME_WIDTH,1);
    static QRect down_line(0,GAME_HEIGHT,GAME_WIDTH,1);
    if((head->S_Rect.intersects(l_line))||(head->S_Rect.intersects(r_line))||(head->S_Rect.intersects(up_line))||(head->S_Rect.intersects(down_line))){
        life--;
        flag=true;
    }
     for(int i=0;i<WALL_NUM;i++){
         if(head->S_Rect.intersects(W_group.wall_group[i].W_rect)) {
             life--;
             flag=true;
             break;
         }
     }
     node *p=head->next->next;     //从蛇头的后后节点开始进行碰撞检测，避免出问题
      while(p!=NULL&&p->next!=NULL){
          if(head->S_Rect.intersects(p->S_Rect)){
             life--;
             flag=true;
             break;
          }
       p=p->next;
      }
     if(flag&&life>0){             //如果发生碰撞并且蛇还活着，则进行下面的操作
         node *p=head;
                  while(p->next!=NULL){
//                      if(p==tail) break;
                      p->node_x=p->next->node_x;
                      p->node_y=p->next->node_y;
                      p->direc=p->next->direc;
                      p->S_Rect.moveTo(p->node_x,p->node_y);
                      p=p->next;
                  }
//                  tail->node_x=-400;
//                  tail->node_y=-400;
//                  tail->S_Rect.moveTo(tail->node_x,tail->node_y);
//                  tail=tail->prev;
                  while(this->head->speed>1){      //减速，防止来不及操作
                      this->decrease_speed(1);
                  }
                  tail=p->prev;
                  tail->next=NULL;
                  delete p;
         flag=false;
     }
}


void Snake::update_snake(){
    switch(head->direc){
     case 0:
        head->node_y-=head->speed;
        break;
     case 1:
       head->node_y+=head->speed;
       break;
     case 2:
       head->node_x-=head->speed;
       break;
     case 3:
       head->node_x+=head->speed;
       break;
    }
    head->S_Rect.moveTo(head->node_x,head->node_y);
    node *p=head->next;
    while(p!=NULL){
        p->updatenode();
        if(p==tail) break;
        p=p->next;

    }
}

































