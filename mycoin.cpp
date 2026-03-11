#include "mycoin.h"
#include "Config.h"
using namespace GameConfig;

#include<QPixmap>

MyCoin::MyCoin(QWidget *parent)
    : QPushButton{parent}
{}

MyCoin::MyCoin(QString imagePath)
{
    m_normalImgPath = imagePath;
    initUI();
    initTimers();

}

void MyCoin::initUI()
{
    QPixmap pix;
    bool ret = pix.load(m_normalImgPath);
    if(!ret)
    {
        QString str = QString("图片 %1 加载失败").arg(m_normalImgPath);
        qDebug() << str;
        return;
    }

    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void MyCoin::initTimers()
{
    m_flipTimer1 = new QTimer(this);
    m_flipTimer2 = new QTimer(this);

    connect(m_flipTimer1,&QTimer::timeout,[=]()
            {
                QPixmap pix;
                QString str = QString(":/picture/Coin000%1.png").arg(m_minFrame++);
                pix.load(str);
                this->setFixedSize(pix.width(),pix.height());
                this->setStyleSheet("QPushButton{border:0px;}");
                this->setIcon(pix);
                this->setIconSize(QSize(pix.width(),pix.height()));

                if(m_minFrame > m_maxFrame)
                {
                    m_minFrame = COIN_FRAME_MIN;
                    m_isAnimating = false;
                    m_flipTimer1->stop();
                    emit animationFinished();
                }
            });

    connect(m_flipTimer2,&QTimer::timeout,[=]()
            {
                QPixmap pix;
                QString str = QString(":/picture/Coin000%1.png").arg(m_maxFrame--);
                pix.load(str);
                this->setFixedSize(pix.width(),pix.height());
                this->setStyleSheet("QPushButton{border:0px;}");
                this->setIcon(pix);
                this->setIconSize(QSize(pix.width(),pix.height()));

                if(m_maxFrame < m_minFrame)
                {
                    m_maxFrame = COIN_FRAME_MAX;
                    m_isAnimating = false;
                    m_flipTimer2->stop();
                    emit animationFinished();
                }
            });
}

void MyCoin::mousePressEvent(QMouseEvent *e )   //避免重复点击
{
    if(m_isAnimating || m_isWin)
    {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}

void MyCoin::changeFlag()   //启动标志
{
    if(this->m_isFront)
    {
        m_flipTimer1->start(COIN_FLIP_INTERVAL);
        m_isAnimating = true;
        m_isFront = false;
    }
    else
    {
        m_flipTimer2->start(COIN_FLIP_INTERVAL);
        m_isAnimating = true;
        m_isFront = true;
    }
}

MyCoin::~MyCoin()
{
    if (m_flipTimer1) {
        m_flipTimer1->stop();
        delete m_flipTimer1;

    }
    if (m_flipTimer2) {
        m_flipTimer2->stop();
        delete m_flipTimer2;

    }
}
