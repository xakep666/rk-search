/**
 * Project Untitled
 */

#include <assert.h>
#include "RkSearchLibrary.h"

/**
 * RkSearchLibrary implementation
 */


/**
 * @param s
 * @param samples
 * @return vector<int>
 */
std::vector<int> RkSearchLibrary::find(const std::string &s, const StringHashMap &samples) {
    assert(s.length()>=samples.sampleLength());
    std::vector<int> ret;
    std::string substr = s.substr(0,samples.sampleLength());
    long int substrhash = StringHashMap::hash(substr);
    for (int i=0;(unsigned int)i<s.length()-samples.sampleLength();i++) {
        if (samples.containsHash(substrhash)) {
            if (samples.containsString(substr)) {
                ret.push_back(i);
            }
        }
    }
    return ret;
}
