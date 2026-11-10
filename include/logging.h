#pragma once

#include <iostream>
#include <fstream>

static std::ofstream logFile("dynamic.log", std::ios::app);

#define LOG(msg) logFile << "[LOG]: " << msg << std::endl

#define ERR(msg) std::cerr << "[ERR]: " << msg << std::endl

#define PRINT(msg) std::cout << msg << std::endl

#ifdef NDEBUG

#define DEBUG(msg) ((void)(0))

#else

#define DEBUG(msg) std::cout << "[DEBUG]: " << __FILE__ << ":" << __LINE__ << " - " << msg << std::endl

#endif
