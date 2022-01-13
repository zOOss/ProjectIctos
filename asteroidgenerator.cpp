#include "asteroidgenerator.h"

AsteroidGenerator::AsteroidGenerator()
{

}

AsteroidGenerator::AsteroidGenerator(QString path, SpaceShip* ship)
{
    spaceShip = ship;
    zeit = QTime::currentTime();
    pfad = path;

    //Aufstellung erstellen
    asteroidenAufstellung.append(QVector3D(0.0, 0.0, 0.0));
    asteroidenAufstellung.append(QVector3D(0.0, 0.0, 1.0));
    asteroidenAufstellung.append(QVector3D(0.0, 1.0, 0.0));
    asteroidenAufstellung.append(QVector3D(0.0, 1.0, 1.0));
    asteroidenAufstellung.append(QVector3D(1.0, 0.0, 0.0));
    asteroidenAufstellung.append(QVector3D(1.0, 0.0, 1.0));
    asteroidenAufstellung.append(QVector3D(1.0, 1.0, 0.0));

    //Asteroiden erstellen
    Asteroiden* asteroid1_1 = new Asteroiden(path, ship);
    asteroid1_1->setPosition(-14.0, 0.0, 90);
    asteroidenListe1.append(asteroid1_1);
    Asteroiden* asteroid1_2 = new Asteroiden(path, ship);
    asteroid1_2->setPosition(-14.0, 0.0, 90);
    asteroidenListe1.append(asteroid1_2);
    Asteroiden* asteroid1_3 = new Asteroiden(path, ship);
    asteroid1_3->setPosition(-14.0, 0.0, 90);
    asteroidenListe1.append(asteroid1_3);
    Asteroiden* asteroid1_4 = new Asteroiden(path, ship);
    asteroid1_4->setPosition(-14.0, 0.0, 90);
    asteroidenListe1.append(asteroid1_4);
    //Asteroiden* asteroid1_5 = new Asteroiden(path, ship);
    //asteroid1_5->setPosition(-14.0, 0.0, 90);
    //asteroidenListe1.append(asteroid1_5);
    //Asteroiden* asteroid1_6 = new Asteroiden(path, ship);
    //asteroid1_6->setPosition(-14.0, 0.0, 90);
    //asteroidenListe1.append(asteroid1_6);
    //Asteroiden* asteroid1_7 = new Asteroiden(path, ship);
    //asteroid1_7->setPosition(-14.0, 0.0, 90);
    //asteroidenListe1.append(asteroid1_7);
    //Asteroiden* asteroid1_8 = new Asteroiden(path, ship);
    //asteroid1_8->setPosition(-14.0, 0.0, 90);
    //asteroidenListe1.append(asteroid1_8);

    Asteroiden* asteroid2_1 = new Asteroiden(path, ship);
    asteroid2_1->setPosition(0.0, 0.0, 90);
    asteroidenListe2.append(asteroid2_1);
    Asteroiden* asteroid2_2 = new Asteroiden(path, ship);
    asteroid2_2->setPosition(0.0, 0.0, 90);
    asteroidenListe2.append(asteroid2_2);
    Asteroiden* asteroid2_3 = new Asteroiden(path, ship);
    asteroid2_3->setPosition(0.0, 0.0, 90);
    asteroidenListe2.append(asteroid2_3);
    Asteroiden* asteroid2_4 = new Asteroiden(path, ship);
    asteroid2_4->setPosition(0.0, 0.0, 90);
    asteroidenListe2.append(asteroid2_4);
    //Asteroiden* asteroid2_5 = new Asteroiden(path, ship);
    //asteroid2_5->setPosition(0.0, 0.0, 90);
    //asteroidenListe2.append(asteroid2_5);
    //Asteroiden* asteroid2_6 = new Asteroiden(path, ship);
    //asteroid2_6->setPosition(0.0, 0.0, 90);
    //asteroidenListe2.append(asteroid2_6);
    //Asteroiden* asteroid2_7 = new Asteroiden(path, ship);
    //asteroid2_7->setPosition(0.0, 0.0, 90);
    //asteroidenListe2.append(asteroid2_7);
    //Asteroiden* asteroid2_8 = new Asteroiden(path, ship);
    //asteroid2_8->setPosition(0.0, 0.0, 90);
    //asteroidenListe2.append(asteroid2_8);

    Asteroiden* asteroid3_1 = new Asteroiden(path, ship);
    asteroid3_1->setPosition(14.0, 0.0, 90);
    asteroidenListe3.append(asteroid3_1);
    Asteroiden* asteroid3_2 = new Asteroiden(path, ship);
    asteroid3_2->setPosition(14.0, 0.0, 90);
    asteroidenListe3.append(asteroid3_2);
    Asteroiden* asteroid3_3 = new Asteroiden(path, ship);
    asteroid3_3->setPosition(14.0, 0.0, 90);
    asteroidenListe3.append(asteroid3_3);
    Asteroiden* asteroid3_4 = new Asteroiden(path, ship);
    asteroid3_4->setPosition(14.0, 0.0, 90);
    asteroidenListe3.append(asteroid3_4);
    //Asteroiden* asteroid3_5 = new Asteroiden(path, ship);
    //asteroid3_5->setPosition(14.0, 0.0, 90);
    //asteroidenListe3.append(asteroid3_5);
    //Asteroiden* asteroid3_6 = new Asteroiden(path, ship);
    //asteroid3_6->setPosition(14.0, 0.0, 90);
    //asteroidenListe3.append(asteroid3_6);
    //Asteroiden* asteroid3_7 = new Asteroiden(path, ship);
    //asteroid3_7->setPosition(14.0, 0.0, 90);
    //asteroidenListe3.append(asteroid3_7);
    //Asteroiden* asteroid3_8 = new Asteroiden(path, ship);
    //asteroid3_8->setPosition(14.0, 0.0, 90);
    //asteroidenListe3.append(asteroid3_8);
}

