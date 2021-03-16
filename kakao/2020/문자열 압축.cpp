#include <iostream>

using namespace std;

int main()
{
    string s = "xababcdcdababcdcd";
    int min = 0;
    for (int strSize = 1; strSize <= s.size()/2; strSize++) {
        int result = 0;
        int compact = 0;
        bool isSequence = false;
        
        for (int i = 0; i < s.size()-strSize; i += strSize) {
            string now = s.substr(i, strSize);
            string next = s.substr(i + strSize, strSize);
            if (now == next) {
                compact++;
                isSequence = true;
                if (i + strSize >= s.size()-strSize) result++;  //last char
            } else {
                if (isSequence) result++;
                isSequence = false;
            }
        }
        result += (s.size() - (compact*strSize));
        if (min == 0 || min > result) min = result;
    }

    cout << min;
    return 0;
}
