#include "PhoneBook.hpp"

void PhoneBook::search()
{
  string valid_indexes = "0123456789";
  string index_str;
  int index;
  print_contacts();
  cout << "contact index : ";
  cin >> index_str;
  // cout << valid_indexes.find(index_str[0]) << endl;
  if(index_str.length() != 1 || !(valid_indexes.find(index_str[0]) < 10))
      cout << "WRONG INDEX YOU DUMBASS\n";
  else
  {
    index = atoi(index_str.c_str());
    _contacts[index].print();
  }
  cout << endl << endl;
}

void PhoneBook::add()
{
  Contact contact;
  contact.init();
  cout << "NEW CONTACT : " << endl;
  _contacts[_oldest_contact] = contact;
  _oldest_contact = (_oldest_contact + 1) % 8;
  cout << endl << endl;
}

void PhoneBook::print_contacts()
{
  cout << "---------------------------------------------\n";
  cout << "|" << format("index");
  cout << "|" << format("first_name");
  cout << "|" << format("last_name");
  cout << "|" << format("nick_name") << "|\n";
  cout << "---------------------------------------------\n";


  for(int i = 0; i < 8; i++)
    _contacts[i].print_line(i);
  cout << "---------------------------------------------\n";
}
