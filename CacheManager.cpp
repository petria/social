/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CacheManager.cpp
 * Author: petria
 * 
 * Created on March 12, 2019, 3:45 PM
 */
#include <iostream>

#include "CacheManager.h"
#include "User.h"

CacheManager::CacheManager() {
}

CacheManager::CacheManager(const CacheManager& orig) {
}

CacheManager::~CacheManager() {
}

void CacheManager::addToCache(std::string key, Cacheable* instance) {
    std::cout << "CacheManager:: addToCache key=" << key << " instance=" << instance << std::endl;
    this->instanceCache[key] = instance;
}

void CacheManager::removeFromCache(std::string key, Cacheable* instance) {
//    this->instanceCache.erase(instance->getHashKey());
}

Cacheable* CacheManager::createUser(unsigned int id, std::string name, unsigned int age, unsigned int height, User::Sex sex, std::vector<std::string> hobbies) {
    User* user = new User();
    user->setId(id);
    user->setName(name);
    user->setAge(age);
    user->setHeight(height);
    user->setSex(sex);
    user->setHobbies(hobbies);
    
    cacheUser(user);
    
    return (Cacheable*)user;
}

void CacheManager::cacheUser(User* user) {
    for (std::string key : user->getCacheKeys()) {
        addToCache(key, (Cacheable *) user);
    }
}

void CacheManager::deleteCacheable(Cacheable* cacheable) {
    //removeFromCache(cacheable);
            
}
