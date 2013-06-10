/*
   Copyright (C) 2012
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

#ifndef _PARSER_H_INCLUDED_
#define _PARSER_H_INCLUDED_
//
//

//
// INCLUDE FILES
//
#include <string>
#include <vector>
#include "Message.h"


namespace ipctest
{

//
// MACRO DEFINITIONS
//
#ifndef DllExport
#define DllExport
#endif

static const char* TOKEN_SEPERATORS = " \t\n\r;:()/#*";

//
// FORWARD CLASS DECLARATIONS
//

//
// TYPE DEFINITIONS
//

//
// CLASS DEFINITIONS
//

/**
 * A convenience class that simply holds two iterators that point into a string.
 *
 * It is useful for parsing that is often working with a range (start, end)
 * of iterators.
 */
class PairIter
{
public:
    /** Create an empty string. */
    PairIter(void) { }
    /**
     * Create a new pair.
     * @param itBegin begin iterator of pair.
     * @param itEnd   end iteraotr of pair.
     */
	PairIter(std::string::const_iterator itBegin, std::string::const_iterator itEnd)
        : begin_(itBegin), end_(itEnd) { }
    /**
     * Create a new pair.
     * @param itBegin begin iterator of pair.
     * @param itEnd   end iteraotr of pair.
     */
    PairIter(const std::string& str)
        : begin_(str.begin()), end_(str.end()) { }


    /** Return the begin iterator */
    const std::string::const_iterator& begin() const { return begin_; }
    /** Return the end iterator */
    const std::string::const_iterator& end()   const { return end_; }
    /**
     * Extract the begin and end iterators.
     * @param itBegin reference to begin iterator is returned here.
     * @param itEnd   reference to end iterator is returned here.
     */
    void get(std::string::const_iterator& itBegin, std::string::const_iterator& itEnd) const
    {
        itBegin = begin_;
        itEnd = end_;
    }
    /**
     * Get the value of the range as a string.
     * @returns string representation of the range (begin, end).
     */
    std::string get() const { return std::string(begin_, end_); }

    /**
     * Set the beginning iterator of range.
     * @param itBegin reference to the new begin.
     */
    void set(const std::string::const_iterator& itBegin)
    {
        begin_ = itBegin;
    }
    /**
     * Set the beginning and ending iterators of range.
     * @param itBegin reference to the new begin.
     * @param itEnd   reference to the new end.
     */
    void set(const std::string::const_iterator& itBegin,
             const std::string::const_iterator& itEnd)
    {
        begin_ = itBegin;
        end_ = itEnd;
    }

private:
    std::string::const_iterator begin_;
    std::string::const_iterator end_;
};

/*
  Future:
  (a)    t1
       / |  \
    d1(  a   )

    t2  and(a,"b")
    |  \
   a,"b" )


class PTNode
{
public:
    void addChild(PTNode* child) { children_.push_back(child); }
protected:
    std::vector<PTNode*> children_;
};
class PTDelimiter : public PTNode
{
    std::string open_;
    std::string close_;
};
class PTContent : public PTNode
{
    std::string content_;
};
class ParseTree : public PTNode
{
    
};
*/

/**
 * Main parsing class.
 *
 * At the moment, it is only used to parse the IPC message definitions, which for the
 * first version is a (restrictive) C languange include file.
 * This will be refactored as a MessageParser class.  Probably a new Parser manager
 * class will be added to allow unified parsing (IPC, xml, json, etc.).
 */ 
class Parser
{
public:
    /** Create new IPC message parser. */
    Parser();
    virtual ~Parser();

    /**
     * Read message definitions from a file and create a message list.
     * @param fname file name containing IPC message definitions.
     * @param ml message list returned.
     * @returns true on success, otherwise false.
     */
    bool fileToMessageList(const std::string& fname, MessageList& ml);
    /**
     * Read message definitions from a string and create a message list.
     * @param str string containing IPC message definitions.
     * @param ml message list returned.
     * @returns true on success, otherwise false.
     */
    bool stringToMessageList(const std::string& str, MessageList& ml);

    /**
     * Create new message structure based on message name and definition.
     * @param msgName name of message to define.
     * @param inStr iterator pair of string containing the message definition.
     *              The pair's end may point beyond the message.  This parameter
     *              is updated to point past the message body upon return.
     * @return pointer to the new message definition.
     */
    Message* createMessage(const std::string& msgName, PairIter& inStr);

    // These are more internal functions, but could be useful outside this class
    static bool getLine(PairIter& inStr, PairIter& outLine, bool trim = true);
    //static bool makeParseTree(const std::string& str, ParseTree& tree);
    static void splitTokens(const std::string& str, std::vector<std::string>& strVec,
        const char* seps = TOKEN_SEPERATORS);
    static void splitDelimitedTokens(const std::string& str, std::vector<std::string>& strVec,
        const char* seps = TOKEN_SEPERATORS);
    static void trimSpace(PairIter& pi, bool stripComments = true);
    static std::string trimSpace(const std::string& instr);
    static std::vector<std::string> splitString(const std::string& str);

private:
    Parser(const Parser&);	// disable copy constructor
    Parser& operator=(const Parser& rSource);	// disable assignment operator
};

}  // namespace ipctest

#endif
