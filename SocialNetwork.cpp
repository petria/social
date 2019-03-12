/* 
 * File:   SocialNetwork.cpp
 * Author: petria
 * 
 * Created on March 11, 2019, 9:12 AM
 */

#include <map>
#include <regex>
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
    std::vector<User> results;
    for (std::pair<unsigned int, User> e : users) {
        if (e.second.hasHobby(hobby)) {
            results.push_back(e.second);
        }
    }
    return results;
}

std::map<unsigned int, User> SocialNetwork::searchByHobbies(std::vector<std::string> hobbies) {
    std::map<unsigned int, User> results;
    for (std::pair<unsigned int, User> e : users) {
        for (std::string hobby : hobbies) {
            if (e.second.hasHobby(hobby)) {
                results[e.second.getId()] = e.second;
            }
        }
    }
    return results;
}

std::map<unsigned int, User> SocialNetwork::searchByAge(unsigned int age) {
    std::map<unsigned int, User> results;
    for (std::pair<unsigned int, User> e : users) {
        if (e.second.getAge() == age) {
            results[e.second.getId()] = e.second;
        }
    }
    return results;
}

std::map<unsigned int, User> SocialNetwork::searchByAgeBetween(unsigned int age1, unsigned int age2) {
    std::map<unsigned int, User> results;
    for (std::pair<unsigned int, User> e : users) {
        if (e.second.getAge() >= age1 && e.second.getAge() <= age2) {
            results[e.second.getId()] = e.second;
        }
    }
    return results;
}

std::map<unsigned int, User> SocialNetwork::searchByName(std::string name) {
    std::map<unsigned int, User> results;
    for (std::pair<unsigned int, User> e : users) {
        if (e.second.getName() == name) {
            results[e.second.getId()] = e.second;
        }
    }
    return results;
}

std::map<unsigned int, User> SocialNetwork::searchByNameMatching(std::string regexp) {
//
    std::map<unsigned int, User> results;
    for (std::pair<unsigned int, User> e : users) {
        if (std::regex_match (e.second.getName(), std::regex(regexp) )) {
            results[e.second.getId()] = e.second;
        }
    }
    return results;
    
}

