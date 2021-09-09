//
// Created by Dongmin on 9/10/21.
//

// using floyd warshall

#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#include <functional>
#include <stack>
#include <map>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

const int INF = 2000000;

vector<vector<int>> dist(201, vector<int>(201, INF));

void do_floyd(int n){
    for (int j = 0 ; j < n ; j++){
        dist[j][j] = 0;
    }

    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++){
            for (int k = 0 ; k < n ; k++){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    s -= 1;
    a -= 1;
    b -= 1;

    for (auto& a : fares){
        int src = a[0] - 1;
        int dest = a[1] - 1;
        int fare = a[2];

        dist[src][dest]= fare;
        dist[dest][src]= fare;
    }

    do_floyd(n);

    // no mid
    answer = dist[s][a] + dist[s][b]; //    cout << answer << endl;

    for (int mid = 0 ; mid < n; mid++){
        answer = min(answer, dist[s][mid] + dist[mid][a] + dist[mid][b]);
//        cout << dist[s][mid]  << ", " <<  dist[mid][a]  << ", " <<  dist[mid][b] << endl;
//        cout << mid << ", " << answer << endl;
    }

    return answer;
}

int main(){
    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    int result = solution(6, 4, 6, 2, fares);
    cout << "result : " << result << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    vector<vector<int>> fare_2 = {{2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}};
    result = solution(6, 4, 5, 5, fare_2);
    cout << "result : " << result << endl;
    return 0;
}