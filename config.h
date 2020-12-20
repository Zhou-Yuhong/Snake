#ifndef CONFIG_H
#define CONFIG_H
#define GAME_WIDTH 960      //页面宽度
#define GAME_HEIGHT 640     //页面高度
#define GAME_RATE 10        //屏幕刷新间隔
#define SNAKE_SPEED 2       //蛇初始移动的速度
#define MAX_SPEED 10        //蛇的最大速度
#define MIN_SPEED 1         //蛇的最小速度
#define ENERGY_VALUE 1      //电池加速值
#define ICE_VALUE   1       //冰块减速值
#define INITIAL_NODE_NUM 3  //初始蛇身数量
#define ORIGIN_LIFE 1       //初始生命数
#define AI_RATE   4          //AI蛇的敏感度
#define GAME_TITLE "贪吃蛇 v1.0"  //游戏标题
#define BEGIN_MAP_PATH ":/res/begin_background.png" //开始时的背景
#define MAP_PATH ":/res/backguound.png"    //游戏背景
#define BODY_UP_PATH ":/res/body_up.png"    //上下方向一节蛇图片的路径
#define BODY_LEVEL_PATH ":/res/body_level.png"   //水平方向一节蛇图片的路径
#define HEAD_UP_PATH ":/res/head_up.png"    //向上的蛇头图片的路径
#define HEAD_DOWN_PATH ":/res/head_down.png"    //向下的蛇头图片的路径
#define HEAD_LEFT_PATH ":/res/head_left.png"    //向左的蛇头图片的路径
#define HEAD_RIGHT_PATH ":/res/head_right.png"    //向右的蛇头图片的路径
#define FOOD_HEART_PATH ":/res/heart.png"          //红心图片的路径
#define FOOD_ICE_PATH ":/res/ice.png"             //冰棍图片的路径
#define FOOD_ENERGY_PATH ":/res/energy.png"       //电池图片的路径
#define FOOD_APPLE_PATH ":/res/apple.png"         //苹果图片的路径
#define WALL_PATH ":/res/wall.png"                //墙图片的路径
#define FOOD_MUSHROOM_PATH ":/res/mushroom.png"        //蘑菇图片的路径
#define WALL_NUM 10                                //墙块的数目
#define KEYBOARD_UP 16777235                     //键盘需要用到的键的key值
#define KEYBOARD_DOWN 16777237
#define KEYBOARD_LEFT 16777234
#define KEYBOARD_RIGHT 16777236
#define KEYBOARD_A 65
#define KEYBOARD_S 83
#define KEYBOARD_D 68
#define KEYBOARD_W 87
#define KEYBOARD_SPACE 0x20                       //暂停的键值
#define KEYBOARD_ENTER 0x0D                       //ai蛇的键值
#endif // CONFIG_H
