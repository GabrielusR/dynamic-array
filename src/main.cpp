#include "dyn_array.h"

int main() {
	
	DynamicArray<int> arr1;
	
	for(unsigned int i = 0; i < 10; i++) {
		
		arr1.add(i+1);
	}
	
	arr1.add(11);
	
	DynamicArray<int> arr2 = arr1;
	
	arr2.remove(4);
	
	DynamicArray<int> arr3 = arr2;
	
	arr3.add(12);
	
	arr3 = arr1;
	
	std::cout << arr1 << arr2 << arr3;
	
	DynamicArray<int> arr4 = std::move(arr3);
	
	return 0;
}