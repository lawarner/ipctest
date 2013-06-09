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

// CommandRunner.cpp
//
//#define LOGLIBFILE "/dev/tty"
//#define LOGLEVEL   Warning

#include "CommandRunner.h"
#include "Log.h"
#include "RunContext.h"
#include "TestBase.h"

using namespace ipctest::uitext;
using namespace std;

// This needs to be declared once in a program
LOGINIT


CommandRunner::CommandRunner(const std::string& defsFile, const std::string& testFile)
    : defsFile_(defsFile)
    , testFile_(testFile)
    , context_(*new ipctest::RunContext)
    , testBase_(*new ipctest::TestBase)
{

}

CommandRunner::~CommandRunner()
{
    delete &testBase_;
    delete &context_;
}

bool CommandRunner::setup()
{
    bool ret = false;

    if (defsFile_.empty() || testFile_.empty())
        return ret;

    // Open definitions
    if (!testBase_.readIpcDefs(defsFile_))
        return ret;

    // Open test file
    if (testBase_.deserialize(testFile_))
    {
        CommandList& commandList = testBase_.commandList();
        LOG << "Read in " << commandList.size() << " commands." << endl;
        ret = true;
    }

    LOG << "command runner setup suceeded = " << boolalpha << ret << endl;

    return ret;
}


bool CommandRunner::run()
{
    CommandList& commands = testBase_.commandList();
    if (!commands.empty())
    {
        context_.setCommands(&commands);
        ipctest::CommandIterator it = context_.getCommandIterator();
        for ( ; it != commands.end(); ++it)
        {
            ipctest::Command* cmd = *it;
            context_.setCommandIterator(it);
            LOG << "Execute from run:" << std::endl;
            cmd->execute(context_);
            it = context_.getCommandIterator();
        }
    }

    return true;
}

