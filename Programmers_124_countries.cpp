#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    char dic[3] = {'4','1','2'};
    
    while(true) {
        answer = dic[n%3] + answer;
        if(n < 4) return answer;
        n = (n%3) == 0 ? (n/3) - 1 : n/3;
    }
}