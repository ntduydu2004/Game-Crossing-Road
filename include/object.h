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
    int width, height;
public:
    Object(){};
    Object(string TypeOfObject, int width, int height);
    ~Object();
    void Draw(Vector2 position, bool isLeft);
    short GetHeight();
    short GetWidth();
};
class ObjectFactory{
private:
    Object object[4][13] = 
    {
        {
            Object("car1", 234, 60),
            Object("car2", 196, 60),
            Object("car3", 182, 70),
            Object("car4", 190, 60),
            Object("car5", 186, 60),
            Object("car6", 188, 60),
            Object("car7", 190, 70),
            Object("car8", 190, 60),
            Object("car9", 178, 70),
            Object("car10", 174, 80),
            Object("TrafficGreen", 34, 90),
            Object("TrafficYellow", 34, 90),
            Object("TrafficRed", 34, 90),
        },

        {

        },
        
        {
            Object("Wood1", 194, 140),
            Object("Wood2", 344, 140),
        },

        {
            Object("buffalo", 116, 70),
            Object("deer", 66, 80),
            Object("elephant", 142, 90),
            Object("girrafe", 102, 110),
            Object("leopard", 88, 60),
            Object("lion", 80, 60),
            Object("rhino", 128, 70),
        },
    };
public:
    ~ObjectFactory(){};
    void Draw(int typeLane, int type, Vector2 position, bool isLeft);
    short GetHeight(int typeLane, int type);
    short GetWidth(int typeLane, int type);
};
class MovingObject{
private:
    int typeLane;
    int type;
    bool isLeft;
public:
    Vector2 position;
    // MovingObject(){};
    MovingObject(Vector2 position, int typeLane, int type, bool isLeft);
    short GetHeight(ObjectFactory& objectFactory);
    short GetWidth(ObjectFactory& objectFactory);
    // void Set(Vector2, int typeLane, int type, bool isLeft);
    void Draw(ObjectFactory& objectFactory, int TrafficLight);
    void Move(float p = 0.5f);
    void MoveX(int TrafficLight);
    void Follow(Vector2& position);
    void CheckCollisionObject(ObjectFactory& objectfactory, Vector2& position, bool& isCollided);
};