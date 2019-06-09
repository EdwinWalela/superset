#include <iostream>
template <typename T,int N>
class SuperArray{

private:
	T* arr = new T[N];
	int SIZE = N;
	int currentIndex = 0;
	void swap(T* a,T* b){
		T temp = *a;
		*a = *b;
		*b = temp;
	}
	T* expand(){
		SIZE++;
		T* newArr = new T[SIZE];
		// Transfer elements to the new array 
		for(int i = 0; i < SIZE-1; i++){
			newArr[i] = arr[i];
		}
		// delete original array
		delete[] arr;
		// return pointer to new array
		return newArr;
	}
 public:  
	int length(){
		return SIZE;
	}
	void push(T value){
		if(currentIndex != SIZE){
			arr[currentIndex] = value;
			currentIndex++;
		}else{
			arr = expand();
			arr[currentIndex] = value;
		}
	}
	void printArr(){
		for(int i = 0; i < SIZE; i++)
		{
			std::cout<<arr[i]<<" ";
		}
	}
	void bubbleSortAscV(){
		for(int i = 0; i < N-1; i++){
			for(int j = 0; j < N - i - 1; j++){
				if(arr[j] > arr[j+1]){
					swap(&arr[j],&arr[j+1]);
				}
			}
			std::cout<<"pass ("<<i+1<<"): ";
			printArr();
			std::cout<<std::endl;
		}
	}
	void bubbleSortAsc(){
		for(int i = 0; i < N-1; i++){
			for(int j = 0; j < N - i - 1; j++){
				if(arr[j] > arr[j+1]){
					swap(&arr[j],&arr[j+1]);
				}
			}
		}
	}
	void bubbleSortDesc(){
		for(int i = 0; i < N-1; i++){
			for(int j = 0; j < N - i - 1; j++){
				if(arr[j] < arr[j+1]){
					swap(&arr[j],&arr[j+1]);
				}
			}
		}
	}
	void bubbleSortDescV(){
		for(int i = 0; i < N-1; i++){
			for(int j = 0; j < N - i - 1; j++){
				if(arr[j] < arr[j+1]){
					swap(&arr[j],&arr[j+1]);
				}
			}
			std::cout<<"pass ("<<i+1<<"): ";
			printArr();
			std::cout<<std::endl;
		}
	}
};