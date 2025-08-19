#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#define cnsl(...) spdlog::get("console")->info("[{}:{}] {}", __FILE__, __LINE__, fmt::format(__VA_ARGS__))
