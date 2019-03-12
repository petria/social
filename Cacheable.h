/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cacheable.h
 * Author: petria
 *
 * Created on March 12, 2019, 3:33 PM
 */

#ifndef CACHEABLE_H
#define CACHEABLE_H

#include <string>

class Cacheable {
public:
    Cacheable();
    Cacheable(const Cacheable& orig);
    virtual ~Cacheable();
    
    virtual std::string getHashKey() = 0;
    virtual Cacheable* createInstance() = 0;
    
private:

};

#endif /* CACHEABLE_H */

