#include<iostream>
#include"SmallVector.h"
/*150140040 Fatih KURU--*//*
void printSmallVector(const char* const message,   SmallVector& in_vector) {
	std::cout << message << ": ";
	for (int i = 0; i < in_vector.getSize(); i++)
	{
		std::cout << in_vector[i] << " ";
	}  
	std::cout << std::endl;
}*/
int main() {
	int temp[35];
	int temp2[40];
	for (int i = 0; i < 35; i++) {
		temp[i] = i;
	}

	for (int i = 0; i < 40; i++) {
		temp2[i] = i;
	}

	SmallVector test(temp, 10);
	SmallVector test2(temp, 35);
	//printSmallVector("Printing test in reverse ", test.reverse());
	SmallVector test3(temp2,35);
	//printSmallVector("Printing test3 ", test3);
	SmallVector test4 = test3+test;
	//printSmallVector("Printing test4 ", test4);
	SmallVector test5(temp, 2);
	test5 = test5 * 5;
	test5.push_back(12);
	//test5[0] = 4;
	//printSmallVector("Printing test5 ", test5);
	test3.push_back(temp,1);
	int a = test3.pop_back();
	std::cout <<"a=poplu ="<< a << std::endl;
	
}