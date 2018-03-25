#include"SmallVector.h"
/*150140040 Fatih KURU--*/

//--------getting size function
const int & SmallVector::getSize()const  {

	return size;//returning the size of the object
}

//--------default constructor-----------
SmallVector::SmallVector(){
	size = 0;
}

//--------constructor for calling array and size-----
SmallVector::SmallVector(int temp[], int size_2){
	size = 0;
	if (size_2 <= 32){//if size smaller than 32 , we will take only static buffer memory 
		for (int i = 0; i < size_2; i++){
			static_buffer[i] = temp[i];

		}
		size = size_2;
	}
	else// if size bigger than 32, we will take both static and dynamic memory
	{
		int i;
		for (i = 0; i < 32; i++){
			static_buffer[i] = temp[i];
		}
		dynamic_buffer = new int[size_2 - 32];//allocating the rest of elements in dynamic buffer

		for (int a = 0; a < size_2 - 32; a++){
			dynamic_buffer[a] = temp[i];
			i++;
		}
		size = size_2;
	}
}

//--------Copy Constructor--------------------
SmallVector::SmallVector(const SmallVector & object_in){
	size = object_in.size;//size assignment
	if (size < 32){
		for (int i = 0; i < 32; ++i){
			static_buffer[i] = object_in.static_buffer[i];
		}
	}
	else{//size is bigger than 32

		for (int i = 0; i < 32; ++i){//first static buffer is completed
			static_buffer[i] = object_in.static_buffer[i];
		}
		dynamic_buffer = new int[size - 32];//allocating the rest of elements in dynamic buffer

		for (int a = 0; a < size - 32; a++){
			dynamic_buffer[a] = object_in.dynamic_buffer[a];
		}
	}


}

//--------[] operator----------------------------------------------
int & SmallVector::operator[](int i)  // [] operator is overloaded with negative and positive calling number
{
	if (i < 32 && i >= 0){//if size is between 0 and 32 we will get static buffer element
		return static_buffer[i];
	}
	else if (i >= 32){//if size is bigger than 32 , we will get dynamic buffer element
		return dynamic_buffer[i - 32];
	}
	else if (i < 0 && size + i<32){//if size is negative and size +i smaller than 32
		return static_buffer[size + i];
	}
	else  if (i < 0 && size + i >= 32){//if size is negative and size+i bigger than 32
		return dynamic_buffer[size + i - 32];
	}

}

