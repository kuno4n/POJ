
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
    string s(n, ' ');
    REP(i, n) cin >> s[i];
    int a = 0, b = n-1;
    string res = "";
    while(a <= b){
        string s1, s2;
        s1 = s2 = s.substr(a, b-a+1);
        reverse(ALL(s2));
        if(s1 <= s2){
            res += s[a];
            a++;
        }
        else{
            res += s[b];
            b--;
        }
    }
    REP(i, n){
        if(i%80 == 0 && i!=0) cout << endl;
        cout << res[i];
    }
    cout << endl;
    return 0;
}
