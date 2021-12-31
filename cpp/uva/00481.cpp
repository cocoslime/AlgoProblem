#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

#define REP(i, a, b) for (int i = int(a) ; i < int(b); i++)

#include <iostream>
#include <fstream>

ofstream fout("res.txt");

int length;
int L[100000];
int L_id[100000];
int numbers[100000];

int pre[100000];

int main() {
	int num = 0;
	int last = -1;
	int v;
	while (cin >> v)
	{
		numbers[num] = v;
		int pos = lower_bound(L, L + length, v) - L;
		L[pos] = v;
		L_id[pos] = num;
		if (pos == 0) pre[num] = -1;
		else {
			pre[num] = L_id[pos - 1];
		}
		if (pos + 1 > length) {
			length = pos + 1;
			last = num;
		}
		num++;
	}
	cout << length << endl;
	cout << "-" << endl;
	
	int x = last;
	stack<int> s;
	for (; pre[x] >= 0; x = pre[x]) s.push(numbers[x]);
	printf("%d\n", numbers[x]);
	for (; !s.empty(); s.pop()) printf("%d\n", s.top());
	
	return 0;
}