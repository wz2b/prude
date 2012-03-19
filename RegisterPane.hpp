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

#ifndef __REGISTERPANE_HPP__
#define __REGISTERPANE_HPP__

#include <ncurses.h>
#include <stdint.h>
#include "Layout.hpp"

class RegisterPane {



public:
	RegisterPane();

	/* Update the data */
	void update();
        void redraw(WINDOW * w);

        static const int NUM_REGS = 32;
        
        void setDataValid(bool);

private:
        void *addr;
        int paintAllRegisters(WINDOW *w, int start);
        int paintControl(WINDOW *w, int start);
        int paintCycles(WINDOW *w, int start);
        int paintStalls(WINDOW *w, int start);
        int paintPC(WINDOW *w, int start);
        
        void paintRegister(WINDOW *w, int start, int regNum);

        uint32_t r[NUM_REGS];
        bool reg_set[NUM_REGS];
        
        uint32_t control;
        uint32_t status;
        uint32_t cycles;
        uint32_t stalls;
        uint32_t wakeup_en;
        
        bool data_valid;
        
};



#endif
