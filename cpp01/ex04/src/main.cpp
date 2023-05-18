/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:19:12 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/18 15:26:57 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

std::string	replace(std::string line, std::string s1, std::string s2) {
	std::string	tmp;
	int	len = s1.length();
	for (int i = 0; line[i]; i++) {
		if (!std::strncmp(&line.c_str()[i], s1.c_str(), len)) {
			tmp.append(s2);
			i += len - 1;
		}
		else
			tmp.push_back(line.c_str()[i]);
	}
	return (tmp);
}

int	main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cout << "Incorrect amount of arguments\n";
		return (0);
	}
	std::string	filename = argv[1];
	std::ifstream	file1(filename.c_str());
	if (!file1) {
		std::perror("Opening file1 failed");
		return (-1);
	}
	std::ofstream	file2((filename + ".replace").c_str());
	if (!file2) {
		file1.close();
		std::perror("Opening file2 failed");
		return (-1);
	}
	std::string	line;
	while(std::getline(file1, line) && !file1.bad() && !file1.eof())
	{
		line = replace(line, argv[2], argv[3]);
		file2 << line << '\n';
		if (file2.bad())
		{
			file1.close();
			file2.close();
			std::perror("Error writing to file2");
			return (-1);
		}
		line.clear();
	}
	if (file1.bad())
	{
		file1.close();
		file2.close();
		std::perror("Error writing to file1");
		return (-1);
	}
	file1.close();
	file2.close();
	return (0);
}
