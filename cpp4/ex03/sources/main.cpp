/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 02:27:31 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/11 02:27:37 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"
#include <iostream>

int	main(void) {

	std::cout << "======== Basic Test ========" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;
	std::cout << "======== Second Test ========" << std::endl;
	std::cout << "----- Here we will test the unequip function -----" << std::endl;
	AMateria* floor[100];
	int	floorCount = 0;

	ICharacter* ody = new Character("Hero");
	ICharacter* evil = new Character("Evil");
	AMateria* temp1 = new Ice();
	AMateria* temp2 = new Cure();
	AMateria* temp3 = new Cure();
	AMateria* temp4 = new Ice();
	ody->equip(temp1);
	ody->equip(temp2);
	ody->equip(temp3);
	ody->equip(temp4);
	ody->use(0, *evil);
	ody->use(1, *evil);
	ody->use(2, *evil);
	ody->use(3, *evil);
	floor[floorCount++] = temp1;
	floor[floorCount++] = temp2;
	floor[floorCount++] = temp3;
	floor[floorCount++] = temp4;
	ody->unequip(0);
	ody->unequip(1);
	ody->unequip(2);
	ody->unequip(3);
	std::cout << "We have now unequipped the 4 spells that we used" << std::endl;
	std::cout << "These are the spells left on the floor" << std::endl;
	for (int i = 0; i < floorCount; i++)
		std::cout << floor[i]->getType() << std::endl;
	delete ody;
	delete evil;
	for (int j = 0; j < floorCount; j++)
		delete floor[j];

	std::cout << std::endl;
	std::cout << "======== Third Test ========" << std::endl;
	std::cout << "----- Here we will test to see if I really make deep copies -----" << std::endl;
	Character* original = new Character("Original");
	AMateria* a = new Ice();
	original->equip(a);
	Character* copy = new Character(*original);
	original->unequip(0);

	std::cout << "We have now unequipped only the spell of the original character" << std::endl;
	std::cout << "****Original's inventory****" << std::endl;
	original->use(0, *original);
	std::cout << "****Copy's inventory****" << std::endl;
	copy->use(0, *original);

	delete original;
	delete copy;
	delete a;
	return 0;
}
