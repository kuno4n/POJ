
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
        int a, b;
        cin >> a >> b;
        if(a == 0) break;
        bool f = true;
        while(1){
            if(b < a) swap(a, b);
            if(b - a >= a || b % a == 0) break;
            b -= a;
            f ^= 1;
        }
        if(f) cout << "Stan wins";
        else cout << "Ollie wins";
        cout << endl;
    }

    
    return 0;
}



