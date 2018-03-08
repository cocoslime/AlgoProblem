//
// Created by Dong's MacBook Pro on 2018. 3. 8..
//
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <istream>
#include <iostream>

using namespace std;

int numbers[100001];
char command[100001];

int main(){
    int test_case;
    scanf("%d\n", &test_case);
    while (test_case--){
        int sizeOfCommand = 0;
        for (int i = 0; ; i++){
            char c; scanf("%c", &c);
            if (c == '\n') {
                sizeOfCommand = i;
                break;
            }
            command[i] = c;
        }

        int sizeOfArray; scanf("%d\n",&sizeOfArray);

        char c; scanf("%c", &c);
        if (c != '[') {
            return -1;
        }
        for (int i = 0 ; i < sizeOfArray ; i++){
            int num; scanf("%d", &num);
            numbers[i] = num;
            if (i != sizeOfArray - 1) {
                scanf("%c", &c);
                if (c != ',')
                    return -1;
            }
        }
        scanf("%c", &c);
        if (c != ']') {
            return -1;
        }
        if (test_case != 0){
            scanf("%c", &c);
        }

        bool reverse = false;
        int d_num = 0;
        int startI = 0, endI = sizeOfArray - 1;
        for (int i = 0 ; i < sizeOfCommand ; i++){
            switch(command[i]){
                case 'R' :{
                    reverse = !reverse;
                    break;
                }
                case 'D' :{
                    d_num++;
                    if (reverse){
                        endI--;
                    }
                    else{
                        startI++;
                    }
                    break;
                }
            }
        }

        if (d_num > sizeOfArray){
            printf("error\n");
            continue;
        }

        printf("[");
        if (reverse){
            for (int i = endI ; i >= startI ; i--){
                printf("%d", numbers[i]);
                if (i != startI) printf(",");
            }
        }
        else{
            for (int i = startI ; i <= endI ; i++){
                printf("%d", numbers[i]);
                if (i != endI) printf(",");
            }
        }
        printf("]\n");

    }
    return 0;
}