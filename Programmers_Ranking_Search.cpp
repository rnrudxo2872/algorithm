#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct Info {
    int lang; //0 cpp, 1 java, 2 python 
    int position; //0 backend, 1 frontend
    int expert; //0 junior, 1 senior
    int food; //0 chicken, 1 pizza
};

vector<int> Map[3][2][2][2];

bool cmp(int& a, int& b) {
    return a > b;
}

void InsertInfo(string str[5]) {
    int lang = str[0][0] == 'c' ? 0 : (str[0][0] == 'j' ? 1 : 2);
    int position = str[1][0] == 'b' ? 0 : 1;
    int expert = str[2][0] == 'j' ? 0 : 1;
    int food = str[3][0] == 'c' ? 0 : 1;
    int score = stoi(str[4]);

    Map[lang][position][expert][food].push_back(score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for (string str : info) {
        istringstream infoSplit(str);
        string insStr[5];
        infoSplit >> insStr[0] >> insStr[1] >> insStr[2] >> insStr[3] >> insStr[4];

        InsertInfo(insStr);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int z = 0; z < 2; z++)
                    sort(Map[i][j][k][z].begin(), Map[i][j][k][z].end(), cmp);
            }
        }
    }
    /*for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int z = 0; z < 2; z++) {
                    for (int q = 0; q < Map[i][j][k][z].size(); q++)
                        cout << Map[i][j][k][z][q] << " ";
                cout << endl;
                }
            }
        }
    }*/
    //int lang; //0 cpp, 1 java, 2 python 
    //int position; //0 backend, 1 frontend
    //int expert; //0 junior, 1 senior
    //int food; //0 chicken, 1 pizza

    for (string str : query) {
        istringstream querySplit(str);
        string insStr[8];

        //lang and pos and exper and food score
        querySplit >> insStr[0] >> insStr[1] >> insStr[2] >> insStr[3] >> insStr[4] >> insStr[5] >> insStr[6]
            >> insStr[7];
        
        int lang = insStr[0][0] == 'c' ? 0 : (insStr[0][0] == 'j' ? 1 : insStr[0][0] == 'p' ? 2 : 10);
        int position = insStr[2][0] == 'b' ? 0 : (insStr[2][0] == 'f' ? 1 : 10);
        int expert = insStr[4][0] == 'j' ? 0 : (insStr[4][0] == 's' ? 1 : 10);
        int food = insStr[6][0] == 'c' ? 0 : (insStr[6][0] == 'p' ? 1 : 10);
        int score = stoi(insStr[7]);

        int cnt = 0;
        
        for (int l = 0; l < 3; l++) {
            if (lang != 10 && lang != l)
                continue;
            for (int p = 0; p < 2; p++) {
                if (position != 10 && position != p)
                    continue;
                for (int e = 0; e < 2; e++) {
                    if (expert != 10 && expert != e)
                        continue;
                    for (int f = 0; f < 2; f++) {
                        if (food != 10 && food != f)
                            continue;
                        for (int i = 0; i < Map[l][p][e][f].size(); i++) {
                            if (Map[l][p][e][f][i] < score)
                                break;
                            cnt++;
                        }
                    }
                }
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}

int main() {
    vector<int> ans = solution({ "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" }, 
        { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" });

    for (int num : ans)
        cout << num << " ";
}