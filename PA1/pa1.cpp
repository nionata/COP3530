//
//  pa1.cpp
//  
//
//  Created by Nicholas Ionata on 9/20/18.
//

#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>

class Node {
	public:
		Node(std::string value);
		std::string data;
		Node* next;
};

//Implementation of Node class
Node::Node(std::string value) {
	data = value;
	next = NULL;
}

class LinkedList {
	private:
		Node* head;
	public:
		LinkedList();
		void insertEnd(std::string value);
		void insert(int index, std::string value);
		void deleteLine(int index);
		void edit(int index, std::string value);
		void print();
		void search(std::string value);
};

//Implementation of LinkedList class
LinkedList::LinkedList() {
	head = NULL;
}

void LinkedList::insertEnd(std::string value) {
	Node* node = new Node(value);
	Node* currentNode = head;
	
	if(currentNode) {
		while(currentNode->next != NULL) {
			currentNode = currentNode->next;
		}
		
		currentNode->next = node;
	} else {
		head = node;
	}
	
	//delete currentNode;
	//delete node;
}

void LinkedList::insert(int index, std::string value) {
	Node* node = new Node(value);
	
	if(!head) {
		head = node;
		return;
	}
	
	if(index == 1) {
		Node* temp = head;
		head = node;
		head->next = temp;
	}
	
	Node* prevNode = head;
	Node* currentNode = head->next;
	int currentIndex = 2;
	
	while(currentIndex < index) {
		if(!currentNode) {
			std::cout << "You tried to insert to a line out of range! Try again on a line " << currentIndex << " or less." << std::endl;
			return;
		}
		
		prevNode = currentNode;
		currentNode = currentNode->next;
		currentIndex++;
	}
	
	prevNode->next = node;
	node->next = currentNode;
	
	//delete prevNode;
	//delete currentNode;
	//delete node;
}

void LinkedList::deleteLine(int index) {
	if(index == 1) {
		head = head->next;
	}
	
	Node* currentNode = head->next;
	Node* prevNode = head;
	int currentIndex = 2;
	
	while(currentIndex < index) {
		if(!currentNode->next) {
			std::cout << "You tried to delete to a line out of range! Try again on a line " << currentIndex << " or less." << std::endl;
			return;
		}
		
		prevNode = currentNode;
		currentNode = currentNode->next;
		currentIndex++;
	}
	
	prevNode->next = currentNode->next;
}

void LinkedList::edit(int index, std::string value) {
	Node* currentNode = head;
	int currentIndex = 1;
	
	while(currentIndex < index) {
		if(!currentNode->next) {
			std::cout << "You tried to edit a line out of range! Try again on a line " << currentIndex << " or less." << std::endl;
			return;
		}
		
		currentNode = currentNode->next;
		currentIndex++;
	}
	
	currentNode->data = value;
}

void LinkedList::print() {
	if(!head) {
		return;
	}
	
	Node* currentNode = head;
	int index = 1;
	
	do {
		std::cout << index << " " << currentNode->data << std::endl;
		currentNode = currentNode->next;
		index++;
	} while(currentNode != NULL);
	
	//delete currentNode;
}

void LinkedList::search(std::string value) {
	Node* currentNode = head;
	int currentIndex = 1;
	
	while(currentNode) {
		if(currentNode->data.find(value) != std::string::npos) {
			std::cout << currentIndex << " " << currentNode->data << std::endl;
			return;
		}
		
		currentNode = currentNode->next;
		currentIndex++;
	}
	
	std::cout << "Could not find the value you searched for!" << std::endl;
}

int main() {
	LinkedList* document = new LinkedList();
	
	
	
	/*document->insertEnd("First statement");
	document->insert(1, "Second statement");
	document->insert(4, "Third statement");
	document->insertEnd("Fourth statement");
	document->print();
	document->deleteLine(4);
	document->print();
	document->edit(2, "new");
	document->print();
	document->search("statement");/*
};

