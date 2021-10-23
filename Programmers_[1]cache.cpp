#include<bits/stdc++.h>

using namespace std;

string convertLower(string str) {
    for(int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    list<string> cache;
    list<string>::iterator it;
    
    if(cacheSize == 0) return cities.size() * 5;
    
    for(int i = 0; i < cities.size(); ++i) {
        cities[i] = convertLower(cities[i]);
        
        if(cache.size() == 0) {
            answer += 5;
            cache.push_back(cities[i]);
            continue;
        }
        
        //search
        bool flag = false;
        for(it = cache.begin(); it != cache.end(); ++it) {
            string cur = *it;
            
            if(cur.compare(cities[i]) == 0) {
                answer++;
                flag = true;
                
                cache.erase(it);
                cache.push_back(cur);
                break;
            }
        }
        
        if(flag) continue;
        
        answer += 5;
        if(cache.size() >= cacheSize) {
            cache.erase(cache.begin());
            cache.push_back(cities[i]);
            continue;
        }
        cache.push_back(cities[i]);
    }
    
    return answer;
}