//
//  hashing.cpp
//  
//
//  Created by Nicholas Ionata on 10/28/18.
//

#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>

class Node {
	public:
	int key;
	int value;
	
	Node(int key, int value) {
		this->key = key;
		this->value = value;
	}
};

class HashTable {
	public:
	int tableSize;
	double size;
	int collisions;
	Node **table;
	
	HashTable(int tableSize) {
		this->tableSize = tableSize;
		this->size = 0.0;
		this->collisions = 0;
		table = new Node*[tableSize];
		
		for(int i = 0; i < tableSize; i++) {
			table[i] = NULL;
		}
	}
	
	//Hash Function 1 - Key mod table size
	int hashCode(int key) {
		return key % tableSize;
	}
	
	//Hash Function 2 - Mid square
	/*
	int hashCode(int key) {
	}
	*/
	
	double getLoadFactor() {
		return size/tableSize;
	}
	
	void put(int key, int value) {
		Node *newValue = new Node(key, value);
		
		int tableIndex = hashCode(key);
		
		while(table[tableIndex] != NULL && table[tableIndex]->key != key && table[tableIndex]->key != -1) {
			collisions++;
			tableIndex++;
			
			if(tableIndex == tableSize) {
				tableIndex = 0;
			}
		}
		
		if(table[tableIndex] == NULL || table[tableIndex]->key == -1) {
			size++;
		}
		
		table[tableIndex] = newValue;
	}
	
	void print() {
		for(int i = 0; i < tableSize; i++) {
			if(table[i] == NULL) {
				std::cout << i << std::endl;
				continue;
			}
			
			std::cout << i << " (" << table[i]->key << ", " << table[i]->value << ")" << std::endl;
		}
 	}
};

int main() {
	HashTable *table = new HashTable(10);
	table->put(12, 5);
	std::cout << "Collisions: " << table->collisions << " Load factor: " << table->getLoadFactor() << std::endl;
	table->put(4, 10);
	std::cout << "Collisions: " << table->collisions << " Load factor: " << table->getLoadFactor() << std::endl;
	table->put(2, 11);
	std::cout << "Collisions: " << table->collisions << " Load factor: " << table->getLoadFactor() << std::endl;
	table->put(29, 69);
	std::cout << "Collisions: " << table->collisions << " Load factor: " << table->getLoadFactor() << std::endl;
	table->put(19, 50);
	std::cout << "Collisions: " << table->collisions << " Load factor: " << table->getLoadFactor() << std::endl;
	
	table->print();
}
