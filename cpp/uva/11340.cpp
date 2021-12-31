#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define REP(i, a, b) for (int i = int(a) ; i < int(b); i++)

#include <iostream>

map <char, double> mymap;
map <char, double>::iterator it;
int N;
int K;
double cent;
string temp;

int main() {
	cin >> N;
	while (N--) {
		cent = 0;
		cin >> K;
		while (K--) {
			char t;
			double v;
			cin >> t >> v;
			mymap[t] = v;
		}

		int line; cin >> line;
		cin.ignore();
		while (line--) {
			temp = "";
			getline(cin, temp);
			for (int i = 0; i < temp.size(); i++) {
				it = mymap.find(temp[i]);
				if (it != mymap.end()) cent += it->second;
				//cout << (char)id << "," << value[id] << endl;
			}
		}
		
		printf("%0.2lf$\n", cent / 100);
		mymap.clear();
		
	}
	return 0;
}