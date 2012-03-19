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
#include "RegisterPane.hpp"
#include "Layout.hpp"

RegisterPane::RegisterPane() {
    data_valid = false;
}

void
RegisterPane::setDataValid(bool valid) {
    data_valid = valid;
}

void
RegisterPane::redraw(WINDOW *w) {

    int y = 1;
    y = paintAllRegisters(w, y);
    y = paintControl(w, y + 1);
    y = paintCycles(w, y + 1);
    y = paintStalls(w, y);
    y = paintPC(w, y);
    wrefresh(w);
}

void
RegisterPane::paintRegister(WINDOW *w, int y, int regNum) {
    int x;
    if (regNum < 16) {
        x = 1;
        y = y + regNum + 1;
    } else {
        x = 17;
        y = y + regNum - 16 + 1;
    }

    wattron(w, A_BOLD);
    mvwprintw(w, y, x, "r%-2d", regNum);
    wattroff(w, A_BOLD);

    if (data_valid) {
        wprintw(w, " %08x", r[regNum]);
    } else {
        wprintw(w, " --------", r[regNum]);
    }

    return;
}

int
RegisterPane::paintAllRegisters(WINDOW* w, int start) {
    for (int i = 0; i < NUM_REGS; ++i) {
        paintRegister(w, start, i);
    }

    return start + (NUM_REGS / 2);
}

int
RegisterPane::paintControl(WINDOW * w, int y) {
    wattron(w, A_BOLD);
    mvwprintw(w, ++y, 1, "CONTROL");
    wattroff(w, A_BOLD);

    if (data_valid) {
        wprintw(w, " %08x\n", control);
    } else {
        wprintw(w, " --------\n");
    }

    if (data_valid) {
        /* running or halted */
        mvwprintw(w, ++y, 5, "STATE.......%s", control & 0x00008000 ? "RUN" : "HALTED");
        mvwprintw(w, ++y, 5, "STEP........%s", control & 0x0100 ? "ON" : "OFF");
        mvwprintw(w, ++y, 5, "COUNT.......%s", control & 0x0008 ? "ON" : "OFF");
        mvwprintw(w, ++y, 5, "SLEEP.......%s", control & 0x0004 ? "ON" : "OFF");
        mvwprintw(w, ++y, 5, "PROCESSOR...%s", control & 0x0002 ? "ENABLED" : "DISABLED");
        mvwprintw(w, ++y, 5, "RESET.......%s", control & 0x0001 ? "RUN" : "RESET");
    }

    return y;
}

int
RegisterPane::paintCycles(WINDOW* w, int y) {
    wattron(w, A_BOLD);
    mvwprintw(w, ++y, 1, "CYCLES: ");
    wattroff(w, A_BOLD);
    wprintw(w, "%08x", cycles);
    
    return y;
}

int
RegisterPane::paintStalls(WINDOW* w, int y) {
    wattron(w, A_BOLD);
    mvwprintw(w, ++y, 1, "STALLS: ");
    wattroff(w, A_BOLD);
    wprintw(w, "%08x", stalls);
    
    return y;
}

int
RegisterPane::paintPC(WINDOW* w, int y) {
    wattron(w, A_BOLD);
    mvwprintw(w, ++y, 1, "    PC: ");
    wattroff(w, A_BOLD);
    wprintw(w, "%08x", status & 0xFFFF);
    
    return y;
}