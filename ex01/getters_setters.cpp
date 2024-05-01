#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

void Contact::set_firstName(std::string s)
{
    firstName = s;
}

std::string Contact::get_firstName()
{
    return firstName;
}

void Contact::set_lastName(std::string s)
{
    lastName = s;
}

std::string Contact::get_lastName()
{
    return lastName;
}

void Contact::set_nickname(std::string s)
{
    nickname = s;
}

std::string Contact::get_nickmame()
{
    return nickname;
}

void Contact::set_phoneNumber(std::string s)
{
    phoneNumber = s;
}

std::string Contact::get_phoneNumber()
{
    return phoneNumber;
}

void Contact::set_darkestSecret(std::string s)
{
    darkestSecret = s;
}

std::string Contact::get_darksestSecret()
{
    return darkestSecret;
}

bool Contact::empty()
{
    if (firstName.length() == 0 && lastName.length() == 0 && nickname.length() == 0 && phoneNumber.length() == 0 && darkestSecret.length() == 0)
        return true;
    return false;
}

void Contact::deleteContact()
{
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    darkestSecret = "";
}


void PhoneBook::appendContact(Contact contact)
{
    for (int i = 0; i < 8; i++)
    {
        if (l_contact[i].empty())
        {
            l_contact[i] = contact;
            break;
        }
    }
}

void PhoneBook::replaceOlder(Contact contact, int index)
{
    l_contact[index] = contact;
}

bool PhoneBook::isfull()
{
    for (int i = 0; i < 8; i++)
        if (l_contact[i].empty())
            return false;
    return true;
}

void PhoneBook::init()
{
    for (int i = 0; i < 8; i++)
    {
        l_contact[i].set_firstName("");
        l_contact[i].set_lastName("");
        l_contact[i].set_nickname("");
        l_contact[i].set_phoneNumber("");
        l_contact[i].set_darkestSecret("");
    }
}

Contact PhoneBook::get_contact(int i)
{
    return l_contact[i];
}