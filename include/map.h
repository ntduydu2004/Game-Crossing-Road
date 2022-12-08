#pragma once
#include <bits/stdc++.h>
#include "lane.h"
class Map{
private:
    LaneFactory laneFactory;
    ObjectFactory objectFactory;
    vector <MovingLane> lane;
public:
    short x;
    Map();
    ~Map(){};
    void Move(float p = 0.5);
    void MoveObjectX(int TrafficLight);
    void Fill();
    void Draw(int TrafficLight);
    void Follow(Vector2& position);
    void CheckCollisionObject(Vector2& position, bool& isCollided);
    void Restart();
};