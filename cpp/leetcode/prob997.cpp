//
// Created by Dongmin on 2022/01/03.
//
// https://leetcode.com/problems/find-the-town-judge/

int findJudge(int n, vector<vector<int>>& trust) {
    if (n == 1) return 1;
    if (trust.size() < n - 1) return -1;

    vector<int> count(n + 1, 0);

    for (auto& trustOne : trust){
        count[trustOne[0]] = -1;
        if (count[trustOne[1]] >= 0)
            count[trustOne[1]]++;
    }

    for (int i = 1; i <= n ; i++){
        if (count[i] == n - 1)
            return i;
    }
    return -1;
}