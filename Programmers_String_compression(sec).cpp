#include<bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for (int Len = 1; Len <= s.length(); Len++) {
        int CurLen = s.length();
        int Idx = 0;
       
        while (1) {

            int cnt = 0;

            //처음 잘리는 문자열
            string CurSub = s.substr(Idx, Len);
            Idx += Len;
            cnt++;

            if (CurSub.length() < Len || Idx >= s.length())
                break;

            while (1) {
                if (CurSub.compare(s.substr(Idx, Len)) != 0)
                    break;
                cnt++;
                Idx += Len;
            }

            if (cnt > 1) {
                CurLen -= Len * (cnt - 1);
                
                if (cnt < 10) 
                    CurLen += 1;
                
                else if (cnt < 100) 
                    CurLen += 2;
                
                else if (cnt < 1000)
                    CurLen += 3;
             
                else
                    CurLen += 4;
                    
            }

        }
        answer = answer < CurLen ? answer : CurLen;
    }
    
    return answer;
}