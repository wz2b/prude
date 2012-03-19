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

#ifndef LAYOUT_HPP
#define	LAYOUT_HPP

#include <string>
#include <ncurses.h>
#include "WindowRect.hpp"

class Layout {
public:
    Layout();
    Layout(const Layout& orig);
    virtual ~Layout();
    void redraw();
    
    enum WindowType { STATUS, MEM, CODE, REGS };
    WINDOW * getWindow(WindowType type) const;
    
    void destroyAll();
    
    
private:
    WINDOW * statusWindow;
    WINDOW * registersWindow;
    WINDOW * memWindow;
    WINDOW * codeWindow;
    void calcWindowGeometries();
    void drawBorders();
};

#endif	/* LAYOUT_HPP */

