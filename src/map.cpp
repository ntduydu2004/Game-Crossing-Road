#include "map.h"
using namespace std;
Map::Map(){
    lane.clear();
    x = -10;
    int type = GetRandomValue(0, 3);
    if (type == 2) type = 3;
    short height = laneFactory.GetHeight(type);
    MovingLane x((Vector2){-10, GetScreenHeight() + 10}, type, height, 0);
    lane.push_back(x);
    while (lane.back().isLastInScreen()){
        int type = GetRandomValue(0, 3);
        if (type == 2) type = 3;
        short height = laneFactory.GetHeight(type);
        prevType = type;
        MovingLane x((Vector2){-10, lane.back().position.y - height}, type, height, 0);
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
        int ChangeDirect = 0;
        if (type == prevType && type == 2){
            bool isLeft = lane.back().GetDirection();
            if (isLeft == 0) ChangeDirect = 1;
            else ChangeDirect = -1;
        }
        short height = laneFactory.GetHeight(type);
        MovingLane x1((Vector2){x, lane.back().position.y - height}, type, height, ChangeDirect);
        lane.push_back(x1);
        prevType = type;
    }
}
void Map::Draw(int TrafficLight){
    for (int i = (int)lane.size() - 1; i >= 0; i --){
        lane[i].Draw(laneFactory, objectFactory, TrafficLight);
    }
}
void Map::MoveObjectX(int TrafficLight, float IncreaseSpeed){
    for (int i = 0; i < lane.size(); i ++){
        lane[i].MoveObjectX(TrafficLight, IncreaseSpeed);
    }
}
void Map::Follow(Vector2& position, float IncreaseSpeed){
    for (int i = 0; i < lane.size(); i++){
        if (lane[i].position.y < position.y + 60 && lane[i].position.y + lane[i].GetHeight() > position.y + 60){
            lane[i].Follow(position, IncreaseSpeed);
            break;
        }
    }
}
void Map::CheckCollisionObject(Vector2& position, bool& isCollided){
    for (int i = 0; i < lane.size(); i ++){
        if (isCollided) return;
        lane[i].CheckCollisionObject(objectFactory ,position, isCollided);
    }
}
void Map::Restart(){
    lane.clear();
    x = -10;
    int type = GetRandomValue(0, 3);
    if (type == 2) type = 3;
    short height = laneFactory.GetHeight(type);
    MovingLane x((Vector2){-10, GetScreenHeight() + 10}, type, height, 0);
    lane.push_back(x);
    while (lane.back().isLastInScreen()){
        int type = GetRandomValue(0, 3);
        if (type == 2) type = 3;
        short height = laneFactory.GetHeight(type);
        MovingLane x((Vector2){-10, lane.back().position.y - height}, type, height, 0);
        lane.push_back(x);
        prevType = type;
    }
}
void Map::Load(ifstream& fin){
    lane.clear();
    int numLane;
    fin >> numLane;
    lane.resize(numLane);
    for (int i = 0; i < numLane; i ++){
        lane[i].Load(fin);
    }
}
void Map::Save(ofstream& fout){
    fout << lane.size() << '\n';
    for (int i = 0; i < lane.size(); i ++){
        lane[i].Save(fout);
    }
}