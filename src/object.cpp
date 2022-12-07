#include "object.h"
using namespace std;
void ObjectFactory::Draw(int typeLane, int type, Vector2 position, bool isLeft){
    object[typeLane][type].Draw(position, isLeft);
}
Object::~Object(){
    UnloadTexture(PicLeft);
    UnloadTexture(PicRight);
}
Object::Object(string TypeOfObject){
    string FilePath = "../data/image/Object/" + TypeOfObject;
    PicLeft = LoadTexture((FilePath + "Left.png").c_str());
    PicRight = LoadTexture((FilePath + "Right.png").c_str());
}
void Object::Draw(Vector2 position, bool isLeft){
    if (isLeft){
        DrawTextureEx(PicLeft, position, 0.0f, 2.0f, WHITE);
    }
    else{
        DrawTextureEx(PicRight, position, 0.0f, 2.0f, WHITE);
    }
}

MovingObject::MovingObject(Vector2 position, int typeLane, int type, bool isLeft){
    this->position = position;
    this->typeLane = typeLane;
    this->type = type;
    this->isLeft = isLeft;
}
void MovingObject::Draw(ObjectFactory& objectFactory, int TrafficLight){
    if (type >= 10){
        objectFactory.Draw(0, 10 + TrafficLight, position, true);
    }
    else 
    objectFactory.Draw(typeLane, type, position, isLeft);
}
void MovingObject::Move(float p){
    position.y += p;
}
void MovingObject::MoveX(int TrafficLight){
    if (type > 9) return;
    int p1 = 0;
    // Check the speed of every object
    // if...
    if (typeLane == 0){
        if (TrafficLight == LIGHT_YELLOW) p1 = 4;
        else if (TrafficLight == LIGHT_RED) p1 = 0;
        else 
        p1 = 8;
    }
    else if (typeLane == 2) p1 = 2;
    else if (typeLane == 3) p1 = 3;
    if (isLeft) p1 *= -1;
    position.x += p1;
    // check outside screen and comeback to the beginning
    if (isLeft && position.x < -340) position.x = GetScreenWidth() + 10;
    if (!isLeft && position.x > GetScreenWidth() + 10) position.x = -340;
}