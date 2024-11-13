#pragma once

template <class K, class V>
struct TreeMapNode {
public:
	K key;
	V value;

	TreeMapNode(K key, V value) {
		this->key = key;
		this->value = value;
	}

	bool operator==(TreeMapNode<K, V>& node) { return this->key == node.key; }
	bool operator<(TreeMapNode<K, V>& node) { return this->key < node.key; }
	bool operator>(TreeMapNode<K, V>& node) { return this->key > node.key; }
};