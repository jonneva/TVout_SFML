/*
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
#include "TVout.h"

extern void refresh();
extern void TVsetup();
extern int pollEvent();
extern int pollFire();
extern int pollLeft();
extern int pollRight();
extern int pollUp();
extern int pollDown();

extern TVout TV;
extern sf::Texture TVtexture;
extern sf::Sprite TVsprite;
extern unsigned int windowWidth, windowHeight, viewWidth, viewHeight;
extern float viewZoom;
extern sf::RectangleShape myPixel;
extern sf::RenderWindow window;
extern sf::View tv;
extern sf::Event event;
extern bool keyLeft, keyRight, keyUp, keyDown, keyFire;

#define PI 3.14159265
