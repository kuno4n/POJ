
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




		int p[1000000];

int main() {
		int res = 1000001;
		int n; cin >> n;
		REP(i, n) scanf("%d", p+i);
		set<int> s;
		REP(i, n) s.insert(p[i]);
		int sz = SZ(s);
		int a=0, b=1;
		map<int, int> m;
		m[p[0]]++;
		int cnt = 1;
		while(b<=n){
			bool next = true;
			if(cnt == sz){
				res = min(res, b-a);
				if(b-a > 1) next = false;
			}
			if(next){
				if(m[p[b++]]++ == 0) cnt++;
			}
			else{
				if(--m[p[a++]] == 0) cnt--;
			}
		}
		cout << res << endl;
	return 0;
}
