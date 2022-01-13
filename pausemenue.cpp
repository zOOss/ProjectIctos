#include "pausemenue.h"
#include "drawable.h"
#include "inputregistry.h"
#include "shadermanager.h"

PauseMenue::PauseMenue()
{

}

PauseMenue::PauseMenue(QString path) : Node()
{
    Drawable* drawablePfeil = new Drawable(new TriangleMesh(path+QString("/models/Pfeil.obj")));
    mPauseText = new Drawable(new TriangleMesh(path+QString("/models/Pause.obj")));
    init();
    Node* transform = new Node(mPfeil);
    Node* drawable = new Node(drawablePfeil);
    Node* drawOver = new Node(mPauseText);
    transform->addChild(drawable);
    Transformation *pos = new Transformation();
    Node* posNode = new Node(pos);
    this->addChild(transform);
    this->addChild(posNode);
    posNode->addChild(drawOver);

    pos->translate(0.0, 15.0, 0.0);
    pos->rotate(40.0, 1.0, 0.0, 0.0);
    pos->scale(2.0, 2.0, 2.0);

    mPfeil->translate(-5.0, 15.0, 1.40);
    mPfeil->rotate(40.0, 1.0, 0.0, 0.0);

    mPauseText->setShader(ShaderManager::getShader("://shaders/hello_glsl.vert", "://shaders/hello_glsl.frag"));
    drawablePfeil->setShader(ShaderManager::getShader("://shaders/hello_glsl.vert", "://shaders/hello_glsl.frag"));

    pfad = path;

    position = 0;
}

void PauseMenue::setPosition(float x, float y, float z)
{
    mPfeil->translate(x, y, z);
}

void PauseMenue::keyboard(int key, int modifier)
{
    KeyboardInput* keyIn = InputRegistry::getInstance().getKeyboardInput();

    Transformation& trafo = this->getTrafo();
    int lMyKeyW = 'w';
    int lMyKeyS = 's';
    int lMyKeyM = 'm';

    if (keyIn->isKeyPressed(lMyKeyW) && position > 0)
    {
        trafo.translate(0.0, 0.0, -2.0);
        position += -1;
    }

    if (keyIn->isKeyPressed(lMyKeyS) && position < 1)
    {
        trafo.translate(0.0, 0.0, +2.0);
        position += 1;
    }

    if (keyIn->isKeyPressed(lMyKeyM) && position > 0)
    {
        //Irgendwie Szene auf Szene 1 wechseln
    }

    if (keyIn->isKeyPressed(lMyKeyM) && position < 1)
    {
        //Irgendwie Spiel beenden
    }
}

void PauseMenue::init()
{
    mPfeil = new Transformation;
}

QVector4D PauseMenue::getPosition()
{
    return mPfeil->getModelMatrix() * QVector4D(0.0, 0.0, 0.0, 1.0);
}
