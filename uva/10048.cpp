#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

#define INF 1000000000

#include <iostream>
#include <fstream>

ofstream fout("res.txt");
FILE* fp;

class UnionFind {                                              // OOP style
private:
	vi p, rank, setSize;                       // remember: vi is vector<int>
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
			else {
				p[x] = y; setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};


vector<pair<int, ii>> edgeList;
vector<vii> adjList;
bool checked[101];
int C, S, Q;

int find(int pre, int dest) {
	if (checked[pre]) return -1000000;
	checked[pre] = true;
	
	
	for (auto i : adjList[pre]) {
		int dist = i.first;
		int temp = i.second;
		if (dest == temp) return dist;
		else {
			int max_dist = find(temp, dest);
			if (max_dist > 0) {
				return max(dist, max_dist);
			}
			
		}
	}

	return -100000000;
}

int main() {
	fp = fopen("res.txt", "w");
	
	int test_case = 1;
	while (cin >> C >> S >> Q) {
		adjList.clear();
		edgeList.clear();
		if (C == 0 && S == 0 && Q == 0) {
			break;
		}

		if (test_case != 1) printf("\n");
		printf("Case #%d\n", test_case);
		test_case++;

		for (int i = 0; i < S; i++) {
			int c1, c2, d;
			cin >> c1 >> c2 >> d;
			edgeList.push_back(make_pair(d, make_pair(c1 - 1, c2 - 1)));
			//edgeList.push_back(make_pair(d, make_pair(c2, c1)));
		}

		sort(edgeList.begin(), edgeList.end());
		adjList.assign(C, vii());
		UnionFind uf(C);
		for (int i = 0; i < S; i++) {
			int dist = edgeList[i].first;
			int c1 = edgeList[i].second.first;
			int c2 = edgeList[i].second.second;
			if (!uf.isSameSet(c1, c2)) {
				uf.unionSet(c1, c2);
				adjList[c1].push_back(make_pair(dist, c2));
				adjList[c2].push_back(make_pair(dist, c1));
			}
		}


		for (int i = 0; i < Q; i++) {
			memset(checked, false, sizeof(checked));
			int s, e;
			cin >> s >> e;
			int ret = find(s - 1, e - 1);
			if (ret < 0) printf("no path\n");
			else printf("%d\n", ret);
		}
	}
	return 0;
}