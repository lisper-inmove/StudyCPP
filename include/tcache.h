#pragma once

#include <string>
#include <vector>

void insert_data(const std::string &key, const std::string &data);
std::string get_data(const std::string &key);
bool delete_data(const std::string &key);
void list_data();
void init_db(size_t size);
void repl();