#pragma once

#include <string>

class IMiniTestInterceptor {
public:
	virtual void before() = 0;
	virtual void after() = 0;

	virtual void iterCaseBefore(std::string caseName) = 0;
	virtual void iterCaseAfter(std::string caseName) = 0;
};