#pragma once

#include "MiniTestException.h"


#define ASSERT(condition) \
	if (!(condition)) { \
		throw MiniTestException(__FILE__, __LINE__); \
	}


#define ASSERT_EQ(expected, actual) \
	if ((expected) != (actual)) { \
		throw MiniTestException(__FILE__, __LINE__); \
	}