// ASE-CW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

std::unordered_map<std::string, std::string> get_all_bricks()
{
    std::unordered_map<std::string, std::string> brick_names;
    std::ifstream infile("input-pairs-20.txt");
    if (!infile.good()) throw "File not found";
    std::string line;
    while (std::getline(infile, line)) {
        const size_t pos = line.find(",");
        const std::string side1 = line.substr(0, pos);
        const std::string side2 = line.substr(pos + 1);
        brick_names.insert({ side1, side2 });
    }
    infile.close();
    return brick_names;
    
}

int main()
{
    std::unordered_map<std::string, std::string> brick_names = get_all_bricks();

    auto const start_point = brick_names.begin();
    std::list<std::string> result = { start_point->first, start_point->second};

    while (brick_names.find(result.back()) != brick_names.end()) {
        std::unordered_map<std::string, std::string>::const_iterator found_at = brick_names.find(result.back());
        result.push_back(found_at->second);
    }

    for (auto const& answers : result) {
        std::cout << answers << std::endl;
    }
}