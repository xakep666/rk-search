/**
 * Project Untitled
 */


#ifndef _TESTFILEPARSER_H
#define _TESTFILEPARSER_H
#include <vector>
#include <string>
#include "TestSetWithAnswer.h"
class TestFileParser {
public: 
    
    /**
     * @param filename
     */
    static std::vector<TestSetWithAnswer> parseWithAnswer(const std::string &filename);
    
    /**
     * @param filename
     */
    typedef std::pair<std::string,std::vector<std::string>> testset;
    static std::vector<testset> parse(const std::string &filename);
};

#endif //_TESTFILEPARSER_H
