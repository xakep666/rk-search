/**
 * Project Untitled
 */


#ifndef _RKSEARCHLIBRARY_H
#define _RKSEARCHLIBRARY_H
#include <vector>
#include <string>
#include "StringHashMap.h"
namespace RkSearchLibrary {
    /**
     * @param s
     * @param samples
     */
    std::vector<int> find(const std::string &s, const StringHashMap &samples);
}


#endif //_RKSEARCHLIBRARY_H
