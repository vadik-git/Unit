#include<string >
#include<vector>
#include<iostream>
#include"Unit.h"

using namespace std;



struct Node {

	int data;
	Node*prev;
	Node*next;

};


class List {

	Node *head=nullptr,*tail=nullptr;
	
public:
	List() = default;
	

	void addHead(int v) {
		if (head != nullptr) {
			Node*tmp = new Node;
			tmp->next = head;
			head->prev = tmp;
			tmp->data = v;
			tmp->prev = nullptr;
			head = tmp;
		}
		else {
			head = tail = new Node{ v,nullptr };
		}
	}

	void print() {
		Node*tmp = head;

		while (tmp!=nullptr) {
			
			cout << tmp->data << endl;
			tmp = tmp->next;
			
		}

	}

};




class Person  abstract {
	string name;

public:
	Person(const string&name = "vadim") :name(name) {

	}
	virtual void print()=0 {
		cout << "name person" << name << endl;
	}
	virtual void bizzy()abstract;


};

class Worker:public Person {
	string profesion;

public:
	Worker(const string&profesion = "Ingener",const string&name="vadim") :profesion(profesion) ,Person(name) {

	}

	void print()override {
		Person::print();
		cout << "profesion" << profesion << endl;
	}
	void bizzy()override {
		cout << "I workern profesion" << profesion << endl;
	}
	
};

class Student :public Person {
	string profesion;
	
public:
	Student(const string&profesion = "student", const string&name = "vadim") :profesion(profesion), Person(name) {

	}

	void print()override {
		Person::print();
		cout << "stud " << profesion << endl;
	}
	void bizzy()override {
		cout << "I student study " << profesion << endl;
	}

};




int main() {
	Game a;
	a.start();
	
	


	system("pause");
	return 0;
}