#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#include <stack>
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

int N;

vector<vector<ii>> adjList; // <cost, dest>
priority_queue<ii> pq;
vector<bool> checked;

void process(int vtx){
    checked[vtx] = true;
    
    for (int i = 0 ; i < adjList[vtx].size() ; i++){
        int v = adjList[vtx][i].second;
        if (!checked[v]) pq.push(ii(-adjList[vtx][i].first,v));
    }
    
}

void prim(){
    int test_case; test_case = 0;
    while (cin >> N){
        adjList.clear();
        adjList.assign(N, vector<ii>());
        if (test_case != 0) fprintf(stdout, "\n");
        ll origin = 0;
        for (int i = 0 ; i < N - 1; i++){
            int src, dest;
            int cost;
            cin >> src >> dest >> cost;
            origin += cost;
        }
        
        int K; cin >> K;
        for (int i = 0 ; i < K ; i++){
            int src, dest;
            int cost;
            cin >> src >> dest >> cost;
            adjList[src - 1].push_back(make_pair(cost, dest - 1));
            adjList[dest - 1].push_back(make_pair(cost, src - 1));
        }
        
        int M; cin >> M;
        for (int i= 0 ; i < M ; i++){
            int src, dest;
            int cost;
            cin >> src >> dest >> cost;
            adjList[src - 1].push_back(make_pair(cost, dest - 1));
            adjList[dest - 1].push_back(make_pair(cost, src - 1));
        }
        
        checked.assign(N, false);
        process(0);
        ll ret = 0;
        
        while(pq.size() != 0){
            ii n_pair = pq.top();
            pq.pop();
			if (checked[n_pair.second]) continue;
            ret += (-n_pair.first);
            process(n_pair.second);
        }
        fprintf(stdout,"%lld\n%lld\n",origin,ret);
		test_case++;
    }

    
}

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


vector<pair<int, ii> > edgeList;

void kruskal() {
	int test_case; test_case = 0;
	while (cin >> N) {
		edgeList.clear();
		if (test_case != 0) fprintf(stdout, "\n");
		ll origin = 0;
		for (int i = 0; i < N - 1; i++) {
			int src, dest;
			int cost;
			cin >> src >> dest >> cost;
			origin += cost;
		}

		int K; cin >> K;
		for (int i = 0; i < K; i++) {
			int src, dest;
			int cost;
			cin >> src >> dest >> cost;
			edgeList.push_back(make_pair(cost, ii(src-1, dest-1)));
		}

		int M; cin >> M;
		for (int i = 0; i < M; i++) {
			int src, dest;
			int cost;
			cin >> src >> dest >> cost;
			edgeList.push_back(make_pair(cost, ii(src-1, dest-1)));
		}

		UnionFind* uf = new UnionFind(N);
		sort(edgeList.begin(), edgeList.end());
		
		ll ret = 0;
		for (int i = 0; i < edgeList.size(); i++) {
			int comp1 = edgeList[i].second.first;
			int comp2 = edgeList[i].second.second;
			int cost = edgeList[i].first;
			if (!uf->isSameSet(comp1, comp2)) {
				uf->unionSet(comp1, comp2);
				ret += cost;
			}
			if (uf->numDisjointSets() == 1) {
				break;
			}
		}
		fprintf(stdout, "%lld\n%lld\n", origin, ret);
		test_case++;
	}

}

int main(){
    kruskal();
    //prim();
    return 0;
}
