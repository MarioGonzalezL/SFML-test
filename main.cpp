#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#include "Rectangle.h"
#include <vector>

int main()
{
    RenderWindow window(VideoMode(1920, 1000), "SFML works!");
    vector<Rectangle> rectangulos;

    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Right)
                {
                    int w = 50;
                    int h = 50;
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    Rectangle rec(Vector2f(w, h), x, y);
                    rectangulos.push_back(rec);
                }
                 if (event.mouseButton.button == Mouse::Left)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    for(auto &r: rectangulos)
                    {
                        r.click(x,y);
                        
                    }
                }
            }
        }
        window.clear();
        for (auto &r : rectangulos)
        {
            r.update();
            r.drawTo(window);
        }
        window.display();
    }

    return 0;
}