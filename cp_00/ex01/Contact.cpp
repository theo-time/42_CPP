#include "Contact.hpp"


void Contact::init()
{
    cout << "first_name     :" << endl;
    cin >> _first_name;
    cout << "last_name      :" << endl;
    cin >> _last_name;
    cout << "nick_name      :" << endl;
    cin >> _nick_name;
    cout << "phone_number   :" << endl;
    cin >> _phone_number;
    cout << "darkest_secret :" << endl;
    cin >> _darkest_secret;
}

void Contact::print_line(int index)
{
    cout << "|" << index << "         ";
    cout << "|" << format(_first_name);
    cout << "|" << format(_last_name);
    cout << "|" << format(_nick_name) << "|\n";
}

void Contact::print()
{
    cout << "first_name :" <<_first_name  << endl;
    cout << "last_name :" << _last_name  << endl;
    cout << "nick_name :" << _nick_name  << endl;
    cout << "phone_number :" << _phone_number  << endl;
    cout << "darkest_secret :" << _darkest_secret  << endl;
}