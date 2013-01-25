
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

#define M_PI_ 3.1415926535

int n, c;
int L[10010], s[10010], a[10010];
int prev[10010];
double x[40040], y[40040];
double arg[40040];

void init(int _n, int l, int r){
	x[_n] = 0;
	if(r-l == 1){
		y[_n] = L[l];
		arg[_n] = -10000.0; // 葉なので使用しない値
	}
	else{
		int m = (l+r)/2;
		init(_n*2+1, l, m);
		init(_n*2+2, m, r);
		y[_n] = y[_n*2+1] + y[_n*2+2];
		arg[_n] = 0.0;
	}
	return;
}

void change(int point, double ar, int node, int l, int r){
	if(r-l == 1) return;
	if(point <= l || point >= r) return;
	int m = (l+r)/2;
	int chl = node*2+1;
	int chr = node*2+2;
	change(point, ar, chl, l, m);
	change(point, ar, chr, m, r);
	if(point <= m) arg[node] += ar;
	x[node] = x[chl] + x[chr]*cos(arg[node]) - y[chr]*sin(arg[node]);
	y[node] = y[chl] + x[chr]*sin(arg[node]) + y[chr]*cos(arg[node]);
	return;
}

void run(){
	init(0, 0, n);
	for(int i=1; i<n; i++) prev[i] = 180;
	REP(i, c){
		double ar = (double)(a[i]-prev[s[i]])/360*2*M_PI_;
		change(s[i], ar, 0, 0, n);
		prev[s[i]] = a[i];
		printf("%.2f %.2f\n", x[0], y[0]);
	}
}

int main() {
	scanf("%d", &n);
	while(1){
		fill(L, L+10005, 0);
		fill(s, s+10005, 0);
		fill(a, a+10005, 0);
		scanf("%d", &c);
		REP(i, n) scanf("%d", &L[i]);
		REP(i, c) scanf("%d %d", &s[i], &a[i]);
		run();
		if(scanf("%d", &n) != EOF) cout << endl;
		else break;
	}
	return 0;
}
