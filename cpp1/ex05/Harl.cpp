#include "Harl.hpp"
#include <iostream>

//Constructor && Destructor
Harl::Harl(void) {
	return ;
}
Harl::~Harl(void) {
	return ;
}

//Member functions
void	Harl::debug(void) {
	std::cout << "I love playing the English opening. The center control is amazing. I really do love it!" << std::endl;
}
void	Harl::info(void) {
	std::cout << "I can't believe you didn't go for the bishop trade. You didn't develop them correctly, if you did, I wouldn't ask for a trade" << std::endl;
}
void	Harl::warning(void) {
	std::cout << "I think I deserve to add 3 more minutes to my clock, I was talking with my friend. I've been playing on chess.com for the last year, whereas you started playing last month" << std::endl;
}
void	Harl::error(void) {
	std::cout << "There is no way you found a royal fork on your own. You are cheating! I'll report you. I want to speak to the site moderators now" << std::endl;
}
void	Harl::complain(std::string level) {
	void	(Harl::*complaints[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*complaints[i])();
			return ;
		}
	}
	std::cout << "Wrong level, try one of these {DEBUG, INFO, WARNING, ERROR}" << std::endl;
}
