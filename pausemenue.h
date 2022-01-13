#ifndef PAUSEMENUE_H
#define PAUSEMENUE_H

#include "drawable.h"
#include "transformation.h"
#include "simplecube.h"
#include "listener.h"
#include "trianglemesh.h"

class PauseMenue : public Node, public Listener
{
public:
    PauseMenue();
    PauseMenue(QString);

    void setPosition(float x, float y, float z);
    QVector4D getPosition();

    virtual void keyboard(int key, int /*modifier*/);

private:
    void init();

    int position;
    Transformation* mPfeil;
    QString pfad;
    Drawable* mPauseText;

protected:
    inline Transformation& getTrafo();
};

inline Transformation& PauseMenue::getTrafo()
{
    return *mPfeil;
}

#endif // PAUSEMENUE_H
