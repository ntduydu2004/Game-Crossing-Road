#include "lane.h"
using namespace std;
void LaneFactory::Draw(int type, Vector2 position){
    lane[type].Draw(position);
}
short LaneFactory::GetHeight(int type){
    return lane[type].GetHeight();
}
Lane::Lane(string TypeOfLane, short height){
    string Filename = "../data/image/Lane/" + TypeOfLane + ".png";
    Pic = LoadTexture(Filename.c_str());
    this->height = height;
}
Lane::~Lane(){
    UnloadTexture(Pic);
}
void Lane::Draw(Vector2 position){
    DrawTextureEx(Pic, position, 0.0f, 1.0f, WHITE);
}
short Lane::GetHeight(){
    return height;
}
MovingLane::MovingLane(Vector2 position, int type, short height){
    this->type = type;
    this->position = position;
    this->height = height;
    numObject = 0;
    numObject = GetRandomValue(1, 5);
    int tmp = 0;
    if (type == 0){
        tmp = GetRandomValue(0, 1);
    }
    else if (type == 1) numObject = 0;
    else if (type == 2) numObject = 1;
    object.clear();
    for (int i = 0; i < numObject; i ++){
        bool isLeft = GetRandomValue(0, 1);
        int x, y;
        if (isLeft){
            x = GetRandomValue(GetScreenWidth() + 950 - i*250, GetScreenWidth() + 1000 - i*250);
            y = position.y + 35;
        }
        else{
            x = GetRandomValue(-1000 + i*250, - 950 + i*250);
            y = position.y + height - 80;
        }
        int typeName;
        if (type == 0){
            typeName = GetRandomValue(0, 9);
        }
        else if (type == 2){
            typeName = GetRandomValue(0, 1);
            y = position.y - 2;
        }
        else if (type == 3)
            typeName = GetRandomValue(0, 6);
        object.push_back(MovingObject((Vector2){x*1.0, y*1.0}, type, typeName, isLeft));
    }
    if (tmp == 1){
        numObject++;
        object.push_back(MovingObject((Vector2){700, position.y - 80 + height}, 0, 10, true));
    }
}
void MovingLane::Draw(LaneFactory& lanefactory, ObjectFactory& objectfactory, int TrafficLight){
    lanefactory.Draw(type, position);
    if (type == 1) return;
    for (int i = 0; i < numObject; i ++){
        object[i].Draw(objectfactory, TrafficLight);
    }

    // object[0].Draw(objectfactory);
}
void MovingLane::Move(float p){
    position.y += p;
    for (int i = 0; i < numObject; i ++){
        object[i].Move(p);
    }
}
short MovingLane::GetHeight(){
    return height;
}
bool MovingLane::isOutOfScreen(){
    return position.y > GetScreenHeight();
}
bool MovingLane::isLastInScreen(){
    return position.y > -700;
}
void MovingLane::MoveObjectX(int TrafficLight){
    for (int i = 0; i < numObject; i ++){
        object[i].MoveX(TrafficLight);
    }
}
void MovingLane::Follow(Vector2& position){
    if (type != 2) return;
    for (int i = 0; i < numObject; i ++){
        object[i].Follow(position);
    }
}
void MovingLane::CheckCollisionObject(ObjectFactory& objectFactory, Vector2& position, bool& isCollided){
    if (this->position.y < position.y + 60 && position.y + 60 < this->position.y + height){
        for (int i = 0; i < numObject; i ++){
            if (isCollided) return;
            object[i].CheckCollisionObject(objectFactory, position, isCollided);
        }
    }
}