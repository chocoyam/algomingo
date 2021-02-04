## Using lower_bound(), upper_bound()
*#include \<algorithm\>*   
중복된 자료가 있을 때, 중복된 자료의 개수 구할 때 사용

### - lower_bound
> *ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val);*   
> *ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);*   

key 이상인 값을 가지는 iter 리턴

### - upper_bound
> *ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val);*   
> *ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);*   

key를 초과하는 iter 리턴

```
std::vector<int> inputs = {1, 1, 2, 2, 2, 2, 3};
int find = 2;
int count = 0;

std::vector<int>::iterator leftIter =  std::lower_bound(inputs.begin(), inputs.end(), find);
std::vector<int>::iterator rightIter = std::upper_bound(inputs.begin(), inputs.end(), find);

count = rightIter - leftIter;
```
