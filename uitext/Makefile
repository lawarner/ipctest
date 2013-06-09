#
#   Copyright (C) 2012
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
SOCKSTR=../../sockstr
INCDIR = $(SOCKSTR)/include
LIBSOCKLIB = $(SOCKSTR)/src/libsockstr.a
LIBIPCDIR = ../libipctest
LIBIPCTEST = $(LIBIPCDIR)/libipctest.a
LIBOPENSSL = -lssl -lcrypto

XMLINC = `pkg-config --cflags expat`
XMLLIB = `pkg-config --libs expat`

DEPLIBS = $(LIBIPCTEST) $(LIBSOCKLIB) $(LIBOPENSSL)

SUBDIRS = 

CC = g++
CCFLAGS = -Wall -g -O0 -DTARGET_LINUX=1 -I$(TOP) -I$(INCDIR) -I$(LIBIPCDIR) $(XMLINC)
DEPCPPFLAGS = $(CCFLAGS)
LDFLAGS = -pthread
LDLIBS = $(XMLLIB)

OBJS := ipctest-tui.o CommandRunner.o

SRCS := $(OBJS:.o=.cpp)

INCS = 

PROGRAMS = ipctest-tui

.cpp.o: ; $(CC) $(CCFLAGS) -c $<


all: $(PROGRAMS) subdirs

ipctest-tui: $(OBJS) $(DEPLIBS)


.PHONY: subdirs
subdirs:
	for dir in $(SUBDIRS); do \
		make -C $$dir; \
	done


.PHONY: clean
clean:
	rm -f $(OBJS) $(PROGRAMS)
	touch -r .mkdep-timestamp .makedepends
	for dir in $(SUBDIRS); do \
		make -C $$dir clean; \
	done

.PHONY: depends
depends: $(SRCS) $(INCS)
	$(CC) -I. $(DEPCPPFLAGS) -MM $(SRCS) > .makedepends
	touch .mkdep-timestamp

.makedepends:
include .makedepends
