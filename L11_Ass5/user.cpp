#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr) // For a pointer to a string
  , _size(0)
  , _capacity(0) // This is the number of friends of the user
{
} 

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity]; 
    // newFriends is a pointer to a list of strings with _capacity lenght
    for (size_t i = 0; i < _size; ++i) //What is size_t? Is it an iterator, why?
    {
      newFriends[i] = _friends[i]; //Am I copying each char of the string?
    }
    delete[] _friends; // Why deleting _friends?? Since new is using in newFriends, not _friends
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name. //Changes user's friend
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/** 
 * Operator << 
 * 
 */
std::ostream& operator<<(std::ostream& out, const User& usr){
  out << "User(name="<< usr._name << ", friends =[" << 
  // for (size_t i = 0; i < _size; ++i) {_friend[i]} << "])"; FOR IS OUTSIDE THE OUT
  return out;
}



//Make the User class copy constructible. 
User::User(const User& other) : _name(other._name), _size(other._size), _capacity(other._capacity), _friends(other._friends)
{
  // Do I need this member with friend since I am using private
  // variable _size...?
  for (size_t i = 0; i < _size; i++) {
    _friends[i] = other._friends[i];
  }
}


User& operator+=(User& rhs, User& shr) {
  rhs.add_friend(shr.get_name());
  shr.add_friend(shr.get_name());
  return rhs;
}



int main(){
  User Proof("Ari");
  User Proof2("Carlos");
  Proof += Proof2;
  std::cout << Proof;
  std::cout << Proof;
}