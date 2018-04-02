//success

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


char quadtree[64][64];

string decompress(int x, int y, int n_size){

    char first = quadtree[y][x];
    if (n_size == 1){
        return string(1,first);
    }
    bool same = true;
    for (int i = y; i < y + n_size ; i++){
        for (int j = x; j < x + n_size; j++){
            if (first != quadtree[i][j]){
                same = false;
                break;
            }
        }
    }

    if (same){
        return string(1,first);
    }
    else{
        int half = n_size/2;
        string upper_left = decompress(x,y,half);
        string upper_right = decompress(x+half,y,half);
        string lower_left = decompress(x,y+half,half);
        string lower_right = decompress(x+half,y+half,half);

        return "("+upper_left+upper_right+lower_left+lower_right+")";
    }

}

int main(){
    //ifstream fin("input.inp");
    int n_size ; cin >> n_size;

    for (int i=0;i<n_size;i++){
        cin >> quadtree[i];
    }

    cout << decompress(0,0,n_size)<<endl;


    return 0;
}
