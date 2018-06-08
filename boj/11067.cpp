#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;


#define CIN fin

int cafe[100001][2];
int cafe_order[100001][2];
int cafe_num;
void set_order(int, int, int);
int compare (const void * pa, const void * pb)
{
    const int* a = ((const int *)pa);
    const int* b = (const int *)pb;

    if (a[0] > b[0])
    {
        return 1;

    }
    else if (a[0] < b[0])
    {
        return -1;

    }
    else
    {
        return a[1] - b[1];
    }

}

int order = 1;

int main()
{

   // ifstream(fin);
   // fin.open("sample.inp");
    int test_case;

    cin >> test_case;


    while (test_case--)
    {
        order =1;
        for (int i = 0 ; i < 100001 ; i++)
        {

            cafe[i][0] = -1;
            cafe[i][1] = -1;
            cafe_order[i][0] = -1;
            cafe_order[i][1] = -1;
        }




        cin >> cafe_num;

        cafe[0][0] = -1;
        cafe[0][1] = 0;
        for (int i = 1 ; i <= cafe_num ; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            //fin >> x >> y;
            /*
                        if ( cafe_x[x][2] == 0 )
                        {
                            cafe_x[x][0] = y;
                            cafe_x[x][1] = y;
                            cafe_x[x][2]++;
                        }else{
                            if (cafe[x][0] > y) cafe[x][0] = y;
                            else if ( cafe[x][1] < y ) cafe[x][1] = y;
                            cafe_x[x][2]++;
                        }*/
            cafe[i][0] = x;
            cafe[i][1] = y;



        }

        qsort(cafe, cafe_num + 1, sizeof(cafe[0]), compare);


        int pre_x = -1;
        int pre_y = 0;

        set_order(pre_x, pre_y, 0);

        int m; cin >> m;

        for (int i = 0 ; i <m ; i++){
            int ans; cin >>ans;
            cout << cafe_order[ans-1][0] << " " << cafe_order[ans-1][1] <<endl;
        }
    }

    return 0;

}


void set_order(int px, int py, int index)
{
    //remain x


    int first_order = order;

    while (1){
        order++;
        if (cafe[order][0] != cafe[first_order][0]) break;

    }

    if (cafe[first_order][1] != py)  //(cafe[order][1] < py)
    {
        for (int i = order-1 ; i >= first_order; i--)
        {
            cafe_order[index][0] = cafe[i][0];
            cafe_order[index][1] = cafe[i][1];
            index++;

        }

    }
    else
    {
        for (int i = first_order ; i < order; i++)
        {
            cafe_order[index][0] = cafe[i][0];
            cafe_order[index][1] = cafe[i][1];
            index++;
        }
    }
    if (index > cafe_num+1) return;
    set_order(cafe_order[index-1][0],cafe_order[index-1][1],index);
}
