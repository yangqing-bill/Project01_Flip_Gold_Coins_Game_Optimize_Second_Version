#include "playscene.h"
#include"dataconfig.h"
#include"soundmanager.h"
#include "Config.h"
using namespace GameConfig;

#include <QMenuBar>
#include<QAction>
#include<QTimer>
#include<QLabel>
#include<QPainter>
#include<QDebug>
#include<QPropertyAnimation>

PlayScene::PlayScene(QWidget *parent)
    : QMainWindow{parent}
{}

PlayScene::PlayScene(int levelNum)
{
    QString str = QString("您选择的是第%1关").arg(levelNum);
    m_levelIndex = levelNum;

    initUI();               //界面初始化
    initCloseBtn();                //back按钮初始化
    initLevelLabel();              //关卡标签初始化
    loadLevelData();                //关卡信息
    createGameBoard();              //金币翻转

    connect(m_closeBtn,&MyPushButton::clicked,this,&PlayScene::cleanupWinLabel);
}

void PlayScene::initUI()
{
    this->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);        //设置主窗口固定大小
    this->setWindowTitle("翻金币");      //设置窗口标题
    this->setWindowIcon(QPixmap(":/picture/Coin0001.png")); //设置主窗口图标

    QMenuBar *bar = new QMenuBar(this);     //创建菜单栏
    this->setMenuBar(bar);                  //放入窗口

    QMenu *FileMenu = bar->addMenu("开始");   //创建菜单
    QAction *ActionQuit = new QAction("退出",this);   //创建菜单项
    FileMenu->addAction(ActionQuit);              //添加菜单项

    connect(ActionQuit,&QAction::triggered,[=]()    //动作触发，窗口关闭
            {
                this->close();
            });
}

void PlayScene::initCloseBtn()
{
    m_closeBtn = new MyPushButton(":/picture/BackButton.png",":/picture/BackButtonSelected.png");
    m_closeBtn->setParent(this);
    m_closeBtn->move(this->width()-m_closeBtn->width(),this->height()-m_closeBtn->height());
    m_closeBtn->show();
    connect(m_closeBtn,&MyPushButton::clicked,[=]()
            {
                SoundManager::instance()->playBackSound();
                QTimer::singleShot(BACK_BUTTON_DELAY,this,[=]()         //单次定时，5ms执行槽函数
                                   {
                                       this->hide();
                                       emit chooseSceneBack();
                                   });
            });

}

void PlayScene::initLevelLabel()
{
    m_levelLabel = new QLabel(this);
    QFont font;
    font.setFamily(FONT_FAMILY);
    font.setBold(true);
    font.setPointSize(FONT_SIZE02);
    m_levelLabel->setFont(font);

    QString str1 = QString("Leavel：%1").arg(m_levelIndex);
    m_levelLabel->setText(str1);
    m_levelLabel->setGeometry(QRect(30,this->height()-50,120,50));     //设置位置、大小
    m_levelLabel->show();
}

void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/picture/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/picture/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(TITLE_X,TITLE_Y,pix.width(),pix.height(),pix);
}

void PlayScene::flipAdjacentCoin(int x,int y)
{
    if(x < 0 || x >= 4 || y < 0 || y >= 4)
    {
        return;
    }
    m_coinButtons[x][y]->changeFlag();        //金币翻转
    m_animatingCount++;
    m_gameBoard[x][y] = m_gameBoard[x][y] == 0 ? 1 : 0;
}

bool PlayScene::checkWin()
{
    for(int i = 0 ; i < 4; i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            if( m_coinButtons[i][j]->m_isFront == false)
            {
                return false;
            }
        }
    }
    return true;
}

