#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void    PhoneBook::add_contact()
{
    this->contact[this->cnt % 8].set_contact(this->cnt);
    this->cnt++;
}
