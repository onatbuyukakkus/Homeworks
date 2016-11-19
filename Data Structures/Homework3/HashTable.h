/*
 * HashTable.h
 *
 *  Created on: Dec 23, 2014
 *      Author: dilek
 */
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

template<typename Key, typename Value>
class HashEntry {					
public:
	// public functions
	HashEntry(const Key& k = Key(), const Value& v = Value())
	:
			_key(k), _value(v) {
	}
	const Key& key() const {
		return _key;
	}		// get key
	const Value& value() const {
		return _value;
	}		// get value
	void setKey(const Key& k) {
		_key = k;
	}		// set key
	void setValue(const Value& v) {
		_value = v;
	}		// set value
private:
	// private data
	Key _key;		// key
	Value _value;	// value
};

template<class Key, class Value>
class HashTable {

public:

	typedef HashEntry<Key, Value> Entry; // a (key,value) pair
	typedef std::list<Entry> Bucket; // a bucket of entries
	typedef std::vector<Bucket> BktArray;	// a bucket array

	HashTable(const Value & notFound, int capacity = 101) :
			ITEM_NOT_FOUND(notFound), capacity(capacity), bucketArray(capacity) {
	}

	HashTable(const HashTable & rhs) :
			ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND), capacity(rhs.capacity), bucketArray(
					rhs.bucketArray) {
	}

	HashTable & operator=(const HashTable & rhs);

	// Insert method adds the new key,value pair to the table if key is not found.
	// If key is found, its value is updated.
	void insert(const Key& key, const Value & value);

	void remove(const Key& key);

	// find method returns ITEM_NOT_FOUND if there exists no item with Key=key
	const Value & find(const Key& key) const;

	void print() const;

private:

	int capacity;
	const Value ITEM_NOT_FOUND;
	BktArray bucketArray;  

};

inline int hashFunction(int key, int tableSize) {
	return key % tableSize;
}

inline int hashFunction(long key, int tableSize) {
	return key % tableSize;
}

template<class Key, class Value>
HashTable<Key, Value>& HashTable<Key, Value>::operator=(
		const HashTable & other) {

	if (this != &other) {
		this->capacity = other.capacity;
		this->bucketArray = other.bucketArray;
		this->ITEM_NOT_FOUND = other.ITEM_NOT_FOUND;
	}
	return *this;
}

template<class Key, class Value>
void HashTable<Key, Value>::insert(const Key& key, const Value& value) {

	int h = hashFunction(key, capacity);
	Bucket& whichBucket = bucketArray[h];
	typename Bucket::iterator itr = whichBucket.begin();
	while (itr != whichBucket.end() && ((*itr).key()) != key)
		itr++;

	if (itr == whichBucket.end()) 
		whichBucket.push_back(Entry(key, value));
	else
		(*itr).setValue(value);

}

template<class Key, class Value>
void HashTable<Key, Value>::remove(const Key& key) {

	int h = hashFunction(key, capacity);
	Bucket& whichBucket = bucketArray[h];
	typename Bucket::iterator itr = whichBucket.begin();
	while (itr != whichBucket.end() && ((*itr).key()) != key)	
		itr++;

	if (itr != whichBucket.end()) 
		whichBucket.erase(itr);

}

template<class Key, class Value>
const Value& HashTable<Key, Value>::find(const Key& key) const {

	int h = hashFunction(key, capacity);
	const Bucket& whichBucket = bucketArray[h];
	typename Bucket::const_iterator itr = whichBucket.begin();
	while (itr != whichBucket.end() && ((*itr).key()) != key)	
		itr++;

	if (itr == whichBucket.end())
		return ITEM_NOT_FOUND;
	else
		return (*itr).value();
}

template<class Key, class Value>
void HashTable<Key, Value>::print() const {

	for (int i = 0; i < this->capacity; i++) {

		typename Bucket::const_iterator itr = bucketArray[i].begin();

		for (; itr != bucketArray[i].end(); itr++) {
			cout << (*itr).key() << "," << (*itr).value() << " ";
		}
		cout << endl;
	}
}

#endif //HASHTABLE_H_
