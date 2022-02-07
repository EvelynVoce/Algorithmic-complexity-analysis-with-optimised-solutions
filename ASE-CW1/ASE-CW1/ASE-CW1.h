#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

struct brick_names_struct;
std::unordered_map<std::string, std::string> get_all_bricks();
void update_eastern_wall(const std::unordered_map<std::string, std::string>, std::list<std::string>&);