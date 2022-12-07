#pragma once
#include "raylib.h"
#include <bits/stdc++.h>
using namespace std;
typedef enum{
    LIGHT_GREEN = 0,
    LIGHT_YELLOW = 1,
    LIGHT_RED = 2,
}TrafficLight;
class Object{
private:
    Texture2D PicLeft;
    Texture2D PicRight;
public:
    Object(){};
    Object(string TypeOfObject);
    ~Object();
    void Draw(Vector2 position, bool isLeft);
};
class ObjectFactory{
private:
    Object object[4][13] = 
    {
        {
            Object("car1"),
            Object("car2"),
            Object("car3"),
            Object("car4"),
            Object("car5"),
            Object("car6"),
            Object("car7"),
            Object("car8"),
            Object("car9"),
            Object("car10"),
            Object("TrafficGreen"),
            Object("TrafficYellow"),
            Object("TrafficRed"),
        },

        {

        },
        
        {
            Object("Wood1"),
            Object("Wood2"),
        },

        {
            Object("buffalo"),
            Object("deer"),
            Object("elephant"),
            Object("girrafe"),
            Object("leopard"),
            Object("lion"),
            Object("rhino"),
        },
    };
public:
    ~ObjectFactory(){};
    void Draw(int typeLane, int type, Vector2 position, bool isLeft);
};
class MovingObject{
private:
    Vector2 position;
    int typeLane;
    int type;
    bool isLeft;
public:
    // MovingObject(){};
    MovingObject(Vector2 position, int typeLane, int type, bool isLeft);
    // void Set(Vector2, int typeLane, int type, bool isLeft);
    void Draw(ObjectFactory& objectFactory, int TrafficLight);
    void Move(float p = 0.5f);
    void MoveX(int TrafficLight);
};