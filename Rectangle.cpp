#include "Rectangle.h"

Rectangle::Rectangle(Vector2f size)
{
    this->shape = RectangleShape(size);
    this->shape.setFillColor(Color::Green);
    this->speed = Vector2f(1.f, 4.f);
    this->acc = Vector2f(0.f, 1.f);
}

Rectangle::Rectangle(Vector2f size, int x, int y)
{
    this->shape = RectangleShape(size);
    this->shape.setFillColor(Color::Green);
    this->speed = Vector2f(1.f, 4.f);
    this->shape.setPosition(Vector2f(x, y));
    this->acc = Vector2f(0.f, 1.f);
}

void Rectangle::update()
{
    this->speed += this->acc;
    this->shape.move(speed);

    if (this->shape.getPosition().x + this->shape.getSize().x >= 1920 || this->shape.getPosition().x < 0)
    {
        this->speed.x *= -1;
    }
    if (this->shape.getPosition().y + this->shape.getSize().y >= 1000)
    {
        this->speed.y *= -1;
        Vector2f position = this->shape.getPosition();
        this->shape.setPosition(position.x, 1000 - this->shape.getSize().y);
    }
}

void Rectangle::drawTo(RenderWindow &window)
{
    window.draw(this->shape);
}

void Rectangle::click(int x, int y)
{
    if (x > this->shape.getPosition().x && x < (this->shape.getPosition().x + this->shape.getSize().x))
    {
        if (y > this->shape.getPosition().y && y < (this->shape.getPosition().y + this->shape.getSize().y)){
           this->shape.setFillColor(Color::Red); 
        }
    }
}