// ASE-CW1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "ASE-CW1.h"

struct brick_names_struct {
    std::unordered_map<std::string, std::string> inorder;
    std::unordered_map<std::string, std::string> reverse_order;
};

brick_names_struct get_all_bricks()
{
    brick_names_struct brick_names;
    std::ifstream infile("Great_Wall_Problem-test_data//20//input-pairs-20.txt");
    if (!infile.good()) throw "Error: File not found";
    std::string line;
    while (std::getline(infile, line)) {
        const size_t pos = line.find(",");
        const std::string side1 = line.substr(0, pos);
        const std::string side2 = line.substr(pos + 1);
        brick_names.inorder.insert({ side1, side2 });
        brick_names.reverse_order.insert({ side2, side1});
    }
    infile.close();
    return brick_names;
}

void update_western_wall(const std::unordered_map<std::string, std::string> brick_names, std::list<std::string>& result)
{
    while (brick_names.find(result.front()) != brick_names.end()) {
        const std::unordered_map<std::string, std::string>::const_iterator found_at = brick_names.find(result.front());
        result.push_front(found_at->second);
    }
}

void update_eastern_wall(const std::unordered_map<std::string, std::string> brick_names, std::list<std::string>& result)
{
    while (brick_names.find(result.back()) != brick_names.end()) {
        const std::unordered_map<std::string, std::string>::const_iterator found_at = brick_names.find(result.back());
        result.push_back(found_at->second);
    }
}

int main()
{
    const brick_names_struct brick_names = get_all_bricks();

    const std::unordered_map<std::string, std::string>::const_iterator start_point = brick_names.inorder.begin();
    std::list<std::string> result = { start_point->first, start_point->second};

    update_eastern_wall(brick_names.inorder, result);
    update_western_wall(brick_names.reverse_order, result);
    
    std::cout << "Done\n" << std::endl;
    for (std::string const& answers : result) {
        std::cout << answers << std::endl;
    }
}


/* // Test to see if the need for reversed unordered map could be removed efficiently
void update_western_wall(const std::unordered_map<std::string, std::string> brick_names, std::list<std::string>& result)
{
    bool keep_going = true;
    while (keep_going) {
        keep_going = false;
        for (auto found_at = brick_names.begin(); found_at != brick_names.end(); ++found_at) {
            if (found_at->second == result.front()) {
                result.push_front(found_at->first);
                keep_going = true;
            }
        }
    }
} */