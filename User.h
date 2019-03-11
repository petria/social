/* 
 * File:   User.h
 * Author: petria
 *
 * Created on March 11, 2019, 9:12 AM
 */

#ifndef USER_H
#define USER_H

#include <map>
#include <vector>
#include <string>

class User {
public:
    User();
    User(const User& orig);
    virtual ~User();

    unsigned int getId();
    void setId(unsigned int id);

    std::string getName();
    void setName(std::string name);

    unsigned int getAge();
    void setAge(unsigned int age);

    unsigned int getHeight();
    void setHeight(unsigned int height);

    void addFriend(User user);
    void unFriend(User user);
    void clearFriends();
    int getFriendCount();
    std::vector<unsigned int> getFriendIds();

    void addHobby(std::string hobby);
    bool hasHobby(std::string hobby);

    void toString() const;

private:

    unsigned int id;
    std::string name;
    unsigned int age;
    unsigned int height;

    std::map<unsigned int, User> friends;
    std::map<std::string, std::string> hobbies;

};

#endif /* USER_H */

