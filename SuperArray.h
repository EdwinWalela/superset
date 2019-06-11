#include <iostream>
template <typename T>
class SuperArray{

private:
	T* arr;
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
	void mergeAsc(int from,int to,int mid){
		int i = from;
		int j = mid + 1;
		int k = 0;

		int temp[to-from+1];

		// Merge the two parts into temp[]
		while(i <= mid && j<= to){
			if(arr[i] < arr[j]){
				temp[k] = arr[i];
				k++; i++;
			}else{
				temp[k] = arr[j];
				k++;j++;
			}
		}
		// Insert all the remaining values from i to mid into temp[]
		while(i <= mid){
			temp[k] = arr[i];
			k++; i++;
		}
		// Insert all the remaining values from j to to into temp[]
		while(j <= to){
			temp[k] = arr[j];
			k++; j++;
		}
		// Assign sorted data stored in temp[] to a[]
		for(i = from; i <= to; i++){
			arr[i] = temp[i - from];
		}
	}
	void mergeDesc(int from,int to,int mid){
		int i = from;
		int j = mid + 1;
		int k = 0;

		int temp[to-from+1];

		// Merge the two parts into temp[]
		while(i <= mid && j<= to){
			if(arr[i] > arr[j]){
				temp[k] = arr[i];
				k++; i++;
			}else{
				temp[k] = arr[j];
				k++;j++;
			}
		}
		// Insert all the remaining values from i to mid into temp[]
		while(i <= mid){
			temp[k] = arr[i];
			k++; i++;
		}
		// Insert all the remaining values from j to to into temp[]
		while(j <= to){
			temp[k] = arr[j];
			k++; j++;
		}
		// Assign sorted data stored in temp[] to a[]
		for(i = from; i <= to; i++){
			arr[i] = temp[i - from];
		}
	}
	void print(int from,int to){
		std::cout<<"[";
		for(int i = from; i < to+1; i++){
			std::cout<<i<<" ";
		}
		std::cout<<"] ";
	}
 public: 
	int SIZE;
	SuperArray(int N = 1){
		arr = new T[N];
		SIZE = N;
	}
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
			currentIndex++;
		}
	}
	void print(){
		for(int i = 0; i < SIZE; i++)
		{
			std::cout<<arr[i]<<" ";
		}
	}
	void bubbleSortAscV(){
		for(int i = 0; i < SIZE -1; i++){
			for(int j = 0; j < SIZE - i - 1; j++){
				if(arr[j] > arr[j+1]){
					swap(&arr[j],&arr[j+1]);
				}
			}
			std::cout<<"pass ("<<i+1<<"): ";
			print();
			std::cout<<std::endl;
		}
	}
	void bubbleSortAsc(){
		for(int i = 0; i < SIZE-1; i++){
			for(int j = 0; j < SIZE - i - 1; j++){
				if(arr[j] > arr[j+1]){
					swap(&arr[j],&arr[j+1]);
				}
			}
		}
	}
	void bubbleSortDesc(){
		for(int i = 0; i < SIZE-1; i++){
			for(int j = 0; j < SIZE - i - 1; j++){
				if(arr[j] < arr[j+1]){
					swap(&arr[j],&arr[j+1]);
				}
			}
		}
	}
	void bubbleSortDescV(){
		for(int i = 0; i < SIZE - 1; i++){
			for(int j = 0; j < SIZE - i - 1; j++){
				if(arr[j] < arr[j+1]){
					swap(&arr[j],&arr[j+1]);
				}
			}
			std::cout<<"pass ("<<i+1<<"): ";
			print();
			std::cout<<std::endl;
		}
	}
	void mergeSortAsc(int from,int to){
		// from = 0 to = 4
		// [ 5 , 4 , 3 , 2 , 1]

		if(to == SIZE){
			to--;
		}
		int mid;
		if(from < to){
			mid = (from + to) / 2;
			mergeSortAsc(from,mid);
			mergeSortAsc(mid+1,to);

			mergeAsc(from,to,mid);

		}
	}
	void mergeSortDesc(int from,int to){
		// from = 0 to = 4
		// [ 5 , 4 , 3 , 2 , 1]

		if(to == SIZE){
			to--;
		}
		int mid;
		if(from < to){
			mid = (from + to) / 2;
			mergeSortDesc(from,mid);
			mergeSortDesc(mid+1,to);

			mergeDesc(from,to,mid);

		}
	}
	
};