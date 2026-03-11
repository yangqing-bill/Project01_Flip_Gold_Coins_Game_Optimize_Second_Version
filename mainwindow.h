#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mypushbutton.h"
#include"chooseselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUI();              //界面初始化
    void initStartBtn();               //开始按钮初始化
    void initChooseScene();            //选择界面初始化

protected:void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    MyPushButton *m_startBtn;             //开始按钮
    ChooseSelevelScene *m_chooseScene;    //选择界面

};
#endif // MAINWINDOW_H
