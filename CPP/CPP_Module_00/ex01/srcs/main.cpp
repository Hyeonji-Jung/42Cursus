#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << "Enter the Command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << "No command entered. Program terminated." << std::endl;
			return (1);
		}
		if (!cmd.compare("ADD"))
			;
		else if (!cmd.compare("SEARCH"))
			;
		else if (!cmd.compare("EXIT"))
			break ;
		else
			std::cout << "Invalid Command." << std::endl;
	}
	std::cout << "Good Bye :)" << std::endl;
	return (0);
}
