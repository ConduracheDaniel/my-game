#include "gameLogic.h"

bool collisionWithArenaLeftWall(CollisionBox arena, CollisionBox object) {
   
    return object.width.min <= arena.width.min;
}
bool collisionWithArenaRightWall(CollisionBox arena, CollisionBox object) {

    return object.width.max >= arena.width.max;
}
bool collisionWithArenaFloor(CollisionBox arena, CollisionBox object) {
    if (object.hight.max >= arena.hight.max) {
        return true;
    }
    return false;
}
bool collisionWithArenaTop(CollisionBox arena, CollisionBox object) {
    if (object.hight.max <= arena.hight.min) {
        return true;
    }
    return false;
}
bool collisionWithPlayer_Attack(CollisionBox player, CollisionBox object) {
    bool xOverlap = (player.width.min < object.width.max) && (player.width.max > object.width.min);

    bool yOverlap = (player.hight.min < object.hight.max) && (player.hight.max > object.hight.min);

    return xOverlap && yOverlap;
}