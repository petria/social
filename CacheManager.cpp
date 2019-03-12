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

#include "CacheManager.h"
#include "User.h"

CacheManager::CacheManager() {
}

CacheManager::CacheManager(const CacheManager& orig) {
}

CacheManager::~CacheManager() {
}

void CacheManager::addToCache(Cacheable* instance) {
    this->instanceCache[instance->getHashKey()] = instance;
}

void CacheManager::removeFromCache(Cacheable* instance) {
    this->instanceCache.erase(instance->getHashKey());
}

Cacheable* CacheManager::createUser(unsigned int id) {
    User* user = new User();
    user->setId(id);
    return (Cacheable*)user;
}

void CacheManager::deleteCacheable(Cacheable* cacheable) {
    removeFromCache(cacheable);
            
}
