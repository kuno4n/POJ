
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
    
    while(1){
        int r, n;
        cin >> r >> n;
        if(r == -1) break;
        int res = 0;
        VI x(n);
        REP(i, n) cin >> x[i];
        sort(ALL(x));
        int ptr = 0;
        while(ptr < n){
            res++;
            int tmp = ptr;
            while(ptr < n && x[ptr+1]-x[tmp] <= r) ptr++;
            tmp = ptr;
            while(ptr < n && x[ptr+1]-x[tmp] <= r) ptr++;
            ptr++;
        }
        cout << res << endl;
    }
    return 0;
}
