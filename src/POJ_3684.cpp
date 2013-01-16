
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




int main() {
	int c;
	cin >> c;
	REP(prob, c){
		int n, h, r, t;
		cin >> n >> h >> r >> t;
		double pt = sqrt((double)h/5);
		double place[100];
		REP(i, n){
			if(i<t){
				int cnt = (int)((t-i)/pt);
				if(cnt%2 == 0) place[i] = h-5*(t-i-cnt*pt)*(t-i-cnt*pt);
				else place[i] = h-5*(pt-t+i+cnt*pt)*(pt-t+i+cnt*pt);
			}
			else place[i] = h;
		}
		sort(place, place+n);
		REP(i, n) {
			printf("%.2f%c", place[i] + (double)2*r*i/100, i==n-1 ? '\n': ' ');
		}
	}
	return 0;
}
