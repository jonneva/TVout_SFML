/*
 Based on Arduino TVout library Copyright (c) 2010 Myles Metzer
 http://code.google.com/p/arduino-tvout/

 Arduino TVout port for SFML Copyright (c) 2014 Jonne Valola
 https://github.com/jonneva/TVout_SFML

 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:

 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
*/

#include <SFML/Graphics.hpp>
#include "wrapper.h"
#include "TVout.h"

using namespace std;
using namespace sf;

TVout TV;
sf::Texture TVtexture;
sf::Sprite TVsprite;
sf::RectangleShape myPixel;
RenderWindow window{{windowWidth, windowHeight}, "SFML TVout"};
sf::View tv(sf::FloatRect(0, 0, viewWidth,viewHeight));
sf::Event event;

int pollEvent()
{
window.pollEvent(event);
    if(event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
       window.close();
    return -1;
    }
return 0;
}

int pollFire()
{
window.pollEvent(event);
    if(Keyboard::isKeyPressed(Keyboard::Key::Space)) return 1;
    return 0;
}
int pollLeft()
{
window.pollEvent(event);
    if(Keyboard::isKeyPressed(Keyboard::Key::Left)) return 1;
    return 0;
}
int pollRight()
{
window.pollEvent(event);
    if(Keyboard::isKeyPressed(Keyboard::Key::Right)) return 1;
    return 0;
}
int pollUp()
{
window.pollEvent(event);
    if(Keyboard::isKeyPressed(Keyboard::Key::Up)) return 1;
    return 0;
}
int pollDown()
{
window.pollEvent(event);
    if(Keyboard::isKeyPressed(Keyboard::Key::Down)) return 1;
    return 0;
}


void TVsetup()
{
    window.setFramerateLimit(60);
    myPixel.setSize(sf::Vector2f(1,1));
    myPixel.setFillColor(sf::Color::White);
    tv.zoom(viewZoom);
    tv.setViewport(sf::FloatRect(0, 0, 1, 1));
    window.clear(Color::Black);
    window.setView(tv);
    //sf::Thread update(&updateTV,&window,&tv);
}

void refresh(){
    window.setView(tv);
    window.clear(Color::Black);
    for (int y=0; y < viewHeight; y++) {
        for (int x=0; x < viewWidth; x ++) {
            if (display.screen[x/8+y*display.hres] & (0x80 >>(x&7)))
                {
                    myPixel.setPosition(x,y);
                    window.draw(myPixel);
                }
            }
        }
    window.display();
    pollEvent();
}
