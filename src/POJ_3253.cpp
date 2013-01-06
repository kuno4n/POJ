
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
    priority_queue<int, VI, greater<int> > L;
    REP(i, n) {
        int a;
        cin >> a;
        L.push(a);
    }
    LL res = 0;
    while(SZ(L) > 1) {
        int i1 = L.top();
        L.pop();
        int i2 = L.top();
        L.pop();
        res += i1+i2;
        L.push(i1+i2);
    }
    cout << res << endl;
    
    return 0;
}
