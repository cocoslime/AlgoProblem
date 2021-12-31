
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

int x_size, y_size;
int x_start, y_start;
int num_of_beep;
vii beep_coord;

int dp[20][2048];

int calc_dist(int src, int dest)
{
    return abs(beep_coord[src].first - beep_coord[dest].first) + abs(beep_coord[src].second - beep_coord[dest].second);
}

int tsp(int cur_pos, unsigned int bm_path)
{
    
    if (bm_path == (int)pow(2, num_of_beep + 1) - 1) {
        return calc_dist(cur_pos, 0); // last
    }
    if (dp[cur_pos][bm_path] != INF) return dp[cur_pos][bm_path];

    int min_value = INF;
    for (int i = 1 ; i <= num_of_beep; i++)
    {
        if (!(bm_path & 1 << i))
        {
            min_value = min(min_value, calc_dist(cur_pos, i) + tsp(i, bm_path | 1 << i));
        }
    }

    dp[cur_pos][bm_path] = min_value;
    return min_value;
}

int main()
{
    FILE* fout;
    // fout = fopen("output.txt", "w");

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        cin >> x_size >> y_size;
        cin >> x_start >> y_start;
        beep_coord.push_back(make_pair(x_start, y_start));
        cin >> num_of_beep;

        for (int i = 0; i < num_of_beep; i++)
        {
            int x, y;
            cin >> x >> y;
            beep_coord.push_back(make_pair(x, y));
        }

        for (int i = 0; i <= 10; i++)
        {
            for (int j = 0; j <= (int)pow(2, num_of_beep + 1) - 1; j++)
            {
                dp[i][j] = INF;
            }
        }
        int ret = tsp(0, 1);

        fprintf(stdout, "The shortest path has length %d\n", ret);

        beep_coord.clear();
    }
    // fclose(fout);

    return 0;
}