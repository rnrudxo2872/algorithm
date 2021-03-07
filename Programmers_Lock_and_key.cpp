#include <string>
#include <vector>
#include <iostream>

using namespace std;

int map[61][61] = { 0, };

void arr_rotate(vector<vector<int>>& key) {//키 회전 함수
    int size = key.size();
    vector<vector<int>> temp(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[i][j] = key[size - j - 1][i];
        }
    }
    key = temp;
    return;
}

bool check(int y, int x, int LockStart, int sizeOfLock, vector<vector<int>> &key) {
    int dum = 0, dum2 = 0;
    int temp[61][61] = { 0, };
    for (int e = y; e <= y + LockStart; e++) {
        for (int f = x; f <= x + LockStart; f++) {
            temp[e][f] = key[dum][dum2];
            dum2++;
        }
        dum2 = 0;
        dum++;
    }

    for (int i = LockStart; i < LockStart + sizeOfLock; i++) {
        for (int j = LockStart; j < LockStart + sizeOfLock; j++) {
            temp[i][j] += map[i][j];
            if (temp[i][j] != 1)
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
     // maximum 39 x 39 loop
    int LockStart = key.size() - 1; // 중앙 map에 lock array를 시작시킬 index
    int sizeOfLock = lock.size();

    int y = 0, x = 0;
    //cout << LockStart << ": " << sizeOfLock << endl;
    for (int i = LockStart; i < LockStart + sizeOfLock; i++) {
        for (int j = LockStart; j < LockStart + sizeOfLock; j++) {
            map[i][j] = lock[y][x];
            x++;
        }
        x = 0;
        y++;
    }

    y = 0;
    x = 0;
    for (int k = 0; k < 4; k++) {

        for (int i = 0; i < LockStart + sizeOfLock; i++) { //key 값을 다 더해본다.
            for (int j = 0; j < LockStart + sizeOfLock; j++) {
                if (check(i, j, LockStart, sizeOfLock, key)) {
                    return true;
                }
                
            }
            
        }
        x = 0;
        y = 0;
        arr_rotate(key);
    }
    return answer;
}

//#include <algorithm>
//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//void arr_rotate(vector<vector<int>>& key) {
//    int size = key.size();
//    vector<vector<int>> temp(size, vector<int>(size, 0));
//
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            temp[i][j] = key[size - j - 1][i];
//        }
//    }
//    key = temp;
//    return;
//}
//
//bool alight(int x, int y, vector<vector<int>> map, vector<vector<int>> key, vector<pair<int, int>> index) {
//    int s = 0, e = 0;
//    for (int i = x; i < key.size() + x && i < map.size(); i++) {
//        for (int j = y; j < key.size() + y && j < map.size(); j++) {
//            map[i][j] += key[s][e];
//            //cout << "i : "<< i<< " j : "<< j<< " 좌표값 : "<< map[i][j] << endl;
//            if (map[i][j] > 1)
//                return false;
//            e++;
//        }
//        e = 0;
//        s++;
//    }
//
//    /*for (int i = key.size() - 1; i < map.size() - (key.size() * 2) + 2; i++) {
//        for (int j = key.size() - 1; j < map.size() - (key.size() * 2) + 2; j++) {
//
//        }
//    }*/
//
//    while (!index.empty()) {
//        int i_point = index.back().first, j_point = index.back().second;
//        index.pop_back();
//        //cout << "비었던 i 좌표 : " << i_point << " 비었던 j 좌표 : " << j_point << endl;
//        //cout << "빈 좌표 : "<<map[i_point][j_point] << endl;
//        if (map[i_point][j_point] == 0)
//            return false;
//    }
//    return true;
//}
//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//    bool answer = false;
//
//    int k_size = key.size(), l_size = lock.size();
//    vector<vector<int>> map((k_size * 2) + l_size - 2, vector<int>((k_size * 2) + l_size - 2, 0)); // 2차원 vector 0 defalt;
//    vector<pair<int, int>> index;
//
//
//    int t = 0, tt = 0;
//
//    for (int i = 0; i < key.size(); i++) {
//        for (int j = 0; j < key.size(); j++) {
//            if (key[i][j] == 1)
//                t++;
//        }
//    }
//    int x = 0, y = 0;
//    for (int i = k_size - 1; i < k_size + l_size - 1; i++) {
//        for (int j = k_size - 1; j < k_size + l_size - 1; j++) {
//            map[i][j] = lock[x][y];
//            if (lock[x][y] == 0) {
//                index.push_back(make_pair(i, j));
//                tt++;
//            }
//
//            y++;
//        }
//        y = 0;
//        x++;
//    }
//
//    if (t < tt)
//        return false;
//
//    for (int rot = 0; rot < 4; rot++) {
//        for (int i = 0; i < map.size(); i++) {
//            for (int j = 0; j < map.size(); j++) {
//                //cout << "i : " << i <<" j : "<< j << endl;
//                //cout << " 판단 " << endl;
//                if (alight(i, j, map, key, index)) {
//                    return true;
//                }
//                else {
//                    answer = false;
//                }
//            }
//        }
//        //cout << "돌려" << endl;
//        arr_rotate(key);
//    }
//
//    return answer;
//}