#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Player: public QObject, public QGraphicsRectItem, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    //explicit Player(QObject *parent = nullptr);
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void createEnemy();

};

#endif // PLAYER_H
