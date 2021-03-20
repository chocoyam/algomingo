## std::string
#### operator[]
- access using index
> char& operator (size_t pos);   
> const char& operator[] (size_t pos) const;   
```c++
std::string str = "Hello";
char ch = str[1];
std::cout << ch;  //e

char& pCh = str[0];
pch = 'J';
std::cout << str;  //"Jello"
```

</br>

## char/string <-> number
#### char -> int
```c++
char numChar = "1";
int num = numChar - '0';  //int casting if needed
```

#### string -> int
```c++
std::string numStr = "123";
int num = std::stoi(numStr);
```

</br>

## string 대소문자 변환
```c++
std::string lowStr = "abcd";
for (char& ch : lowStr) {
  ch = toupper(ch);
}
std::cout << lowStr;  //"ABCD"

std::string upperStr = "ABCD";
for (char& ch : upperStr) {
  ch = tolower(ch);
}
std::cout << upperStr;  //"abcd"
```
