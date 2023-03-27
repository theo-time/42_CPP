#ifndef CONTACT_HPP
#include "libs.hpp"

class Contact {

  private:
    std::string _first_name;
    std::string _last_name;
    std::string _nick_name;
    std::string _phone_number;
    std::string _darkest_secret;

  public:
    Contact() {};
    ~Contact() {};

    void setFirstName(string s) {_first_name = s;};
    void setLastName(string s) {_last_name = s;};
    void setNick_name(string s) {_nick_name = s;};
    void setPhoneNumber(string s) {_phone_number = s;};
    void setDarkestSecret(string s) {_darkest_secret = s;};

    string getFirstName() {return _first_name;};
    string getLastName() {return _last_name;};
    string getNick_name() {return _nick_name;};
    string getPhoneNumber() {return _phone_number;};
    string getDarkestSecret() {return _darkest_secret;};

    void init();
    void print_line(int index);
    void print();

};

#endif