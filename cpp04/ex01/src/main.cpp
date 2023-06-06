/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:44:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/06 11:14:13 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	const Animal *animals[20];
	int	count = 5;

	for(int i = 0; i < count; i++) {
		if (i <= count / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "\n";

	dynamic_cast<const Dog *>(animals[0])->getBrain()->setIdea("Good idea");
	dynamic_cast<const Dog *>(animals[0])->getBrain()->setIdea("Bad idea");
	dynamic_cast<const Dog *>(animals[0])->getBrain()->printIdeas();

	std::cout << "\n";

	for(int i = 0; i < count; i++) {
		delete animals[i];
	}

	return 0;
};
