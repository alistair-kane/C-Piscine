/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:40:15 by alkane            #+#    #+#             */
/*   Updated: 2022/07/14 15:06:22 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

static std::string	replace_all(std::string &line, const std::string &search, const std::string &replace) 
{
	for (size_t pos = 0; ; pos += replace.length()) 
	{
		pos = line.find(search, pos);
		if (pos == std::string::npos) 
			break;
		line.erase(pos, search.length());
		line.insert(pos, replace);
	}
	return (line);
}

int main(int argc, char *argv[])
{
	std::string filename;
	std::string search;
	std::string replace;
	std::string line;
	std::string result;

	if (argc != 4)
	{
		std::cerr << "Invalid amount of parameters: [" 
			<< argc - 1 << "] - Required: [3]" << std::endl;
		return (0);
	}
	filename = argv[1];
	search = argv[2];
	replace = argv[3];
	std::ifstream input_stream(filename.c_str());
	if (!input_stream)
	{
		std::cerr << "Couldn't open file: " << filename << std::endl;
		return (0);
	}
	while (getline(input_stream, line))
		result += replace_all(line, search, replace);
	std::ofstream out_file(filename.append(".replace").c_str());
	out_file << result;
	out_file.close();
	return (0);
}
