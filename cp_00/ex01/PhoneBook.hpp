#ifndef PHONE_BOOK_HPP
#include "libs.hpp"
#include "Contact.hpp"


class PhoneBook {
  private:
    Contact _contacts [8];
    int _oldest_contact;
  public:
    
    PhoneBook() {     
      _oldest_contact = 0;
    };

    void search();
    void add();
    void print_contacts();
};

#endif