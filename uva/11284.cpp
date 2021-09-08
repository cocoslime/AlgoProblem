//
// Created by Dongmin on 7/15/21.
//


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
#include <iostream>
#include <fstream>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

#define INF 1000000000

int gas_arr[51][51];
int price_arr[51];
int n, m, p;
int dp_arr[51][]

int dp_func(int src, unsigned int path)
{
    int min_value = INF;
    for (int i = 1; i < n ; i++)
    {
        if (!(1 << i & path))
            min_value = min(min_value, gas_arr[src][i] + price_arr[i] + dp_func(i, path | 1 << i));
    }


}

int main()
{
    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        cin >> n >> m;
        getchar();

        for (int i = 0 ; i < 51 ; i++)
            memset(gas_arr[i], 0, 51 * sizeof(int));
        memset(price_arr,0, 51 * sizeof(int));

        for (int i = 0 ; i < m ; i++) {
            int src, dest;
            double gas;
            cin >> src >> dest;
            cin >> gas;

            gas_arr[src][dest] = (int) (gas * 100);
            gas_arr[dest][src] = (int) (gas * 100);
        }

        cin >> p;

        for (int i = 0 ; i < p ; i++) {
            int store;
            double price;
            cin >> store;
            cin >> price;

            price_arr[store] = -(int) (price * 100);
        }

        getchar();
    }
    return 0;
}