#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int totalLen = s.length();
    int answer = totalLen;

    for (int i = 1; i <= totalLen / 2; i++) { //길이의 반까지 단위로 자를 수 있다.
        int pos = 0; //문자열 시작점
        int Len = totalLen;
        
        while(1){
            string temp = s.substr(pos, i);
            pos += i;
            int cnt = 0;

            if (pos >= totalLen)
                break;

            while(1) {
                if (temp.compare(s.substr(pos, i)) == 0) {
                    cnt++;
                    pos += i;
                }
                else
                    break;
            }

            if (cnt > 0) {
                Len -= i * cnt;
                
                if (cnt < 9)
                    Len += 1;
                else if (cnt < 99)
                    Len += 2;
                else if (cnt < 999)
                    Len += 3;
                else
                    Len += 4; //1000 글자일 때
            }
        }
        answer = answer < Len ? answer : Len;
    }

    return answer;
}