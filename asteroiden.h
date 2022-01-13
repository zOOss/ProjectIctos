#ifndef ASTEROIDEN_H
#define ASTEROIDEN_H

#include "drawable.h"
#include "transformation.h"
#include "simplecube.h"
#include "trianglemesh.h"
#include "idleobserver.h"
#include "spaceship.h"

class Asteroiden : public Node, public IdleObserver, public Listener
{
public:
    Asteroiden();
    Asteroiden(QString, SpaceShip*);
    //~Asteroiden();

    void setPosition(float x, float y, float z);
    void Spawn();
    bool collisionDetect();
    bool outOfScreen();
    void setAsteroidRunning(float b);

    virtual void keyboard(int key, int /*modifier*/);

private:
    void init();
    void doIt();

    int position;
    Transformation* mAsteroid;
    //float sx, sy, sz;
    QString pfad;
    SpaceShip* spaceShip;
    float speedDiff;
    Drawable* GameOver;
    float asteroidRunning;

protected:
    inline Transformation& getTrafo();
};

inline Transformation& Asteroiden::getTrafo()
{
    return *mAsteroid;
}

#endif // SPACESHIP_H
