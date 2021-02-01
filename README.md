
## std::string
1. Can access using index, []
```
std::string str = "Hello";
std::cout << str[1];  //e
```

## char/string <-> number
1. char -> int
```
char numChar = "1";
int num = numChar - '0';  //int casting if needed
```

2. string -> int
```
std::string numStr = "123";
int num = std::stoi(numStr);
```
