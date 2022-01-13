#include "scenemanager.h"
#include "screenrenderer.h"
#include "mousekeyboardcameracontroller.h"
#include "simplecube.h"
#include "shadertimed.h"
#include "transformation.h"
#include "shadermanager.h"
#include "modeltransformation.h"
#include "spaceship.h"
#include "trianglemesh.h"
#include "sunlight.h"
#include "list"
#include <QTimer>
#include "texture.h"
#include "asteroiden.h"
#include "pausemenue.h"
#include "idleobserver.h"
#include "time.h"
//#include "asteroidgenerator.h"

Node* initScene1();
Node* initScene2();

ScreenRenderer* sortedRenderer;
unsigned int myScene, myScene2;

class SceneSwitcher: public Listener
{
    void keyboard(int key, int modifier)
    {
        if (key == '1')
        {
            sortedRenderer->setScene(myScene);
        }
        else if(key =='2')
        {
            sortedRenderer->setScene(myScene2);
        }
    }
};


void SceneManager::initScenes()
{
    SceneSwitcher* lSwitch = new SceneSwitcher();
    Camera* cam = new Camera();
    //CameraController* camController = new MouseKeyboardCameraController(cam);
    //Q_UNUSED(camController);
    RenderingContext* myContext = new RenderingContext(cam);
    unsigned int myContextNr = SceneManager::instance()->addContext(myContext);
    myScene = SceneManager::instance()->addScene(initScene1());
    myScene2 = SceneManager::instance()->addScene(initScene2());
    sortedRenderer = new ScreenRenderer(myContextNr, myScene2);
    Q_UNUSED(lSwitch);
    cam->setPosition(0.0, 30.0, 22.0);
    cam->setRotation(0.0, 40.0, 0.0);
    // Vorsicht: Die Szene muss initialisiert sein, bevor das Fenster verändert wird (Fullscreen)
    SceneManager::instance()->setActiveScene(myScene);
    SceneManager::instance()->setActiveContext(myContextNr);
    //SceneManager::instance()->setFullScreen();
}

Node* initScene1()
{
    QString path(SRCDIR); // aus .pro-File!

    Node* root = new Node();

    SpaceShip* spaceShip = new SpaceShip(path);
    Asteroiden* asteroid0 = new Asteroiden(path, spaceShip);
    Asteroiden* asteroid1 = new Asteroiden(path, spaceShip);
    Asteroiden* asteroid2 = new Asteroiden(path, spaceShip);
    Asteroiden* asteroid3 = new Asteroiden(path, spaceShip);
    Asteroiden* asteroid4 = new Asteroiden(path, spaceShip);
    Asteroiden* asteroid5 = new Asteroiden(path, spaceShip);
    Asteroiden* asteroid6 = new Asteroiden(path, spaceShip);
    Asteroiden* asteroid7 = new Asteroiden(path, spaceShip);
    Asteroiden* asteroid8 = new Asteroiden(path, spaceShip);
    Asteroiden* asteroid9 = new Asteroiden(path, spaceShip);
    //AsteroidGenerator* generator = new AsteroidGenerator(path, spaceShip);

    asteroid0->setPosition(-14.0, 0.0, -140.0);
    asteroid1->setPosition(14.0, 0.0, -50.0);
    asteroid2->setPosition(0.0, 0.0, -30.0);
    asteroid3->setPosition(14.0, 0.0, -19.0);
    asteroid4->setPosition(-14.0, 0.0, -120.0);
    asteroid5->setPosition(14.0, 0.0, -70.0);
    asteroid6->setPosition(0.0, 0.0, -240.0);
    asteroid7->setPosition(-14.0, 0.0, -120.0);
    asteroid8->setPosition(0.0, 0.0, -50.0);
    asteroid9->setPosition(0.0, 0.0, -120.0);

    SunLight* light1 = new SunLight;
    Node *light1Node = new Node(light1);

    light1->setDiffuse(0.7, 0.7, 0.7);
    light1->setSpecular(0.6, 0.6, 0.6);
    light1->setAmbient(0.6, 0.6, 0.6);
    light1->turnOn();



    root->addChild(light1Node);
    root->addChild(spaceShip);
    root->addChild(asteroid0);
    root->addChild(asteroid1);
    root->addChild(asteroid2);
    root->addChild(asteroid3);
    root->addChild(asteroid4);
    root->addChild(asteroid5);
    root->addChild(asteroid6);
    root->addChild(asteroid7);
    root->addChild(asteroid8);
    root->addChild(asteroid9);
    //root->addChild(generator);

    return (root);
}


Node* initScene2()
{
    QString path(SRCDIR); // aus .pro-File!

    Node* root = new Node();

    PauseMenue* pauseMenue = new PauseMenue(path);
    root->addChild(pauseMenue);
    return (root);
}
