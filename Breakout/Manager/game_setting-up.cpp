/*******************************************************************
 ** This code is part of Breakout.
 **
 ** Breakout is free software: you can redistribute it and/or modify
 ** it under the terms of the CC BY 4.0 license as published by
 ** Creative Commons, either version 4 of the License, or (at your
 ** option) any later version.
 ******************************************************************/
#include "game_setting-up.hpp"
#include "resource_manager.hpp"
#include "sprite_renderer.hpp"

SpriteRenderer  *Renderer;

Game::Game(GLuint width, GLuint height)
: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
    
}

Game::~Game()
{
    delete Renderer;
}

void Game::Init()
{
    // 加载着色器
    ResourceManager::LoadShader("Shaders/sprite.vert", "Shaders/sprite.frag", nullptr , "sprite");
    // Configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // Load textures
    ResourceManager::LoadTexture("Sources/Textures/awesomeface.png", GL_TRUE, "face");
    // Set render-specific controls
    Shader shader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(shader);
}

void Game::Update(GLfloat dt)
{
    
}


void Game::ProcessInput(GLfloat dt)
{
    
}

void Game::Render()
{
    Texture2D textrue = ResourceManager::GetTexture("face");
    Renderer->DrawSprite(textrue, glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}
