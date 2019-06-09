template <typename T>
class SuperA{

private:
    T arr[n];

    void swap(T* a,T* b){
        T temp = *a;
        *a = *b;
        *b = temp;
    }
 public:  
    void printArr(){
        for(int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    void bubbleSortV(){
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(arr[j] > arr[j+1]){
                    swap(&arr[j],&arr[j+1]);
                }
            }
            std::cout<<"pass ("<<i+1<<"): ";
            printArr(arr,n);
            std::cout<<endl;
        }
    }
    void bubbleSort(){
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(arr[j] > arr[j+1]){
                    swap(&arr[j],&arr[j+1]);=
                }
            }
        }
    }

}