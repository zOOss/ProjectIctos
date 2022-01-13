#include "spaceship.h"
#include "drawable.h"
#include "inputregistry.h"
#include "shadermanager.h"
#include "texture.h"

SpaceShip::SpaceShip()
{

}

SpaceShip::SpaceShip(QString path) : Node()
{
    Drawable* drawableShip = new Drawable(new TriangleMesh(path+QString("/models/SpaceShip2.obj")));
    GameOver = new Drawable(new TriangleMesh(path+QString("/models/GameOver.obj")));
    init();
    Node* transform = new Node(mSpaceShip);
    Node* drawable = new Node(drawableShip);
    Node* drawOver = new Node(GameOver);
    transform->addChild(drawable);
    Transformation *pos = new Transformation();
    Node* posNode = new Node(pos);
    this->addChild(transform);
    this->addChild(posNode);
    posNode->addChild(drawOver);
    Texture* t;

    pos->translate(0.0, 24.0, 15.0);
    pos->rotate(40.0, 1.0, 0.0, 0.0);
    pos->scale(2.0, 2.0, 2.0);

    GameOver->setEnabled(false);
    GameOver->setShader(ShaderManager::getShader("://shaders/hello_glsl.vert", "://shaders/hello_glsl.frag"));

    //Texturen laden
    t = drawableShip->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/SpaceShip_Diffuse.png"));

    drawableShip->setShader(ShaderManager::getShader("://shaders/texture.vert", "://shaders/texture.frag"));

    pfad = path;

    astSpeed = 0.05;
    mRunning = 0.0;

    position = 0;
}

void SpaceShip::setPosition(float x, float y, float z)
{
	mSpaceShip->translate(x, y, z);
}

void SpaceShip::keyboard(int key, int modifier)
{
	KeyboardInput* keyIn = InputRegistry::getInstance().getKeyboardInput();

	Transformation& trafo = this->getTrafo();
    int lMyKeyA = 'a';
    int lMyKeyD = 'd';

    if (mRunning > 0.5)
    {
    if (keyIn->isKeyPressed(lMyKeyA) && position > -1)
	{
        trafo.translate(-14.0, 0.0, 0.0);
        position += -1;
	}

    if (keyIn->isKeyPressed(lMyKeyD) && position < 1)
    {
        trafo.translate(14.0, 0.0, 00.0);
        position += 1;
    }
    }
}

void SpaceShip::init()
{
	mSpaceShip = new Transformation;
}

QVector4D SpaceShip::getPosition()
{
    return mSpaceShip->getModelMatrix() * QVector4D(0.0, 0.0, 0.0, 1.0);
}

float SpaceShip::getSpeed()
{
    return astSpeed;
}

void SpaceShip::setSpeed(float speed)
{
    astSpeed = speed;
}

void SpaceShip::addSpeed()
{
    astSpeed += 0.001;
}

void SpaceShip::makeGameOver()
{
    GameOver->setEnabled(true);
    mRunning = 0.0;
}

float SpaceShip::getRunning()
{
    return mRunning;
}

void SpaceShip::setRunning(float f)
{
    mRunning = f;
}
