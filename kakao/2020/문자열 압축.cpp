#include <string>
#include <vector>

using namespace std;

void compRes(string& res, string str, int cnt) {
    res += str;
    if (cnt != 1) {
        res += to_string(cnt);
    }
    return;
}

int solution(string s) {
    string answerStr = s;
    for (int i = 1; i <= s.size()/2; i++) {
        int cur = 0;
        vector<string> strs;
        while (cur < s.size()) {
            strs.push_back(s.substr(cur, i));
            cur += i;
        }
        
        string curStr = "";
        string res = "";
        int cnt = 1;
        for (string str : strs) {
            if (curStr != str) {
                compRes(res, curStr, cnt);
                curStr = str;
                cnt = 1;
            } else {
                cnt++;   
            }
        }
        compRes(res, curStr, cnt);
        if (res.size() < answerStr.size()) {
            answerStr = res;
        }
    }

    return answerStr.size();
}
