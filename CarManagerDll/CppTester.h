#pragma once
#ifdef CPPTESTER_EXPORT
#define CppTester_API __declspec(dllexport)
#else
#define CppTester_API __declspec(dllimport)
#endif // CPPTESTER_EXPORT

extern "C" {
	void Test();
}
