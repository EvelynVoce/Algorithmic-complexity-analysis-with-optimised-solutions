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
        std::string line;
        while (std::getline(infile, line)) {

            // std::unordered_map<std::string, std::string> example = { {,'a'},{2,'b'}};

            const int pos = line.find(",");
            const std::string side1 = line.substr(0, pos);
            const std::string side2 = line.substr(pos+1);
            std::cout << side1 << " " << side2 << std::endl;
        }
        infile.close();
    }

}