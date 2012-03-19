#
# PRU Debugger
# Copyright (C) 2012 Christopher Piggott
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#

#CC=/usr/local/angstrom/arm/bin/arm-angstrom-linux-gnueabi-g++ 
CC=g++

LDFLAGS+=-lncurses

TARGET=prude

OBJS=main.o RegisterWindow.o Layout.o
DEPDIR=deps
OBJDIR=objs

OBJSTMP = $(patsubst %.cc,%.o,$(wildcard *.cc))
OBJS = $(patsubst %,$(OBJDIR)/%,$(OBJSTMP))
DEPS = $(patsubst %.o,$(DEPDIR)/%.d,$(OBJSTMP))

all: init $(TARGET)
	

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)


init:
	@mkdir -p $(DEPDIR)
	@mkdir -p $(OBJDIR)

clean:
	rm -f ${OBJDIR}/*.o ${DEPDIR}/*.d prudebug


-include $(DEPS)

$(OBJDIR)/%.o : %.cc
	$(CC) $(DEFINES) $(CFLAGS) $(INCPATH) -o $@ -c $<
	$(CC) -MM -MT $(OBJDIR)/$*.o $(DEFINES) $(CFLAGS) $(INCPATH) $*.cc > $(DEPDIR)/$*.d


