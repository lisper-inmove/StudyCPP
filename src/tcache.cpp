#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "tcache.h"

static std::vector<std::string> values;
static std::vector<std::string> keys;

static uint16_t calculate_idx(const std::string &key) {
	uint16_t key_idx = 0;
	for (unsigned char c : key) {
		key_idx += c;
	}
	key_idx = key_idx % keys.size();
	return key_idx;
}

static std::vector<std::string> split(const std::string& value)
{
	char delimiter = ' ';
	std::string item;
	std::vector<std::string> result;
	std::stringstream ss(value);
	while (getline(ss, item, delimiter))
	{
		result.push_back(item);
	}
	return result;
}

void insert_data(const std::string& key, const std::string& data)
{
	uint16_t idx = calculate_idx(key);
	keys[idx] = key;
	values[idx] = data;
}

std::string get_data(const std::string& key)
{
	uint16_t idx = calculate_idx(key);
	std::string value = values[idx];
	return value;
}

bool delete_data(const std::string& key)
{
	uint16_t idx = calculate_idx(key);
	std::string value = get_data(key);
	if (value.empty()) {
		return false;
	}
	keys[idx].clear();
	values[idx].clear();
	return true;
}

void list_data()
{
	for (int i = 0; i < keys.size(); i++) {
		std::string key = keys[i];
		std::string value = values[i];
		if (value.empty()) {
			continue;
		}
		std::cout << "Key: " << key << ", Value: " << value << std::endl;
	}
}

void init_db(size_t size)
{
	values.resize(size);
	keys.resize(size);
}

void repl() {
	std::string input;
	while (true) {
		std::cout << ">> ";
		std::getline(std::cin, input);
		if (input == "quit" || input == "q") {
			break;
		}
		//std::cout << "User input: " << input << std::endl;
		std::vector<std::string> parts = split(input);
		if (parts.size() == 1) {
			if (parts[0] == "list") {
				list_data();
			}
		}
		else if (parts.size() == 2) {
			if (parts[0] == "delete") {
				delete_data(parts[1]);
			}
			else if (parts[0] == "get") {
				std::string value = get_data(parts[1]);
				if (value.empty()) {
					continue;
				}
				else {
					std::cout << "Get value for '" << parts[1] << "' is: " << value << std::endl;
				}
			}
		}
		else if (parts.size() == 3) {
			if (parts[0] == "set") {
				insert_data(parts[1], parts[2]);
			}
		}
	}
}

/**
 *int main()
{
	init_db(2048);

	insert_data("Job", "Teacher");
	insert_data("Name", "inmove");
	insert_data("Hobby", "Ð´´úÂë");

	string data = get_data("Job");
	if (!data.empty())
	{
		cout << "Data for 'Job' is: " << data << endl;
	} else
	{
		cout << "No data found for 'Job'" << endl;
	}

	list_data();

	bool flag = delete_data("Job");
	if (flag)
	{
		cout << "Remove data for 'Job' successfully." << endl;
	} else
	{
		cout << "Failed to remove data for 'Job'." << endl;
	}

	list_data();

	cout << "tcache repl is running...." << endl;
	repl();

	return 0;
}
 *
 * 
 */