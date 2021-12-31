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

int n, m, p;

vii road_list[51];
int price_arr[51];
int d[51][51];

int dvd_adj_arr[13][13];
int dvd_id_list[13];
int dp_arr[13][8192];

int dp_func(int src, unsigned int path)
{
    if (dp_arr[src][path] != INF)
        return dp_arr[src][path];

    int min_value = dvd_adj_arr[src][0];// go home
    for (int i = 1; i < n ; i++)
    {
        if (!(path & 1 << i))
            min_value = min(min_value, dvd_adj_arr[src][i] - price_arr[dvd_id_list[src]] + dp_func(i, path | 1 << i));
    }

    dp_arr[src][path] = min_value;
    return min_value;
}

void dijkstra(int start)
{
    d[start][start] = 0;
    priority_queue<ii> pq;

    pq.emplace(start, 0);

    while (!pq.empty())
    {
        int curr = pq.top().first;
        int dist = -pq.top().second;
        pq.pop();

        if (d[start][curr] < dist)
            continue;

        for (int i = 0 ; i < road_list[curr].size() ; i++)
        {
            int next = road_list[curr][i].first;
            int gas = road_list[curr][i].second;

            if (d[start][next] > dist + gas)
            {
                pq.emplace(next, -(dist + gas));
                d[start][next] = dist + gas;
            }
        }
    }
}

int main()
{
    ofstream fout("out.txt");
    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        cin >> n >> m;
        getchar();

        n += 1;

        for (int i = 0 ; i < 51 ; i++)
            road_list[i].clear();
        memset(price_arr,0, 51 * sizeof(int));

        for (int i = 0 ; i < m ; i++) {
            int src, dest;
            double gas;
            cin >> src >> dest;
            cin >> gas;

            int gas_100 = (int) (gas * 100);
            road_list[src].emplace_back(dest, gas_100);
            road_list[dest].emplace_back(src, gas_100);
        }

        cin >> p;

        for (int i = 0 ; i < p ; i++) {
            int store;
            double price;
            cin >> store;
            cin >> price;

            price_arr[store] = (int)(price * 100);
        }

        getchar();

        for (int j = 0 ; j < 51 ; j++)
            d[0][j] = INF;
        dijkstra(0);
        for (int i = 1 ; i < n; i++)
        {
            for (int j = 0 ; j < 51 ; j++)
                d[i][j] = INF;
            if (price_arr[i] > 0)
                dijkstra(i);
        }

        int dvd_id = 0;
        dvd_id_list[0] = 0;
        for (int i = 1 ; i < n; i++)
        {
            if (price_arr[i] > 0)
            {
                dvd_id_list[dvd_id] = i;
                dvd_id++;
            }
        }

        for (int i = 0 ; i < p ; i++)
        {
            int dvd_i = dvd_id_list[i];
            for (int j = i + 1 ; j <= p ; j++)
            {
                int dvd_j = dvd_id_list[j];
                dvd_adj_arr[i][j] = d[dvd_i][dvd_j];
                dvd_adj_arr[j][i] = d[dvd_i][dvd_j];
            }
        }

        for (int i = 0 ; i < 13 ; i++)
        {
            for (int j = 0 ; j < 8192 ; j++)
            {
                dp_arr[i][j] = INF;
            }
        }
        int result = dp_func(0, 1);
        printf("result : %d\n", result);
    }
    return 0;
}