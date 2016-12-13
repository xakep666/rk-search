/**
 * Project Untitled
 */

#include <cmath>
#include <algorithm>
#include <assert.h>
#include "StringHashMap.h"

/**
 * StringHashMap implementation
 */


RkSearchLibrary::StringHashMap::StringHashMap (int items) {
    table = new table_t(items);
    for (int i=0;i<items;i++) (*table)[i]=nullptr;
}

RkSearchLibrary::StringHashMap::~StringHashMap() {
    std::for_each(table->begin(),table->end(),[](bucket_t *b){
        if (b!=nullptr) delete b;
    });
    delete table;
}

/**
 * @param s
 */
void RkSearchLibrary::StringHashMap::add(const std::string &s) {
    if (slength==0) {
        slength=s.length();
    } else {
        assert(slength==s.length());
    }
    long int strhash = hash(s);
    int pos = strhash%table->size();
    if ((*table)[pos]!=nullptr) {
        (*table)[pos]->push_back(s);
    } else {
        bucket_t *bucket = new bucket_t();
        bucket->push_back(s);
        (*table)[pos]=bucket;
    }
}

/**
 * @param s
 * @return long int
 */
long int RkSearchLibrary::StringHashMap::hash(const std::string &s) {
    long int ret = 0;
    long int ppow = 1;
    std::for_each(s.begin(),s.end(),[&](char c){
        ret+=c*ppow;
        ppow*=p;
    });
    return ret;
}

/**
 * @param prevch
 * @param nextch
 * @param prevhash
 * @return long int
 */
long int RkSearchLibrary::StringHashMap::rehash(const std::string &prevstr, char nextch, long int prevhash) {
    return (prevhash-prevstr[prevstr.length()-1]*std::pow(p,prevstr.length()))*p+nextch;
}

/**
 * @param hash
 */
bool RkSearchLibrary::StringHashMap::containsHash(long int hash) const {
    return (*table)[hash%table->size()]!=nullptr;
}

/**
 * @param s
 * @return bool
 */
bool RkSearchLibrary::StringHashMap::containsString(const std::string &s) const {
    bool ret = false;
    int pos = hash(s)%table->size();
    bucket_t* b = (*table)[pos];
    if (b!=nullptr) {
        std::for_each(b->cbegin(),b->cend(),[&](const std::string &tablestr){
            if (tablestr==s) ret=true;
        });
    }
    return ret;
}

unsigned int RkSearchLibrary::StringHashMap::sampleLength() const {
    return slength;
}
