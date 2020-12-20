#ifndef FOOD_H
#define FOOD_H
#include "config.h"
#include <QPixmap>
#include <time.h>
#include <stdlib.h>
//#include <QPixmapCache>
#include <QImage>
enum typeoffood{apple,heart,ice,energy,mushroom};
class food{
 public:
      typeoffood type;
      food();
      QImage m_food;
      int food_x;
      int food_y;
      QRect f_Rect;
      bool f_free=true;    //判断是否出现在场上,为true时表示在场上
      void update_food();
};

#endif // FOOD_H
