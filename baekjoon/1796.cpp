//success
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string lcd_str;
int cache[26][3];
//int cache[26][2];
int dp_count[26][2];


int find_count(int p_alpha, int pre_lot){
    int value = 0;

    if (p_alpha > 25) return 0;

    if (cache[p_alpha][0] == -1){
        return find_count(p_alpha+1,pre_lot);
    }



    if (cache[p_alpha][0] >= pre_lot){
        value += cache[p_alpha][1] - pre_lot;
        return value + find_count(p_alpha+1,cache[p_alpha][1]);
    }

    else if (cache[p_alpha][1] <= pre_lot){
        value += pre_lot - cache[p_alpha][0];
        return value + find_count(p_alpha+1,cache[p_alpha][0]);
    }
    else{
        int left_right_value = cache[p_alpha][1] - pre_lot + (pre_lot - cache[p_alpha][0]) * 2
            + find_count(p_alpha+1,cache[p_alpha][1]);
        int right_left_value = (cache[p_alpha][1] - pre_lot) * 2 + (pre_lot - cache[p_alpha][0])
            + find_count(p_alpha+1,cache[p_alpha][0]);

        if (left_right_value > right_left_value) return right_left_value;
        else return left_right_value;
    }
}


int find_count_dp(int p_alpha, int left, int right){

    if (p_alpha > 25){
        return min(dp_count[p_alpha-1][0],dp_count[p_alpha-1][1]);
    }


    if (cache[p_alpha][2] == 0){
        dp_count[p_alpha][0] = dp_count[p_alpha-1][0];
        dp_count[p_alpha][1] = dp_count[p_alpha-1][1];
        return find_count_dp(p_alpha+1,left,right);
    }
    else{
        int length = (cache[p_alpha][1] - cache[p_alpha][0]);
        dp_count[p_alpha][0] = min(dp_count[p_alpha-1][0] + abs(cache[p_alpha][1] - left) + length ,
                                dp_count[p_alpha-1][1] + abs(cache[p_alpha][1] - right) + length);//left

        dp_count[p_alpha][1] = min(dp_count[p_alpha-1][0] + length + abs(left - cache[p_alpha][0]),
                               dp_count[p_alpha-1][1] + length + abs(right - cache[p_alpha][0]) );

        return find_count_dp(p_alpha+1,cache[p_alpha][0],cache[p_alpha][1]);

    }

}

int main()
{
    //memset(lcd_array,'\0',sizeof(lcd_array));

    for (int i = 0 ; i < 26 ; i++){
        //memset(cache[i],-1,sizeof(cache[i]));
        memset(cache[i],0,sizeof(cache[i]));
    }
    cin >> lcd_str;
  //  cout << lcd_str.size();

    for (int i = 0 ; i < lcd_str.size(); i++){
        int temp = lcd_str[i]-'a';

        if (cache[temp][2] == 0){
            cache[temp][0] = i;
            cache[temp][1] = i;
         //   cout <<"---"<<endl;
        }
        else
            cache[temp][1] = i;
        cache[temp][2] += 1;
    }
    dp_count[0][0] = cache[0][1] * 2 - cache[0][0];
    dp_count[0][1] = cache[0][1];

    cout << find_count_dp(1, cache[0][0], cache[0][1]) + lcd_str.size()<< endl;
    //cout << find_count(0,0) + lcd_str.size() << endl;
    return 0;
}



