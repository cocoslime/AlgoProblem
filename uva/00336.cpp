//
//  00336.cpp
//  algo
//
//  Created by Dong's MacBook Pro on 2017. 11. 23..
//  Copyright © 2017년 Dong's MacBook Pro. All rights reserved.
//


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

int nodes_index = 0;
map<int, int> nodes;

int findValue(int key){
    if (nodes.find(key) != nodes.end()){
        return nodes[key];
    }
    else{
        nodes[key] = nodes_index;
        nodes_index++;
    }
    return nodes[key];
}

int main(){
    int NC;
    int test_case = 1;
    while (true){
        cin >> NC;
        if (NC == 0) break;
        vector<vi> adjList;
        adjList.assign(30, vi());

        nodes.clear();
        nodes_index = 0;
        for (int i = 0 ; i < NC ; i++){
            int src, dest;
            cin >> src >> dest;
            src = findValue(src);
            dest = findValue(dest);
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
        
//        for (int i = 0 ; i < 30 ; i++){
//            cout << i << endl;
//            for (int j = 0 ; j < adjList[i].size() ; j++){
//                cout << adjList[i][j] << ", ";
//            }
//            cout << endl;
//        }
        
        while (true){
            int ori_source, TTL;
            cin >> ori_source >> TTL;
            if (ori_source == 0 && TTL == 0) break;
            int source = findValue(ori_source);
            vi dist(30, INF);
            dist[source] = 0;
            int num = 0;
            queue<int> qu;
            qu.push(source);
            while (!qu.empty()){
                num++;
                int curr = qu.front(); qu.pop();
                if (dist[curr] >= TTL) continue;
                for (int i = 0 ; i < adjList[curr].size() ; i++){
                    int next = adjList[curr][i];
                    if (dist[next] == INF){
                        dist[next] = dist[curr]+1;
                        qu.push(next);
                    }
                }
            }
            //cout << nodes_index << ", " << num << endl;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",test_case++, nodes_index - num, ori_source, TTL);
            
        }
    }
    return 0;
}
