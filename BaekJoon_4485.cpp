#include<iostream>
#include<queue>
#include<functional>
#include<cstring>

using namespace std;
#define defalt 999999
#define endl "\n"
int map[125][125];
int dist[125][125];
int delx[4] = { 0,0,1,-1 };
int dely[4] = { 1,-1,0,0 };
int visit[125][125];

int N;

void dijkstra() {
	priority_queue < pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> qu;
	qu.push({ map[0][0],{0,0} });
	visit[0][0] = true;
	dist[0][0] = map[0][0];

	while (!qu.empty()) {
		int weight = qu.top().first;
		int y = qu.top().second.first;
		int x = qu.top().second.second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			if (y + dely[i] > -1 && x + delx[i] > -1 && !visit[y + dely[i]][x + delx[i]] 
				&& dist[y + dely[i]][x + delx[i]] > weight + map[y + dely[i]][x + delx[i]]
				&& y + dely[i] < N && x + delx[i] < N) {
				dist[y + dely[i]][x + delx[i]] = weight + map[y + dely[i]][x + delx[i]];
				visit[y + dely[i]][x + delx[i]] = true;
				qu.push({ weight + map[y + dely[i]][x + delx[i]],{ y + dely[i], x + delx[i] } });
			}		
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int number = 1;
	while (1) {
		cin >> N;

		if (N == 0)
			break;
		fill(&dist[0][0], &dist[124][125], defalt);
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		}

		dijkstra();

		cout << "Problem " << number << ": "<< dist[N - 1][N - 1] << endl;
		number++;
	}
}