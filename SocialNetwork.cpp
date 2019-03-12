/* 
 * File:   SocialNetwork.cpp
 * Author: petria
 * 
 * Created on March 11, 2019, 9:12 AM
 */

#include <map>
#include <vector>

#include "SocialNetwork.h"
#include "User.h"

SocialNetwork::SocialNetwork() {
}

SocialNetwork::SocialNetwork(const SocialNetwork& orig) {
}

SocialNetwork::~SocialNetwork() {
}

int SocialNetwork::getUserCount() const {
    return this->users.size();
}

std::map<unsigned int, User> SocialNetwork::getUsers() const {
    return this->users;
}

User SocialNetwork::getUserById(unsigned int id) {
    return this->users[id];
}

User* SocialNetwork::getUserRefById(unsigned int id) {
    User* orig = &this->users[id];
    return orig;
}

void SocialNetwork::addUser(User user) {
    this->users[user.getId()] = user;
}

void SocialNetwork::deleteUser(User user) {
    this->users.erase(user.getId());
}

void SocialNetwork::deleteUserById(unsigned int id) {
    this->users.erase(id);
}

void SocialNetwork::deleteAllUsers() {
    this->users.clear();
}

std::vector<User> SocialNetwork::getUsersWithHobby(std::string hobby) {
    std::vector<User> usersWithHobby;
    for (std::pair<unsigned int, User> e : users) {
        if (e.second.hasHobby(hobby)) {
            usersWithHobby.push_back(e.second);
        }
    }
    return usersWithHobby;
}

std::map<unsigned int, User> SocialNetwork::getUsersWithHobbies(std::vector<std::string> hobbies) {
    std::map<unsigned int, User> usersWithHobby;
    for (std::pair<unsigned int, User> e : users) {
        for (std::string hobby : hobbies) {
            if (e.second.hasHobby(hobby)) {
                usersWithHobby[e.second.getId()] = e.second;
            }
        }
    }
    return usersWithHobby;
}
