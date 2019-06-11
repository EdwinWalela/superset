# SuperArray
C++ Dynamically sized array with sorting methods

## Usage
1. Clone / download the repo
2. Add `SuperArray.h` into your working directory
3. Include the header in your cpp file

```c++
#include "SuperArray.h"
```

## Features
- [x] Dynamically sized
- [x] Bubble Sort (+ verbose)
- [x] Merge Sort 

## TODO
- [ ] Merge Sort (Verbose)
- [ ] Exception Handling (print() method)
- [x] Reverse function
- [ ] Union
- [ ] Intersection
- [ ] Quick Sort
- [ ] Radix Sort
- [ ] Selection Sort
- [ ] Search Algorithims ...


## Usage
### Initialization
The SuperArray can be initialized with a size(optional)
```c++
  SuperArray<int> arr(5);
  
  SuperArray<int> arr;
  
```

### Utility Methods
```c++
    SuperArray<int> arr;
    
    for(int i = 0; i < 5; i++){
      arr.push(i);  // Add elements to the SuperArray
    }

    // Output contents of the SuperArray

    arr.print(); // [0,1,2,3,4]

    // print method can be overloaded by providing limits

    int mid = arr.length()/2;

    arr.print(mid,arr.length()); // [2,3,4]

    // Get length of the SuperArray

    arr.length(); // 5

    // Reverse SuperArray

    arr.reverse(); // [4,3,2,1,0]

    // Search for element
    int x = 0;

    int size = arr.length();

    bool present = arr.exists(x,0,size);

    if(present){
      std::cout<<x<<" is present in the SuperArray";
    }else{
      std::cout<<x<<" does not exist in the SuperArray";
    }
  }
```

### Sorting Methods
The SuperArray has 4 modes for each sorting algorigthim
1. Ascending (Asc)
2. Ascending Verbose (AscV)
3. Descending (Desc)
4. Descending Verbose (DescV)

The Verbose mode provides output at each step/pass of the algorithim

### 1. Bubble Sort
```c++
  SuperArray<int> arr;
  
  for(int i = 0; i < 5; i++){
    arr.push(i);
  }
  // arr = [ 0 , 1 , 2 , 3 , 4 ]
  
  arr.bubbleSortDesc();
  // arr = [ 4 , 3 , 2 , 1 , 0 ]
```

#### Verbose Mode
This will print each pass of the bubble sort algorithim 

```cpp
SuperArray<int> arr;
  
for(int i = 0; i < 5; i++){
    arr.push(i);
}

arr.bubbleSortDescV();
/*
  Output:
  pass(1): 1 2 3 4 0
  pass(2): 2 3 4 1 0
  pass(3): 3 4 2 1 0
  pass(4): 4 3 2 1 0
*/

```