// ------ +operator--------------------------------
SmallVector SmallVector::operator+(const SmallVector&k)const{
	int temp[1000];//
	int a = size + k.size;
	int temp_size = 0;

	if (size + k.size <= 32){// if sum of total size is smaller than 32
		int i = 0;
		for (i = 0; i < size; i++){
			temp[i] = static_buffer[i];

		}
		for (int a = 0; a < k.size; a++){
			temp[i] = k.static_buffer[a];
			i++;
		}

	}
	else{// when total of size and k.size is bigger than 32
		if (size>32 && k.size > 32){//both of them is bigger than 32
			int i = 0;
			for (i = 0; i < 32; i++){
				temp[i] = static_buffer[i];
			}

			for (int a = 0; a < size - 32; a++){
				temp[i] = dynamic_buffer[a];
				i++;
			}
			for (int b = 0; b < 32; b++){
				temp[i] = k.static_buffer[b];
				i++;
			}
			for (int c = 0; c < k.size - 32; c++){
				temp[i] = k.dynamic_buffer[c];
				i++;
			}
		}
		else if (size>32 && k.size <= 32){//only one of them is bigger than 32
			int i = 0;

			for (i = 0; i < 32; i++){
				temp[i] = static_buffer[i];
			}

			for (int a = 0; a < size - 32; a++){
				temp[i] = dynamic_buffer[a];
				i++;
			}
			for (int b = 0; b < k.size; b++){
				temp[i] = k.static_buffer[b];
				i++;
			}
		}
		else if (k.size>32 && size <= 32){// only k is bigger than 32
			int i = 0;

			for (i = 0; i < size; i++){
				temp[i] = static_buffer[i];
			}

			for (int a = 0; a < 32; a++){
				temp[i] = k.static_buffer[a];
				i++;
			}

			for (int b = 0; b < k.size - 32; b++){
				temp[i] = k.dynamic_buffer[b];
				i++;
			}
		}
		else{//both of them is smaller than 32 but sum of them is bigger than 32
			int i = 0;
			for (i = 0; i < size; i++){
				temp[i] = static_buffer[i];
			}
			for (int a = 0; a < k.size; a++){
				temp[i] = k.static_buffer[a];
				i++;
			}
		}


	}
	temp_size = size + k.size;//size assignment

	return	SmallVector(temp, temp_size);

}
// -------push_back----------------------------------
void SmallVector::push_back(int x){
	if (size < 32){//we will add in static buffer because of we have capacity in static buffer
		static_buffer[size] = x;
		size++;// size is incremented
	}
	else{
		int *temp = new int[size - 31];//temp array which holds the dynamic array elements

		for (int i = 0; i < size - 32; i++){
			temp[i] = dynamic_buffer[i];//assignment to temp from dynamic buffer
		}

		temp[size - 32] = x;//last element of temp is given x element
		delete[] dynamic_buffer;//deleting the dynamic buffer
		dynamic_buffer = new int[size - 31];//new dynamic buffer's size is incremented

		for (int i = 0; i < size - 31; i++){//assignment to dynmic buffer from temp
			dynamic_buffer[i] = temp[i];
		}
		size++;//size is incremented
		delete[] temp;//deleting the temp

	}
}
//--------overloaded push_back--------------------------
void SmallVector::push_back(int array_in[], int size_3){
	if (size_3 + size <= 32){//if total size is smaller than 32
		for (int i = 0; i < size_3; i++){
			static_buffer[size] = array_in[i];
			size++;
		}
	}
	else{//if total size is bigger than 32
		if (size < 32){//objects size is smaller than 32
			int temp = 0;//temp is holding the array_in array's elements
			for (int a = size; a < 32; a++){//first the assigning the static buffer
				static_buffer[a] = array_in[temp];
				temp++;

			}
			dynamic_buffer = new int[size_3 + size - 32];// allocating the dynamic buffer for new elements
			
			for (int b = 0; b < size_3 + size - 32; b++){//assigning the dynamic buffer
				dynamic_buffer[b] = array_in[temp];
				temp++;
			}
			size = size_3 + size;//total size is calculating and assigning
		}
		else if (size >= 32){//if objects size is bigger than 32
			int *temp;//holding the dynamic buffer elements
			if (size != 32){//if size isnt 32
				temp = new int[size - 32 + size_3];//dynamic memory allocating
				int i = 0;//holding the number of array 
				for (i = 0; i < size - 32; i++){//dynamic buffer assignment
					temp[i] = dynamic_buffer[i];
				}
				for (int b = 0; b < size_3; b++){//given array assignment
					temp[i] = array_in[b];
					i++;
				}
				delete[] dynamic_buffer;//deleting the dynamic buffer
				dynamic_buffer = new int[size - 32 + size_3];//new size of dynamic buffer is allocated
				for (int c = 0; c < size + size_3 - 32; c++){// assignment from temp to dynamic buffer
					dynamic_buffer[c] = temp[c];
				}
				delete[] temp;//deleting temp because of extra consumption
				size = size_3 + size;//new size 
			}
			else if (size == 32){//if size is equal to 32 
				dynamic_buffer = new int[size_3];//allocating new areas for dynamic buffer
				for (int i = 0; i < size_3; i++){//adding the arra_in elements to dynamic buffer
					dynamic_buffer[i] = array_in[i];
				}
				size = size_3 + size;//new size
			}
		}
	}

}
//--------pop_back function---------------
int SmallVector::pop_back(){
	if (size <= 32){//if size is smaller than 32 
		int k = static_buffer[size - 1]; //last elements of static buffer is holded in k
		static_buffer[size - 1] = 0; //last elements is assigning to 0
		size--;//size is decremented
		return k;//last element return 
	}
	else{//if size is bigger than 32
		int k;//last element
		int* temp = new int[size - 32 - 1];//new size allocating to temp which is decreased by 1
		for (int i = 0; i < size - 32 - 1; i++){
			temp[i] = dynamic_buffer[i];//holding the temperature values
		}
		k = dynamic_buffer[size - 32 - 1];//holding the last element
		delete[] dynamic_buffer;//deleting dynamic buffer for new size
		dynamic_buffer = new int[size - 32 - 1];//allocating to decreasing number
		for (int i = 0; i < size - 32 - 1; i++){//assignment
			dynamic_buffer[i] = temp[i];
		}
		delete[] temp;//deleting temp
		size--;//size is decrease
		return k;//last element
	}

}
//--------reverse function-----------
SmallVector SmallVector::reverse(){
	SmallVector temp;
	if (size <= 32){//size is smaller than 32
		int a = 0;//holding the order of array
		for (int i = size - 1; i >= 0; i--){//assignment
			temp.static_buffer[a] = static_buffer[i];
			a++;
		}
		temp.size = size;//new size
		return temp;// return reverse object
	}
	else{//if size is bigger than 32
		if (size - 32 <= 32){//if dynamic buffer size is smaller than static buffer capacity which is 32
			int a = 0;//order of array 
			for (int i = size - 32 - 1; i >= 0; i--){//first dynamic buffer assignment
				temp.static_buffer[a] = dynamic_buffer[i];
				a++;
			}
			for (int b = 31; b >= size - 32; b--){//second static buffer assignment
				temp.static_buffer[a] = static_buffer[b];
				a++;
			}

			temp.dynamic_buffer = new int[size - 32];//allocating the given temp object  dynamic buffer

			for (int c = size - 32 - 1; c >= 0; c--){//assignment to dynamic buffer of temp from static buffer
				temp.dynamic_buffer[a - 32] = static_buffer[c];
				a++;
			}
			temp.size = size;//size of temp object
			return temp;
		}
		else{//if dynamic array size is bigger than static buffer capacity
			int a = 0;//number of order of array
			for (int i = size - 32 - 1; i >= size - 64; i--){//first dynamic buffer to temp static buffer
				temp.static_buffer[a] = dynamic_buffer[i];
				a++;
			}
			temp.dynamic_buffer = new int[32 + size - 64];//new area for dynamic buffer of temp
			int dynamic_temp = 0;//order of dynamic bufffer 
			for (int c = size - 64 - 1; c >= 0; c--){//rest of dynamic buffer elements assign to temp dynamic buffer
				temp.dynamic_buffer[dynamic_temp] = dynamic_buffer[c];
				dynamic_temp++;
			}
			for (int i = 31; i >= 0; i--){//static buffer to temp dynamic buffer
				temp.dynamic_buffer[dynamic_temp] = static_buffer[i];
				dynamic_temp++;
			}
			temp.size = size;//temp size assignment
			return temp;//reverse object
		}
	}
}
//------- * replicate function overloading
SmallVector SmallVector::operator *(int factor){
	SmallVector x;//temp object
	for (int i = 0; i < factor; i++){
		x = x.operator+ (*this);
	}
	return x;
}
//--------assignment operator overloading
const SmallVector& SmallVector::operator=(const SmallVector &in_object)
{
	if (size > 32){//if size is bigger than 32
		delete[] dynamic_buffer;//deleting the dynamic buffer of left value
	}

	if (in_object.size <= 32){//if right value object size is smaller than 32
		for (int i = 0; i < in_object.size; i++){
			static_buffer[i] = in_object.static_buffer[i];
		}
	}
	else if (in_object.size>32){//if right value object size is bigger than 32
		for (int i = 0; i < 32; i++){
			static_buffer[i] = in_object.static_buffer[i];
		}
		dynamic_buffer = new int[in_object.size - 32];//new memory for dynamic buffer
		for (int a = 0; a < in_object.size - 32; a++){
			dynamic_buffer[a] = in_object.dynamic_buffer[a];
		}
	}
	size = in_object.size;//assignment to size from rightvalue objec
	return *this;//returning left value
}
//--------destructor------------------------
SmallVector::~SmallVector(){
	if (size>32){
		delete[] dynamic_buffer;//deleting the dynamic buffer for extra consumption when the scope is ended
	}

}
