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

#ifndef PRU_HPP
#define	PRU_HPP

class Pru {
        /**
     * Get the number of general purpose for a PRU
     * @return number of general purpose registers for this PRU
     */
    virtual int getNumGpRegisters(void) = 0;

    /**
     * Get a block of registers
     * @return number of registers retrieved, or -1 on error
     */
    virtual int getGpRegisters(int startReg, int count, u_int32_t [] dst) = 0;

    /**
     * Set some general purpose registers
     * @return number of registers written, -1 on error
     */
    virtual int setGpRegisters(int startReg, int count, u_int3_t [] src) = 0;

    /**
     * Get size (in 32-bit words) of the instruction memory
     * @return 
     */
    virtual int getImemSize() = 0;

    /**
     * Get size (number of 32-bit words) of data memory
     * @return 
     */
    virtual int getDmemSize() = 0;

    /**
     * Get size (number of 32-bit words) of shared memory - that shared
     * between all the PRUs in this PRUSS
     * @return 
     */
    virtual int getSharedDmemSize() = 0;


    /**
     * Get a block of instruction memory
     * @return 
     */
    virtual int getImem(int startAddr, int endAddr, u_int32_t [] dest) = 0;

    /**
     * Set a block of instruction memory
     * @return 
     */
    virtual int setImem(int startAddr, int endAddr, u_int32_t [] dest) = 0;

    /**
     * Get a block of data memory
     * @return 
     */
    virtual int getDmem(int pruNum, int startAddr, int endAddr, u_int32_t [] dest) = 0;

    /**
     * Set a block of data memory
     * @return 
     */
    virtual int setDmem(int startAddr, int endAddr, u_int32_t [] dest) = 0;

    
    /**
     * Get a block of shared data memory
     * @return 
     */
    virtual int getSharedDmem(int startAddr, int endAddr, u_int32_t [] dest) = 0;

    
    /**
     * Set a block of shared data memory
     * @return 
     */
    virtual int setSharedDmem(int startAddr, int endAddr, u_int32_t [] dest) = 0;
    

    /**
     * Start the PRU (releases it from reset)
     * @return 
     */
    virtual int start(void) =0;
    
    /**
     * Stop the PRU (puts it in reset, which resets the PC)
     * @return 
     */
    virtual int stop(void) =0;
    
    /**
     * Single step the CPU from the current PC
     * @return 
     */
    virtual int step(void) =0;

    /**
     * Reset the CPU
     */
    virtual int reset(void) =0;
    
    /**
     * Enable or disable counting mode
     * @param counting
     */
    virtual void setCycleCountingMode(bool counting) =0;
    
    /**
     * Get whether or not counting mode is on
     * @return 
     */
    virtual bool getCycleCountingMode(void) =0;
    
    
    /**
     * Get the cycle count register
     * @return 
     */
    virtual u_int32_t getCycleCount(void) =0;
    
    /**
     * Get the current program counter
     * @return 
     */
    virtual u_int32_t getProgramCounter(void) =0;
    
    
    /**
     * Get the current value of the PRU status register.  This may
     * be broken out into multiple methods later.
     * @return 
     */
    virtual u_int32_t getStatus(void) =0;
    
};


#endif	/* PRU_HPP */

