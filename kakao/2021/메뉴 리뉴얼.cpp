#include <bits/stdc++.h>

using namespace std;

vector<string> Orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
vector<int> Course = {2, 3, 5};

map<string, int> ordersByCourse[Course.size()];

string sortString(string str)
{
    vector<char> chVector(str.begin(), str.end());
    sort(chVector.begin(), chVector.end());
    return string(chVector.begin(), chVector.end());
}

vector<string> splitStrByLen(string str, int len)
{
    vector<string> returnVec;
    string sortedStr = sortString(str);
    vector<char> charVec(str.begin(), str.end());
    vector<bool> combVec(charVec.size(), true);
    for (int i = 0; i < charVec.size() - len; i++) combVec[i] = false;
    
    //조합으로
    do {
        string menu = "";
        for (int i = 0; i < charVec.size(); i++) 
            if (combVec[i]) menu += charVec[i];
        
        returnVec.push_back(menu);
    } while(next_permutation(combVec.begin(), combVec.end()));
}

bool comp(pair<string, int> lhs, pair<string, int> rhs)
{
    if (lhs.second < rhs.second) return true;
    else return false;
}

int main()
{

    return 0;
}
