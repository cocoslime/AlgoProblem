//
// Created by Dongmin on 9/10/21.
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

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int strToInt(string str) {
    std::stringstream ss(str);
    int n;
    ss >> n;
    return n;
}

vector<int> split_int(string input, char delimiter) {
    vector<int> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(strToInt(temp));
    }

    return answer;
}

const int HH = 0;
const int MM = 1;
const int SS = 2;

int toSeconds(vector<int> &hms) {
    int seconds = 0;
    seconds += hms[0] * 60 * 60 + hms[MM] * 60 + hms[SS];
    return seconds;
}

string toTimeStr(int time) {
    int n_zero = 2;
    string result = std::string(n_zero - to_string(time).length(), '0') + to_string(time);
    return result;
}

string toHHMMSS(int seconds) {

    int hh = seconds / (60 * 60);
    int mm = (seconds % (60 * 60)) / 60;
    int ss = seconds % 60;

    string result = toTimeStr(hh) + ":" + toTimeStr(mm) + ":" + toTimeStr(ss);

    return result;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    vector<int> v_play_time = split_int(play_time, ':');
    vector<int> v_adv_time = split_int(adv_time, ':');

    int play_time_seconds = toSeconds(v_play_time);
    int adv_time_seconds = toSeconds(v_adv_time);

    vector<int> frequency(play_time_seconds, 0);

    for (auto &log : logs) {
        vector<string> log2 = split(log, '-');
        vector<int> v_log_st_time = split_int(log2[0], ':');
        vector<int> v_log_end_time = split_int(log2[1], ':');

        int log_st_time_seconds = toSeconds(v_log_st_time);
        int log_end_time_seconds = toSeconds(v_log_end_time);

        for (int i = log_st_time_seconds; i < log_end_time_seconds; i++) {
            frequency[i]++;
        }
    }

    long long max_count = 0;
    long long pre_count = 0;
    int max_idx;

    if (adv_time_seconds == play_time_seconds){
        return toHHMMSS(0);
    }


    for (int i = 0 ; i <= play_time_seconds - adv_time_seconds ; i++){
        long long count;

        if (i == 0) {
            count = std::accumulate(frequency.begin(), frequency.begin() + adv_time_seconds, 0);
        } else {
            count = pre_count - frequency[i-1] + frequency[i + adv_time_seconds - 1];
        }
//        cout << "time : " << toHHMMSS(i) << "," << count << endl;

        if (max_count < count) {
            max_count = count;
            max_idx = i;
        }

        pre_count = count;

    }

    answer = toHHMMSS(max_idx);

    return answer;
}

int main() {
    string result;
    vector<string> logs = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29",
                           "01:37:44-02:02:30"};
    result = solution("02:03:55", "00:14:15", logs);
    cout << result << endl;
    vector<string> logs_2 = {"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"};
    result = solution("99:59:59", "25:00:00", logs_2);
    cout << result << endl;

    vector<string> logs_3 = {"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"};
    result = solution("50:00:00", "50:00:00", logs_3);
    cout << result << endl;

    vector<string> logs_4 = {"00:00:09-00:00:10"};
    result = solution("00:0:10", "00:00:01", logs_4);
    cout << result << endl;
    return 0;
}
