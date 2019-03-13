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
#include "User.h"

class CacheManager {
public:
    CacheManager();
    CacheManager(const CacheManager& orig);
    virtual ~CacheManager();
    
    Cacheable* createUser(unsigned int id, std::string name, unsigned int age, unsigned int height, User::Sex sex, std::vector<std::string> hobbies);
    void deleteCacheable(Cacheable* cacheable);
    
private:
    void addToCache(std::string key, Cacheable* instance);
    void removeFromCache(std::string key, Cacheable* instance);

    void cacheUser(User* user);
    
    std::map<std::string, Cacheable *> instanceCache;
    
};

#endif /* CACHEMANAGER_H */

