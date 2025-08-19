#pragma once

#include <string>
#include <vector>

std::string base16_encode(const std::vector<uint8_t>& data);
std::vector<uint8_t> base16_decode(const std::string &data);