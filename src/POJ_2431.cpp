
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
	int n;
	cin >> n;
	vector< PII > stop;
	REP(i, n){
		int s, f;
		cin >> s >> f;
		stop.PB(make_pair(s, f));
	}
	sort(ALL(stop));
	int L, P;
	cin >> L >> P;
	int ptr = n;
	int cnt = 0;
	priority_queue<int> pq;
	while(L>P){
		while(ptr >= 0 && L-P <= stop[ptr-1].first){
			ptr--;
			pq.push(stop[ptr].second);
		}
		if(pq.empty()) break;
		P += pq.top();
		pq.pop();
		cnt++;
	}
	cout << (L<=P ? cnt : -1) ;

	return 0;
}
