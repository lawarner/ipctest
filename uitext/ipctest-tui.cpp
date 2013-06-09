/*
   Copyright (C) 2012, 2013
   Andy Warner
   This file is part of the sockstr class library.

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

// ipctest-tui.cpp
//
// This is a testing tool used to create and execute various collections
// of tests.  The underlying IPC mechanism uses the sockstr library.

#include <cerrno>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sockstr/sstypes.h>
#include <sockstr/Socket.h>
#include "CommandRunner.h"
#include "Parser.h"

using namespace sockstr;
using namespace std;
using namespace ipctest;

struct TParams
{
    string ipcDefsFile;
    string testFilename;
};


bool client_process(TParams* params)
{
    bool ret = true;

    uitext::CommandRunner* runner
        = new uitext::CommandRunner(params->ipcDefsFile, params->testFilename);

    ret = runner->setup();
    if (ret)
        ret = runner->run();
    else
        std::cerr << "Unable to setup command runner." << endl;

    delete runner;
    return ret;
}


int main(int argc, const char* argv[])
{
    std::cout << "Program ipctest-tui start." << std::endl;
    TParams params;
    params.ipcDefsFile  = "../examples/t";
    params.testFilename = "../examples/t.its";

#if 0
    if (argc < 2)
    {
        std::cerr << "Usage: ipctest-tui <ipcdef_filename> <testcase>" << std::endl;
        return 1;
    }
#endif
    if (argc > 1)
        params.ipcDefsFile = argv[1];
    if (argc > 2)
        params.testFilename = argv[2];

    std::cout << "Defs=" << params.ipcDefsFile
              << ", testcase=" << params.testFilename << std::endl;

    client_process(&params);

    return 0;
}
