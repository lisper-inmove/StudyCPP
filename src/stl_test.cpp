#include <vector>
#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <map>

using namespace std;

std::pair<int, int> divide_reminder(int dividend, int divisor)
{
	return std::make_pair(dividend / divisor, dividend % divisor);
}

std::tuple<std::string, std::chrono::system_clock::time_point, unsigned> stock_info(const std::string &name)
{
	return std::make_tuple(name, std::chrono::system_clock::now(), 100);
}

void stl_test() {
	const auto result = divide_reminder(27, 8);
	auto [fraction, remainder] = divide_reminder(93, 7);
	auto [a1, a2, a3] = stock_info("AAPL");

	map<std::string, size_t> animal_population{
		{"Humans", 70000000},
		{"Chickens", 12321341234},
	};
	for (const auto &[species, count] : animal_population)
	{
		cout << species << ": " << count << endl;
	}

	if (auto iter (animal_population.find("Humans")); iter != animal_population.end())
	{
		cout << "Not the end\n";
	} else
	{
		cout << "The end\n";
	}

	{
		std::vector<int> v1{ 1, 2 };
		std::vector<int> v2(3, 4);
	}
	cout << "End \n";
}