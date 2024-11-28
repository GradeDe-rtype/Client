/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "RType.hpp"

float speed = 15;

/*  ---- FUNCTION ---- */
void handleEvent(gd::Window &window, gd::Event &event, gd::Shape &shape)
{
    bool orientationReset = true;

    if (event.close()) window.close();
    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Escape)) window.close();
    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Up)) {
        shape.move({0, -speed});
        shape.setRotation(-20);
        orientationReset = false;
    }
    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Down)) {
        shape.move({0, speed});
        shape.setRotation(20);
        orientationReset = false;
    }
    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Left)) {
        shape.move({-speed, 0});
    }
    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Right)) {
        shape.move({speed, 0});
    }
    if (orientationReset) shape.setRotation(0);
    if (event.joyStick().isConnected()) {
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::A)) shape.setFillColor(gd::Color::Red);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::B)) shape.setFillColor(gd::Color::Green);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::X)) shape.setFillColor(gd::Color::Blue);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::Y)) shape.setFillColor(gd::Color::Yellow);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::LB)) shape.setFillColor(gd::Color::Magenta);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::RB)) shape.setFillColor(gd::Color::Cyan);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::Home)) window.close();
        if (event.joyStick().isJoyStickMoved()) {
            gd::Vector2<float> move = {0, 0};
            if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LX)) {
                float percent = event.joyStick().getAxisPosition(gd::JoyStick::Axis::LX) / 100;
                move.x = speed * percent;
            }
            if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LY)) {
                float percent = event.joyStick().getAxisPosition(gd::JoyStick::Axis::LY) / 100;
                move.y = speed * percent;
            }
            shape.move(move);
        }
    }
    if (event.mouse().getButtonState(gd::Mouse::Button::Left)) {
        gd::Vector2<int> mouse = event.mouse().getPosition(window);
        shape.setPosition({ (float)(mouse.x - shape.getSize().x / 2), (float)(mouse.y - shape.getSize().y / 2) });
    }
}

void graphique(void)
{
    srand(time(NULL));
    gd::Window window;
    window.create(800, 600, "R-Type");
    gd::Event event;
    gd::Time time;

    float size = 40;
    gd::Shape shape({{0, 0}, {size, size / 2}, {0, size}, {size / 4, size / 2}});
    shape.setOrigin({size / 2, size / 2});

    shape.setFillColor(gd::Color::Transparent);
    shape.setOutlineColor(gd::Color::White);
    shape.setOutlineThickness(5);
    shape.setPosition({ (float)(window.getWidth() / 2 - shape.getSize().x / 2), (float)(window.getHeight() / 2 - shape.getSize().y / 2) });

    while (window.isOpen()) {
        if (time.getElapsedTime() < gd::FrameRate::get().fps()) continue;
        time.reset();
        window.pollEvent(event);
        handleEvent(window, event, shape);
        window.clear(gd::Color::Black);

        shape.draw(window);
        window.display();
    }
    window.close();
}
