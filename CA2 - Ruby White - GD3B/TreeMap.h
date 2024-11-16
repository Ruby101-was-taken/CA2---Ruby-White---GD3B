#pragma once
#include "TreeMapNode.h"(
#include "BinaryTree.h"

template <class K, class V>
struct TreeMap {
private:
	BinaryTree<TreeMapNode<K, V>> tree;

public:
	TreeMap();

	void clear();
	bool contains(K key);
	V& get(K key);
	BinaryTree<K> keySet();
	void put(K key, V value);
	int size();
	bool removeKey(K key);

	V& operator[](K key);

	~TreeMap();
};

template<class K, class V>
inline TreeMap<K, V>::TreeMap(){
	
}

template<class K, class V>
inline void TreeMap<K, V>::clear() {
	tree.clear();
}

template<class K, class V>
inline bool TreeMap<K, V>::contains(K key) {
	bool found = false;
	BSTNode<TreeMapNode<K, V>>* node = tree.root;

	while (!found) {
		if (node == nullptr)
			return false;
		if (node->getItem().key == key)
			return true;
		else if (key > node->getItem().key)
			node = node->getRight();
		else
			node = node->getLeft();
	}
}

template<class K, class V>
inline V& TreeMap<K, V>::get(K key) {
	bool found = false;
	BSTNode<TreeMapNode<K, V>>* node = tree.root;

	while (!found) {
		if (node == nullptr)
			return nullptr;
		if (node->getItem().key == key)
			return node->getItem();
		else if (key > node->getItem().key)
			node = node->getRight();
		else
			node = node->getLeft();
	}
}

template<class K, class V>
inline BinaryTree<K> TreeMap<K, V>::keySet()
{
	return BinaryTree<K>();
}

template<class K, class V>
inline void TreeMap<K, V>::put(K key, V value)
{
	TreeMapNode<K, V>* newItem = TreeMapNode<K, V>(key, value);
	bool found = false;
	BSTNode<TreeMapNode<K, V>>* node = tree.root;

	while(!found) {
		if(node->getItem().key == key) { // if the keys match the value should be replaced
			node->getItem().value = value;
			return;
		}

		// Otherwise, chech if the key is greater than or less than the key were are looking to add
		// then we try get the node on the left or right and if it exists we do the loop again
		// otherwise we add a new node

		else if(key > node->getItem().key) {
			if(node->getRight() != nullptr) {
				node = node->getRight();
			}
			else {
				node->setRight(newItem);
				return;
			}
		}
		else {
			if(node->getLeft() != nullptr) {
				node = node->getLeft();
			}
			else {
				node->setLeft(newItem);
				return;
			}
		}
	}
}

template<class K, class V>
inline int TreeMap<K, V>::size()
{
	return 0;
}

template<class K, class V>
inline bool TreeMap<K, V>::removeKey(K key)
{
	return false;
}

template<class K, class V>
inline V& TreeMap<K, V>::operator[](K key)
{
	// TODO: insert return statement here
}

template<class K, class V>
inline TreeMap<K, V>::~TreeMap(){

}
