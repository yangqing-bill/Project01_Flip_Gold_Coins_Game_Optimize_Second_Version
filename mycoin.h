#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include<QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = nullptr);
    ~MyCoin()override;

    MyCoin(QString butImg);

    void changeFlag();      //改变标志，执行翻转效果
    void mousePressEvent(QMouseEvent *e);

    void initUI();              //界面初始化
    void initTimers();

    bool m_isFront = false;
    int m_posX;   //X坐标
    int m_posY;   //y坐标
    bool m_isWin = false;     //是否胜利

private:
    QTimer *m_flipTimer1;         //正面翻反面，定时器
    QTimer *m_flipTimer2;         //反面翻正面 定时器
    int m_minFrame = 1;            //最小图片
    int m_maxFrame = 8;            //最大图片
    bool m_isAnimating = false;   //做翻转动画的标志
    QString m_normalImgPath;      //正常图片

signals:
    void animationFinished();   //动画完成播放
};

#endif // MYCOIN_H
