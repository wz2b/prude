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

#CXX=/usr/local/angstrom/arm/bin/arm-angstrom-linux-gnueabi-g++ 
CXX=g++

LIBS=-lncurses

TARGET=prude

OBJS=main.o RegisterWindow.o Layout.o
DEPDIR=deps
OBJDIR=objs

OBJSTMP = $(patsubst %.cc,%.o,$(wildcard *.cc))
OBJS = $(patsubst %,$(OBJDIR)/%,$(OBJSTMP))
DEPS = $(patsubst %.o,$(DEPDIR)/%.d,$(OBJSTMP))

all: init $(TARGET)
	

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) ${LIBS} $(LDFLAGS)


init:
	@mkdir -p $(DEPDIR)
	@mkdir -p $(OBJDIR)

clean:
	rm -f ${OBJDIR}/*.o ${DEPDIR}/*.d prudebug


-include $(DEPS)

$(OBJDIR)/%.o : %.cc
	$(CXX) $(DEFINES) $(CFLAGS) $(INCPATH) -o $@ -c $<
	$(CXX) -MM -MT $(OBJDIR)/$*.o $(DEFINES) $(CFLAGS) $(INCPATH) $*.cc > $(DEPDIR)/$*.d


