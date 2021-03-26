#pragma once
#include "GameController.h"
#include "GPU2D.h"
#include "GameLevel.h"
class Level1 :
    public GameLevel
{
    float ySpeed;
    float yPos;
    SpriteSheet* sprite;

public:
    void Load() override;
    void UnLoad() override;
    void Update() override;
    void Render() override;
};

