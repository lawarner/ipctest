#pragma once

/*
   Copyright (C) 2013
   Andy Warner
   This file is part of the ipctest testing utility.

   The sockstr class library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The sockstr class library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the sockstr library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

//
// Define convenience logging functions and macros

// TODO: LOG should only output when DEBUG is defined.  Other
//       options could make check to write to a file, socket, etc.
//
// This is limited to lib and app logs currently, but it will be expanded
// to allow any number of separate logger.

#include <fstream>
#include <iostream>

/**
 * Log levels
 */
enum CLogLevel
{
    Trace,
    Debug,
    Info,
    Warning,
    Error,
    Fatal
};

extern CLogLevel _cloglevel;
extern std::ostream& _capplog;
extern std::ostream& _cliblog;
extern std::ostream& _cnullog;


// The default configuration is to Warning log level and to 
// have app logging to terminal and suppress lib logging.
#ifndef LOGLEVEL
# define LOGLEVEL Warning
#endif
#ifndef LOGAPPFILE
# define LOGAPPFILE "/dev/tty"
#endif
#ifndef LOGLIBFILE
# define LOGLIBFILE "/dev/null"
#endif

// Do static initialization to set up log.  This must be declared once
// in the program.
#define LOGINIT \
    CLogLevel _cloglevel(LOGLEVEL); \
    std::ostream& _capplog = *new std::ofstream(LOGAPPFILE); \
    std::ostream& _cliblog = *new std::ofstream(LOGLIBFILE); \
    std::ostream& _cnullog = *new std::ofstream("/dev/null");


#define LOGA _capplog
#define LOGL _cliblog
#ifndef LOG
# define LOG LOGA
#endif

#define LOGLN(LEVEL) ((LEVEL < _cloglevel) ? _cnullog : _cliblog)
#define LOGN(LEVEL)  ((LEVEL < _cloglevel) ? _cnullog : _capplog)

#define LOGLT LOGLN(Trace)
#define LOGLD LOGLN(Debug)
#define LOGLE LOGLN(Error)

namespace ipctest
{

// Class 
class Logger
{
public:
    static std::ostream& clog();

    // Simple stream manipulators
    static std::ostream& prefix(std::ostream& os);
    static std::ostream& postfix(std::ostream& os);

protected:
    static bool inited_;
    static std::ofstream clog_;

private:
    Logger();
};

}  // namespace ipctest
