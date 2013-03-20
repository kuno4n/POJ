
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

int p[1010];

int main() {
    int t;
    cin >> t;
    REP(c, t){
        int nim = 0;
        int n;
        cin >> n;
        REP(i, n){
            if(i == 0 && (n&1) == 1){
                p[0] = 0;
                n++;
            }
            else{
                cin >> p[i];
            }
        }
        sort(p, p+n);
        REP(i, n) if(i & 1) nim ^= p[i] - p[i-1] - 1;
        if(nim == 0) cout << "Bob will win";
        else cout << "Georgia will win";
        cout << endl;
        
    }

    
    return 0;
}



