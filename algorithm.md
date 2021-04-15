# <algorithm>

## 순열
### std::next_permutation   
- 원소가 10개 이하일 때 사용하는게 좋음 (그 이상이면 DFS로 순열 구현)
> template \<class BidirectionalIterator\>   
  bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);  
>  
> template \<class BidirectionalIterator, class Compare\>   
  bool next_permutation (BidirectionalIterator first, BidirectionalIterator last, Compare comp);   
```c++    
  int myints[] = {1, 2, 3};
    std::sort (myints, myints+3);  //오름차순으로 정렬되어야 함
    
  do {
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  } while ( std::next_permutation(myints, myints+3) );  //[first,last)
    
  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
```


#### REFERENCE
- https://ansohxxn.github.io/algorithm/combination/#stl-next_permutation%EC%9C%BC%EB%A1%9C-%EC%A1%B0%ED%95%A9-%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0
