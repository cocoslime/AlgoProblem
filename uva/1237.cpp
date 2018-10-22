//
// Created by dongmin on 18. 10. 22.
//


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#include <functional>
#include <stack>
#include <map>
#include <cassert>
#include <fstream>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

typedef struct Car{
    string name;
    int min;
    int max;
} Car;

int D, Q;
vector<Car> cars;


bool acompare(Car lhs, Car rhs) { return lhs.min < rhs.min; }


int main(){
    ofstream fout("out.txt");
    int test_case; cin >> test_case;

    while (test_case--){
        cars.clear();
        cin >> D;
        for (int i = 0 ; i < D;i++){
            Car car1;
            cin >> car1.name;
            cin >> car1.min;
            cin >> car1.max;
            cars.push_back(car1);
        }

        sort(cars.begin(), cars.end(), acompare);

        cin >> Q;

        for (int i = 0 ; i < Q; i ++){
            int P; cin >> P;
            bool found = false;
            bool dup = false;
            string ans;
            for (int c = 0 ; c < cars.size() ; c++){
                if (P < cars[c].min){
                    break;
                }
                else if (cars[c].min <= P && cars[c].max >= P){
                    if (found){
                        dup = true;
                        break;
                    }
                    else{
                        found = true;
                        ans = cars[c].name;
                    }
                }
            }
            if (!found || dup){
                printf("UNDETERMINED");
                //fout << "UNDETERMINED";
            }
            else{
                printf("%s", ans.c_str());
                //fout << ans;
            }
            printf("\n");
            //fout << endl;
        }

        if (test_case != 0){
            //fout << endl;
            printf("\n");
        }
    }
    return 0;
}