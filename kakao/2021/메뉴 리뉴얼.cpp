#include <bits/stdc++.h>

using namespace std;

vector<string> Orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
vector<int> Course = {2, 3, 5};



string sortString(string str)
{
    vector<char> chVector(str.begin(), str.end());
    sort(chVector.begin(), chVector.end());
    return string(chVector.begin(), chVector.end());
}

vector<string> splitStrByLen(string str, int len)
{
    vector<string> result;
    if (str.size() < len) return result;
    for (int i = 0 ; i <= str.size() - len; i++) 
        result.push_back(str.substr(i, len));
    return result;
}

bool comp(pair<string, int> lhs, pair<string, int> rhs)
{
    if (lhs.second < rhs.second) return true;
    else return false;
}

int main()
{
    map<string, int> ordersByCourse[Course.size()];
    //Orders에 있는 각 문자열을 오름차순으로
    for (string str : Orders) {
        str.replace(0, str.size(), sortString(str));

        for (int i = 0; i < Course.size(); i++) {
            vector<string> temp = splitStrByLen(str, Course[i]);
            
            for (string tempStr : temp) {
                if (ordersByCourse[i].find(tempStr) == ordersByCourse[i].end()) {
                    ordersByCourse[i][tempStr] = 0;
                } else {
                    ordersByCourse[i][tempStr] += 1; 
                }
            }
            
            for (pair<string, int> data : ordersByCourse[i]) 
                cout << data.first << " : " << data.second << endl;
        }
    }
    
    vector<string> answer;
    for (auto courseMap : ordersByCourse) {
        pair<string, int> data = *max_element(courseMap.begin(), courseMap.end(), comp);
        
        for (pair<string, int> element : courseMap) {
            if (element.second == data.second)  answer.push_back(element.first);
        }
    }
    
    for (string res : answer) cout << res << endl;
    

    return 0;
}
