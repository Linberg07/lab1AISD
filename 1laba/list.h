#pragma once
#include<iostream>
#ifndef LIST_H
#define LIST_H
using namespace std;

class List {
public:
	List();

	void push_back(int data);
	void push_front(int data);
	void pop_back();
	void pop_front();
	void clear();
	int GetSize() { return Size; };
	void insert(int data, size_t index);
	int at(size_t index);
	void remove(size_t index);
	void print_to_console();
	void set(size_t index, int data);
	bool isEmpty();
	void push_front(List lst);

private:
	class Node {
	public:
		Node* pNext;
		int data;
		Node(int data = NULL, Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}

	};
	int Size;
	Node* head;
};


List::List() {
	Size = 0;
	head = nullptr;
}

void List::push_back(int data)
{
	if (head == nullptr) {
		head = new Node(data);
	}
	else {
		Node* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	Size++;
}

void List::push_front(int data)
{
	if (head == nullptr) {
		head = new Node(data);
	}
	else {
		Node* current = this->head;
		int next_item;
		next_item = current->data;
		while (current->pNext != nullptr) {
			int swap;
			current = current->pNext;
			swap = current->data;
			current->data = next_item;
			next_item = swap;
		}
		current->pNext = new Node(next_item);
		head->data = data;
	}
	Size++;
}

void List::pop_back()
{
	Node* current = this->head;
	if (Size == 0) {
		return;
	}
	else if (Size == 1) {
		delete current;
		Size--;
		head = nullptr;
	}
	else {
		for (int i = 0; i < Size - 2; i++) {
			current = current->pNext;
		}
		Node* temp = current->pNext;
		delete temp;
		current->pNext = nullptr;
		Size--;
	}
}

void List::pop_front()
{
	Node* temp = head;
	if (Size == 0) {
		return;
	}
	else if (Size == 1) {
		delete temp;
		Size--;
		head = nullptr;
	}
	else {
		head = head->pNext;
		delete temp;
		Size--;
	}
}

void List::clear()
{
	while (Size) {
		pop_front();
	}
}

void List::insert(int data, size_t index)
{
	
		Node* current = this->head;
		if (head == nullptr) return;
		if (index > Size - 1) return;
		int counter = 0;
		while (current != nullptr) {
			if (counter == index) {
				break;
			}
			current = current->pNext;
			counter++;
		}
		int next_item;
		next_item = current->data;
		current->data = data;
		while (current->pNext != nullptr) {
			int swap;
			current = current->pNext;
			swap = current->data;
			current->data = next_item;
			next_item = swap;
		}
		current->pNext = new Node(next_item);
		Size++;
	
}

int List::at(size_t index)
{
	Node* current = this->head;
	int counter = 0;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
	return 0;
}

void List::remove(size_t index)
{
	if (head == nullptr) return;
	if (index > Size - 1) {
		cout << "YE";
		return;
	}
	else if (index == 0) pop_front();
	else if (index == Size - 1) pop_back();
	else {
		Node* temp = this->head;
		Node* current = this->head;
		for (int i = 0; i < index; i++) {
			temp = temp->pNext;
		}


		for (int i = 0; i < index - 1; i++) {
			current = current->pNext;
		}
		current->pNext = temp->pNext;
		delete temp;

		Size--;
	}

}

void List::print_to_console()
{
	Node* current = this->head;
	if (current != nullptr) {
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->pNext;
		}
	}
}

void List::set(size_t index, int data)
{
	Node* current = this->head;
	if (current == nullptr) return;
	if (index > Size - 1) return;
	for (int i = 0; i < index; i++) {
		current = current->pNext;
	}
	current->data = data;
}

bool List::isEmpty()
{
	if (Size == 0) {
		return true;
	}
	else return false;
}

void List::push_front(List lst)
{
	for (int i = lst.GetSize()-1; i >= 0; i--) {
		push_front(lst.at(i));
	}
}

#endif