#include "mypushbutton.h"
#include "Config.h"
using namespace GameConfig;

#include<QDebug>
#include<QPropertyAnimation>    //动画处理


MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton{parent}
{}

MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    m_normalImgPath = normalImg;      //成员初始化
    m_pressImgPath = pressImg;

    initUI();
}

void MyPushButton::initUI()
{
    QPixmap pix;
    bool ret = pix.load(m_normalImgPath);     //验证图片加载情况
    if(!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }

    this->setFixedSize(pix.width(),pix.height());   //图片尺寸
    this->setStyleSheet("QPushButton{border:0px;}"); //设置样式表，移除边框
    this->setIcon(pix);                             //图片转为图标
    this->setIconSize(QSize(pix.width(),pix.height())); //图标尺寸
}

void MyPushButton::animatePressDown()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");    //位置-大小做平滑变化
    animation->setDuration(BUTTON_ZOOM_DURATION);        //持续100ms
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));  //开始位置+大小
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height())); //结束位置+大小
    animation->setEasingCurve(QEasingCurve::OutBounce);     //设置弹跳曲线
    animation->start();     //启动
}

void MyPushButton::animatePressUp()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(BUTTON_ZOOM_DURATION);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(m_pressImgPath !="")
    {
        QPixmap pix;
        bool ret = pix.load(m_pressImgPath);
        if(!ret)
        {
            qDebug()<<"加载图片失败";
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(m_pressImgPath !="")
    {
        QPixmap pix;
        bool ret = pix.load(m_normalImgPath);
        if(!ret)
        {
            qDebug()<<"加载图片失败";
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}
