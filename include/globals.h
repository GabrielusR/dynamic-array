#pragma once

#include <iostream>

#define LOG(msg) std::cout << "[LOG] LINE " << __LINE__ << ": " << msg << std::endl

#ifdef NDEBUG

#define DEBUG(msg) ((void)(0))

#else

#define DEBUG(msg) std::cout << "[DEBUG] LINE " << __LINE__ << ": " << msg << std::endl

#endif
