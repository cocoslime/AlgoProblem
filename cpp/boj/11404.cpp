#include <iostream>
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
#include <cassert>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

#define INF 10000000

int N;
int M;

int city[101][101];

void floyd_warshall(){
    for ( int i = 0 ; i < N ; i++){
        for ( int j = 0 ; j < N ; j++){
            for ( int k = 0 ; k < N ; k++){
                city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
            }
        }
    }
}

int main(){
    scanf("%d",&N);
    scanf("%d",&M);

    for ( int j = 0 ; j < N ; j++)
    {
        for ( int k = 0 ; k < N ; k++)
        {
            city[j][k] = INF;
        }
    }

    for (int i = 0 ; i < N ; i++){
        city[i][i] = 0;
    }

    for (int i = 0 ; i< M ; i++){
        int a;
        int b;
        int c;
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);

        if (city[a-1][b-1] > c)
            city[a-1][b-1] = c;

    }

    floyd_warshall();

    for ( int j = 0 ; j < N ; j++)
    {
        for ( int k = 0 ; k < N ; k++)
        {
            if (city[j][k] > 100000)
                printf("%d ", 0);
            else
                printf("%d ",city[j][k]);
        }
        printf("\n");
    }

    return 0;
}
