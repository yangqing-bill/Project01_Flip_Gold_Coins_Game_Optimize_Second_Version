#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

    MyPushButton(QString normalImg,QString pressImg = "");  //带参数构造
    void animatePressDown();               //向下跳动画
    void animatePressUp();               //向上跳动画
    void initUI();      //界面初始化


private:
    QString m_normalImgPath;      //正常图片
    QString m_pressImgPath;       //按下后图片

protected:
    void mousePressEvent(QMouseEvent *e);        //鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *e);      //鼠标松开事件

signals:
};

#endif // MYPUSHBUTTON_H
