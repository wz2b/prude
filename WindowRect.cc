/*
 * PRU Debugger
 * Copyright (C) 2012 Christopher Piggott
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "WindowRect.hpp"

WindowRect::WindowRect() {
}

WindowRect::WindowRect(const WindowRect& orig) {
    x = orig.x;
    y = orig.y;
    width = orig.width;
    height = orig.height;
}

WindowRect::~WindowRect() {
}

void
WindowRect::setWidth(int newWidth) {
    width = newWidth;
}

void
WindowRect::setHeight(int newHeight) {
    height = newHeight;
}

void
WindowRect::setX(int newX) {
    x = newX;
}

void
WindowRect::setY(int newY) {
    y = newY;
}

int
WindowRect::getHeight() const {
    return height;
}

int
WindowRect::getWidth() const {
    return width;
}

int
WindowRect::getX() const {
    return x;
}

int
WindowRect::getY() const {
    return y;
}
