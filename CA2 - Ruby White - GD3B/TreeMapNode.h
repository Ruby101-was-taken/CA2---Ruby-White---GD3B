#pragma once
#include <iostream>
#include <string>

template <class K, class V>
struct TreeMapNode {
public:
	K key;
	V value;

	TreeMapNode(K key, V value) {
		this->key = key;
		this->value = value;
	}
	TreeMapNode(K key) {
		this->key = key;
	}
	TreeMapNode() {
	}

	bool operator==(TreeMapNode<K, V>& node) { return this->key == node.key; }
	bool operator<(TreeMapNode<K, V>& node) { return this->key < node.key; }
	bool operator>(TreeMapNode<K, V>& node) { return this->key > node.key; }

	friend std::ostream& operator<<(std::ostream& out, const TreeMapNode<K, V>& node) {
		out << "{'" << node.key << "':\t" << node.value << "}";
		return out;
	}
};