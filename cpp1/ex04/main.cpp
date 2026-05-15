#include "Handler.hpp"
#include <iostream>

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Wrong number of arguments, try again with 3" << std::endl;
		return (1);
	}
	Handler sed(av[1], av[2], av[3]);
	sed.replaceFile();
	return (0);
}
