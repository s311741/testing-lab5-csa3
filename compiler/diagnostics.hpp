#pragma once
#include <cstdio>
#include <cstdlib>
#include <fmt/core.h>
#include <utility>

// Compiler error, for when the victim Lisp program is beyond repair
template<typename... Args>
[[noreturn]] void error
(const fmt::format_string<Args...>& fmt, Args&&... args) {
  std::fputs("Error: ", stderr);
  fmt::print(stderr, fmt, std::forward<Args>(args)...);
  std::fputc('\n', stderr);
  std::fflush(stderr);
  std::exit(1);
}