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
#include "Prude.hpp"
#include "RegisterPane.hpp"
#include "Layout.hpp"

Prude::Prude() {
}

Prude::Prude(const Prude& orig) {
}

Prude::~Prude() {
}

void
Prude::run() {

    int ch;

    rw.setDataValid(true);
    
    initscr();
    cbreak();
    noecho();
    redrawAll();

    while ((ch = getch()) != 'q') {
        switch (ch) {
            case KEY_RESIZE:
                redrawAll();
                break;
                
            case '0':
                setPru(0);
                break;
                
            case '1':
                setPru(1);
                break;
        }

    }


    l.destroyAll();
    endwin(); /* End curses mode		  */
}

void
Prude::redrawAll() {
    l.redraw();
    rw.redraw(l.getWindow(Layout::REGS));
    refresh();
}

void
Prude::setPru(int num)
{
    WINDOW *w = l.getWindow(Layout::STATUS);
    wattron(w, A_BOLD);
    mvwprintw(w, 0, 0, "   *** PRU %d ***", num);
    wattroff(w, A_BOLD);
    wrefresh(w);
}
