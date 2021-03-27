#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

string play_time = "50:00:00";
string adv_time = "50:00:00";
vector<string> logs = {"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"};

int strToSec(string str) {
    int hour = stoi(str.substr(0, 2));
    int min = stoi(str.substr(3, 2));
    int sec = stoi(str.substr(6, 2));
    
    int res = (hour * 3600) + (min * 60) + sec;
    return res;
}

string SecToStr(int input) {
    string res = "";
    int hour = input / 3600;
    int min = (input % 3600) / 60;
    int sec = input - hour*3600 - min*60;
    
    string timeStr = to_string(hour);
    if (timeStr.size() == 1) res += "0";
    res +=timeStr + ":";
    timeStr = to_string(min);
    if(timeStr.size() == 1) res += "0";
    res += timeStr + ":";
    timeStr = to_string(sec);
    if(timeStr.size() == 1) res += "0";
    res += timeStr;
    
    return res;
}

int main()
{
    int playTime = strToSec(play_time);
    int advTime = strToSec(adv_time);
    vector<int> section(playTime, 0);
    
    for (string log : logs) {
        int start = strToSec(log.substr(0, 8));
        int end = strToSec(log.substr(9, 8));
        
        for (int i = start; i <= end; i++) section[i]++;
    }
    
    int maxSum = accumulate(section.begin(), section.begin() + advTime, 0);
    int sum = maxSum;
    int idx = 0;
    
    for (int i = 1; i < section.size()-advTime; i++) {
        sum = sum - section[i-1] + section[i+advTime];
        if (maxSum < sum) {
            idx = i;
            maxSum = sum;
        }
    }
    
    cout << SecToStr(idx);
    
    return 0;
}
