
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

#define EPS 1e-9

double L[10000];

int main() {
	int N, K;
	cin >> N >> K;
	REP(i, N) scanf("%lf", &L[i]);

	double lo = 0.0, hi = 100010.0;
	while(hi-lo > EPS){
		double mid = (lo+hi) /2;
		int cnt = 0;
		REP(i, N) cnt += (int)(L[i]/mid);
		if(cnt >= K) lo = mid;
		else hi = mid;
	}

	printf("%.2f\n", floor(hi * 100)/100);

	return 0;
}
