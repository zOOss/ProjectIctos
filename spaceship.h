#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "drawable.h"
#include "transformation.h"
#include "simplecube.h"
#include "listener.h"
#include "trianglemesh.h"

class SpaceShip : public Node, public Listener
{
public:
    SpaceShip();
    SpaceShip(QString);

    void setPosition(float x, float y, float z);
    QVector4D getPosition();
    float getSpeed();
    void setSpeed(float);
    void addSpeed();
    void makeGameOver();
    float getRunning();
    void setRunning(float);

    virtual void keyboard(int key, int /*modifier*/);

private:
    void init();
    
    int position;
    float astSpeed;
    float mRunning;
    Transformation* mSpaceShip;
    //float sx, sy, sz;
    QString pfad;
    Drawable* GameOver;

protected:
    inline Transformation& getTrafo();
};

inline Transformation& SpaceShip::getTrafo()
{
    return *mSpaceShip;
}

#endif // SPACESHIP_H
