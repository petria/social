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
    User orig = this->users[id];
    std::vector<unsigned int> ids = orig.getFriendIds();
    return this->users[id];
}

User& SocialNetwork::test2(unsigned int id) {
    return this->users[id];
}


/*User& SocialNetwork::test2(unsigned int id) {
    this->users[user.getId()] = user;
    int foo = 0;
}*/

void SocialNetwork::test(User& user) {
    this->users[user.getId()] = user;
    int foo = 0;
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
        User t = getUserById(e.second.getId());
        t.toString();
        //e.second.toString();
        if (e.second.hasHobby(hobby)) {

            usersWithHobby.push_back(e.second);
        }
        //       std::cout <<  e.second << " ";
    }
    return usersWithHobby;
}
