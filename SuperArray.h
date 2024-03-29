#include <iostream>
template <typename T>
class SuperArray{
private:
	T* arr;
	int currentIndex = 0;
	// Methods
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
	T* shrink(T arr[],int targetSize){
		T* newArr = new T[targetSize];
		for(int i = 0; i < targetSize; i++){
			newArr[i] = arr[i];
		}
		// delete original array
		delete[] arr;
		// return pointer to new array
		return newArr;
	}
	bool exists(T value,SuperArray<T> arr,int size){
		for(int i = 0; i < arr.length(); i++){
			if(value == arr.at(i)){
				return true;
			}
		}
		return false;
	}
	void swap(T* a,T* b){
		T temp = *a;
		*a = *b;
		*b = temp;
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
 public: 
 int MAX = 100;
	int SIZE;
	SuperArray(int N = 1){
		arr = new T[N];
		SIZE = N;
	}
	int length(){
		return SIZE;
	}
	T at(int index){
		return arr[index];
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
		std::cout<<"[";
		for(int i = 0; i < SIZE; i++){
			char comma = ( i != SIZE-1 ? ',' : ']');
			std::cout<<arr[i]<<comma;
		}
	}
	void print(int from,int to){
		// Printing fowards
		if(from <= to){
			std::cout<<"[";
			for(int i = from; i < to+1; i++){
				char comma = ( i != to ? ',' : ']');
				std::cout<<i<<comma;
			}
		}else{
		// Printing backwords
			std::cout<<"[";
			for(int i = from; i >= to; i--){
				char comma = ( i != to ? ',' : ']');
				std::cout<<i<<comma;
			}
		}
	}
	void reverse(){
		T* temp = new T[SIZE];
		int newIndex = 0;
		int arrIndex = SIZE-1;
		while(arrIndex > 0){
			temp[newIndex] = arr[arrIndex];
			newIndex++;arrIndex--;
		}
		delete[] arr;
		arr = temp;
	}
	bool exists(T value,int left,int right){
		if(left>right){
			return false;
		}
		int mid = (left + right ) / 2;
		if(arr[mid]==value){
			return true;
		}else if(value < arr[mid]){
			exists(value,left,mid-1);
		}else if(value > arr[mid]){
			exists(value,mid+1,right);
		}
	}
	SuperArray<T> setUnion(SuperArray<T> setB){
		SuperArray<T> set;
		// sort sets
		setB.bubbleSortAsc();
		// perform union    
		for(int i = 0; i < SIZE; i++){
			if(!exists(set.at(i),set,MAX)){
				set.push(arr[i]);
			}
		}
		for(int i = 0; i < setB.length(); i++){
			if(!exists(setB.at(i),set,MAX)){
				set.push(setB.at(i));
			}
		}
		set.bubbleSortAsc();
		return set;
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