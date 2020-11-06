#include<iostream>
#include"list.h"



int main() {
	setlocale(LC_ALL, "russian");
	List lst;
	List lst1;
	
	

	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	cout << "Список 1:" << endl;
	lst.print_to_console();
	cout << endl;
	cout << "Список 2:" << endl;
	lst1.print_to_console();
	cout << endl;
	cout << "Списки после обьединения:" << endl;
	lst.push_front(lst1);
	lst.print_to_console();
	
	
}