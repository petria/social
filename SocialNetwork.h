/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SocialNetwork.h
 * Author: petria
 *
 * Created on March 11, 2019, 9:12 AM
 */

#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H

#include <map>
#include <vector>

#include "User.h"


class SocialNetwork {
public:
    SocialNetwork();
    SocialNetwork(const SocialNetwork& orig);
    virtual ~SocialNetwork();

int getUserCount() const;    
std::map<unsigned int, User> getUsers() const;
User getUserById(unsigned int id);
User* getUserRefById(unsigned int id);

void addUser(User user);
void deleteUser(User user);
void deleteUserById(unsigned int id);
void deleteAllUsers();

std::vector<User> getUsersWithHobby(std::string hobby);
std::map<unsigned int, User> getUsersWithHobbies(std::vector<std::string> hobbies);

private:
    std::map<unsigned int, User > users;
};

#endif /* SOCIALNETWORK_H */

