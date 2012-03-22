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

#ifndef PRUSS_HPP
#define	PRUSS_HPP

#include <stdint.h>
#include "Pru.hpp"

/**
 * Defines the interface to a PRU subsystem
 */
class Pruss {
public:

    /**
     * Get the number of PRUs in this subsystem
     * @return 
     */
    virtual int getNumPrus() = 0;

    /**
     * Get object model for one PRU within the subsystem
     * @param pruNum
     * @return 
     */
    Pru & getPru(int pruNum) =0;
    
    /**
     * Get the revision ID of the PRUSS
     * @return 
     */
    u_int32_t getRevId(void) =0;
    
    /**
     * Get the calue of the SYSCFG register
     * I may break this out into individual pieces later
     * @return 
     */
    u_int32_t getSysConfig(void) =0;
    
    
    /* There are other PRUSS_CFG registers I am ignoring for now. */
    
};


#endif	/* PRUSS_HPP */

