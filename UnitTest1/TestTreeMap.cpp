#pragma once
#include "CppUnitTest.h"
#include "../CA2 - Ruby White - GD3B/TreeMapNode.h"
#include <iostream>
#include "../CA2 - Ruby White - GD3B/TreeMap.h"


// I AM UNABLE TO RUN MY TESTS BECAUSE OF AN ERROR
//Severity	Code	Description	Project	File	Line	Suppression State	Details
//Error	LNK2019	unresolved external symbol main referenced in function "int __cdecl invoke_main(void)" (? invoke_main@@YAHXZ)	SplitWords	C : \Users\ruby_\Desktop\college\!Year THREE\dataStructs\CA2\CA2 - Ruby White - GD3B\SplitWords\MSVCRTD.lib(exe_main.obj)	1

// IT WILL NOT GO AWAY
// I WILL WRITE TESTS BUT THERE IS NO GUARENTEE THEY WORK

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestTreeMap
{
	TEST_CLASS(TestTreeMapNode)
	{
	public:
		// testing with and without the different value to make sure it has not effect on the output
		TEST_METHOD(TestNodeEqualsDifferentValues) {
			TreeMapNode<std::string, int> node("test", 100);
			TreeMapNode<std::string, int> node2("test", 20);

			Assert::IsTrue(node == node2);
		}
		TEST_METHOD(TestNodeNotEqualsDifferentValues) {
			TreeMapNode<std::string, int> node("test", 100);
			TreeMapNode<std::string, int> node2("no test", 20);

			Assert::IsFalse(node == node2);
		}
		TEST_METHOD(TestNodeEqualsSameValues) {
			TreeMapNode<std::string, int> node("test", 100);
			TreeMapNode<std::string, int> node2("test", 100);

			Assert::IsTrue(node == node2);
		}
		TEST_METHOD(TestNodeNotEqualsSameValues) {
			TreeMapNode<std::string, int> node("test", 100);
			TreeMapNode<std::string, int> node2("no test", 100);

			Assert::IsFalse(node == node2);
		}


		TEST_METHOD(TestNodeGreaterDifferentValues) {
			TreeMapNode<std::string, int> node("Atest", 100);
			TreeMapNode<std::string, int> node2("Ztest", 20);

			Assert::IsFalse(node > node2);
			Assert::IsTrue(node2 > node);
		}
		TEST_METHOD(TestNodeGreaterSameValues) {
			TreeMapNode<std::string, int> node("Atest", 100);
			TreeMapNode<std::string, int> node2("Ztest", 100);

			Assert::IsFalse(node > node2);
			Assert::IsTrue(node2 > node);
		}

		TEST_METHOD(TestNodeLesserDifferentValues) {
			TreeMapNode<std::string, int> node("Atest", 100);
			TreeMapNode<std::string, int> node2("Ztest", 20);

			Assert::IsFalse(node2 < node);
			Assert::IsTrue(node < node2);
		}
		TEST_METHOD(TestNodeLesserSameValues) {
			TreeMapNode<std::string, int> node("Atest", 100);
			TreeMapNode<std::string, int> node2("Ztest", 100);

			Assert::IsFalse(node2 < node);
			Assert::IsTrue(node < node2);
		}
	};

	TEST_CLASS(TestTreeMap) {
	public:
		TreeMap<std::string, int> map;
		TEST_METHOD_INITIALIZE(setup) {
			
			map.put("John", 20);
			map.put("Bill", 18);
			map.put("Zack", 23);
			map.put("Paula", 22);
			map.put("Ciara", 21);
		}

		TEST_METHOD(TestGetSuccess) {
			Assert::AreEqual(20, map.get("John"));
			Assert::AreEqual(18, map.get("Bill"));
			Assert::AreEqual(23, map.get("Zack"));
		}
		TEST_METHOD(TestAdd) {
			map.put("Terry", 26);
			Assert::AreEqual(26, map.get("Terry"));
		}
		TEST_METHOD(TestCount) {
			Assert::AreEqual(5, map.size());
		}
		TEST_METHOD(TestCount) {
			Assert::AreEqual(5, map.size());
		}
		TEST_METHOD(TestRemove) {
			map.removeKey("Zack");
			Assert::AreEqual(4, map.size());
		}

	};
}
