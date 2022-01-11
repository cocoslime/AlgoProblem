//
// Created by Dongmin on 2022/01/10.
//

#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#include <functional>
#include <stack>
#include <map>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <numeric>

using namespace std;

vector<int> faces;

vector<int> moveRobot(string& instructions, vector<int> start) {
    vector<int> current(start);
    for (auto c : instructions){
        vector<int> newfaces(2, 0);
        switch (c) {
            case 'G':
                current[0] += faces[0];
                current[1] += faces[1];
                break;
            case 'L':
                newfaces[0] = faces[1];
                newfaces[1] = -faces[0];
                faces = newfaces;
                break;
            case 'R':
                newfaces[0] = -faces[1];
                newfaces[1] = faces[0];
                faces = newfaces;
                break;
        }
    }
    return current;
}

bool isRobotBounded(string instructions) {
    vector<int> pos(2, 0);
    faces.assign(2, 0);

    faces[1] = 1; // north

    for (int i = 0 ; i < 100 ; i++){
        pos = moveRobot(instructions, pos);
        if (pos[0] == 0 && pos[1] == 0)
            return true;
    }

    return false;
}

int main () {
    cout << isRobotBounded("GL");
    return 0;
}
