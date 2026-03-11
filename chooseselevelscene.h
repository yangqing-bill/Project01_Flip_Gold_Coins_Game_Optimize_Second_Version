#ifndef CHOOSESELEVELSCENE_H
#define CHOOSESELEVELSCENE_H

#include <QMainWindow>
#include "mypushbutton.h"
#include "playscene.h"

class ChooseSelevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseSelevelScene(QWidget *parent = nullptr);
    ~ChooseSelevelScene();

    void initUI();              //界面初始化
    void initCloseBtn();               //back按钮初始化
    void initLevelButtons();                  //关卡标签初始化

private:
    PlayScene *m_play = NULL;
    MyPushButton *m_closeBtn;             //返回按钮
    QLabel *m_label;

protected:
    void paintEvent(QPaintEvent *e);

signals:
    void chooseSceneBack(); //返回信号
};

#endif // CHOOSESELEVELSCENE_H
