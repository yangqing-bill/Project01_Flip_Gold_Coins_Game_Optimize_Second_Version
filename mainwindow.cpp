#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"soundmanager.h"
#include "Config.h"
using namespace GameConfig;

#include<QPixmap>
#include<QMenuBar>
#include<QPaintEvent>
#include<QPainter>
#include<QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();
    initStartBtn();
    initChooseScene();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this); //创建画家，指定绘图设备
    QPixmap pix;            //创建画家工具
    pix.load(":/picture/PlayLevelSceneBg.png");     //加载背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);   //画家作画

    pix.load(":/picture/Title.png");                //加载第二幅图
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5,Qt::KeepAspectRatio,Qt::SmoothTransformation);    //平滑缩放
    painter.drawPixmap(TITLE_X,TITLE_Y,pix);
}

void MainWindow::initUI()
{
    this->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);        //设置主窗口固定大小
    this->setWindowIcon(QPixmap(":/picture/Coin0001.png")); //设置主窗口图标
    this->setWindowTitle("翻金币");      //设置窗口标题


    QMenuBar *bar = new QMenuBar(this);     //创建菜单栏
    this->setMenuBar(bar);                  //放入窗口

    QMenu *FileMenu = bar->addMenu("开始");   //创建菜单
    QAction *quitAction = new QAction("退出",this);   //创建菜单项
    FileMenu->addAction(quitAction);              //添加菜单项

    connect(quitAction,&QAction::triggered,[=]()    //动作触发，窗口关闭
            {
                this->close();
            });
}

void MainWindow::initStartBtn()
{
    m_startBtn = new MyPushButton(":/picture/MenuSceneStartButton.png");    //设置开始按钮
    m_startBtn->setParent(this);
    m_startBtn->move(this->width()*0.5-m_startBtn->width()*0.5,this->height()*0.7);     //按钮位置

    connect(m_startBtn,&MyPushButton::clicked,[=]()
            {
                SoundManager::instance()->playStartSound();
                m_startBtn->animatePressDown();
                m_startBtn->animatePressUp();

                QTimer::singleShot(START_BUTTON_DELAY,this,[=]()
                                   {
                                       this->hide();
                                       m_chooseScene->setGeometry(this->geometry());
                                       m_chooseScene->show();
                                   });
            });
}

void MainWindow::initChooseScene()
{
    m_chooseScene = new ChooseSelevelScene;

    connect(m_chooseScene,&ChooseSelevelScene::chooseSceneBack,[=]()  //back按钮点击后主界面显示
            {
                this->setGeometry(m_chooseScene->geometry());
                m_chooseScene->hide();
                this->show();
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}
