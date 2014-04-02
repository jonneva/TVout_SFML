/*
  Hackvision Controller library
  Copyright (C) 2010 nootropic design, LLC
  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
*/

/*
 Controller.h ported to SFML modified portions Copyright (c) 2014 Jonne Valola
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



#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <SFML/Graphics.hpp>
#include "ButtonController.h"
#include "wrapper.h"

bool keyLeft, keyRight, keyUp, keyDown, keyFire;

ButtonController::ButtonController() {
  init(3, 2, 4, 5, 10);
}

ButtonController::ButtonController(uint8_t left, uint8_t right, uint8_t up, uint8_t down, uint8_t fire) {
  init(left, right, up, down, fire);
}


void ButtonController::init(uint8_t left, uint8_t right, uint8_t up, uint8_t down, uint8_t fire) {
  this->leftPin = left;
  this->rightPin = right;
  this->upPin = up;
  this->downPin = down;
  this->firePin = fire;
}


uint8_t ButtonController::leftPressed(void) {
if (pollLeft()) return 1;
}

uint8_t ButtonController::rightPressed(void) {
if (pollRight()) return 1;
}

uint8_t ButtonController::upPressed(void) {
if (pollUp()) return 1;
}

uint8_t ButtonController::downPressed(void) {
  if (pollDown()) return 1;
}

uint8_t ButtonController::firePressed(void) {
  if (pollFire()) return 1;
return 0;
}


// Preinstantiate default ButtonController object for the integrated controller
ButtonController Controller = ButtonController();

