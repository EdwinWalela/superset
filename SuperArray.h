#include <iostream>
template <typename T,int N>
class SuperArray{

private:
	T arr[N];
	int currentIndex = 0;
	void swap(T* a,T* b){
		T temp = *a;
		*a = *b;
		*b = temp;
	}
 public:  
	int length(){
		return N;
	}
	void push(T value){
		arr[currentIndex] = value;
		currentIndex++;
	}
	void printArr(){
		for(int i = 0; i < N; i++)
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