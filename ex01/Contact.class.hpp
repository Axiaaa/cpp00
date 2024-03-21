#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <string>
#include <iostream>

#define BOLD "\033[1m"
#define RESET "\033[0m"

class Contact {

    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public :

    void set_firstName(std::string s)
    {
        firstName = s;
    }

    std::string get_firstName()
    {
        return firstName;
    }
    
    void set_lastName(std::string s)
    {
        lastName = s;
    }

    std::string get_lastName()
    {
        return lastName;
    }

    void set_nickname(std::string s)
    {
        nickname = s;
    }

    std::string get_nickmame()
    {
        return nickname;
    }

    void set_phoneNumber(std::string s)
    {
        phoneNumber = s;
    }

    std::string get_phoneNumber()
    {
        return phoneNumber;
    }

    void set_darkestSecret(std::string s)
    {
        darkestSecret = s;
    }

    std::string get_darksestSecret()
    {
        return darkestSecret;
    }

    bool empty()
    {
        if (firstName.length() == 0 && lastName.length() == 0 && nickname.length() == 0 && phoneNumber.length() == 0 && darkestSecret.length() == 0)
            return true;
        return false;
    }

    void deleteContact()
    {
        firstName = "";
        lastName = "";
        nickname = "";
        phoneNumber = "";
        darkestSecret = "";
    }
};

#endif