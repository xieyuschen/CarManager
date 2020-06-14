#pragma once
#ifdef CPPTESTER_EXPORT
#define CppTester_API __declspec(dllexport)
#else
#define CppTester_API __declspec(dllimport)
#endif // CPPTESTER_EXPORT
class TestClass {
public:
	void ClassTester();
	void ClassTester(int n);
	TestClass(int n);
private:
	int value;
};
TestClass* staobject;
extern "C" {
	void CreateTestClassInstance(int val) {
		staobject=new TestClass(val);
	}
	void CallClassTester() {
		staobject->ClassTester();
	}
}
