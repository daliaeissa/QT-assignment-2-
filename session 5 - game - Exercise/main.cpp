
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include<QPixmap>
#include<QGraphicsPixmapItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // *******  Create the View ********
    QGraphicsView view;
    view.setFixedSize(800, 600);

    // *******  Create the Player ********
    Player* player = new Player();
    // player->setRect(0, 0, 60, 100);
    // player->setBrush(Qt::red);
    QPixmap spaceship("C:/Users/dalia/Desktop/Spring 2024 semester/CS2 lab/Assignments/Assignment 2 QT");
    player->setPixmap(spaceship.scaled(100,100));

    // ******* Create the Scene ********
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);
    //scene.addItem(player);
    scene.addItem(static_cast<QGraphicsPixmapItem*>(player));
    player->QGraphicsPixmapItem::setFocus();
    // *******  Setting the foucs to the Player ********
    // player->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    // player->setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********
    player->QGraphicsPixmapItem::setPos(view.width()/2, view.height()-player->rect().height());

   // *******   Assign scene to the view   ***************
    view.setScene(&scene);

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);
    view.show();

    return a.exec();
}
