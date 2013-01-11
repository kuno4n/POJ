
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
	int test; cin >> test;
	REP(t, test){
		int res = 100001;
		int n, s; cin >> n >> s;
		int num[100000];
		REP(i, n) cin >> num[i];
		int a=0, b=1;
		int sum = num[0];
		while(b<=n){
			if(sum >= s){
				res = min(res, b-a);
				if(b-a > 1){
					sum -= num[a];
					a++;
				}
				else{
					sum += num[b];
					b++;
				}
			}
			else{
				sum += num[b];
				b++;
			}
		}
		cout << (res==100001 ? 0 : res) << endl;
	}
	return 0;
}
