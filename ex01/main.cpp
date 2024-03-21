#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

#include <iostream>

int main()
{
    PhoneBook Phone;
    Phone.init();
    std::string answer;
    int flag = 0;
    while (42)
    {
        std::cout << "Enter ADD | SEARCH | EXIT" << std::endl;
        std::cin >> answer;
        if (answer == "ADD")
        {
            Contact contact;

            do {
                std::cout << "Enter first name: ";
                std::cin >> answer;
                contact.set_firstName(answer);
            } while (contact.get_firstName().length() == 0);

            do {
                std::cout << "Enter last name: ";
                std::cin >> answer;
                contact.set_lastName(answer);
            } while (contact.get_lastName().length() == 0);

            do {
                std::cout << "Enter nickname: ";
                std::cin >> answer;
                contact.set_nickname(answer);
            } while (contact.get_nickmame().length() == 0);

            do {
                std::cout << "Enter phone number: ";
                std::cin >> answer;
                for (unsigned int i = 0 ; i < answer.length(); i++)
                    if (!isdigit(answer[i]))
                        flag = 1;
                if (flag == 1)
                    std::cout << "The phone number must only contains digits !" << std::endl;
                else 
                    contact.set_phoneNumber(answer);
                flag = 0;
            } while (contact.get_phoneNumber().length() == 0);

            do {
                std::cout << "Enter darkest secret: ";
                std::cin >> answer;
                contact.set_darkestSecret(answer);
            } while (contact.get_phoneNumber().length() == 0);

            if (Phone.isfull())
                Phone.replaceOlder(contact);
            else
                Phone.appendContact(contact);
            std::cout << "Contact added" << std::endl;
        }
        else if (answer == "SEARCH")
        {
            std::cout << "|Index    |Last Name |First Name|Nickname  |" << std::endl;
            std::cout << "|---------|----------|----------|----------|" << std::endl;
            for (int i = 0; i < 8; i++)
            {
                if (Phone.get_contact(i).get_firstName().length() != 0)
                {
                    std::cout << "|" << i << "        |";
                    if (Phone.get_contact(i).get_lastName().length() > 10)
                        std::cout << Phone.get_contact(i).get_lastName().substr(0, 9) << ".|";
                    else
                    {
                        std::cout << Phone.get_contact(i).get_lastName();
                        for (u_int j = 0; j < 10 - Phone.get_contact(i).get_lastName().length(); j++)
                            std::cout << " ";
                        std::cout << "|"; 
                    }
                    if (Phone.get_contact(i).get_firstName().length() > 10)
                        std::cout << Phone.get_contact(i).get_firstName().substr(0, 9) << ".|";
                    else
                    {
                        std::cout << Phone.get_contact(i).get_firstName();
                        for (u_int j = 0; j < 10 - Phone.get_contact(i).get_firstName().length(); j++)
                            std::cout << " ";
                        std::cout << "|"; 
                    }
                    if (Phone.get_contact(i).get_nickmame().length() > 10)
                        std::cout << Phone.get_contact(i).get_nickmame().substr(0, 9) << ".|";
                    else
                    {
                        std::cout << Phone.get_contact(i).get_nickmame();
                        for (u_int j = 0; j < 10 - Phone.get_contact(i).get_nickmame().length(); j++)
                            std::cout << " ";
                        std::cout << "|"; 
                    }
                    std::cout << std::endl;
                }
            }
            std::cout << "Enter the index of the contact you want to see: " << std::endl;
            std::cin >> answer;
            if (Phone.get_contact(answer[0] - '0').get_firstName() == "")
                std::cout << "The contact is empty ! Try to add one more." << std::endl;

            else if (answer.length() == 1 && isdigit(answer[0]) && answer[0] - '0' >= 0 && answer[0] - '0' < 8)
            {
                std::cout << BOLD << "Here are informations about contact n°" << answer[0] << RESET <<std::endl;
                std::cout << "First name: " << Phone.get_contact(answer[0] - '0').get_firstName() << std::endl;
                std::cout << "Last name: " << Phone.get_contact(answer[0] - '0').get_lastName() << std::endl;
                std::cout << "Nickname: " << Phone.get_contact(answer[0] - '0').get_nickmame() << std::endl;
                std::cout << "Phone number: " << Phone.get_contact(answer[0] - '0').get_phoneNumber() << std::endl;
                std::cout << "Darkest secret: " << Phone.get_contact(answer[0] - '0').get_darksestSecret() << "\n" << std::endl;
            }
            else
                std::cout << "Invalid input" << std::endl;
        }
        else if (answer == "EXIT")
            exit(EXIT_SUCCESS);
        else
            std::cout << "Invalid input" << std::endl;
       }
    return 0;
}