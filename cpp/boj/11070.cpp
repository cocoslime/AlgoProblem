#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

long long baseballscore[1001][2];

using namespace std;


void inputgraph(int numberOfRuns)
{
    for (int i = 0; i < numberOfRuns; i++)
        {
            int team_1, team_2;
            cin >> team_1 >> team_2;

            long long score_1, score_2;
            cin >> score_1 >> score_2;

            baseballscore[team_1-1][0] += score_1;//scored
            baseballscore[team_1-1][1] += score_2;//allowed

            baseballscore[team_2-1][0] += score_2;
            baseballscore[team_2-1][1] += score_1;
        }
}

int pythagoreanExpectation(int team)
{
    long long scored = baseballscore[team][0];
    long long allowed = baseballscore[team][1];

    if (scored ==0) return 0;
    else if (allowed == 0) return 1000;
    int pythagorean = std::floor(1000LL *( scored * scored / (double)( scored * scored + allowed * allowed )));
    return pythagorean;
}


void maxpythagorean(int numberOfTeam)
{
        int maxpyt = -1;
        int minpyt = 1001;
        for ( int i = 0; i < numberOfTeam; i++)
        {
            int i_pyth = pythagoreanExpectation(i);
            //cout << " i : " << i_pyth <<endl;
            maxpyt = max(i_pyth, maxpyt);
            minpyt = min(minpyt, i_pyth);
        }
        cout << maxpyt << endl;
        cout << minpyt << endl;

}


int main()
{
    int gameCase;

    int numberOfTeam;
    int numberOfRuns;

    cin >> gameCase;
    while (gameCase--)
    {

        cin >> numberOfTeam >> numberOfRuns;

        for (int i = 0 ; i < 1001 ; i++)
        {
            baseballscore[i][0] = 0;
            baseballscore[i][1] = 0;
        }

        inputgraph(numberOfRuns);

        maxpythagorean(numberOfTeam);




    }


    return 0;
}
