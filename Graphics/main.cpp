// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "core.h"
#include "helper.h"
#include "mathLib.h"
#include "painter.h"
#include <iostream>
#include <vector>

Painter painter;

bool Update(float dt) // deltaTime
{
    bool quit = false;
    quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);

    painter.Update(dt);

    return quit;
}

void Draw(Core::Graphics& graphics)
{
    graphics.SetColor(RGB(rand() % 255, rand() % 255, rand() % 255)); // 4 bytes (a, b, g, r)

    painter.Draw(graphics);
}

int main()
{
    char name[] = "Maple";
    Core::Init(name, 800, 600, 120);
    Core::RegisterUpdateFn(Update);
    Core::RegisterDrawFn(Draw);
    Core::GameLoop();
    Core::Shutdown();

    std::cout << "Hello World!\n";
}

