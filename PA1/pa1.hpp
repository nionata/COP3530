//
//  pa1.hpp
//  
//
//  Created by Nicholas Ionata on 9/20/18.
//

#ifndef pa1_hpp
#define pa1_hpp

#include <stdio.h>
#include <string>

class Node {
	private:
		std::string data;
		Node* next;
	public:
		Node(std::string value);
		std::string getData();
		Node* getNext();
};

class LinkedList {
	private:
		Node* head;
		Node* tail;
	public:
		LinkedList();
		void insertEnd(std::string value);
		void insert(int index, std::string value);
		void deleteLine(int index);
		void edit(int index, std::string value);
		void print();
		void search(std::string value);
};

#endif /* pa1_hpp */
