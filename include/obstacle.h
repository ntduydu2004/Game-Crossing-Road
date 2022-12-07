#pragma once
#include <bits/stdc++.h>
#include "raylib.h"
using namespace std;
// Vehicle
//----------------------------------------------------------------------------------
class Vehicle{
protected:
    Texture2D left;
    Texture2D right;
    Vector2 position;
    bool isLeft;
public:
    virtual ~Vehicle();
    Vehicle(bool isLeft, Vector2 position);
    virtual void Draw() = 0;
    virtual void ChangePosition() = 0;
};

class Truck: public Vehicle{
public:
    Truck(bool isLeft, Vector2 position);
    ~Truck();
    void Draw();
    void ChangePosition();
};


class Car: public Vehicle{
public:
    Car(bool isLeft, Vector2 position);
    ~Car();
    void Draw();
    void ChangePosition();
};

// Animal
//----------------------------------------------------------------------------------
class Animal{
protected:
    vector<Texture2D> left;
    vector<Texture2D> right;
    Vector2 position;
    bool isLeft;
public:
    Animal(bool isLeft, Vector2 position);
    ~Animal();
    virtual void Draw() = 0;
    virtual void ChangePosition() = 0;
};

class Bird: public Animal{
public:
    Bird(bool isLeft, Vector2 position);
    ~Bird();
    void Draw();
    void ChangePosition();
};

class Elephant: public Animal{
public:
    Elephant(bool isLeft, Vector2 position);
    ~Elephant();
    void Draw();
    void ChangePosition();
};
class Dinosaur: public Animal{
public:
    Dinosaur(bool isLeft, Vector2 position);
    ~Dinosaur();
    void Draw();
    void ChangePosition();
};

// Wood
//----------------------------------------------------------------------------------
class Wood{
private:
    Texture2D Pic;
    Vector2 position;
public:
    Wood(Vector2 position);
    ~Wood();
    void Draw();
    void ChangePosition();
};
