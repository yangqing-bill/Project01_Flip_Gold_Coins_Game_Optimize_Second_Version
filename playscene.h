#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"mypushbutton.h"
#include"mycoin.h"

#include<QLabel>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    ~PlayScene() ;

    PlayScene(int levelNum);

    MyCoin * m_coinButtons[4][4];             //金币数组类

    void initUI();              //界面初始化
    void initCloseBtn();               //back按钮初始化
    void initLevelLabel();             //关卡标签初始化

    void flipAdjacentCoin(int,int);     //翻转逻辑

    bool checkWin();                    //判断胜负
    void showVictoryAnimation();        //播放胜利动画
    void handleVictory();               //胜利结算
    void loadLevelData();               //关卡信息
    void createGameBoard();             //金币翻转操作
    void cleanupWinLabel();             //清除胜利时动画标签

private:
    int m_levelIndex;                     //关卡信息
    int m_gameBoard[4][4];                //四维数组

    bool m_isWin = false;               //判断胜利
    int m_animatingCount = 0;           //动画播放的金币数量

    MyPushButton *m_closeBtn;             //返回按钮
    QLabel *m_winLabel = nullptr;         //胜利时动画标签
    QLabel *m_levelLabel;                 //关卡标签

protected:
    void paintEvent(QPaintEvent *);

signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
