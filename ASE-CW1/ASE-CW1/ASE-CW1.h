#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

struct brick_names_struct;
brick_names_struct get_all_bricks();
void update_western_wall(const std::unordered_map<std::string, std::string>, std::list<std::string>&);
void update_eastern_wall(const std::unordered_map<std::string, std::string>, std::list<std::string>&);