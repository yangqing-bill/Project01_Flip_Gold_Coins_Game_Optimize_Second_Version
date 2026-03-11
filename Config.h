#ifndef CONFIG_H
#define CONFIG_H
#include<QString>

namespace GameConfig
{
constexpr int WINDOW_WIDTH = 320;           //窗口尺寸-长
constexpr int WINDOW_HEIGHT = 588;          //窗口尺寸-宽

constexpr int GRID_SIZE = 4;                //网络行列数
constexpr int GRID_CELL_SIZE = 50;          //网络单元格大小
constexpr int GRID_OFFSET_X = 57;           //网格背景-X偏移
constexpr int GRID_OFFSET_Y = 200;          //网格背景-Y偏移
constexpr int COIN_OFFSET_X = 59;           //金币背景-X偏移
constexpr int COIN_OFFSET_Y = 204;          //金币背景-Y偏移

constexpr int LEVEL_BUTTON_START_X = 25;            //关卡按钮-X坐标
constexpr int LEVEL_BUTTON_START_Y = 130;           //关卡按钮-Y坐标
constexpr int LEVEL_BUTTON_HORIZONTAL_GAPP = 70;    //按钮水平间距
constexpr int LEVEL_BUTTON_VERRTICAL_GAP = 70;      //按钮垂直间距

constexpr int TITLE_X = 10;     //标签图片位置
constexpr int TITLE_Y = 30;

constexpr int COIN_FLIP_INTERVAL = 50;  //金币翻转每帧间隔
constexpr int BUTTON_ZOOM_DURATION = 100;   //按钮弹跳动画时长
constexpr int ADJACENT_FLIP_DELAY = 100;    //点击后延时翻转相邻金币
constexpr int START_BUTTON_DELAY = 500;     //开启按钮后延时进入选择界面
constexpr int BACK_BUTTON_DELAY = 5;        //返回按钮延迟
constexpr int ANIMATION_WIN = 1000;         //胜利动画

constexpr int COIN_FRAME_MIN = 1;           //金币图片帧范围
constexpr int COIN_FRAME_MAX = 8;

constexpr float SOUND_VOLUME = 0.8f;        //音效音量

constexpr int TOTAL_LEVELS = 20;            //关卡总数

const QString FONT_FAMILY = QStringLiteral("微软雅黑");     //关卡字体
constexpr int FONT_SIZE01 = 10;
constexpr int FONT_SIZE02 = 15;

}
#endif // CONFIG_H
