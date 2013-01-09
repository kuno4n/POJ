
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

LL x[100000];
int N, C;

bool can(LL a){
	int ptr = 1, cnt = 1;
	LL tmp = x[0];
	while(1){
		while(tmp+a > x[ptr]) {
			ptr++;
			if(ptr == N ) return false;
		}
		cnt++;
		if(cnt == C) return true;
		tmp = x[ptr];
	}
}



int main() {
	cin >> N >> C;
	REP(i, N) scanf("%ld", &x[i]);
	sort(x, x+N);

	LL lo = 1, hi = (LL)1000000001;
	while(hi-lo > 1){
		LL mid = (lo+hi)/2;
		if(can(mid)) lo = mid;
		else hi = mid;
	}


	cout << lo;
	return 0;
}
