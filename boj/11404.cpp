#include <climits>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int N;
int M;

int city[100][100];

void floyd_warshall(){
    for ( int i = 0 ; i < N ; i++){
        for ( int j = 0 ; j < N ; j++){
            for ( int k = 0 ; k < N ; k++){
                if (city[j][k] > city[j][i] + city[i][k]){
                    city[j][k] = city[j][i] + city[i][k];
                }
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
            city[j][k] = 100001;
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
            printf("%d ",city[j][k]);
        }
        printf("\n");
    }

    return 0;
}
