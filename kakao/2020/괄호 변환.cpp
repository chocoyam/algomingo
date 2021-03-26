#include <string>
#include <vector>

using namespace std;

void divideStr(string str, string& u, string& v) {
    int open = 0;
    int close = 0;
    
    for (char ch : str) {
        if (ch == '(') open++;
        else close++;
        
        u += ch;
        
        if (open == close) {
            v = str.substr(u.size(), str.size()-1);
            return;
        }
    }
}

bool isCorrectStr(string str) {
    string temp = str;
    
    if (temp[0] == ')') return false;
    else {
        temp.erase(0, 1);
        
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == ')') {
                temp.erase(i, 1);
                break;
            }
        }
        
        if (temp.size() == 0) return true;
        else return isCorrectStr(temp);
    }
}

string removeAndReverse(string str) {
    string res = "";
    
    for (int i = 1; i < str.size()-1; i++) {
        if (str[i] == '(') res += ")";
        else res += "(";
    }
    return res;
}

string dfs(string str) {
    if (str.empty()) return str;
    
    string res, u, v = "";
    divideStr(str, u, v);
    
    if (isCorrectStr(u) == true) {
        return u + dfs(v);
    } else {
        return "(" + dfs(v) + ")" + removeAndReverse(u);
    }
}

string solution(string p) {
    string answer = dfs(p);
    return answer;
}
