#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook {

    private:

    Contact l_contact[8];
    
    public :

    void appendContact(Contact contact)
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

    Contact get_contact(int i)
    {
        return l_contact[i];
    }

    void replaceOlder(Contact contact)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == 0)
                l_contact[i].deleteContact();
            else if (i == 7)
                l_contact[i] = contact;
            else
                l_contact[i - 1] = l_contact[i];
        }
    }

    bool isfull()
    {
        for (int i = 0; i < 8; i++)
            if (l_contact[i].empty())
                return false;
        return true;
    }


    void init()
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
};

# endif