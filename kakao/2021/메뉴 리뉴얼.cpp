#include <bits/stdc++.h>

using namespace std;

string sortString(string str)
{
    vector<char> chVector(str.begin(), str.end());
    sort(chVector.begin(), chVector.end());
    return string(chVector.begin(), chVector.end());
}

void splitStrByLen(string str, int courseIdx, map<string, int>* maps, int len)
{
    if (str.size() < len) return;
    
    string sortedStr = sortString(str);
    if (len == str.size()) {
        if (maps[courseIdx].find(sortedStr) == maps[courseIdx].end()) maps[courseIdx][sortedStr] = 1;
        else maps[courseIdx][sortedStr] += 1;
        
        return;
    }

    vector<char> charVec(str.begin(), str.end());
    vector<bool> combVec(charVec.size(), true);
    for (int i = 0; i < charVec.size() - len; i++) combVec[i] = false;
    
    //조합으로
    do {
        string menu = "";
        for (int i = 0; i < charVec.size(); i++) 
            if (combVec[i]) menu += charVec[i];
        
        if (maps[courseIdx].find(menu) == maps[courseIdx].end()) maps[courseIdx][sortString(menu)] = 1;
        else maps[courseIdx][sortString(menu)] += 1;

    } while(next_permutation(combVec.begin(), combVec.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    map<string, int> ordersByCourse[course.size()];
    
    for (string order : orders) {
        for (int i = 0; i < course.size(); i++) {
            splitStrByLen(order, i, ordersByCourse, course[i]);
        }
    }
    
    vector<string> answer;
    for (auto map : ordersByCourse) {
        int max = 0;
        vector<string> tempAnswer;
        for (auto data : map) {
            if (data.second > 1 && data.second >= max) {
                if (data.second > max) tempAnswer.clear();
                max = data.second;
                tempAnswer.push_back(data.first);
            }
        }
        answer.insert(answer.end(), tempAnswer.begin(), tempAnswer.end());
    }
    
    sort(answer.begin(), answer.end());    
    return answer;
}

