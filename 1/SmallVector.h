#ifndef _smallvector_           // to include only once
#define _smallvector_
/*150140040 Fatih KURU--*/

class SmallVector{

		int static_buffer[32];//static buffer which contains 32 elements 
		int *dynamic_buffer;// dynamic buffer which take after 32 inputs
		int size;// it contains size of all static and dynamic buffer
	public:
		SmallVector();//default constructor
		SmallVector(int [], int );//constructor
		SmallVector(const SmallVector&);//copy constructor
		int & operator[](int)  ;    // [] operator overloading
		SmallVector operator+(const SmallVector&)const;//+ operator overloading
		const int & getSize()const ;//getsize function
		void push_back(int);//push_back function
		void push_back(int[], int);//overloaded function of push_back
		int pop_back();//pop_back function :removes last element and return it
		SmallVector reverse();//reverse function
		SmallVector operator*(int);//* operator overloading
		const SmallVector& operator=(const SmallVector &);  // assignment operator
		~SmallVector();//destructor

};
#endif