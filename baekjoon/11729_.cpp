#include <iostream>
#include <cstdlib>

#include <string>
using namespace std;



int move_count = 0;

string move_circle(int one, int two, int target){
    string ret;
    //move_count++;
    if (target == 1){
        printf("%d %d\n",one,two);
        //to_string(one) + " " + to_string(two) + "\n";
        //return;
        return;
    }
    //cout << "dd" << endl;
    move_circle(one,6-one-two,target-1);
    printf("%d %d\n",one,two);
    move_circle(6-one-two,two,target-1);
   // return ret;
   return

}


int main(){
    int n_size;
    //cin >> n_size;
    scanf("%d",&n_size);


    int k = 1;
    for(int i = 0 ; i < n_size ; i++)
    {
        k *= 2;
    }
    printf("%d \n",k - 1);
    //string ret =
    move_circle(1,3,n_size);
    //cout << move_count <<endl;
    //printf("%s \n",ret.c_str());
    return 0 ;
}

