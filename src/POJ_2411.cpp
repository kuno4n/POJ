#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
//#include <sys/time.h>
#include <fstream>
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
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())


LL crt[1<<11], nxt[1<<11];
int h, w;

void init() {
}

void input() {
}

void solve() {
	REP(i, (1<<w)) crt[i] = 0;
	crt[0] = 1;
	
	REP(i, h) REP(j, w){
		REP(k, (1<<w)) nxt[k] = 0;
		REP(k, (1<<w)) if(crt[k] > 0) {			
			//tate
			if(!(k & 1) && (i < h-1)) nxt[(k>>1)|(1<<(w-1))] += crt[k];
			//yoko
			if(!(k & 3) && (j < w-1)) nxt[(k>>1)|1] += crt[k];
			//nashi 
			if(k & 1) nxt[k>>1] += crt[k];
		}
		swap(crt, nxt);
	}
	
	cout << crt[0] << endl;
}

int main() {
	init();
    input();
    while(cin >> h >> w){
		if(h == 0) break;
		solve();
	}
	return 0;
}






