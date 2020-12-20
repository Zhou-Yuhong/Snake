#include "food.h"

food::food()
{   //QPixmapCache::setCacheLimit(1);
    //srand(time(NULL));
    int seed=rand()%100;                     //随机生成种类
    if(seed<75) type=apple;
    else if(seed<78) type=heart;
    else if(seed<85) type=ice;
    else if(seed<95) type=energy;
    else type=mushroom;
    switch(type){
      case 0:m_food.load(FOOD_APPLE_PATH);break;
      case 1:m_food.load(FOOD_HEART_PATH);break;
      case 2:m_food.load(FOOD_ICE_PATH);break;
      case 3:m_food.load(FOOD_ENERGY_PATH);break;
      case 4:m_food.load(FOOD_MUSHROOM_PATH);break;
    }
    food_x=rand()%(GAME_WIDTH-m_food.width());
    food_y=rand()%(GAME_HEIGHT-m_food.height());
    f_Rect.setWidth(m_food.width());
    f_Rect.setHeight(m_food.height());
    f_Rect.moveTo(food_x,food_y);

}

void food::update_food()
{   if(f_free) return;
    int seed=rand()%100;                     //随机生成种类
    if(seed<75) type=apple;
        else if(seed<78) type=heart;
        else if(seed<85) type=ice;
        else if(seed<95) type=energy;
        else type=mushroom;
    switch(type){
      case 0:m_food.load(FOOD_APPLE_PATH);break;
      case 1:m_food.load(FOOD_HEART_PATH);break;
      case 2:m_food.load(FOOD_ICE_PATH);break;
      case 3:m_food.load(FOOD_ENERGY_PATH);break;
      case 4:m_food.load(FOOD_MUSHROOM_PATH);break;
    }
    food_x=rand()%(GAME_WIDTH-m_food.width());
    food_y=rand()%(GAME_HEIGHT-m_food.height());
    f_Rect.moveTo(food_x,food_y);
    f_free=true;
}












