#include <sstream>
#include <vector>
#include <fcntl.h>
#include <stdarg.h>
#include <assert.h>
#include <cstdio>

#include "define.h"

std::string trimLeft(const std::string & input);
std::string trimRight(const std::string & input);

std::string trim(const std::string & input);

void explode(const std::string & input, char sep, std::vector<std::string> & output);

void debug_printf(int i, const char * format, ...);

void clr_fl(int fd, int flags);