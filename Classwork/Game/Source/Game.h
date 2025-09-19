#pragma once

#include "Framework.h"

class Game : public fw::GameCore
{
public:
    Game();
    virtual ~Game();

    virtual void update(float deltaTime) override;
    virtual void draw() override;

public:
    fw::Mesh* m_pMesh1;
    fw::Mesh* m_pMesh2;
};
