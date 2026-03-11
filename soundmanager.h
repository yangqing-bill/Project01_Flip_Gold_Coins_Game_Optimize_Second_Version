#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QObject>
#include<QSoundEffect>

class SoundManager : public QObject
{
    Q_OBJECT
public:
    static SoundManager* instance();    //全局访问函数
    void playFlipSound();
    void playWinSound();
    void playBackSound();
    void playStartSound();
    void playLevelSound();

private:
    explicit SoundManager(QObject *parent = nullptr);
    ~SoundManager();

    static SoundManager* m_instance;

    QSoundEffect *m_flipSound;        //金币翻转
    QSoundEffect *m_winSound;         //胜利音效
    QSoundEffect *m_backSound;        //返回音效
    QSoundEffect *m_startSound;       //开始音效
    QSoundEffect *m_levelSound;       //关卡选择音效

signals:
};

#endif // SOUNDMANAGER_H
