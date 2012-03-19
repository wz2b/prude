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
#ifndef WINDOWRECT_HPP
#define	WINDOWRECT_HPP

class WindowRect {
public:
    WindowRect();
    WindowRect(const WindowRect& orig);
    virtual ~WindowRect();
    
    int getWidth() const;
    int getHeight() const;
    int getX() const;
    int getY() const;
    
    void setWidth(int newWidth);
    void setHeight(int newHeight);
    void setX(int newX);
    void setY(int newY);
    
private:
    int x;
    int y;
    int width;
    int height;
};

#endif	/* WINDOWRECT_HPP */

