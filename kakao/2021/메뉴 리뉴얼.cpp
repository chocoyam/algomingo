#include <bits/stdc++.h>

using namespace std;

vector<string> Orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
vector<int> Course = {2, 3, 5};

map<string, int> ordersByCourse[3];

string sortString(string str)
{
    vector<char> chVector(str.begin(), str.end());
    sort(chVector.begin(), chVector.end());
    return string(chVector.begin(), chVector.end());
}

void splitStrByLen(string str, int courseIdx)
{
    int len = Course[courseIdx];
    
    if (str.size() < len) return;
    
    string sortedStr = sortString(str);
    
    if (len == str.size()) {
        if (ordersByCourse[courseIdx].find(str) == ordersByCourse[courseIdx].end()) ordersByCourse[courseIdx][str] = 1;
        else ordersByCourse[courseIdx][str] += 1;
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
        
        if (ordersByCourse[courseIdx].find(menu) == ordersByCourse[courseIdx].end()) ordersByCourse[courseIdx][menu] = 1;
        else ordersByCourse[courseIdx][menu] += 1;
    } while(next_permutation(combVec.begin(), combVec.end()));
}

bool comp(pair<string, int> lhs, pair<string, int> rhs)
{
    if (lhs.second < rhs.second) return true;
    else return false;
}

int main()
{
    for (string order : Orders) {
        for (int i = 0; i < Course.size(); i++) {
            splitStrByLen(order, i);
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
    
    for (string str : answer) cout << str << endl;

    return 0;
}
