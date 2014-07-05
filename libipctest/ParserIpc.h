/*
   Copyright (C) 2014
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

#ifndef _PARSERIPC_H_INCLUDED_
#define _PARSERIPC_H_INCLUDED_
//

#include "Parser.h"


namespace ipctest
{

//
// Macro Definitions
//
#ifndef DllExport
#define DllExport
#endif

//
// Forward Class Declarations
//

/**
 * Parser for sockstr IPC style messages.
 *
 * At the moment, it is only used to parse the IPC message definitions, which for the
 * first version is a (restrictive) C languange include file.
 * This will be refactored as a MessageParser class.  Probably a new Parser manager
 * class will be added to allow unified parsing (IPC, xml, json, etc.).
 */ 
class ParserIpc : public Parser
{
public:
    /** Create new IPC message parser. */
    ParserIpc();
    virtual ~ParserIpc();

    /**
     * Create new message structure based on message name and definition.
     * @param msgName name of message to define.
     * @param inStr iterator pair of string containing the message definition.
     *              The pair's end may point beyond the message.  This parameter
     *              is updated to point past the message body upon return.
     * @return pointer to the new message definition.
     */
    Message* createMessage(const std::string& msgName, PairIter& inStr);

    /**
     * Read message definitions from a string and create a message list.
     * @param str string containing IPC message definitions.
     * @param ml message list returned.
     * @returns true on success, otherwise false.
     */
    virtual bool stringToMessageList(const std::string& str, MessageList& ml);

private:
    ParserIpc(const ParserIpc&);	// disable copy constructor
    ParserIpc& operator=(const ParserIpc& rSource);	// disable assignment operator
};

}  // namespace ipctest

#endif
