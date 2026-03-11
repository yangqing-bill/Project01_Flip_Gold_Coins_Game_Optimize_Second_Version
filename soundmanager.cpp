#include "soundmanager.h"

#include<QCoreApplication>

SoundManager* SoundManager::m_instance = nullptr;

SoundManager::SoundManager(QObject *parent)
    : QObject{parent}
{
    m_flipSound = new QSoundEffect(this);
    m_flipSound->setSource(QUrl("qrc:/music/ConFlipSound.wav"));
    m_flipSound->setVolume(0.8f);

    m_winSound = new QSoundEffect(this);
    m_winSound->setSource(QUrl("qrc:/music/LevelWinSound.wav"));
    m_winSound->setVolume(0.8f);

    m_backSound = new QSoundEffect(this);
    m_backSound->setSource(QUrl("qrc:/music/BackButtonSound.wav"));
    m_backSound->setVolume(0.8f);

    m_startSound = new QSoundEffect(this);
    m_startSound->setSource(QUrl("qrc:/music/TapButtonSound.wav"));
    m_startSound->setVolume(0.8f);

    m_levelSound = new QSoundEffect(this);
    m_levelSound->setSource(QUrl("qrc:/music/TapButtonSound.wav"));
    m_levelSound->setVolume(0.8f);
}

SoundManager* SoundManager::instance()
{
    if (!m_instance) {
        m_instance = new SoundManager(QCoreApplication::instance());
    }
    return m_instance;
}

void SoundManager::playFlipSound()
{
    if(m_flipSound)
        m_flipSound->play();
}

void SoundManager::playWinSound()
{
    if(m_winSound)
        m_winSound->play();
}

void SoundManager::playBackSound()
{
    if(m_backSound)
        m_backSound->play();
}

void SoundManager::playStartSound()
{
    if(m_startSound)
        m_startSound->play();
}

void SoundManager::playLevelSound()
{
    if(m_levelSound)
        m_levelSound->play();
}

SoundManager::~SoundManager()
{

}
