#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int video_map[64][64];

string result;

void div_query(int xst, int yst, int xend, int yend) {
    
    int check = video_map[yst][xst];
    
    for (int y = yst; y < yend; y++) {
        for (int x = xst; x < xend; x++) {
            if (check != video_map[y][x]){

                result += "(";
                div_query(xst, yst, (xst + xend) / 2, (yst + yend) / 2);
                div_query((xst + xend) / 2, yst, xend, (yst + yend) / 2);
                div_query(xst, (yst + yend) / 2, (xst + xend) / 2, yend);
                div_query((xst + xend) / 2, (yst + yend) / 2, xend, yend);


                result += ")";
                return;
            }
        }
    }
    if (check == 1) {
        result += "1";
    }
    else if (check == 0) {
        result += "0";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = "";
    memset(video_map, 0, sizeof(video_map));
    int size = 0;

    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> s;
        for (int j = 0; j < size; j++) {
            video_map[i][j] = s[j] - '0';
        }
    }

    div_query(0, 0, size, size);

    cout << result << "\n";

    return 0;
}