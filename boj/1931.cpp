
#include <iostream>
#include <cstring>
using namespace std;


int meeting[100001][2];
int n_size;

int cache[100001];

int find_max(int index){
    if (n_size <= index) return 0;

    //int &ret = cache[index];
    if (cache[index] != -1 ) return cache[index];
    if (meeting[index][0] == meeting[index][1]){
        int next =index+1;
        int ret = 1 + find_max(next);
        cache[index] = ret;
        return ret;
    }

    int ret = 0;
    int i = index;
    int temp =meeting[index][0];
    while (1){
        i++;
        if ( meeting[i][0] >= meeting[index][1])break;
        if (temp != meeting[i][0]){
            ret = max(ret,find_max(i));
            temp = meeting[i][0];
        }

    }
    ret = max(ret, 1 + find_max(i));
    cache[index] = ret;
    return ret;
}

int compare(const void* pa, const void* pb){
    int* a = (int*)pa;
    int* b = (int*)pb;
    return a[1] - b[1];

}

int main(){

    cin >> n_size;

    memset(cache, -1, sizeof(cache));
    for (int i = 0 ; i < n_size ; i ++){

        scanf("%d %d",&meeting[i][0], &meeting[i][1]);
        //cin >> meeting[i][0] >> meeting[i][1] ;

    }

    qsort(meeting,n_size,sizeof(meeting[0]),compare);

    int index = 1;
    int end = meeting[0][1];
    int num = 1;
    while (index < n_size){
        if (meeting[index][0] >= end){
            num++;
            end = meeting[index][1];
        }
        index++;

    }
    cout <<num<<endl;
    //cout<< find_max(0);

    return 0;
}
