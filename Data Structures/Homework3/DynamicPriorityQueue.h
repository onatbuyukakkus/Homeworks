/*
 * DynamicPriorityQueue.h
 *
 *  Created on: Dec 23, 2014
 *      Author: dilek
 */

#ifndef DYNAMICPRIORITYQUEUE_H_
#define DYNAMICPRIORITYQUEUE_H_

#include <vector>
#include "HashTable.h"


template<class Key, class Priority>
class DynamicPriorityQueue {

public:

    	DynamicPriorityQueue(Priority itemNotFound,Key queueEmpty,int capacity)
            : ITEM_NOT_ON_QUEUE(itemNotFound), QUEUE_EMPTY(queueEmpty),
            capacity(capacity)
    	{
		// NOTE: You may update constructor yet do not modify the signature!!
		iTable= new HashTable<Key,int> (-1,capacity);
		array.push_back(HashEntry<Key,Priority>());
		
    	}
    
	// Should be called for adding items to the queue.
	// The method will not have no effect if the item is already on the queue. 
	void insert(const Key& key, const Priority& priority);

	// NOTE: This method is expected to return QUEUE_EMPTY, 
	// if the queue is empty
	const Key deleteMin();

	// Will update the priority value of the item if it is on the queue
	// will not effect the queue otherwise. 
	void updatePriority(const Key& key, const Priority& newPriority);

	// NOTE: This method is expected to return ITEM_NOT_ON_QUEUE, 
	// if the item with the key is not on the queue
	const Priority& getPriority(const Key& key) const;

	// NOTE: print method will not be tested, you may use for debugging purposes.
	void print();

private:

	int capacity;
    	const Priority ITEM_NOT_ON_QUEUE;
    	const Key QUEUE_EMPTY;

	// NOTE: You may add private members or method declarations under this line
	
	HashTable <Key,int>* iTable;
	vector <HashEntry<Key,Priority> > array;
	void percolateDown(int);
	void percolateUp(int);
};

#endif /* DYNAMICPRIORITYQUEUE_H_ */

// NOTE: Place your method implementations under this line.

template<class Key, class Priority>
void DynamicPriorityQueue<Key, Priority>::insert(const Key& key, const Priority& priority) 
{
	array[0].setValue(priority);
	array[0].setKey(key);

	int hole = array.size();
	array.push_back(HashEntry<Key,Priority>());
	for( ; priority<array[hole/2].value(); hole/= 2)
	{
		array[hole].setValue(array[hole/2].value());
		array[hole].setKey(array[hole/2].key());
		iTable->insert(array[hole/2].key(),hole);
	}
	array[hole].setValue(priority);
	array[hole].setKey(key);
	iTable->insert(key,hole);
}

template<class Key, class Priority>
const Priority& DynamicPriorityQueue<Key, Priority>::getPriority(const Key& key) const
{
	if(iTable->find(key) == -1)
	{
		return ITEM_NOT_ON_QUEUE;
	}
	else
	{
		return array[iTable->find(key)].value();
	}
}

template<class Key, class Priority>
const Key DynamicPriorityQueue<Key, Priority>::deleteMin()
{
	if(array.size()==1)
	{
		return QUEUE_EMPTY;
	}
	else
	{
		Key temp = array[1].key();
		array[1].setValue(array[array.size()-1].value());
		array[1].setKey(array[array.size()-1].key());
		array.pop_back();
		percolateDown(1);
		return temp;
	}
    
}

template<class Key, class Priority>
void DynamicPriorityQueue<Key, Priority>::percolateDown( int hole )
{
	int child;
	Priority tmp = array[hole].value();
	Key ky = array[hole].key();
	for( ; hole*2<=array.size()-1; hole=child )
	{
		child = hole*2;
		if(child != array.size()-1 && array[child+1].value() < array[child].value())
		{
			child++;
		}
		if(array[child].value() < tmp)
		{
			array[hole].setValue(array[child].value());
			array[hole].setKey(array[child].key());
			iTable->insert(array[child].key(),hole);
		}
		else
		{
			break;
		}
	}
	array[hole].setValue(tmp);
	array[hole].setKey(ky);
	iTable->insert(array[hole].key(),hole);
}

template<class Key, class Priority>
void DynamicPriorityQueue<Key, Priority>::updatePriority(const Key& key, const Priority& newPriority)
{
	if(iTable->find(key) == -1)
	{
		ITEM_NOT_ON_QUEUE;		
	}
	else
	{
		int i = iTable->find(key);
		array[i].setValue(newPriority);
		percolateDown(i);
		//percolateUp
		Key temp1 = array[i].key();
		Priority temp2 = array[i].value();
		array[0].setValue(temp2);
		array[0].setKey(temp1);
		for( ; temp2<array[i/2].value(); i/= 2)
		{
			array[i].setValue(array[i/2].value());
			array[i].setKey(array[i/2].key());
			iTable->insert(array[i/2].key(),i);
		}
		array[i].setValue(temp2);
		array[i].setKey(temp1);
		iTable->insert(temp1,i);
	}
}

template<class Key, class Priority>
void DynamicPriorityQueue<Key, Priority>::print()
{
	for(int i=1; i<=array.size()-1; i++)
	{
		std::cout << array[i].value() << std::endl;
	}
}

