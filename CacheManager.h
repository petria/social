/* 
 * File:   CacheManager.h
 * Author: petria
 *
 * Created on March 12, 2019, 3:45 PM
 */

#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H

#include <map>
#include <string>

#include "Cacheable.h"

class CacheManager {
public:
    CacheManager();
    CacheManager(const CacheManager& orig);
    virtual ~CacheManager();
    
    Cacheable* createUser(unsigned int id);
    void deleteCacheable(Cacheable* cacheable);
    
private:
    void addToCache(Cacheable* instance);
    void removeFromCache(Cacheable* instance);
    
    std::map<std::string, Cacheable *> instanceCache;
    
};

#endif /* CACHEMANAGER_H */