void AsteroidGenerator::doIt()
{
    if ((QTime::currentTime().msecsSinceStartOfDay() - zeit.msecsSinceStartOfDay()) < 100000)
    {
        zeit = QTime::currentTime();
        Spawn();
    }

    if((asteroidenLauf1.length() != 0) && asteroidenLauf1[0]->collisionDetect())
    {
        Asteroiden* asteroid1 = asteroidenLauf1[0];
        asteroidenLauf1.remove(0);
        asteroid1->setAsteroidRunning(0.0);
        asteroid1->Spawn();
        asteroidenListe1.append(asteroid1);
    }
    if((asteroidenLauf2.length() != 0) && asteroidenLauf2[0]->collisionDetect())
    {
        Asteroiden* asteroid2 = asteroidenLauf2[0];
        asteroidenLauf2.remove(0);
        asteroid2->setAsteroidRunning(0.0);
        asteroid2->Spawn();
        asteroidenListe1.append(asteroid2);
    }
    if((asteroidenLauf3.length() != 0) && asteroidenLauf3[0]->collisionDetect())
    {
        Asteroiden* asteroid3 = asteroidenLauf3[0];
        asteroidenLauf3.remove(0);
        asteroid3->setAsteroidRunning(0.0);
        asteroid3->Spawn();
        asteroidenListe1.append(asteroid3);
    }
}

void AsteroidGenerator::Spawn()
{
    int nummer = (rand() % 7);

    if ((asteroidenListe1.length() != 0) && (asteroidenAufstellung[nummer].x() > 0.5))
    {
        Asteroiden* asteroid1 = asteroidenListe1[0];
        asteroidenListe1.remove(0);
        asteroid1->setAsteroidRunning(1.0);
        asteroidenLauf1.append(asteroid1);
    }
    if ((asteroidenListe2.length() != 0) && (asteroidenAufstellung[nummer].y() > 0.5))
    {
        Asteroiden* asteroid2 = asteroidenListe2[0];
        asteroidenListe1.remove(0);
        asteroid2->setAsteroidRunning(1.0);
        asteroidenLauf2.append(asteroid2);
    }
    if ((asteroidenListe1.length() != 0) && (asteroidenAufstellung[nummer].z() > 0.5))
    {
        Asteroiden* asteroid3 = asteroidenListe3[0];
        asteroidenListe1.remove(0);
        asteroid3->setAsteroidRunning(1.0);
        asteroidenLauf3.append(asteroid3);
    }
}
