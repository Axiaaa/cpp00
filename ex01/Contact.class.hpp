#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <string>
#include <iostream>
#include <cstdlib>


#define BOLD "\033[1m"
#define RESET "\033[0m"
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

class Contact {

    private:
    
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    public :

    void set_firstName(std::string s);
    void set_lastName(std::string s);
    void set_nickname(std::string s);
    void set_phoneNumber(std::string s);
    void set_darkestSecret(std::string s);
    void deleteContact();

    bool empty();

    std::string get_firstName();
    std::string get_lastName();
    std::string get_nickmame();
    std::string get_phoneNumber();
    std::string get_darksestSecret();
};

#endif