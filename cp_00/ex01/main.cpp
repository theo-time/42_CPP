#include "PhoneBook.hpp"

string format(string str)
{
    if(9 < str.length())
    {
        str = str.substr(0,  9);
        str = str + ".";
    }
    while(str.length() < 10)
        str = str + " ";
    return str;
}

void router(PhoneBook *phonebook, string input) {
  // do something with the input
    if(input.compare("ADD") == 0)
        phonebook->add();
    else if(input.compare("SEARCH") == 0)
        phonebook->search();
    else if(input.compare("EXIT") == 0)
        exit(0);
}

int main(int argc, char **argv)
{
    string input;
    PhoneBook phonebook;
    (void) argc;
    (void) argv;

    cout << "\n--------- MY PHONE BOOK ---------\n\n";
    cout << "\nmy_phone_book > ";
    while (std::getline(std::cin, input)) 
    {
        if (input.empty()) {
            continue;
        }
        router(&phonebook, input);
        cout << "my_phone_book > ";
        // cout << "input :" << input  << endl;
        // cin.clear();
        // input.clear();
        // cout << "Cleared !" << endl;
        // cout << "input :" << input  << endl;
    }
    return (0);
}