
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N;
vector< pair <int , ii> > edgeList;

class UnionSet{
public:
    vector<int> p, rank;
    
    UnionSet(){}
    UnionSet(int _num){
        p.assign(_num, -1);
        for (int i = 0 ; i < _num ;i++){
            p[i] = i;
        }
        rank.assign(_num, 0);
    }
    int findSet(int i){
        return p[i] == i ? i : (p[i] = findSet(p[i]));
    }
    
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    
    void unionSet(int i, int j){
        int x = findSet(i);
        int y = findSet(j);
        
        if (rank[x] > rank[y]){
            p[y] = x;
        }
        else{
            p[x] = y;
            if (rank[x] == rank[y]){
                rank[y] += 1;
            }
        }
        
    }
};
int main(){
    int test_case; cin >> test_case;
    int caseCount = 1;
    while (test_case--){
        cin >> N;
    for (int i = 0 ; i < N ; i++){
        for (int j=0; j < N ; j++){
            int secu;
            if (j == N-1){
                scanf("%d",&secu);
            }
            else{
                scanf("%d,",&secu);
            }
            //cout << i << ", " << j << endl;
            if (j <= i) continue;
            if (secu != 0){
                edgeList.push_back(make_pair(secu, make_pair(i,j)));
            }
        }
    }
    sort(edgeList.begin(), edgeList.end());
    
    UnionSet* us;
    us = new UnionSet(N);
    
    vector<pair<int, ii>> resultList;
    for (int i = 0 ; i < edgeList.size() ; i++){
        int node1 = edgeList[i].second.first;
        int node2 = edgeList[i].second.second;
        if (!us->isSameSet(node1, node2)){
            us->unionSet(node1, node2);
            resultList.push_back(make_pair(edgeList[i].first, make_pair(node1, node2)));
        }
        if (resultList.size() == N - 1) break;
    }
    
        printf("Case %d:\n",caseCount);
        for (int i = 0 ; i < N - 1 ; i++){
            printf("%c-%c %d\n",resultList[i].second.first + 'A', resultList[i].second.second +'A', resultList[i].first);
        }
        caseCount++;
        edgeList.clear();
        
    }
    
    return 0;
}