void PlayScene::showVictoryAnimation()
{
    if (m_winLabel)
    {
        m_winLabel->deleteLater();
        m_winLabel = nullptr;
    }

    m_winLabel = new QLabel(this);
    QPixmap pix;
    pix.load(":/picture/LevelCompletedDialogBg.png");
    m_winLabel->setGeometry(0,0,pix.width(),pix.height());
    m_winLabel->setPixmap(pix);
    m_winLabel->move((this->width()-pix.width())*0.5,-pix.height());
    m_winLabel->show();

    SoundManager::instance()->playWinSound();
    QPropertyAnimation * animation1 =  new QPropertyAnimation(m_winLabel,"geometry",this);
    animation1->setDuration(ANIMATION_WIN);
    animation1->setStartValue(QRect(m_winLabel->x(),m_winLabel->y(),m_winLabel->width(),m_winLabel->height()));
    animation1->setEndValue(QRect(m_winLabel->x(),m_winLabel->y()+180,m_winLabel->width(),m_winLabel->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}

void PlayScene::cleanupWinLabel()
{
    if(m_winLabel){
        m_winLabel->deleteLater();
        m_winLabel = nullptr;
    }
}

void PlayScene::handleVictory()
{
    for(int i = 0 ; i < 4;i++)
        for(int j = 0 ; j < 4; j++)
            m_coinButtons[i][j]->m_isWin = true;
    showVictoryAnimation();
}

void PlayScene::loadLevelData()
{
    DataConfig config;                  //关卡信息
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(m_levelIndex < 1 || m_levelIndex > 20)return;
            m_gameBoard[i][j] =config.m_dataMap[m_levelIndex][i][j];
        }
    }
}

void PlayScene::createGameBoard()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            QLabel *m_label1 = new QLabel(this);
            m_label1->setGeometry(0,0,GRID_CELL_SIZE,GRID_CELL_SIZE);
            m_label1->setPixmap(QPixmap(":/picture/BoardNode.png"));
            m_label1->move(GRID_OFFSET_X+i*GRID_CELL_SIZE,GRID_OFFSET_Y+j*GRID_CELL_SIZE);

            QString coinImg ;
            if(m_gameBoard[i][j] == 1)
            {
                coinImg  = ":/picture/Coin0001.png";
            }
            else
            {
                coinImg  = ":/picture/Coin0008.png";
            }

            MyCoin *coin = new MyCoin(coinImg);
            coin->setParent(this);
            coin->move(COIN_OFFSET_X+i*GRID_CELL_SIZE,COIN_OFFSET_Y+j*GRID_CELL_SIZE);

            coin->m_posX = i; //记录x坐标
            coin->m_posY = j; //记录y坐标
            coin->m_isFront =m_gameBoard[i][j]; //记录正反标志
            m_coinButtons[i][j] = coin;       // 将指针存入数组

            connect(coin,&MyCoin::animationFinished,[=]()
                    {
                        m_animatingCount--;
                        if(m_animatingCount == 0)
                        {
                            if(checkWin())
                            {
                                qDebug() << "Victory animation triggered!";
                                handleVictory();
                            }
                        }
                    });

            connect(coin,&MyCoin::clicked,[=]()
                    {
                        SoundManager::instance()->playFlipSound();
                        coin->changeFlag();
                        m_animatingCount++;
                        this->m_gameBoard[i][j] = m_gameBoard[i][j] == 0 ? 1 : 0; //数组内部记录的标志同步修改

                        QTimer::singleShot(ADJACENT_FLIP_DELAY, this,[=](){
                            if(coin->m_posX+1 <= 3)        flipAdjacentCoin(coin->m_posX+1,coin->m_posY);   //右侧金币翻转条件
                            if(coin->m_posX-1 >= 0)        flipAdjacentCoin(coin->m_posX-1,coin->m_posY);   //左侧金币翻转条件
                            if(coin->m_posY+1 <= 3)        flipAdjacentCoin(coin->m_posX,coin->m_posY+1);   //上侧金币翻转条件
                            if(coin->m_posY-1 >= 0)        flipAdjacentCoin(coin->m_posX,coin->m_posY-1);   //下侧金币翻转条件

                            m_isWin = checkWin();
                        });
                    });
        }
    }
}

PlayScene::~PlayScene()
{
    qDebug() << "PlayScene destroyed";
}
