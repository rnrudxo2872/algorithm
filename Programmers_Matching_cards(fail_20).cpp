#include <bits/stdc++.h>
#include <unordered_map>
#define INF 99999999

using namespace std;

struct Point {
	int row;
	int col;
	int cnt;
};

vector<vector<int>> Board;
unordered_map<int, int> MemList;
vector<int> SortMem;
int TotalCard;
int answer = INF;
bool Tvisit[8] = { 0, };

//row col  == > ��, ��, ��, ��
int DelPoint[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

struct cmp {
	bool operator()(Point a, Point b) {
		//��������
		return a.cnt > b.cnt;
	}
};

void CntMem() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			//ī�带 ã�� ��, ����Ƽ�� �߰�
			if (Board[i][j] != 0)
				MemList[Board[i][j]] += 1;
		}
	}
	TotalCard = MemList.size();
}

Point SearchPair(Point target, Point Cur, bool CurVisit[8]) {
	queue<Point> Q;
	Q.push({ Cur.row,Cur.col,0 });

	bool ThisMap[4][4] = { 0, };
	ThisMap[Cur.row][Cur.col] = true;

	while (!Q.empty()) {
		Point Cur = Q.front();
		Q.pop();
		// ���ϴ� target ��ǥ�� ���ٸ�,
		if (Cur.row == target.row && Cur.col == target.col) {
			//enter
			Cur.cnt += 1;
			return Cur;
		}

		for (int i = 0; i < 4; i++) {
			//ctrl + ����Ű
			int TR = Cur.row;
			int TC = Cur.col;

			//�ٸ� ī�带 ��������
			bool Mid = false;

			//ctrl ����Ű
			while (1) {
				TR += DelPoint[i][0];
				TC += DelPoint[i][1];
				
				if (!(-1 < TR && TR < 4 && -1 < TC && TC < 4))
					break;

				//0�� �ƴϰ�, �����ī�尡 �ƴϸ�, �湮�� ���� �ƴ϶��
				if (Board[TR][TC] && !CurVisit[Board[TR][TC]] && !ThisMap[TR][TC]) {
					
					ThisMap[TR][TC] = true;
					// �� ī�忡 ��ǥ�� �ű��
					Q.push({ TR,TC,Cur.cnt + 1 });
					
					//�ٸ� ī�带 ������.
					Mid = true;
					break;
				}
			}
			//���� �ε����ٸ�,
			if (!Mid)
				Q.push({ TR,TC,Cur.cnt + 1 });

			//��ĭ�� ������ ��,
			int NR = Cur.row + DelPoint[i][0];
			int NC = Cur.col + DelPoint[i][1];

			//�湮�߾��ٸ�
			if (ThisMap[NR][NC])
				continue;
			if (-1 < NR && NR < 4 && -1 < NC && NC < 4) {
				ThisMap[NR][NC] = true;
				Q.push({ NR,NC,Cur.cnt + 1 });
			}

		}
	}
}

//��ǥ 2�� ������, ���ΰ� �ּ� ī��Ʈ ã�Ƽ� ����
Point FindTwo(int target, Point Cur, bool CurVisit[8]) {
	vector<Point> Pair;
	int cnt = INF;
	Point ret;

	for (int i = 0; i < 4 && Pair.size() < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (target == Board[i][j]) {

				Pair.push_back({ i,j,0 });
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		Point one = SearchPair(Pair[i], Cur, CurVisit);
		Point two = SearchPair(Pair[(i + 1) % 2], one, CurVisit);
		if (cnt > one.cnt + two.cnt) {
			cnt = one.cnt + two.cnt;
			ret = { two.row,two.col,cnt };
		}
	}
	
	return ret;
}

Point Method(Point Cur) {
	bool TemVisit[8] = { 0, };

	//������� ã�´�
	for (int i = 0; i < SortMem.size(); i++) {

		int target = SortMem[i];
		
		Point tem;
		tem = FindTwo(target, Cur, TemVisit);
		Cur = { tem.row, tem.col, Cur.cnt + tem.cnt };

		TemVisit[target] = true;
	}
	return Cur;
}

void dfs(Point CurPoint, int Mem) {
	if (Mem == TotalCard) {

		CurPoint = Method(CurPoint);

		if (answer > CurPoint.cnt)
			answer = CurPoint.cnt;

		return;
	}

	for (int i = 1; i < TotalCard + 1; i++) {
		if (Tvisit[i])
			continue;

		Tvisit[i] = true;
		SortMem.push_back(i);
		dfs(CurPoint, Mem + 1);
		SortMem.pop_back();
		Tvisit[i] = false;
	}
}

int solution(vector<vector<int>> board, int r, int c) {

	Board = board;

	CntMem();

	Point couser;

	//���� Ŀ����ġ
	couser.row = r;
	couser.col = c;
	couser.cnt = 0;

	dfs(couser, 0);

	return answer - 1;
}

int main() {
	cout << solution({ {1,0,0,3} ,{2,0,0,0},{0,0,0,2},{3,0,1,0} }, 1, 0) << endl;
}