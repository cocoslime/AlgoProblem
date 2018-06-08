#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;



int main()
{
    int num;
    cin >> num;

    int *edge;
    int edge_num = (int)pow(2,num+1) - 2;
    edge = new int[edge_num+1];

    int max_sum = 0;
    long long sum = 0;
    for (int i = 0 ; i < num ; i++){
        int max_sum_this = max_sum;
        bool flag = false;
        if (i == num - 1)
        {
            flag = true;

        }
        for (int j = 0 ; j < (int)pow(2,i) ; j++){
            int left, right;

            scanf("%d %d",&left,&right);

            int level = (int)pow(2,i + 1);

            if (!flag){
                edge[level-2 + j * 2] = left;
                edge[level-2 + j * 2 + 1] = right;

                sum += left;
                sum += right;
            }
            else{
                int max_value = max(left, right);
                edge[level-2 + j * 2] = max_value;
                edge[level-2 + j * 2 + 1] = max_value;
                sum += 2*max_value;
            }




        }


    }

    num--;


    while (num>0){
        int level = (int)pow(2, num) - 2;
        int edge_num = (int)pow(2, num-1);

       // cout << sum << endl;
        for (int i = 0 ; i < edge_num  ; i++){
            int left = edge[level + i * 2];
            int right = edge[level + i * 2 +1];

            int left_child = edge[2 * (level + i * 2) + 2];
            int right_child = edge[2 * (level + i * 2 +1) + 2];

            if (left_child + left > right_child + right){
                sum += -(right_child + right) + (left_child + left);
                edge[level + i * 2] = left_child + left;

            }else{
                sum += right_child + right - (left_child + left);
                edge[level + i * 2] = right_child + right;
            }


        }
        num--;
    }

    cout << sum << endl;


}
