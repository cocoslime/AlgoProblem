#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int node_parent[51];
int child[51];

void remove_node(int node){
    child[node] = -1;
    child[node_parent[node]]--;

    for (int i = 0 ; i < N ; i++){
        if (node_parent[i] == node){
            remove_node(i);
        }
    }
}

int main(){
    scanf("%d", &N);
    for (int i = 0 ; i < N ; i++){
        scanf("%d",&node_parent[i]);
        if (node_parent[i] != -1){
            child[node_parent[i]]++;
        }
    }

    int del;
    scanf("%d",&del);

    remove_node(del);

    int leaf = 0;
    for (int i = 0 ; i < N ; i++){
        if (child[i] == 0){
             //   cout << i << endl;
            leaf++;
        }
    }
    printf("%d\n",leaf);
    return 0;
}
