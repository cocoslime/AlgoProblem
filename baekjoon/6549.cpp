#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int histogram[100000];

long long find_rect(int first, int end_){

    if (end_ - first == 0){
        return histogram[first];
    }

    int mid = (first + end_) / 2;

    long long ret = max ( find_rect (first, mid),find_rect(mid+1,end_));

    int mid_first = mid;
    int mid_end = mid+1;
    long long mid_size = 2 * min (histogram[mid] , histogram[mid+1]);
    int max_height = min (histogram[mid] , histogram[mid+1]);
    while ( !(mid_first == first && end_ == mid_end) ){
        if (mid_first == first){
            max_height = min(max_height,histogram[mid_end+1]);
            mid_end++;
        }
        else if (end_ == mid_end){
            max_height = min(max_height,histogram[mid_first-1]);
            mid_first--;
        }
        else if (histogram[mid_first - 1] < histogram[mid_end+1] ){
            max_height = min(max_height,histogram[mid_end+1]);

            mid_end++;

        }else{
            max_height = min(max_height,histogram[mid_first-1]);
            mid_first--;
        }

            //mid_size = max (mid_size, max_height * (mid_end + 1 -mid_first));
            //

        mid_size = max (mid_size, (long long)max_height * (mid_end - mid_first + 1));

        if (mid_first == first && end_ == mid_end) break;

    }

    return max(mid_size , ret);

}


int main(){
    int n_num; scanf("%d",&n_num);
    while (n_num){
        memset(histogram,0,n_num);
        for (int i = 0 ; i < n_num ; i++){
            scanf("%d",&histogram[i]);
        }

        cout << find_rect(0,n_num-1)<<endl;
        scanf("%d",&n_num);

    }
    return 0;
}
