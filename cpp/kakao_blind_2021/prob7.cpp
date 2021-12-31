//
// Created by Dongmin on 2021/09/11.
//


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
#include <numeric>

#define INF LLONG_MAX

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

int num;
vector<bool> isLeader;
vector<vi> children;
vector<ll> dp;

ll color(const vector<int>& sales, int leader);
ll no_color(const vector<int>& sales, int leader);

ll no_color(const vector<int>& sales, int leader){
    cout << "visit no_color leader:"<<leader << endl;
    if (!isLeader[leader]){
        return 0;
    }

    ll result = LLONG_MAX;

    // except all no color
    for (int i = 0 ; i < children[leader].size(); i++){
        int child = children[leader][i];
        // no color
        ll noColorValue = no_color(sales, child);

        // color
        ll colorValue = color(sales, child);


    }

    cout << "leader:" << leader << " result:"<<result<< endl;

    return result;
}

ll color(const vector<int>& sales, int leader) {
    cout << "visit color leader:"<<leader << endl;
    if (dp[leader] != -1){
        cout << "." << leader << ":" << dp[leader] << endl;
        return dp[leader];
    }

    if (!isLeader[leader]){
        return sales[leader];
    }

    ll result = 0;

    for (auto& child : children[leader]){
        // no color
        ll noColorValue = no_color(sales, child);

        // color
        ll colorValue = color(sales, child);

        result += min(colorValue, noColorValue);
    }

    dp[leader] = result + sales[leader];
    return dp[leader];
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;

    num = sales.size();
    isLeader.assign(num + 1, false);
    children.assign(num + 1, vi());
    dp.assign(num+1, -1);

    for (auto& link : links){
        int leader = link[0] - 1;
        int child = link[1] - 1;

        isLeader[leader] = true;

        children[leader].push_back(child);
    }

    answer = color(sales, 0);
    cout << "answer, " << answer << endl;
    int nc = no_color(sales, 0);
    answer = min(answer, nc);
    cout << "answer, " << nc << endl;
    return answer;
}

int main(){
    /*
     *
     * sales	links	result
[14, 17, 15, 18, 19, 14, 13, 16, 28, 17]	[[10, 8], [1, 9], [9, 7], [5, 4], [1, 5], [5, 10], [10, 6], [1, 3], [10, 2]]	44
[5, 6, 5, 3, 4]	[[2,3], [1,4], [2,5], [1,2]]	6
[5, 6, 5, 1, 4]	[[2,3], [1,4], [2,5], [1,2]]	5
[10, 10, 1, 1]	[[3,2], [4,3], [1,4]]	2
     */
    int result = solution(
            {14, 17, 15, 18, 19, 14, 13, 16, 28, 17},
            { {10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2} }
            );
    cout << "44 => " << result << endl;
    return 0;
}