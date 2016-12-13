/**
 * Project Untitled
 */


#ifndef _STRINGHASHMAP_H
#define _STRINGHASHMAP_H
#include <vector>
#include <string>
namespace RkSearchLibrary {
    class StringHashMap {
    public:
        StringHashMap(int items);
        virtual ~StringHashMap();
        /**
         * @param s
         */
        void add(const std::string &s);

        /**
         * @param s
         */
        static long int hash(const std::string &s);

        /**
         * @param prevch
         * @param nextch
         * @param prevhash
         */
        static long int rehash(const std::string &prevstr, char nextch, long int prevhash);

        /**
         * @param hash
         */
        bool containsHash(long int hash) const;

        /**
         * @param s
         */
        bool containsString(const std::string &s) const;

        /**
         * @brief sampleLength
         * @return
         */
        unsigned int sampleLength() const;
    private:
        typedef std::vector<std::string> bucket_t;
        typedef std::vector<bucket_t *> table_t;
        table_t *table;
        static const int p = 255; //standart ascii table size
        unsigned int slength = 0;
    };
}

#endif //_STRINGHASHMAP_H
