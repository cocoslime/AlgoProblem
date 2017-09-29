
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <climits>
#include <queue> 
#include <functional> 
#include <stack>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ii;
typedef vector<int> vi;
typedef vector<ii> vii;


#define INF 1000000000

#include <iostream>
#include <fstream>

ofstream fout("res.txt");
ifstream fin("input.txt");
FILE* fp;

#define MAX_N 1000

void print();

vector<ii> coords;
int min_x, min_y;
int max_x, max_y;

int N;

ll getDistance(ii, ii);

int fn(ii A, ii B, ii C) {
	ll ret = ((ll)A.first * (ll)B.second - (ll)A.second * (ll)B.first) +
		((ll)B.first * (ll)C.second - (ll)C.first * (ll)B.second) +
		((ll)C.first * (ll)A.second - (ll)A.first * (ll)C.second);
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}

int findIntersect(ii A, ii B, ii C, ii D) {
	if (A == C || A == D || B == C || B == D) return 0;
	int abc = fn(A, B, C);
	int abd = fn(A, B, D);
	int cda = fn(C, D, A);
	int cdb = fn(C, D, B);

	int ab = abc * abd;
	int cd = cda * cdb;

	if (ab < 0 && cd < 0) return 1; //intersect;
	if (ab == 0 && cd == 0) { 
		if (abc == 0 && abd == 0 && cda == 0 && cdb == 0) {// linear
			if (A.first == B.first) { //compare Y
				int min_ab = min(A.second, B.second);
				int max_ab = max(A.second, B.second);
				int min_cd = min(C.second, D.second);
				int max_cd = max(C.second, D.second);
				if (min_ab <= max_cd && max_ab >= min_cd) return 0;
				else return -1;
			}
			else { //compare X
				int min_ab = min(A.first, B.first);
				int max_ab = max(A.first, B.first);
				int min_cd = min(C.first, D.first);
				int max_cd = max(C.first, D.first);
				if (min_ab <= max_cd && max_ab >= min_cd) return 0;
				else return -1;
			}
		}
		return 0;
	}
	if (ab == 0 || cd == 0) {
		if (ab == 0) {
			if (cd <= 0) return 0;
			else return -1;
		}
		else {
			if (ab <= 0) return 0;
			else return -1;
		}
	}
	else return -1;
}

bool isIntersectWithBig(ii A, ii B) {
	for (int i = 0; i < coords.size() - 1; i++) {
		//if (i == 6) {
		//	cout << endl;
		//}
		int intersect = findIntersect(coords[i], coords[i + 1], A, B);
		if (intersect == 1) 
			return true;
	}
	return false;
}

ll getDistance(ii A, ii B) {
	return (ll)(A.first - B.first) * (ll)(A.first - B.first) + (ll)(A.second - B.second) * (ll)(A.second - B.second);
}

bool isInTriangle(vector<ii>& tri, ii point) {
	//vector<ii> triangle = triangulation[i];
	
	for (int i = 0; i < 3; i++) {
		if (fn(tri[i], tri[i + 1], point) <= 0) return false;
	}
	return true;
}

int isInBig(vector<ii>& tri) {
	if (N == 4) {
		
		int in = 0;
		for (int j = 0; j < 3; j++) {
			if (tri[j].first <= max_x && tri[j].first >= min_x
				&& tri[j].second <= max_y && tri[j].second >= min_y)
				in++;
			
		}
		return in;
	}
	else {
		int out = 0;
		int in = 0;
		for (int j = 0; j < 3; j++) {
			ii coord = ii(10001, 10001);
			int inter_num = 0;
			for (int i = 0; i < coords.size() - 1; i++) {
				int type = findIntersect(tri[j], coord, coords[i], coords[i + 1]);
				if (fn(tri[j],coord, coords[i]) == 0 || fn(tri[j],coord, coords[i+1]) == 0) {
					coord.second -= 1;
					i = -1;
					break;
				}
				else if (type == 1){
					inter_num++;
				}
			}
			if (inter_num % 2 == 0) out++;
			else in++;
		}
		return in;
	}

	
}

bool isAnyPointInTriangle(vector<ii>& tri) {
	for (int i = 0; i < coords.size() - 1; i++) {
		if (isInTriangle(tri, coords[i])) return true;
	}
	return false;
}

int getType(vector<ii>& tri) {
	int intersect_num = 0;
	int zup_num = 0;
	int non_intersect_num = 0;

	for (int i = 0; i < coords.size() - 1; i++) {
		for (int j = 0; j < 3;j++) {
			int intersect = findIntersect(coords[i], coords[i + 1], tri[j], tri[j + 1]);
			if (intersect == -1) {
				non_intersect_num++;
			}
			else if (intersect == 0) zup_num++;
			else intersect_num++;
		}
	}
	if (intersect_num > 0) return 4;
	else {
		int isIn = isInBig(tri);
		if (isIn == 3) {
			return 1;
		}
		else if (isIn == 0) { // 2 or 3 or 4
			if (isAnyPointInTriangle(tri)) 
				return 4;
			if (zup_num > 0)
				return 3;
			else
				return 2;
		}	
		else {
			if (isAnyPointInTriangle(tri))
				return 4;
			else if (zup_num > 0)
				return 3; // 3 or 4
			else
				cout << -100 << endl;
			return -100;
		}
	}
}

int main() {
	fp = fopen("input.txt", "r");//stdin;
	int test_case;
	fscanf(fp, "%d", &test_case);
	int test_num = 0;
	while (test_case--) {
		test_num++;
		//cout << findIntersect(ii(2, 2), ii(2, 0), ii(2, 4), ii(2, 3));
		fscanf(fp, "%d", &N);
		coords.clear();

		max_x = -10001; max_y = -10001;
		min_x = 10001; min_y = 10001;
		for (int i = 0; i < N; i++) {
			int x, y;
			fscanf(fp, "%d %d", &x, &y);
			if (i != 0) {
				if (coords[i - 1].first == x || coords[i - 1].second == y) {
					
				}
				else {
					cout << test_num << " Error :coordinate " << endl;
					return 0;
				}
			}
			coords.push_back(ii(x, y));
			max_x = max(x, max_x);
			max_y = max(y, max_y);
			min_x = min(x, min_x);
			min_y = min(y, min_y);
		}
		coords.push_back(coords[0]);

		int K;
		fscanf(fp, "%d", &K);
		for (int i = 0; i < K; i++) {
			vector<ii> tri;
			for (int j = 0; j < 3; j++) {
				int x, y;
				fscanf(fp, "%d %d", &x, &y);

				tri.push_back(ii(x, y));
			}
			tri.push_back(tri[0]);

			int ret = getType(tri);
			//cout << ret << " ";
			fout << ret ;
			if (i != K - 1 ) fout << " ";
		}
		if (test_case != 0) fout << endl;
		//cout << endl;

	}

	fout.close();
	return 0;

}

