
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

#define INF (1<<30)

int main() {
    int n;
    cin >> n;
    REP(i, n){
        int L, num;
        cin >> L >> num;
        VI pos(num);
        REP(j, num) cin >> pos[j];
//        sort(ALL(pos));
        int mn=0, mx=0;
        
        REP(j, num){
            mn = max(mn, min(pos[j], L-pos[j]));
            mx = max(mx, max(pos[j], L-pos[j]));
        }
        
        cout << mn << " " << mx << endl;
    }
    return 0;
}
