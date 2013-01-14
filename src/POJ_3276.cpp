
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
    int dir[6000];
    REP(i, n){
        char c;
        cin >> c;
        if(c=='B') dir[i] = 1;
        else dir[i] = 0;
    }
    int k = 6000, m = 6000;
    for(int kk=1; kk<=n; kk++){
        int mm = 0, sum = 0;
        int turn[6000] = {0};
//        REP(i, n) turn[i] = 0;
        bool can = true;
        
        REP(i, n){
            if((sum+dir[i])%2 == 1){
                mm++;
                sum++;
                turn[i] = 1;
                if(i>n-kk) can = false;
            }
            if(i-kk+1 >= 0) sum -= turn[i-kk+1];
        }
        
        if(can && mm<m){
            k = kk;
            m = mm;
        }
    }
    cout << k << " " << m << endl;
    

    
    return 0;
}
