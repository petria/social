/* 
 * File:   User.cpp
 * Author: petria
 * 
 * Created on March 11, 2019, 9:12 AM
 */

#include <iostream>
#include <vector>

#include "User.h"

User::User() {
}

User::User(const User& orig) :
id(orig.id),
name(std::move(orig.name)),
age(orig.age),
height(orig.height),
friends(orig.friends),
hobbiesMap(orig.hobbiesMap),
sex(orig.sex)
{

}

User::~User() {
}

unsigned int User::getId() {
    return this->id;
}

void User::setId(unsigned int id) {
    this->id = id;
}

std::string User::getName() {
    return this->name;
}

void User::setName(std::string name) {
    this->name = name;
}

unsigned int User::getAge() {
    return this->age;
}

void User::setAge(unsigned int age) {
    this->age = age;
}

unsigned int User::getHeight() {
    return this->height;
}

void User::setHeight(unsigned int height) {
    this->height = height;
}

void User::addFriend(User user) {
    this->friends[user.getId()] = user;
}

void User::unFriend(User user) {
    this->friends.erase(user.getId());
}

void User::clearFriends() {
    this->friends.clear();
}

int User::getFriendCount() {
    return this->friends.size();
}

std::vector<unsigned int> User::getFriendIds() {
    std::vector<unsigned int> ids;
    for (std::pair<unsigned int, User> e : friends) {
        ids.push_back(e.second.getId());
    }
    return ids;
}

void User::setHobbies(std::vector<std::string> hobbies) {
    this->hobbies = hobbies;
}

void User::addHobby(std::string hobby) {
    this->hobbiesMap[hobby] = hobby;

    //    this->hobbies.push_back(hobby);
}

bool User::hasHobby(std::string hobby) {
    return hobbiesMap.count(hobby) > 0;
}

User::Sex User::getSex() {
    return this->sex;
}

void User::setSex(Sex sex) {
    this->sex = sex;
}


std::vector<std::string> User::getCacheKeys() {
    std::vector<std::string> keys;
    for (std::string hobby : hobbies)
        keys.push_back(hobby);
    
    return keys;
}

Cacheable* User::createInstance() {
    return new User();
}

void User::toString() const {

    std::cout << "[ User: id=" << std::to_string(id) << ", name=" << name << ", age=" << std::to_string(age) << ", height=" << std::to_string(height);
    std::cout << ", sex=" << (sex==0?"MALE":"FEMALE") << ", friend ids: [ ";
    for (std::pair<unsigned int, User> e : friends) {
        std::cout << e.second.getId() << " ";
    }

    std::cout << "],  hobbies: [ ";
    for (std::string hobby : hobbies) {
        std::cout << hobby << " ";
    }
/*    for (std::pair<std::string, std::string> e : hobbiesMap) {
        std::cout << e.second << " ";
    }*/
    std::cout << " ] " << std::endl;

}

