#include "../include/game_objs.h"

GameObjects InitGameObjects() {
    GameObjects game_objects = {0};
    game_objects.player = CreatePlayer();
    game_objects.ball = CreateBall(game_objects.player);
    CreateBricks(game_objects.bricks);

    return game_objects;
}
