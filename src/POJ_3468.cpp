
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

int N, Q, a, b, c;
LL A[100010];
LL all[400040], part[400040];
char ch;

void init(){
    
    return;
}

void add(){
    
    return;
}

void sum(){
    
    return;
}

int main() {
    cin >> N >> Q;
    REP(i, N) scanf("%d", &A[i]);
    init();
    REP(i, Q){
        cin >> ch;
        if(ch == 'C'){
            cin >> a >> b >> c;
            a--; b--;
            add(a, b+1, c, 0, 0, N);
        }
        else{
            cin >> a >> b;
            a--; b--;
            sum(a, b+1, 0, 0, N);
        }
    }
    
    return 0;
}



