#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {    
    //소문자로
    for (char& ch : new_id) {
        ch = tolower(ch);
    }
    
    string result2 = "";
    //허용 안되는 문자 제거
    for (char ch : new_id) {
        if (!('a' <= ch && ch <= 'z') && !('0' <= ch && ch <= '9') &&
            ch != '-' && ch != '_' && ch != '.') {
            continue;
        }
        result2 += ch;
    }
    
    //. 중복 제거
    string result = "";
    bool existDot = false;
    for (char ch : result2) {
        if (ch == '.') {
            if (existDot) continue;
            existDot = true;
        } else {
            existDot = false;
        }
        result += ch;
    }
        
    //처음이나 끝에 마침표 제거
    if (result[0] == '.') {
        result = result.substr(1, result.size());
    }
    if (result[result.size()-1] == '.') {
        result = result.substr(0, result.size()-1);
    }
    
    //빈 문자열 처리
    if (result.size() == 0) {
        result = "a";
    }
    
    //16글자 이상인지 체크
    if (16 <= result.size()) {
        result = result.substr(0, 15);
    }
    if (result[result.size()-1] == '.') {
        result = result.substr(0, result.size()-1);
    }
    
    //2자 이하인 경우 처리
    if (result.size() == 1) {
        result += result[0];
        result += result[0];
    }
    if (result.size() == 2) {
        result += result[1];
    }
    
    return result;
}
