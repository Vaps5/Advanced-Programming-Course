/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */



#include <iostream>
#include <string>

class User //will store the name and friends list of each user who joins your social media platform!
{
public:
  User(const std::string& name); //Constructor
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const; 
  void set_friend(size_t index, const std::string& name);

  //Operators
  friend std::ostream& operator<<(std::ostream& out, const User& usr);

  // Representing adding a user to another user's friend list
  friend User& operator+=(User& rhs, User& shr);

  //SMFs
  ~User();
  User(const User& other);//Make the User class copy constructible. 
  User& operator=(const User& other);//Make the User class copy assignable
  User(User&& user);// Prevent the User class from being move constructed.
  User& operator=(User&& user); //Prevent the User class from being move assigned

private:
  std::string _name;
  std::string* _friends; //This is a poiter to a string
  size_t _size; //number of friends this User has.
  size_t _capacity;
};