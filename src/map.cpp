#include "map.h"
using namespace std;
Map::Map(){
    x = -10;
    int type = GetRandomValue(0, 3);
    short height = laneFactory.GetHeight(type);
    MovingLane x((Vector2){-10, GetScreenHeight() + 10}, type, height);
    lane.push_back(x);
    while (lane.back().isLastInScreen()){
        int type = GetRandomValue(0, 3);
        short height = laneFactory.GetHeight(type);
        MovingLane x((Vector2){-10, lane.back().position.y - height}, type, height);
        lane.push_back(x);
    }
}
void Map::Move(float p){
    for (int i = 0; i < lane.size(); i ++){
        lane[i].Move(p);
    }
}
void Map::Fill(){
    if (lane[0].isOutOfScreen()){
        lane.erase(lane.begin());
    }
    if (lane.back().isLastInScreen()){
        int type = GetRandomValue(0, 3);
        short height = laneFactory.GetHeight(type);
        MovingLane x1((Vector2){x, lane.back().position.y - height}, type, height);
        lane.push_back(x1);
    }
}
void Map::Draw(int TrafficLight){
    for (int i = 0; i < lane.size(); i ++){
        lane[i].Draw(laneFactory, objectFactory, TrafficLight);
    }
}
void Map::MoveObjectX(int TrafficLight){
    for (int i = 0; i < lane.size(); i ++){
        lane[i].MoveObjectX(TrafficLight);
    }
}