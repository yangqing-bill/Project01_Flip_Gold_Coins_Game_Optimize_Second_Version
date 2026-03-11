#include "chooseselevelscene.h"
#include "soundmanager.h"
#include "Config.h"
using namespace GameConfig;

#include<QMenuBar>
#include<QAction>
#include<QTimer>
#include<QPainter>
#include<QLabel>

ChooseSelevelScene::ChooseSelevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    initUI();
    initCloseBtn();
    initLevelButtons();
}

void ChooseSelevelScene::initUI()
{
    this->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    this->setWindowIcon(QPixmap(":/picture/Coin0001.png")); //设置主窗口图标
    this->setWindowTitle("选择关卡");      //设置窗口标题

    QMenuBar *bar = this->menuBar();     //创建菜单栏
    this->setMenuBar(bar);                  //放入窗口

    QMenu *FileMenu = bar->addMenu("开始");   //创建菜单
    QAction *ActionQuit = FileMenu->addAction("退出");
    connect(ActionQuit,&QAction::triggered,[=]()    //动作触发，窗口关闭
            {
                this->close();
            });
}

void ChooseSelevelScene::initCloseBtn()
{
    m_closeBtn = new MyPushButton(":/picture/BackButton.png");
    m_closeBtn->setParent(this);
    m_closeBtn->move(this->width()-m_closeBtn->width(),this->height()-m_closeBtn->height());

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

void ChooseSelevelScene::initLevelButtons()
{
    for(int i = 0 ; i < TOTAL_LEVELS ; i++)
    {
        MyPushButton *menuBtn = new MyPushButton(":/picture/LevelIcon.png");
        menuBtn->setParent(this);

        menuBtn->move(LEVEL_BUTTON_START_X+(i%GRID_SIZE)*LEVEL_BUTTON_HORIZONTAL_GAPP,LEVEL_BUTTON_START_Y+(i/GRID_SIZE)*LEVEL_BUTTON_VERRTICAL_GAP);    //关卡按钮位置
        connect(menuBtn,&MyPushButton::clicked,[=]()
                {
            SoundManager::instance()->playLevelSound();
                    this->hide();

                    if (m_play) {
                        m_play->deleteLater();
                        m_play = nullptr;
                    }

                    m_play = new PlayScene(i+1);
                    m_play->setGeometry(this->geometry());
                    m_play->show();
                    connect(m_play,&PlayScene::chooseSceneBack,[=]()
                            {
                                this->setGeometry(m_play->geometry());
                                this->show();
                                m_play->hide();
                                m_play->deleteLater();        // 安全延迟销毁
                                m_play = nullptr;
                            });
                });

        m_label = new QLabel(this);
        QFont font;
        font.setFamily(FONT_FAMILY);
        font.setBold(true);
        font.setPointSize(FONT_SIZE01);
        m_label->setFont(font);

        m_label->setFixedSize(menuBtn->width(),menuBtn->height());
        m_label->setText(QString::number(i+1));

        m_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);   //设置居中
        m_label->move(LEVEL_BUTTON_START_X+(i%GRID_SIZE)*LEVEL_BUTTON_HORIZONTAL_GAPP,LEVEL_BUTTON_START_Y+(i/GRID_SIZE)*LEVEL_BUTTON_VERRTICAL_GAP);
        m_label->setAttribute(Qt::WA_TransparentForMouseEvents,true);    //鼠标事件穿透,51号属性
    }
}

void ChooseSelevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this); //创建画家，指定绘图设备
    QPixmap pix;            //创建画家工具
    pix.load(":/picture/OtherSceneBg.png");     //加载背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);   //画家作画

    pix.load(":/picture/Title.png");                //加载第二幅图
    painter.drawPixmap((this->width()-pix.width())*0.5,TITLE_Y,pix.width(),pix.height(),pix);
}

ChooseSelevelScene::~ChooseSelevelScene()
{

}
