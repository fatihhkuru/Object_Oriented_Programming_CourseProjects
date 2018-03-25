//fatih kuru 150140040
#include<iostream>
#include<string>

using namespace std;

class Node{//Node class can hold the next and prev options
public:
	int number;//number can take the number which can get from user
	Node* next;//forward
	Node* previous;//back
};
class ARTraverser{// Artraverser class 
protected:
	Node*current = NULL;//  current is taken NULL about first initilazition
public:
	virtual int hasNode() = 0;//pure virtual class which keep are there any node in artraverser
	virtual int next() = 0;// pure virtual class
	virtual ~ARTraverser(){ cout << "virtual calling"; };
};
class ARTF :public ARTraverser{//derived class  which derived from ARTraverser, FAFR FALR methods use it 

public:
	ARTF();//default constructor
	ARTF(Node*);//constructor
	int hasNode();//keep are there any node in artf
	int next();//move the next object method
	~ARTF();
};
class ARTL :public ARTraverser{//derived class which derived form ARTraverser, LAFR LALR methods use it
	public:
		ARTL();//constructor
		ARTL(Node*);//constructor
		int hasNode();//keep are there any node in artl
		int next();//move the previous object
};
class AdderRemover{//base abstract class
protected:
	Node* head = NULL;//first initilazition
	Node* tail = NULL;//first initilazition
	string name;//name holds the name of adderremover classes
	int nodeCount;//count of node
	ARTraverser* traverser;
public:
	AdderRemover(){  };
	virtual void add(int i) = 0;//pure virtual method that can make adding
	virtual void remove() = 0;//pure virtual method that can remove
	virtual void setTraverser() = 0;
	void removeAll();//it can remove the all nodes
	void display();//showing the nodes
	void traverse();
	virtual ~AdderRemover(){ cout << "virtual caling"  << endl; };

};
class FAFR :public AdderRemover{//derived class which can do first add first remove , from AdderRemover
public:

	FAFR();//default constructor
	void add(int i);//add function	
	void remove();//remove function
	void setTraverser();
	~FAFR();//destructor
};

class FALR :public AdderRemover{//derived class which can do first add Last remove , from AdderRemover
public:

	FALR();//default constructor
	void add(int i);//add function	
	void remove();//remove function
	void setTraverser();
	~FALR();//destructor
};
class LAFR :public AdderRemover{//derived class which can do last add first remove , from AdderRemover
public:

	LAFR();//default constructor
	void add(int i);//add function	
	void remove();//remove function
	void setTraverser();
	~LAFR();//destructor
};
class LALR :public AdderRemover{//derived class which can do last add last remove , from AdderRemover
public:

	LALR();//default constructor
	void add(int i);//add function	
	void remove();//remove function
	void setTraverser();
	~LALR();//destructor
};