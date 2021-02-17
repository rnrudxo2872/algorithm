#include<iostream>
#include<vector>
#include<functional>
#include<queue>

#define endl "\n"

using namespace std;

vector<pair<int, int>> con[20001];
int V, E, K;
int dis[20001];
bool visit[20001];

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> qu; // first 가중치, sec 현재 노드번호

	qu.push({ 0,K });
	fill(dis, dis + V + 1, 999999);

	while (!qu.empty()) {
		int cur_node = qu.top().second;
		int cur_w = qu.top().first;
		qu.pop();
		//cout << "node : " << cur_node << ", w : " << cur_w << endl;

		for (int i = 0; i < con[cur_node].size(); i++) {
			if (dis[con[cur_node][i].second] > cur_w + con[cur_node][i].first) {
				dis[con[cur_node][i].second] = cur_w + con[cur_node][i].first;
				qu.push({ con[cur_node][i].first + cur_w, con[cur_node][i].second });
			}
		}
	}
	dis[K] = 0;
	for (int i = 1; i <= V; i++) {
		if (dis[i] == 999999)
			cout << "INF" << endl;
		else
			cout << dis[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cin >> V >> E >> K; //노드 수, 간선 수, 시작 노드번호

	for (int i = 0; i < E; i++) {
		int a, b, w;
		cin >> a >> b >> w; //a에서 b로 가는 간선, 가중치

		con[a].push_back({ w,b }); // a
	}

	dijkstra();
}