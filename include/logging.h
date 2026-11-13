#pragma once

#include <iostream>
#include <cstring>

enum ErrCode {NoErr, Err1, Err2, Err3};

struct ErrObj { 

	ErrCode code{}; 
	const char * status = ""; 
	explicit operator bool() const { return (code == ErrCode::NoErr || strlen(status) == 0) ? false : true; }
};

std::ostream & operator <<(std::ostream &err, const ErrObj& obj) {

	err << "Error " << obj.code << " - " << obj.status;

	return err; 
}

#define LOG(stream, msg) stream << "[LOG]: " << msg << "\n" 

#define ERR(obj) std::cerr << "[ERR]: " << obj << "\n" 

#define PRINT(msg) std::cout << msg << "\n"

#ifdef NDEBUG

#define DEBUG(msg) ((void)(0))

#else

#define DEBUG(msg) std::cout << "[DEBUG]: " << __FILE__ << ":" << __LINE__ << " - " << msg << "\n"

#endif
