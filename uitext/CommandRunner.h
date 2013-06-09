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

#ifndef _COMMANDRUNNER_H_INCLUDED_
#define _COMMANDRUNNER_H_INCLUDED_
//
//

//
// INCLUDE FILES
//
#include <string>
#include <vector>


namespace ipctest
{

// FORWARD CLASS DECLARATIONS
class Command;
class RunContext;
class TestBase;
typedef std::vector<Command *> CommandList;


namespace uitext
{
//
// MACRO DEFINITIONS
//
#ifndef DllExport
#define DllExport
#endif

//
// TYPE DEFINITIONS
//

// FORWARD CLASS DECLARATIONS

//
// CLASS DEFINITIONS
//

//
class CommandRunner
{
public:
    CommandRunner(const std::string& defsFile, const std::string& testFile);

    virtual ~CommandRunner();

    bool setup();
    bool run();

private:
    CommandRunner(const CommandRunner&);	// disable copy constructor
    CommandRunner& operator=(const CommandRunner& rSource);	// disable assignment operator

    // The list of commands is stored in a std::list.  For many GUI toolkits (GTK included)
    // the list will also be stored inside the widget internally.
    CommandList commands_;

    std::string defsFile_;
    std::string testFile_;
    ipctest::RunContext& context_;
    ipctest::TestBase&   testBase_;
};

}  // namespace uitext
}  // namespace ipctest

#endif
