#pragma once
#pragma warning(disable:4996)
#ifdef CPPTESTER_EXPORT
#define CppTester_API __declspec(dllexport)
#else
#define CppTester_API __declspec(dllimport)
#endif // CPPTESTER_EXPORT
#include<string>
class TestClass {
public:
	void ClassTester();
	void ClassTester(int n);
	TestClass(int n);
private:
	int value;
};
TestClass* staobject;

//there is nothing wrong about function overload
extern "C" {
	void CreateTestClassInstance(int val) {
		staobject=new TestClass(val);
	}
	void CallClassTester() {
		staobject->ClassTester();
	}
	void CallClassTestInt(int n) {
		staobject->ClassTester(n);
	}
	void CallString(char* buf) {
		strcpy(buf, "helloworld");
	}
}
