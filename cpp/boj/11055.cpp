#include <climits>
#include <iostream>
#include <cstring>
using namespace std;

int cache[1000];
int p_sum[1000];
int arr[1000];

int num;

int find_sum(int p_start){

    int &max_v = cache[p_start+1];


    if ( max_v != -1 ) return max_v;
    if ( p_start == num-1) return arr[p_start];
    if ( p_start != -1) max_v = arr[p_start];
    else max_v = 0;
    for (int i = p_start + 1 ; i <num; i++){

        if (p_start == -1) max_v = max(max_v, find_sum(i));
        else if (arr[p_start] < arr[i]) max_v = max(max_v, find_sum(i) + arr[p_start]);
    }

    return max_v;


}


int main(){
    cin >> num;

    memset(cache, -1, sizeof(cache));
    for (int i = 0 ; i < num ; i ++){

        scanf("%d",&arr[i]);
        if (i!=0){
            p_sum[i] = p_sum[i-1] + arr[i];
        }
        else{
            p_sum[i] = arr[i];
        }
    }


    cout << find_sum(-1)<<endl;

    return 0;
}
