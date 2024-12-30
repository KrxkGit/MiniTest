#pragma once

#include "ASSERT.h"
#include "MiniTest.h"

#define MTEST_ITEM(name) \
	void test_##name(); \
	struct Register##name { \
		Register##name() { \
			MiniTest::addTest(#name, test_##name); \
		}\
	} reg##name##Instance; \
	void test_##name()


#define MTEST_RUN(interceptorPtr) \
	MiniTest::setTestInterceptor(interceptorPtr); \
	MiniTest::runAllTest()