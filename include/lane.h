#pragma once
#include "object.h"
using namespace std;
class Lane{
private:
    Texture2D Pic;
    short height;
public:
    Lane(string TypeOfLane, short height);
    ~Lane();
    void Draw(Vector2 position);
    short GetHeight();
};
class LaneFactory{
private:
    Lane lane[4] =
    {
        Lane("Road", 260),
        Lane("Pavement", 135),
        Lane("Stream", 135),
        Lane("Grass", 135),
    };
public:
    ~LaneFactory(){};
    void Draw(int type, Vector2 position);
    short GetHeight(int type);
};
class MovingLane{
private:
    vector<MovingObject> object;
    short height;
    int numObject;
    int type;
public:
    Vector2 position;
    MovingLane(Vector2 position, int type, short height);
    void Draw(LaneFactory& lanefactory, ObjectFactory& objectfactory, int TrafficLight);
    void Move(float p = 0.5f);
    void MoveObjectX(int TrafficLight);
    bool isOutOfScreen();
    bool isLastInScreen();
    short GetHeight();
};
