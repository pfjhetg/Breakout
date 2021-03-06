/*******************************************************************
 ** This code is part of Breakout.
 **
 ** Breakout is free software: you can redistribute it and/or modify
 ** it under the terms of the CC BY 4.0 license as published by
 ** Creative Commons, either version 4 of the License, or (at your
 ** option) any later version.
 ******************************************************************/
#ifndef GAME_H
#define GAME_H

#include "game_level.hpp"
#include "resource_manager.hpp"
#include "sprite_renderer.hpp"
#include "game_object.hpp"
#include "game_level.hpp"
#include "particle_generator.hpp"
#include "post_processor.hpp"
#include "power_up.hpp"
#include <tuple>
#include "text_renderer.hpp"

#include "irrKlang.h"
using namespace irrklang;
#pragma comment(lib, "irrKlang.lib")

// 代表了游戏的当前状态
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

enum Direction {
    COLLISITION_UP,
    COLLISITION_RIGHT,
    COLLISITION_DOWN,
    COLLISITION_LEFT
};

typedef std::tuple<GLboolean, Direction, glm::vec2> Collision;

// Initial size of the player paddle
const glm::vec2 PLAYER_SIZE(100, 20);
// Initial velocity of the player paddle
const GLfloat PLAYER_VELOCITY(500.0f);
// Initial velocity of the Ball
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// Radius of the ball object
const GLfloat BALL_RADIUS = 12.5f;

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    // Game state
    GameState              State;
    GLboolean              Keys[1024];
    GLboolean              KeysProcessed[1024];
    GLuint                 Width, Height;
    std::vector<GameLevel> Levels;
    GLuint                 Level;
    std::vector<PowerUp>   PowerUps;
    GLuint                 Lives;
    // Constructor/Destructor
    Game(GLuint width, GLuint height);
    ~Game();
    // Initialize game state (load all shaders/textures/levels)
    void Init();
    // GameLoop
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
    void DoCollisions();
    
    // Reset
    void ResetLevel();
    void ResetPlayer();
    // Powerups
    void SpawnPowerUps(GameObject &block);
    void UpdatePowerUps(GLfloat dt);
    void ActivatePowerUp(PowerUp &powerUp);
};

#endif
