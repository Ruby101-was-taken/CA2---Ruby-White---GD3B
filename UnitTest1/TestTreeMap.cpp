#pragma once
#include "CppUnitTest.h"
#include "../CA2 - Ruby White - GD3B/TreeMapNode.h"
#include <iostream>

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
}
