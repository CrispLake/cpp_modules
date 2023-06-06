/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:44:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/06 13:01:11 by emajuri          ###   ########.fr       */
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

	dynamic_cast<const Dog*>(animals[0])->getBrain()->setIdea("Good idea");
	dynamic_cast<const Dog*>(animals[0])->getBrain()->setIdea("Bad idea");
	dynamic_cast<const Dog*>(animals[0])->getBrain()->printIdeas();

	const Dog dog = *dynamic_cast<const Dog *>(animals[0]);
	dog.getBrain()->printIdeas();
	std::cout << "\n";
	dog.getBrain()->setIdea("Worst idea");
	dog.getBrain()->printIdeas();

	std::cout << "\n";
	dynamic_cast<const Dog*>(animals[0])->getBrain()->printIdeas();


	std::cout << "\n";

	for(int i = 0; i < count; i++) {
		delete animals[i];
	}
	std::cout << "\n";

	return 0;
};
