#include <iostream>

using namespace std;
int main(){
    int year; cin>>year;

    if (year % 400) cout << 1 << endl;
    else if (year % 100) cout << 0 <<endl;
    else if (year % 4 ) cout << 1 <<endl;
    else cout << 0 << endl;

}
