#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;


int book[501];
int cache[501][501];
int sum_arr[501][501];

int sum(int, int);

int compress(int front, int back){

    if (cache[front][back] != -1) return cache[front][back];

    if (front== back) return 0;

    int min_value = INT_MAX;



    for (int i = front ; i < back ; i++){
        min_value = min(min_value,sum(front,back)+ compress(front, i) + compress(i+1, back));

    }

    cache[front][back] = min_value;
    return min_value;
}


int sum( int front , int back){
    int &ret = sum_arr[front][back];
    if (ret != -1) return ret;

    if (front== back) return book[front];

    int value = 0;
    for (int i = front ; i <= back ; i++){
        value += book[i];

    }

    ret = value;
    return ret;
}


int main(){
    int test_case;
    cin >> test_case;

    while(test_case--){
        for (int i = 0 ; i < 501 ; i++){
            memset(cache[i],-1,sizeof(cache[i]));
            memset(sum_arr[i],-1,sizeof(sum_arr[i]));
        }

        int pages; cin >> pages;

        for (int i = 0 ; i < pages ; i++){
            scanf("%d",&book[i]);
        }


       // cout << sum(0, pages - 1)<<endl;
        cout << compress(0, pages-1 ) << endl;
    }
    return 0;
}
