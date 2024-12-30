#pragma once

#include <string>
#include <vector>
#include "IMiniTestInterceptor.h"

using MTest_WrapFunc = void (*)();

class MiniTest {
protected:
	struct TestCase {
		std::string name;
		MTest_WrapFunc func;
	};
	static std::vector<TestCase> _tests;
	static IMiniTestInterceptor* _interceptor;
public:
	static void setTestInterceptor(IMiniTestInterceptor* inceptor);
	static void addTest(const std::string& name, MTest_WrapFunc wrapFunc);
	static void runAllTest();
};
