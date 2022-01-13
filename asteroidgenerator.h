#ifndef ASTEROIDGENERATOR_H
#define ASTEROIDGENERATOR_H

#include "idleobserver.h"
#include "asteroiden.h"
#include "spaceship.h"
#include "QTime"
#include <QList>

class AsteroidGenerator : public Node, public IdleObserver
{
public:
    AsteroidGenerator();
    AsteroidGenerator(QString, SpaceShip*);

    void Spawn();

private:
    void doIt();

    SpaceShip* spaceShip;
    QTime zeit;
    QList<Asteroiden*> asteroidenListe1;
    QList<Asteroiden*> asteroidenListe2;
    QList<Asteroiden*> asteroidenListe3;
    QList<Asteroiden*> asteroidenLauf1;
    QList<Asteroiden*> asteroidenLauf2;
    QList<Asteroiden*> asteroidenLauf3;
    QList<QVector3D> asteroidenAufstellung;
    QString pfad;
};

#endif // ASTEROIDGENERATOR_H
