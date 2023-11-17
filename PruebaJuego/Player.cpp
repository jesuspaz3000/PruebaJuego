#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {
    // set graphic
    setPixmap(QPixmap("D:/microsoft visual studio/PruebaJuego/Assets/avionVideojuego1.png").scaled(150, 150));
}

void Player::keyPressEvent(QKeyEvent* event) {
    // move the player left and right
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > -40)
            setPos(x() - 10, y());
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 790)
            setPos(x() + 10, y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space) {
        // create a bullet
        Bullet* bullet = new Bullet();
        // Set the position of the bullet to the center of the player's image
        bullet->setPos(x() + pixmap().width() / 2 - bullet->pixmap().width() / 2, y());
        scene()->addItem(bullet);

        // create a new QMediaPlayer for each bullet
        QMediaPlayer* bulletsound = new QMediaPlayer();
        QAudioOutput* audioBulletOutput = new QAudioOutput();
        bulletsound->setAudioOutput(audioBulletOutput);
        bulletsound->setSource(QUrl::fromLocalFile("D:/microsoft visual studio/PruebaJuego/Assets/blaster-2-81267.mp3"));
        audioBulletOutput->setVolume(50);

        // play bulletsound
        bulletsound->play();
    }
}


void Player::spawn() {
    // create an enemy
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
