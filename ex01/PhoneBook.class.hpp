#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook {

    private:
    Contact l_contact[8];
    
    public :
    Contact get_contact(int i);

    bool isfull();
    
    void appendContact(Contact contact);
    void replaceOlder(Contact contact, int index);
    void init();

};

# endif