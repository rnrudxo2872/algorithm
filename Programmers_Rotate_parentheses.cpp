#include <bits/stdc++.h>

using namespace std;

map<char,char> dic;

string shiftStr(string str) {
    char first = str[0];
    string ret = str.substr(1, str.length()-1);
    ret.push_back(first);
    
    return ret;
}

bool isOpen(char ch) {
    
    if(ch == '(') return true;
    if(ch == '{') return true;
    if(ch == '[') return true;

    return false;
}

bool checkAns(string str) {
    vector<char> stack;
    
    for(int i = 0; i < str.length(); i++) {
        if(stack.empty()) {
            if(!isOpen(str[i])) {
                return false;
            }
            stack.push_back(str[i]);
            continue;
        }
        
        char tail = stack[stack.size()-1];
        
        if(!isOpen(str[i])) {
            if(dic[tail] == str[i]) {
                stack.pop_back();
                continue;
            }
            return false;
        }
        stack.push_back(str[i]);
    }
    
    if(stack.size() > 0) return false;
    
    return true;
}

int solution(string s) {
    int answer = 0;
    int len = s.length();
    
    dic.insert(make_pair('(',')'));
    dic.insert(make_pair('{','}'));
    dic.insert(make_pair('[',']'));
    
    for(int i = 0; i < len; i++) {
        if(checkAns(s)) answer++;
        s = shiftStr(s);
        
    }
    
    return answer;
}