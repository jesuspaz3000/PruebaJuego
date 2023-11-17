#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QBrush>
#include <QImage>

Game::Game(QWidget* parent) {
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600); // make the scene 800x600 instead of infinity by infinity (default)
    // Establecer la imagen de fondo
    QPixmap backgroundImage("D:/microsoft visual studio/PruebaJuego/Assets/fondo videojuego.jpg");
    backgroundImage = backgroundImage.scaledToHeight(600); // Estirar la imagen para que ocupe la altura de la ventana
    setBackgroundBrush(QBrush(backgroundImage));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    // create the player
    player = new Player();
    player->setPos(320, 460); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    // spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // play background music
    /*QMediaPlayer * music = new QMediaPlayer();
    music->audioOutput(QUrl("qrc:/sounds/TurnDownForWhat.mp3"));
    music->play();*/

    QMediaPlayer* backgroundMusic = new QMediaPlayer;
    QAudioOutput* audioOutput = new QAudioOutput();
    backgroundMusic->setAudioOutput(audioOutput);
    backgroundMusic->setSource(QUrl::fromLocalFile("D:/microsoft visual studio/PruebaJuego/Assets/TurnDownForWhat.mp3"));
    audioOutput->setVolume(30);
    backgroundMusic->play();

    show();
}
