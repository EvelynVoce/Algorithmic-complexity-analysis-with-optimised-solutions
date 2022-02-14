#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <map>
#include <list>

struct brick_names_struct;
brick_names_struct get_all_bricks(std::string);
void update_western_wall(const std::map<std::string, std::string>, std::list<std::string>&);
void update_eastern_wall(const std::map<std::string, std::string>, std::list<std::string>&);
std::list<std::string> get_results(std::string);
void show_results(std::list<std::string>&);