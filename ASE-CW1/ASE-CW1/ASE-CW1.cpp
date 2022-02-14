// ASE-CW1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "ASE-CW1.h"

struct brick_names_struct {
    std::unordered_map<std::string, std::string> inorder;
    std::unordered_map<std::string, std::string> reverse_order;
};

struct test_data {
    std::string label;
    std::string path;
};

brick_names_struct get_all_bricks(std::string path)
{
    path.erase(std::remove_if(path.begin(), path.end(), ::isspace), path.end());
    brick_names_struct brick_names;
    std::ifstream infile(path);
    if (!infile.good()) throw std::invalid_argument("Error: File not found");
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

std::list<std::string> get_results(std::string path) {
    const brick_names_struct brick_names = get_all_bricks(path);
    const std::unordered_map<std::string, std::string>::const_iterator start_point = brick_names.inorder.begin();
    std::list<std::string> result = { start_point->first, start_point->second };

    update_western_wall(brick_names.reverse_order, result);
    update_eastern_wall(brick_names.inorder, result);
    return result;
}


void show_results(std::list<std::string>& result) {
    for (std::string const& answers : result) {
        std::cout << answers << std::endl;
    }
}

std::list<test_data> get_test_data() {
    std::ifstream infile("Great_Wall_Problem-test_data\\paths.txt");
    if (!infile.good()) throw std::invalid_argument("Error: File not found");
    std::list<test_data> paths = {};
    std::string line;
    while (std::getline(infile, line)) {
        const size_t pos = line.find(",");
        const std::string label = line.substr(0, pos);
        const std::string path_found = line.substr(pos + 1);
        test_data test_instance = { label, path_found };
        paths.push_back(test_instance);
    }
    infile.close();
    return paths;
}

int main()
{
    std::list<test_data> paths = get_test_data();
    for (test_data x : paths) {
        auto start = std::chrono::high_resolution_clock::now();
        std::list<std::string> result = get_results(x.path);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << x.label << "\t" << duration.count() << std::endl;
    }
    
}