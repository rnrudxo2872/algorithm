#include <string>
#include <vector>
#define Max 362500

using namespace std;
typedef long long ll;

ll totalAd[Max] = { 0, };
ll totalBord[Max] = { 0, };

ll conver_sec(string s) {
    string head = s.substr(0, 2);
    string mid = s.substr(3, 2);
    string tail = s.substr(6, 2);

    int hour = stoi(head) * 3600;
    int min = stoi(mid) * 60;
    int sec = stoi(tail) + (hour + min);

    return sec;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    ll temp_ans = 1;

    for (int i = 0; i < logs.size(); i++) { // 시간대별 시청자 수.
        ll Start = conver_sec(logs[i].substr(0, 8));
        ll End = conver_sec(logs[i].substr(9, 8));

        for (int j = Start + 1; j <= End; j++)
            totalBord[j] += 1;
    }
    ll convertAd = conver_sec(adv_time);
    ll convertPlay = conver_sec(play_time);
    ll CurStack = 0;
    ll MaxTime = 0;

    for (int i = 1; i <= convertAd; i++) { // 완전탐색을 위해 0초부터 광고를 넣는다.
        CurStack += totalBord[i];
    }
    MaxTime = CurStack;

    for (int i = 2; i <= (convertPlay - convertAd) + 1; i++) { // early find Max
        CurStack += (totalBord[convertAd + i - 1] - totalBord[i - 1]);

        if (MaxTime < CurStack) {
            temp_ans = i;
            MaxTime = CurStack;
        }
    }
    temp_ans--;
    int hour = temp_ans / 3600;
    temp_ans %= 3600;
    if (hour <= 9)
        answer += "0";
    answer += to_string(hour) + ":";

    int min = temp_ans / 60;
    if (min <= 9)
        answer += "0";
    answer += to_string(min) + ":";
    temp_ans %= 60;

    if (temp_ans <= 9)
        answer += "0";
    answer += to_string(temp_ans);

    return answer;
}