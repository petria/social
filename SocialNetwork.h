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

#include "CacheManager.h"
#include "Cacheable.h"

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
std::vector<User> getUsersWithHobby(std::string hobby);

User* addUser(unsigned int id, std::string name, unsigned int age, unsigned int height, User::Sex sex, std::vector<std::string> hobbies);
void addUser(User user);
void deleteUser(User user);
void deleteUserById(unsigned int id);
void deleteAllUsers();

std::map<unsigned int, User> searchByHobbies(std::vector<std::string> hobbies);
std::map<unsigned int, User> searchByName(std::string name);
std::map<unsigned int, User> searchByNameMatching(std::string regexp);
std::map<unsigned int, User> searchByAge(unsigned int age);
std::map<unsigned int, User> searchByAgeBetween(unsigned int age1, unsigned int age2);
std::map<unsigned int, User> searchBySex(User::Sex sex);

private:
    std::map<unsigned int, User > users;
    CacheManager cache;
    
};

#endif /* SOCIALNETWORK_H */

