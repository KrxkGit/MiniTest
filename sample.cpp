// MiniTest.cpp: 定义应用程序的入口点。
//

// 导入 MTest 所需头文件
#include "MTest/include/MTest.h"

#include <iostream>

// 定义测试拦截器
class MyInterceptor : public IMiniTestInterceptor {
public:
	// 所有测试开始前执行
	void before() {
		std::cout << "before" << std::endl;
	}

	// 所有测试结束后执行
	void after() {
		std::cout << "after" << std::endl;
	}

	// 每项测试开始前执行
	void iterCaseBefore(std::string caseName) {
		std::cout << "iterCase Before: " << caseName << std::endl;
	}

	// 每项测试结束后执行
	void iterCaseAfter(std::string caseName) {
		std::cout << "iterCase After: " << caseName << std::endl;
	}
};

// 待测试函数
template<typename _T>
_T add(_T a, _T b) {
	return a + b;
}

// 添加测试项 1
MTEST_ITEM(Add) {
	// 相等断言
	ASSERT_EQ(8, add<int>(3, 5));
}

// 添加测试项 2
MTEST_ITEM(Add2) {
	// 使用异常捕获模式，如果不使用将采用直接崩溃模式
	try {
		ASSERT_EQ(4, add<int>(2, 2));
		ASSERT_EQ(4, add<int>(3, 5));
	}
	catch (const MiniTestException& e) {
		std::cout << e.what();
	}
}

// 添加测试项 3
MTEST_ITEM(Any) {
	try {
		// 条件断言
		ASSERT(1 == 2);
	}
	catch (const MiniTestException& e) {
		std::cout << e.what();
	}
}


int main()
{
	auto interceptor = std::make_shared<MyInterceptor>();
	
	// 启动所有测试
	MTEST_RUN(interceptor.get());
	return 0;
}
