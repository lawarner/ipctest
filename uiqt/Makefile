#
#   Copyright (C) 2013
#   Andy Warner
#   This file is part of the sockstr class library.
#
#   The sockstr class library is free software; you can redistribute it and/or
#   modify it under the terms of the GNU Lesser General Public
#   License as published by the Free Software Foundation; either
#   version 2.1 of the License, or (at your option) any later version.
#
#   The sockstr class library is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#   Lesser General Public License for more details.
#
#   You should have received a copy of the GNU Lesser General Public
#   License along with the sockstr library; if not, write to the Free
#   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
#   02111-1307 USA.  */

# Simple makefile for the sockstr class library

TOP = ..
SOCKSTR=$(TOP)/../control-service/sockstr
INCDIR = $(SOCKSTR)/include
LIBSOCKLIB = $(SOCKSTR)/src/libsockstr.a

SUBDIRS = build-ipctest-qt

#CC = g++
#CCFLAGS = -Wall -g -O2 -DTARGET_LINUX=1 -I$(TOP) -I$(INCDIR)
#LDFLAGS = -pthread $(LIBSOCKLIB)

OBJS := 
SRCS := $(OBJS:.o=.cpp)
INCS = 


PROGRAMS = 


.cpp.o: ; $(CC) $(CCFLAGS) -c $<


all: setup $(PROGRAMS) subdirs



.PHONY: setup
setup:
	mkdir -p build-ipctest-qt
	cd build-ipctest-qt; qmake -o Makefile ../ipctest-qt/ipctest-qt.pro


.PHONY: subdirs
subdirs:
	for dir in $(SUBDIRS); do \
		make -C $$dir; \
	done


.PHONY: clean
clean:
	for dir in $(SUBDIRS); do \
		make -C $$dir clean; \
	done


.PHONY: depends
depends:
	for dir in $(SUBDIRS); do \
		make -C $$dir depends; \
	done
