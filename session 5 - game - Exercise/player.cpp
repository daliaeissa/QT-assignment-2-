#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include <QList>
#include<QGraphicsPixmapItem>
Player::Player() {

}

void Player::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(QGraphicsPixmapItem::x()>0) // to prevent the player from getting out of the screen
        {
        QGraphicsPixmapItem::setPos(QGraphicsPixmapItem::x()-10,QGraphicsPixmapItem::y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(QGraphicsPixmapItem::x()+100<800) // to prevent the player from getting out of the screen
        QGraphicsPixmapItem::setPos(QGraphicsPixmapItem::x()+10,QGraphicsPixmapItem::y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(QGraphicsPixmapItem::x()+30,QGraphicsPixmapItem::y());
        QGraphicsPixmapItem::scene()->addItem(bullet);

    }

}


 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy();
  QGraphicsPixmapItem::scene()->addItem(enemy);

}
