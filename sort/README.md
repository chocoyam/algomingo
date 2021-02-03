## sort library
*#include \<algorithm\>*   

### \<Basic\>
***void sort (RandomAccessIterator first, RandomAccessIterator last);***   
Sorts the elements in the range [first,last) into ascending order.
#### with array
    sort(arr, arr + arrSize);
#### with vector
    sort(iter.begin(), iter.end());
    
### \<Compare\>
***void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);***  
The elements are compared using comp.
#### with greater/less
    #include <functional>
    sort(first, last, std::greater<DATA_TYPE>());  //Descending
    sort(first, last, std::less<DATA_TYPE>());  //ascending
#### with custom compare
when comparing members of struct or object
```
    bool comapre(Student a, Student b) {
      return a.age < b.age;  //ascending
    }
    
    sort(first, last, compare);
```

### \<Overload Operator\>
```
    class Student {
      public :
        string name;
        int age;
        
        bool operator<(Student s) const {
          return this->age < s.age;  //ascending
        }
    }
```
