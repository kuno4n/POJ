
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

#define M_PI_ 3.1416926535

int n, c;
int L[10010], s[10010], a[10010], prev[10010];

void run(){
	double x[10010], y[10010];
	REP(i, n){
		x[i+1] = 0;
		y[i+1] = y[i] + L[i];
		if(i>=1) prev[i] = 180;
	}
	REP(i, c){
		double px, py;
		px = x[s[i]]; py = y[s[i]];
		double ka = (double)(a[i]-prev[s[i]])/360*2*M_PI_;
		prev[s[i]] = a[i];
		for(int j=s[i]+1; j<=n; j++){
			double a, b;
			a = x[j]-px; b = y[j]-py;
			double aa = a*cos(ka) - b*sin(ka);
			double bb = a*sin(ka) + b*cos(ka);
			x[j] = px+aa; y[j] = py+bb;
		}
		printf("%.2f %.2f\n", x[n], y[n]);
	}
	
}

int main() {
	scanf("%d", &n);
	while(1){
		fill(L, L+10010, 0);
		fill(s, s+10010, 0);
		fill(a, a+10010, 0);
		scanf("%d", &c);
		REP(i, n) scanf("%d", &L[i]);
		REP(i, c) scanf("%d %d", &s[i], &a[i]);
		run();
		if(scanf("%d", &n) != EOF) cout << endl;
		else break;
	}
	return 0;
}
