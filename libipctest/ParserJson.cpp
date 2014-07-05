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

// ParserJson.cpp
//

#include <string.h>
#include <sstream>
#include <vector>
#include <json/json.h>

#include "Field.h"
#include "Log.h"
#include "Message.h"
#include "ParserJson.h"
using namespace ipctest;
using namespace std;

//
static const string msgBegin("IPC_MESSAGE(");
static const string msgEnd("IPC_ENDMESSAGE");


ParserJson::ParserJson()
{

}

ParserJson::~ParserJson()
{

}

bool ParserJson::stringToMessageList(const string& str, MessageList& ml)
{
    vector<string> msgs = Parser::splitString(str, "\n\n");
    vector<string>::const_iterator it;
    for (it = msgs.begin(); it != msgs.end(); ++it)
    {
        Message* msg = createMessage(*it);
        if (msg)
        {
            ml.push_back(msg);
            cout << "Created json message: " << msg->getName() << endl;
        }
    }

    return true;
}

Message* ParserJson::createMessage(const std::string& inStr)
{
    Json::Value json;
    Json::Reader reader(Json::Features::strictMode());
    if (!reader.parse(inStr, json))
    {
        cerr << "Unable to parse as json: " << inStr << endl;
        return 0;
    }

    Json::Value::Members members = json.getMemberNames();
    string msgName(members[0]);
    Message* msg = new Message(msgName);

    Json::Value fields = json[msgName];
    members = fields.getMemberNames();
    for (int idx = 0; idx < fields.size(); idx++)
    {
        cout << "Field: " << members[idx] << endl;
        Field* field = Field::create(members[idx], "int32", 1);
        msg->addField(field);
    }

    return msg;
}
