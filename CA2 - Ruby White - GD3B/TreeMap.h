#pragma once
#include "TreeMapNode.h"
#include "BinaryTree.h"
#include <iostream>

template <class K, class V>
class TreeMap {
private:
	BinaryTree<TreeMapNode<K, V>> tree;
	void addKey(BSTNode<TreeMapNode<K, V>>* node, BinaryTree<K>& keys);
public:
	TreeMap();

	void clear();
	bool contains(K key);
	V& get(K key);
	BinaryTree<K> keySet();
	void put(K key, V value);
	int size();
	bool removeKey(K key);

	void print();

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

	while(!found) {
		if(node == nullptr)
			return false;
		if(node->getItem().key == key)
			return true;
		else if(key > node->getItem().key)
			node = node->getRight();
		else
			node = node->getLeft();
	}
}

template<class K, class V>
inline V& TreeMap<K, V>::get(K key) {
	TreeMapNode<K, V> itemToGet(key);

	return tree.get(itemToGet).value;
}

template<class K, class V>
inline BinaryTree<K> TreeMap<K, V>::keySet() {
	BinaryTree<K> keys;

	addKey(tree.root, keys);

	return keys;
}
template<class K, class V>
inline void TreeMap<K, V>::addKey(BSTNode<TreeMapNode<K, V>>* node, BinaryTree<K>& keys) {
	if(node->getLeft() != nullptr)
		addKey(node->getLeft(), keys);
	keys.add(node->getItem().key);
	if(node->getRight() != nullptr)
		addKey(node->getRight(), keys);
}

template<class K, class V>
inline void TreeMap<K, V>::put(K key, V value)
{
	TreeMapNode<K, V> newItem(key, value);
	tree.add(newItem);
}

template<class K, class V>
inline int TreeMap<K, V>::size() {
	return tree.count();
}

template<class K, class V>
inline bool TreeMap<K, V>::removeKey(K key)
{
	TreeMapNode<K, V> itemToRemove(key);

	return tree.remove(itemToRemove);
}

template<class K, class V>
inline void TreeMap<K, V>::print() {
	tree.printInOrder();
}
 

template<class K, class V>
inline V& TreeMap<K, V>::operator[](K key) {
	return this->get(key);
}

template<class K, class V>
inline TreeMap<K, V>::~TreeMap(){

}