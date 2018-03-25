//fatih kuru 150140040
#include"Header.h"
#include<iostream>
#include<string>

using namespace std;
void AdderRemover::display(){//show the node list of adderremover class

	Node* traverse = new Node;//temp node
	traverse = head;//assignment
	cout << name + "| NodeCount: " << nodeCount << endl; //name of class + nodecount
	cout << "------" << endl;
	if (traverse == 0){//there is no element 
		cout << "there is no element to print" <<endl;
		
	}

	while (traverse != NULL){//if there is a object in class
		cout <<traverse->number << endl;//show the number of class
		traverse = traverse->next;//move the next traverse
	}
	
	delete traverse;//deleting the traverse
}
void AdderRemover::traverse(){// common method for traversing the object

	cout << name << " | NodeCount:  "<<nodeCount <<endl;//class name + nodecount 
	cout << "-----" << endl;
	if (traverser->hasNode() == 0){//if there isnt a object
		cout << "there is no element to print" << endl;
	}
	while (traverser->hasNode() != 0){//if there is a object 

		cout  << traverser->next() << endl;
	}
	
}
int ARTF::next(){//next function
	int a;//keep the element 
	a = current->number;//assingment

	if (current != NULL){//if there is a element in nodelist
		current = current->next;//move the next object
		return a;//returning the current number
	}
	else{
		return 0;//if there isnt any element in nodelist , it will return null

	}
}
ARTF::ARTF(){//constructor
	current = NULL;//first initilazition
}
ARTF::ARTF(Node* temp){//constructor
	current = temp;//keep the temp adress
}
ARTF::~ARTF(){//destructor
	delete current;
}
int ARTF::hasNode(){//if there is a element in class
	if (current == NULL){//if there is not
		return 0;
	}
	else//if there is
		return 1;
}
ARTL::ARTL(){//first assignment constructor
	current = NULL;
}
ARTL::ARTL(Node*temp){//constructor
	current = temp;
}
int ARTL::hasNode(){//if there is a element in object
	if (current == NULL){//if there is not
		return 0;
	}
	else//if there is
		return 1;
}
int ARTL::next(){//next method
	int a;//keep the element 
	a = current->number;//assingment

	if (current != NULL){//if there is a element in nodelist
		current = current->previous;//move the previous object
		return a;//return current number 
	}
	else{
		return 0;//return 0

	}
}


void AdderRemover::removeAll(){//remove all nodes 
	Node*traverse;//temp node
	while (head){//if head is not NULL
		traverse = head;
		head = head->next;
		delete traverse;//deleting
	}
	nodeCount = 0;//nodecount will be 0
}

FAFR::FAFR(){//name constructor
	name = "FAFR";
}
void FAFR::add(int i){// we will add to first element of nodelist  
	Node* newnode = new Node;//entered node 
	newnode->previous = NULL;
	newnode->next = NULL;
	newnode->number = i;//assignment
	if (head == NULL){//if head is empty, it will add to head of nodelist
		head = newnode;
		tail = newnode;
		nodeCount++;
		return;
	}
	newnode->next = head;//the other assignments
	head = newnode;
	(newnode->next)->previous = newnode;
	nodeCount++;
	return;
}
void FAFR::remove(){//remove from first element of nodelist

	if (nodeCount == 0){//if there isnt any nodes
		return;
	}
	if (nodeCount == 1){//if there is a one node
		delete head;
		delete tail;
		nodeCount--;
		return;
	}
	head = head->next;//if there is more than one node
	head->previous = NULL;
	nodeCount--;
	return;
}
FAFR::~FAFR(){ //destructor
	Node*traverse;
	while (head){
		traverse = head;
		head = head->next;
		delete traverse;
	}
	nodeCount = 0;
}

void FAFR::setTraverser(){//set traverser 
	traverser = new ARTF(head);
}


FALR::FALR(){//name 
	name = "FALR";
}
void FALR::add(int i){// we will add to first element of nodelist 
	Node* newnode = new Node;
	newnode->previous = NULL;
	newnode->next = NULL;
	newnode->number = i;
	if (head == NULL){//if head is empty, it will add to head of nodelist
		head = newnode;
		head->previous = NULL;
		tail = newnode;
		tail->next = NULL;
		nodeCount++;
		return;
	}
	newnode->next = head;//the other assignments
	head = newnode;
	(newnode->next)->previous = newnode;
	nodeCount++;
	return;
}
void FALR::remove(){//remove from last  element of nodelist
	if (nodeCount == 0){//if there isnt any nodes
		return;
	}
	if (nodeCount == 1){//if there is a one node
		delete head;
		delete tail;
		nodeCount--;
		return;
	}
	Node*temp = new Node;//if there is more than one node
	temp = tail;
	(temp->previous)->next = NULL;
	tail = temp->previous;
	delete temp;
	nodeCount--;
	return;
}
FALR::~FALR(){//destructor
	Node*traverse;
	while (head){
		traverse = head;
		head = head->next;
		delete traverse;
	}
	nodeCount = 0;	
}
void FALR::setTraverser(){//settraverser
	traverser = new ARTF(head);
}



LAFR::LAFR(){//constructor which holds the name
	name = "LAFR";
}
void LAFR::add(int i){// we will add to last element of nodelist 
	Node* newnode = new Node;
	newnode->previous = NULL;
	newnode->next = NULL;
	newnode->number = i;
	if (head == NULL){//if head is empty, it will add to head of nodelist
		head = newnode;
		head->previous = NULL;
		tail = newnode;
		tail->next = NULL;
		nodeCount++;
		return;
	}
	tail->next = newnode;//the other assignments
	newnode->previous = tail;
	tail = newnode;
	nodeCount++;
	return;
}
void LAFR::remove(){//remove from first  element of nodelist

	if (nodeCount == 0){//if there isnt any nodes
		return;
	}
	if (nodeCount == 1){//if there is a one node
		delete head;
		delete tail;
		nodeCount--;
		return;
	}
	head = head->next;//if there is more than one node
	head->previous = NULL;
	nodeCount--;
	return;
}
LAFR::~LAFR(){//destructor
	Node*traverse;
	while (head){
		traverse = head;
		head = head->next;
		delete traverse;
	}
	nodeCount = 0;	
}
void LAFR::setTraverser(){//settraverser
	traverser = new ARTL(tail);
}

LALR::LALR(){//constructor which hold the name
	name = "LALR";
}
void LALR::add(int i){// we will add to last element of nodelist 
	Node* newnode = new Node;
	newnode->previous = NULL;
	newnode->next = NULL;
	newnode->number = i;
	if (head == NULL){//if head is empty, it will add to head of nodelist
		head = newnode;
		head->previous = NULL;
		tail = newnode;
		tail->next = NULL;
		nodeCount++;
		return;
	}
	tail->next = newnode;//the other assignments
	newnode->previous = tail;
	tail = newnode;
	nodeCount++;
	return;
}
void LALR::remove(){//remove from last  element of nodelist
	if (nodeCount == 0){//if there isnt any nodes
		return;
	}
	if (nodeCount == 1){//if there is a one node
		delete head;
		delete tail;
		nodeCount--;
		return;
	}
	Node*temp = new Node;//if there is more than one node
	temp = tail;
	(temp->previous)->next = NULL;
	tail = temp->previous;
	delete temp;
	nodeCount--;
	return;
}
LALR::~LALR(){//destructor
	Node*traverse;
	while (head){
		traverse = head;
		head = head->next;
		delete traverse;
	}
	nodeCount = 0;

}
void LALR::setTraverser(){
	traverser = new ARTL(tail);
}


