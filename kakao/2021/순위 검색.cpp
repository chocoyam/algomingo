#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum Conditions {
    none = 0 << 0,
    cpp = 1 << 0,
    java = 1 << 1,
    python = 1 << 2,
        
    backend = 1 << 3,
    frontend = 1 << 4,
        
    junior = 1 << 5,
    senior = 1 << 6,

    chicken = 1 << 7,
    pizza = 1 << 8
};

struct Applicant {
    int condInt;
    int score;
};

Conditions getCondition(string str) {
    if (str == "cpp") return Conditions::cpp;
    else if (str == "java") return Conditions::java;
    else if (str == "python") return Conditions::python;
    else if (str == "backend") return Conditions::backend;
    else if (str == "frontend") return Conditions::frontend;
    else if (str == "junior") return Conditions::junior;
    else if (str == "senior") return Conditions::senior;
    else if (str == "chicken") return Conditions::chicken;
    else return Conditions::pizza;
}

Conditions getAllCondition(int index) {
    switch (index) {
        case 0 : return static_cast<Conditions>(Conditions::cpp | Conditions::java | Conditions:: python);
                 break;
        case 1 : return static_cast<Conditions>(Conditions::backend | Conditions::frontend);
                 break;
        case 2 : return static_cast<Conditions>(Conditions::junior | Conditions::senior);
                 break;
        case 3 : return static_cast<Conditions>(Conditions::chicken | Conditions::pizza);
                 break;
        default : return static_cast<Conditions>(Conditions::none);
    }
}

Applicant getApplicant(string str) {
    Applicant applicant;
    int condInt = 0;
    int pos = 0;
    for (int i = 0; i < 5; i++) {
        int space = str.find(' ', pos);
        string getStr = str.substr(pos, space - pos);
        if (i != 4) {
            condInt = condInt | getCondition(getStr);
        }
        else {
            applicant.condInt = condInt;
            applicant.score = stoi(getStr);
        }
        pos = space + 1;
    }
    
    return applicant;
}

bool compareScore(Applicant lhs, Applicant rhs) {
    return lhs.score < rhs.score;
}

vector<int> solution(vector<string> infos, vector<string> query) {    
    vector<int> answer;
    
    vector<Applicant> applicants;
    for (string info : infos) 
        applicants.push_back(getApplicant(info));
        
    sort(applicants.begin(), applicants.end(), compareScore);
    
    for (string q : query) {
        Conditions cond = Conditions::none;
        int pos = 0;
        for (int i = 0; i < 4; i++) {
            int space = q.find(" and ", pos);
            string getStr = q.substr(pos, space - pos);
            
            if (i != 3) {
                if (getStr == "-") cond = static_cast<Conditions>(cond | getAllCondition(i));
                else cond = static_cast<Conditions>(cond | getCondition(getStr));
            } else {
                string food = getStr.substr(0, getStr.find(' '));
                if (food == "-") cond = static_cast<Conditions>(cond | getAllCondition(i));
                else cond = static_cast<Conditions>(cond | getCondition(food));
                int score = stoi(getStr.substr(getStr.find(' ')+1));
                
                int res = 0;
                auto iter = lower_bound(applicants.begin(), applicants.end(), Applicant{0, score}, compareScore);
                for (iter; iter != applicants.end(); iter++) {
                    if ((iter->condInt & cond) == iter->condInt) res++;
                }
                
                answer.emplace_back(res);
                break;
            }
            pos = space + 5;
        }
    }
    
    return answer;
}
