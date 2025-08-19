#include <vector>
#include "spdlog_test.h"

void spdlog_test() {
	spdlog::info("console");
	spdlog::stdout_color_mt("console");
	std::vector<std::uint8_t> test_vector{ 0x48, 0x65, 0x6C, 0x6C, 0x6F }; // "Hello" in ASCII
	//cnsl("ptr: {}", static_cast<void*>(test_vector.data()));
	// spdlog::get("console")->info("Hello: {}", 13);
	cnsl("Hello, {}", 13);
}