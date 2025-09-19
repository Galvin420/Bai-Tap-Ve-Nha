#pragma once

namespace fw
{
    class GameCore
    {
    public:
        GameCore() {}
        virtual ~GameCore() {}

        virtual void update(float deltaTime) = 0;
        virtual void draw() = 0;
    };
} // namespace fw
