#include <iostream>
#include <cstring>
using namespace std;

char moon[1002];

int main(){
	cin >> moon;

	string str(moon);

	int i;
	for (i = 0 ; i < str.size(); i++){
        bool pal = true;
        for (int j = 0 ; j < ((double)(str.size()-1-i)/2) ; j++){
            char front_ch = moon[i+j];
            char rear_ch = moon[str.size() -1- j];
           // cout << front_ch <<", " << rear_ch <<endl;
            if (front_ch != rear_ch){
              pal = false;
              break;
            }

        }

        if(pal) break;
	}

    cout << i + str.size();
}
