#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	private:
		Contact	contact[8];
		int		cnt;
	public:
		PhoneBook(void);
		~PhoneBook();

		void	add_contact(void);
		void	search_contact(void);
};

#endif
