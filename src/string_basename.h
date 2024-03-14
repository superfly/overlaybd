// XXX: This is just to get tests to build when the basename(3)
// available is the POSIX variety, which (unlike the GNU variety) may
// modify its argument. The POSIX and GNU varieties have slightly
// different behavior, which we're not accounting for here. Beware!

#pragma once

#include <libgen.h>
#include <string.h>
#include <string>

static std::string string_basename(const std::string &s) {
    char *c_str = new char[s.length() + 1];
    strcpy(c_str, s.c_str());
    auto base = std::string(basename(c_str));
    delete[] c_str;
    return base;
}
