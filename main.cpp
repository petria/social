/* 
 * File:   main.cpp
 * Author: petria
 *
 * Created on March 11, 2019, 9:08 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "SocialNetwork.h"
#include "User.h"

using namespace std;

User createUser(unsigned int id, std::string name, unsigned int age, unsigned int height) {
    User user;
    user.setId(id);
    user.setName(name);
    user.setAge(age);
    user.setHeight(height);
    return user;
}

bool testAddAndDeleteUsers() {
    SocialNetwork theBook;
    theBook.addUser(createUser(1000, "user 1", 30, 160));
    theBook.addUser(createUser(1001, "user 2", 35, 170));
    theBook.addUser(createUser(1002, "user 3", 40, 180));


    if (theBook.getUserCount() != 3) {
        std::cout << "FAIL: user count should be 3" << std::endl;
        return false;
    }

    theBook.deleteUserById(1001);
    if (theBook.getUserCount() != 2) {
        std::cout << "FAIL: user count should be 2" << std::endl;
        return false;
    }

    theBook.deleteAllUsers();
    if (theBook.getUserCount() != 0) {
        std::cout << "FAIL: user count should be 0" << std::endl;
        return false;
    }

    return true;
}

bool testFriends() {
    SocialNetwork theBook;
    User user1 = createUser(1001, "Kalle", 30, 160);
    User user2 = createUser(1002, "Ville", 31, 161);
    User user3 = createUser(1003, "Jorma", 32, 162);
    User user4 = createUser(1004, "Liisa", 33, 163);

    theBook.addUser(user1);
    theBook.addUser(user2);
    theBook.addUser(user3);
    theBook.addUser(user4);

    user1.addFriend(user2);
    user1.addFriend(user3);
    user1.addFriend(user4);

    std::vector<unsigned int> ids = user1.getFriendIds();
    if (ids.size() != 3 ) {
        std::cout << "FAIL: friend id count should be 3" << std::endl;
        return false;
    }
    
    user1.toString();
    if (user1.getFriendCount() != 3 ) {
        std::cout << "FAIL: friend count should be 3" << std::endl;
        return false;
    }

    user1.unFriend(user3);
    if (user1.getFriendCount() != 2) {
        std::cout << "FAIL: friend count should be 2" << std::endl;
        return false;
    }

    user1.clearFriends();
    if (user1.getFriendCount() != 0) {
        std::cout << "FAIL: friend count should be 0" << std::endl;
        return false;
    }

    return true;
}

bool testHobbies() {
    SocialNetwork theBook;
    User user1 = createUser(1001, "Kalle", 30, 160);
    User user2 = createUser(1002, "Ville", 31, 161);
    User user3 = createUser(1003, "Jorma", 32, 162);
    User user4 = createUser(1004, "Liisa", 33, 163);


    user1.addFriend(user2);
    user1.addFriend(user3);
    user1.addFriend(user4);

    user1.addHobby("sulis");
    user1.addHobby("kendo");
    user1.addHobby("baletti");

    user2.addHobby("kendo");
    user2.addHobby("koris");
    user2.addHobby("bilis");

    user3.addHobby("jalis");
    user3.addHobby("tanssi");
    user3.addHobby("laskettelu");

    user4.addHobby("something");
    
    theBook.test(user1);
    User uu = theBook.test2(1001);
    
    user1.toString();
    
    theBook.getUserById(1001);
    
//    theBook.addUser(user1);
    
/*    theBook.addUser(user2);
    theBook.addUser(user3);
    theBook.addUser(user4);

    
    
    user1.toString();
    user2.toString();
    user3.toString();
    user4.toString();
    
    std::vector<User> withHobbies = theBook.getUsersWithHobby("kendo");
  */  
    return true;
}
/*
 * 
 */
int main(int argc, char** argv) {

/*    std::cout << "test1: start" << std::endl;
    bool test1 = testAddAndDeleteUsers();
    std::cout << "test1: " << test1 << std::endl;

    std::cout << "test2: start" << std::endl;
    bool test2 = testFriends();
    std::cout << "test2: " << test2 << std::endl;
*/
    std::cout << "test3: start" << std::endl;
    bool test3 = testHobbies();
    std::cout << "test3: " << test3 << std::endl;

    return 0;
}

