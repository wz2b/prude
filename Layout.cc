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

#include <ncurses.h>
#include <string>
#include <iostream>
#include <memory>
#include "Layout.hpp"

using namespace std;

Layout::Layout() {
    statusWindow = NULL;
    memWindow = NULL;
    codeWindow = NULL;
    registersWindow = NULL;
}

Layout::Layout(const Layout& orig) {
    statusWindow = orig.statusWindow;
    memWindow = orig.memWindow;
    codeWindow = orig.codeWindow;
    registersWindow = orig.registersWindow;

}

Layout::~Layout() {
}

/**
 * Calculate the position of all the windows
 */
void
Layout::calcWindowGeometries() {

    int statusW, statusH, statusX, statusY;
    int codeW, codeH, codeX, codeY;
    int memW, memH, memX, memY;
    int regW, regH, regX, regY;

    destroyAll();
    /*
     * The register window is 16 rows x 2 columns
     * Each column has a label (e.g. r31) plus a space
     * plus a value (8 bytes of hex digits)
     */
    regW = 31;
    regH = LINES;
    regY = 0;
    regX = COLS - regW;
    registersWindow = newwin(regH, regW, regY, regX);


    statusH = 2;
    statusW = COLS - regW;
    statusX = 0;
    statusY = 0;
    statusWindow = newwin(statusH, statusW, statusY, statusX);

    memW = statusW;
    memH = 6;
    memX = 0;
    memY = statusY + statusH;
    memWindow = newwin(memH, memW, memY, memX);

    codeX = 0;
    codeY = memY + memH;
    codeH = LINES - codeY;
    codeW = memW;
    codeWindow = newwin(codeH, codeW, codeY, codeX);
}

void
Layout::drawBorders() {
    box(registersWindow, 0, 0);
    mvwprintw(registersWindow, 0, 2, "Registers");
    wrefresh(registersWindow);

    box(memWindow, 0, 0);
    mvwprintw(memWindow, 0, 2, "Data Memory");
    wrefresh(memWindow);

//    box(statusWindow, 0, 0);
//    mvwprintw(statusWindow, 0, 2, "PRU Status");
    wrefresh(statusWindow);

    box(codeWindow, 0, 0);
    mvwprintw(codeWindow, 0, 2, "Instruction Memory");
    wrefresh(codeWindow);
}

void
Layout::redraw() {
    refresh();
    calcWindowGeometries();

    wclear(statusWindow);
    wclear(memWindow);
    wclear(codeWindow);
    wclear(registersWindow);

    drawBorders();
    refresh();
}

WINDOW *
Layout::getWindow(WindowType type) const {
    switch (type) {
        case MEM:
            return memWindow;
        case REGS:
            return registersWindow;
        case CODE:
            return codeWindow;
        case STATUS:
            return statusWindow;
        default:
            return NULL;
    }
}

void
Layout::destroyAll() {
    if (registersWindow != NULL) {
        delwin(registersWindow);
        registersWindow = NULL;
    }

    if (statusWindow != NULL) {
        delwin(statusWindow);
        statusWindow = NULL;
    }
    
    if (memWindow != NULL) {
        delwin(memWindow);
        memWindow = NULL;
    }
    if (codeWindow != NULL) {
        delwin(codeWindow);
        codeWindow = NULL;
    }
}
