#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int N_num, W_num, L_num;

int N[1001];
int W[102]; // 0 : 들어오기 직전 트럭. . 1 ~ W_num . W_num+1 : 나온 트럭들

int move_one(){
    int out = W[W_num];
    W[W_num+1] += out;
    for (int i = W_num; i > 0 ; i--){
        W[i] = W[i-1];
    }
    W[0] = 0;
    return out;
}

int get_first_loc(){
    for (int i = W_num ; i > 0 ; i--){
        if (W[i] != 0)
            return i;
    }
}

void move_truck(int moving){
    W[W_num+1] += W[W_num+1 - moving];
    for (int i = W_num; i > moving ; i--){
        W[i] = W[i-moving];
    }
    for (int i = moving ; i > 0 ; i--){
        W[i] = 0;
    }
}

int main()
{
    scanf("%d %d %d",&N_num,&W_num,&L_num);



    for (int i = 0 ; i < N_num ; i++){
        scanf("%d",&N[i]);
    }

    W[0] = N[0];
    int n_index = 1;
    int time = 0;
    int weight = 0;
    bool start = true;
    while (n_index < N_num || weight > 0 || start){
        start = false;
        if ( weight + W[0] - W[W_num] <= L_num){//들어감
            weight = weight + W[0] - W[W_num];
            move_one();
            time++;
            if (n_index < N_num ){
                W[0] = N[n_index];
                n_index++;
            }
        }
        else { //못들어감
            int first = get_first_loc();
            weight -= W[first];
            int moving = (W_num+1) - first;

            move_truck(moving);
            if (weight + W[0] <= L_num){
                weight += W[0];
                W[1] = W[0];
                W[0] = 0;
                if (n_index < N_num ){
                    W[0] = N[n_index];
                    n_index++;
                }
            }

            time += moving;
          //  cout << "not come";
        }

       // cout << endl;
       // cout <<time <<endl;
    }

    cout << time <<endl;
}
