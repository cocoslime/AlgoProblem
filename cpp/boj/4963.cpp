#include <iostream>
#include <cstdio>
using namespace std;

int W;
int H;
int gmap[50][50];
int count;

int eight[8][2] = {
    {-1, -1},{0,-1},{1,-1},
    {-1, 0}, {1,0},
    {-1, 1}, {0, 1}, {1, 1}
};



void coloring(int x, int y){


    if (gmap[x][y] == 1){
     //   cout << x << " " << y << endl;
        gmap[x][y] = 2;
        for (int i = 0 ; i < 8 ; i++){
            int next_x = x + eight[i][0];
            int next_y = y + eight[i][1];
            if (next_x >= 0 && next_x < W && next_y >= 0 && next_y < H){
             //   cout << "color : " << next_x << " " <<y << endl;
                coloring(next_x,next_y);
            }
        }
        return;
    }
    else{
        return;
    }

}

bool island(int x, int y){
    if (gmap[x][y] != 1)
        return false;
    else{
        coloring(x,y);
        return true;
    }

}

int main(){

    while (1){
        scanf("%d %d",&W, &H);
        if (W == 0 && H == 0)
            return 0;

        count = 0;
        for (int i = 0 ; i < H ; i++){
            for (int j = 0 ; j < W ; j++){
                scanf("%d",&gmap[j][i]);
            }
        }


        for (int i = 0 ; i < H ; i++){
            for (int j = 0 ; j < W ; j++){
                if (island(j,i))
                {
                    count++;
                 //   cout << "dd" <<endl;
                }

            }
        }
        printf("%d\n",count);
    }
    return 0;
}
