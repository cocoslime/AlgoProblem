
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
#include <functional>
#include <stack>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ii;
typedef vector<int> vi;
typedef vector<ii> vii;


#define INF 1000000000

#include <iostream>
#include <fstream>

ofstream fout("/Users/dong/Documents/dev/workspace/AlgoProblem/lg/res.txt");
ifstream fin("input.txt");
FILE* fp;

#define MAX_N 300000
ull DIV  = 1000000007;
int N ,K;
int k_num;

vector <vi> adjList;
vector <ii> edgeList;
vector<bool> isK;
bool checked[MAX_N];
vi cutList;
bool isCutted(int src, int dest, vi& cutList){
    for (int i = 0 ; i < cutList.size() ; i++){
        int index = cutList[i];
        if (edgeList[index].first == src && edgeList[index].second == dest){
            return true;
        }
        if (edgeList[index].first == dest && edgeList[index].second == src){
            return true;
        }
    }
    return false;
}

int dfs(int src, vi& cutList){
    int kry = 0;
    if (checked[src]) return 0;
    checked[src] = true;
    if (isK[src]) {
        kry++;
    }
    for (int i = 0 ; i < adjList[src].size() ; i++){
        int dest = adjList[src][i];
        if (isCutted(src, dest, cutList)){
            continue;
        }
        if (!checked[dest]){
            kry += dfs(dest, cutList);
        }
    }

    return kry;
}

vector<int> order;
void make_order(int start){
    order.clear();
    memset(checked, false, sizeof(checked));
    
    queue<int> qu;
    qu.push(start);
    
    while(qu.size()){
        int next = qu.front();
        qu.pop();
        checked[next] = true;
        order.push_back(next);
        if (order.size() == N) break;
        for (int i = 0 ; i < adjList[next].size() ; i++){
            int adj = adjList[next][i];
            if (!checked[adj]) {
                qu.push(adj);
            }
        }
    }
}

int findStart(){
    int ii = 0;
    for (int i = 0 ; i < N ; i++){
        if (adjList[i].size() == 1){
            ii = i ;
        }
        else if(adjList[i].size() == 0){
            cout << " Error " << endl;
            exit(1);
        }
    }
    return ii;
}

ll getWay_small(){
//    if (K == k_num || k_num == 0) {
//        return 0 ;
//    }
    if ( k_num % K != 0){
        cout << "not match" << endl;
        return 0;
    }
    int start = findStart();
    make_order(start);
    
    ull way = 0;
    ull curr_way = 0;
    
    int curr_k = 0;
    int i = 0;
    
    int divider = 0;
    while (i < N ){
        if (curr_way != 0) {
            //cout << curr_way << endl;
            divider++;
            if (way != 0){
                ll temp = way;
                way = way * curr_way;
                if (temp > way) cout << "wrong" << endl;
                way = way % (ull)DIV;
            }
            else{
                way = curr_way;
                //cout << "\n" <<curr_way <<" ";
            }
        }
        //find K
        curr_k = 0;
        for (; i < order.size() ; i++){
            int index = order[i];
            if (isK[index]){
                curr_k ++;
            }
            if ( curr_k == K){
                i++;
                break;
            }
        }
        if (curr_k != K){
            cout << "not done" << endl;
            return 0;
        }
        //get Cut Ways
        curr_way = 1;
        for (; i < order.size() ; i++){
            int index = order[i];
            if (!isK[index]){
                curr_way++;
            }
            else{
                break;
            }
        }
    }
    cout << divider << endl;
    
    return way;
}

int main() {
    fp = fopen("/Users/dong/Documents/dev/workspace/AlgoProblem/lg/input.txt", "r");//stdin;
    
    int test_case;
    fscanf(fp, "%d", &test_case);
    int test_num = 0;
    while (test_case--) {
        test_num++;
        fscanf(fp, "%d %d", &N,&K);
        k_num = 0;
        
        adjList.clear();
        adjList.assign(N, vi());
        edgeList.clear();
        isK.clear();
        isK.assign(N, false);
        
        for (int i = 0 ; i < N ; i++){
            int kv; fscanf(fp, "%d", &kv);
            if (kv == 1) isK[i]= true;
            else isK[i] = false;
            if (isK[i])
                k_num++;
        }
        
        
        for (int i = 0 ; i < N - 1 ; i++){
            int u,v;
            fscanf(fp, "%d %d", &u, &v);
            adjList[u- 1].push_back(v-1);
            adjList[v-1].push_back(u-1);
            edgeList.push_back(ii(u-1,v-1));
        }
        
        //vi cutList;
        ll way = getWay_small() ;//% (ll)DIV;//getWay(-1, cutList);
        cout << "\n" << N << ", " << K << " , " << k_num <<" , " << way << endl;
        
        fout << way << endl;
        
        
    }
    
    fout.close();
    return 0;
    
}
