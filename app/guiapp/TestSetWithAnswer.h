/**
 * Project Untitled
 */


#ifndef _TESTSETWITHANSWER_H
#define _TESTSETWITHANSWER_H
#include <vector>
#include <string>
#include "StringHashMap.h"
class TestSetWithAnswer {
public: 
    std::string text;
    RkSearchLibrary::StringHashMap samples;
    std::vector<int> expectedIndexes;
};

#endif //_TESTSETWITHANSWER_H
