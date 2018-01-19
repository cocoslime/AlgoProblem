//
// Created by dongmin on 18. 1. 17.
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
#include <functional>
#include <stack>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

#define INF 1000000000

FILE* fp;

vector<vi> adjList; //pair : res, dest
vector<vi> programList;
vi p;
int mf, f, s, t, total_people;
int res[38][38];

void result();

void init();

void augment(int v, int min_edge){
    if (v == s){
        f = min_edge;
        return;
    }
    else if (p[v] != -1){
        augment(p[v], min(min_edge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int main(){
    fp = stdout;
    //fp = fopen("res.txt", "w");

    s = 0;
    t = 37;
    init();
    char app;
    while(true){
        if (scanf("%c", &app) == EOF){
            result();
            return 0;
        }
        if (app != '\n'){
            int app_number = app - 'A' + 1;
            //cout << "app_number : " << app_number << endl;
            int people;
            scanf("%d ", &people);
            total_people += people;
            adjList[0].push_back(app_number);
            res[0][app_number] = people;

            char computer;
            do{
                scanf("%c",&computer);
                if (computer == ';') {
                    scanf("%c", &computer);
                    break;
                }
                int computer_number = computer - '0' + 27;
                //cout << "computer : " << computer_number << endl;
                adjList[app_number].push_back(computer_number);
                adjList[computer_number].push_back(app_number);
                programList[computer_number].push_back(app_number);
                res[app_number][computer_number] = INF;
            } while (true);
        }
        else {
            //print
            result();

            //init
            init();

        }
    }
}

void init() {
    programList.clear();
    programList.assign(39, vi());
    adjList.clear();
    adjList.assign(38, vi());
    for (int i = 0 ; i < 38 ; i++){
        for (int j = 0 ; j < 38 ; j++){
            res[i][j] = 0;
        }
    }

    for (int i = 27 ; i < 37 ; i++){
        res[i][37] = 1;
        adjList[i].push_back(37);
    }
    total_people = 0;
}

void result() {
    mf = 0;
    while (true){
        f = 0;
        vector<bool> checked(38, false); checked[s] = true;
        queue<int> q; q.push(s);
        p.assign(38, -1);
        while (!q.empty()){
            int src = q.front();
            q.pop();
            for (int i = 0 ; i < adjList[src].size(); i++){
                int dest = adjList[src][i];
                if (res[src][dest] > 0 && !checked[dest]){
                    q.push(dest);
                    p[dest] = src;
                    checked[dest] = true;
                }
            }
        }

        augment(t, INF);
        // cout << "F : " << f << endl;
        if (f == 0) break;
        mf += f;
    }

    if (mf != total_people) {
        //cout << mf << " ; " << total_people << endl;
        fprintf(fp, "!\n");
    }
    else{
        for (int i = 27 ; i < 37 ; i++){
            char app = '_';
            for (int j = 0 ; j < programList[i].size() ; j++){
                int appnum = programList[i][j];
                if (res[i][appnum] > 0){
                    if (app == '_')
                        app = appnum - 1 + 'A';
                    else
                        exit(-1);
                }
            }
            fprintf(fp, "%c", app);
        }
        fprintf(fp , "\n");
    }
    //cout << mf << endl;
}