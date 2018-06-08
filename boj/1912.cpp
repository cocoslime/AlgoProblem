
#include <climits>
#include <iostream>
#include <cstring>
using namespace std;

int p_sum[100000];
int arr[100000];

int main(){
    int num; cin >> num;

    int min_value = 0;
    int value;
    scanf("%d",&value);
    arr[0] = value;
    p_sum[0] = value;
    int max_value = value;
    int max_minus = max(INT_MIN, value);
    for (int i = 1 ; i < num ; i++){
        int value;
        scanf("%d",&value);
        arr[i] = value;
        p_sum[i] = value + p_sum[i-1];

        min_value = min(min_value, p_sum[i]);
        max_value = max(max_value, p_sum[i] - min_value);
        max_minus = max(max_minus, arr[i]);
    }
    if (max_value == 0)
        cout << max_minus << endl;
    else{
        cout << max_value;
    }
   // cout << find_sum(0, num-1);


    return 0;
}
