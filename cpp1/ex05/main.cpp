#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Wrong number of arguments, try again with 2" << std::endl;
		return (1);
	}
	Harl	complainer;
	complainer.complain(av[1]);
	return (0);
}
