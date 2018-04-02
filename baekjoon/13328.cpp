#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

#define DIV 31991

int input_d;
int input_t;


//ret = a * b
void mult(long long **ret, long long **a, long long **b){
    for (int i = 0 ; i < input_d ; i++){
        for (int j = 0 ; j < input_d; j++){
            ret[i][j] = 0;

            for (int k = 0 ; k < input_d ; k++){

                ret[i][j] += (a[i][k] * b[k][j]) % DIV;
            }
        }
    }
}

int main()
{
    scanf("%d %d",&input_d,&input_t);

    int* base = (int*)malloc(sizeof(int)*input_d);

    base[0] = 1;

    if ( input_t == 1){
        printf("%d",1);
        return 0;
    }
    for (int i = 1 ; i < input_d ; i++){

        if (i == 1)
        {
            base[i] = 1;

        }
        else{
            base[i] = (base[i-1] * 2) % DIV;
        }
        if (i == input_t-1)
        {
            printf("%d",(base[i] * 2) % DIV);
            return 0;
        }


    }


    int time = input_t - input_d + 1;

    long long** mult_mat = new long long*[input_d];
    long long** ret = new long long*[input_d];
    for (int i = 0 ; i < input_d ; i++){
        mult_mat[i] = (long long*)malloc(input_d * sizeof(long long));
        ret[i] = (long long*)malloc(input_d * sizeof(long long));
        for (int j = 0 ; j < input_d ; j++){
            mult_mat[i][j] = 0;
            ret[i][j] = 0;
        }
        ret[i][i] = 1;
    }

    for (int i = 0; i < input_d-1 ; i++){
        mult_mat[i+1][i] = 1;
    }

    for (int i = 0 ; i < input_d ; i ++){
        mult_mat[0][i] = 1;
    }
/*
    for (int i = 0 ; i < input_d ; i++){
        for (int j = 0 ; j < input_d ; j++){
            printf("%lld ",mult_mat[i][j]);
        }
        printf("\n");
    }
*/

    while ( time > 0 )
    {

        if (time % 2 == 1)
        {
            long long** temp2 = new long long*[input_d];
            for (int i = 0 ; i < input_d ; i++)
            {
                temp2[i] = (long long*)malloc(input_d * sizeof(long long));
            }
            mult(temp2, ret, mult_mat);
            ret = temp2;
        }
        if (time == 1) break;
        long long** temp = new long long*[input_d];
        for (int i = 0 ; i < input_d ; i++){
            temp[i] = (long long*)malloc(input_d * sizeof(long long));
        }
        mult(temp, mult_mat, mult_mat);
        mult_mat = temp;
        time /= 2;
    }

    long long int answer = 0;

    for (int i = 0 ; i < input_d ; i++){

        answer += base[i] * ret[0][input_d-1-i];
    }

    printf("%lld",(answer)%DIV );


}
