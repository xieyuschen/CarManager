#define CPPTESTER_EXPORT
#include"CppTester.h"
#include<iostream>
void TestClass::ClassTester() {
	std::cout << "Hello world from ClassTester:)";
}
void TestClass::ClassTester(int n) {
	std::cout << "The number from ClassTester if: " << n << std::endl;
}
TestClass::TestClass(int val) :value(val) {}