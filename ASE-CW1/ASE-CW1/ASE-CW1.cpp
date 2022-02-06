// ASE-CW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

int main()
{

    std::ifstream infile("input-pairs-20.txt");

    if (!infile.good()) std::cout << "File not found" << std::endl;
    else {
        std::unordered_map<std::string, std::string> brick_names;
        std::string line;
        while (std::getline(infile, line)) {
            const size_t pos = line.find(",");
            const std::string side1 = line.substr(0, pos);
            const std::string side2 = line.substr(pos+1);
            brick_names.insert({side1, side2});
        }
        infile.close();
        for (auto const& pair : brick_names) {
            std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        }
    }

}