#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game* game;

Enemy::Enemy(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent) {
    // Set random x position
    int random_number = rand() % 700;
    setPos(random_number - 40, 0);

    // Set the pixmap
    setPixmap(QPixmap("../Assets/Avion enemigo videojuego.png").scaled(150, 150));

    // Create a timer to move the enemy
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // Start the timer
    timer->start(50);
}

void Enemy::move() {
    static const int speed = 5; // Adjust the speed as needed
    qreal targetY = pos().y() + speed;

    // Smoothly interpolate the enemy's position
    if (targetY > 600) {
        // Decrease health and remove enemy when out of screen
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
    else {
        setPos(pos().x(), targetY);
    }
}
