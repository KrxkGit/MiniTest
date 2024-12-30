#include "../Definition/MiniTest.h"

IMiniTestInterceptor* MiniTest::_interceptor = nullptr;
std::vector<MiniTest::TestCase> MiniTest::_tests;


void MiniTest::addTest(const std::string& name, MTest_WrapFunc wrapFunc) {
	_tests.push_back({ name, wrapFunc });
}

void MiniTest::runAllTest() {
	if (_interceptor != nullptr) {
		_interceptor->before();
	}
	
	for (const auto& test : _tests) {
		if (_interceptor != nullptr) {
			_interceptor->iterCaseBefore(test.name);
		}

		test.func();

		if (_interceptor != nullptr) {
			_interceptor->iterCaseAfter(test.name);
		}
	}

	if (_interceptor != nullptr) {
		_interceptor->after();
	}
}

void MiniTest::setTestInterceptor(IMiniTestInterceptor* inceptor) {	
	_interceptor = inceptor;
}

