//
// Created by Dongmin on 8/9/21.
//
#include <iostream>

using namespace std;

unsigned long long i_arr[1024];
unsigned long long k;

void func(int pos, unsigned long long k_temp)
{
    // cout << "\n"<< pos << "," << k_temp << endl;
    if (pos == 2)
    {
        if (k_temp == 0)
            cout << "00";
        else if (k_temp == 1)
            cout << "01";
        else
            cout << "10";
        return;
    }
    else if(pos == 1)
    {
        if (k_temp == 0)
            cout << "0";
        else
            cout << "1";
        return;
    }


    if (i_arr[pos-1] + 1 <= k_temp) {
        k_temp -= i_arr[pos - 1] + 1;
        cout << "10";
        func(pos - 2, k_temp);
    }
    else
    {
        cout << "0";
        func(pos-1, k_temp);
    }

}

int main(){
    while (1) {
        cin >> k;

        switch (k) {
            case 1:
                cout << "1";
                return 0;
            case 2:
                cout << "10";
                return 0;
            case 3:
                cout << "100";
                return 0;
        }
        unsigned long long a, b;

        int i = 0;
        a = 1;
        b = 1;
        i_arr[1] = 1;
        i_arr[2] = 2;
        unsigned long long cur = 2;

        for (i = 3;; i++) {
            if (i % 2 == 1) {
                a = a + 1 + (b - 1);
                cur += a;
                // printf("%d, %d\n", i, a);
            } else {
                b = b + 1 + (a - 1);
                cur += b;
                // printf("%d, %d\n", i, b);
            }
            i_arr[i] = cur;

            if (cur >= k)
                break;
        }

        func(i, k);

        break;
    }
    return 0;
}