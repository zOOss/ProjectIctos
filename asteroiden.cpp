#include "asteroiden.h"
#include "drawable.h"
#include "inputregistry.h"
#include "shadermanager.h"
#include "texture.h"
#include <QPointF>
#include "shadertimed.h"

Asteroiden::Asteroiden()
{

}

Asteroiden::Asteroiden(QString path, SpaceShip* ship) : Node()
{
    Drawable* drawableAsteroid = new Drawable(new TriangleMesh(path+QString("/models/Astroid.obj")));
    init();
    Node* transform = new Node(mAsteroid);
    Node* drawable = new Node(drawableAsteroid);
    transform->addChild(drawable);
    this->addChild(transform);
    Texture* t;

    //Texturen laden
    t = drawableAsteroid->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/Asteroid_Diffuse.png"));

    drawableAsteroid->setShader(ShaderManager::getShader("://shaders/texture.vert", "://shaders/texture.frag"));
    ShaderTimed* shaderA0 = ShaderManager::getShader<ShaderTimed>("://shaders/asteroid.vert", "://shaders/asteroid.frag");
    drawableAsteroid->setShader(shaderA0);

    shaderA0->setMsecsPerIteration(60000);

    pfad = path;
    spaceShip = ship;
    speedDiff = (rand() % 1000) / 15000.0;
    asteroidRunning = 0.0;

    Spawn();
}

//Asteroiden::~Asteroiden()
//{
//    delete[] spaceShip;
//    delete[] mAsteroid;
//    delete[] GameOver;
//}

void Asteroiden::setPosition(float x, float y, float z)
{
    mAsteroid->resetTrafo();
    mAsteroid->translate(x, y, z);
}

void Asteroiden::init()
{
    mAsteroid = new Transformation;
}

void Asteroiden::doIt()
{
    mAsteroid->translate(0.0, 0.0, (spaceShip->getSpeed() + speedDiff) * spaceShip->getRunning() * asteroidRunning);

    if (collisionDetect())
    {
        spaceShip->setSpeed(0.0);
        spaceShip->makeGameOver();
    }

    if (outOfScreen())
    {
        spaceShip->addSpeed();
        mAsteroid->translate(0.0, 0.0, -90 - (rand() % 10) - 5);
    }
}

void Asteroiden::Spawn()
{
    mAsteroid->resetTrafo();
    mAsteroid->translate(0.0, 0.0, -80.0);
}

bool Asteroiden::collisionDetect()
{
    QVector4D posShip = spaceShip->getPosition();
    float abstand = posShip.toVector3D().distanceToPoint((mAsteroid->getModelMatrix() * QVector4D(0.0, 0.0, 0.0, 1.0)).toVector3D());

    if(abstand < 2.0)
    {
        return true;
    }

    return false;
}

bool Asteroiden::outOfScreen()
{
    return (mAsteroid->getModelMatrix() * QVector4D(0.0, 0.0, 0.0, 1.0)).toVector3D().z() > 10;
}

void Asteroiden::keyboard(int key, int modifier)
{
    if (key == '1')
    {
        spaceShip->setRunning(1.0);
    }
    else if(key =='2')
    {
        spaceShip->setRunning(0.0);
    }
}

void Asteroiden::setAsteroidRunning(float b)
{
    asteroidRunning = b;
}
