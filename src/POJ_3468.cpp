
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

void add(int A, int B, int x, int node, int left, int right){
	if(right<=left) return;
    if(A<=left && right<=B){
		all[node] += x;
		return;
	}
	if(!(right<=A) && !(B<=left)) part[node] += x * (min(right,B) - max(left, A));
	else return;

	int m = (left+right)/2;
	add(A, B, x, node*2+1, left, m);
	add(A, B, x, node*2+2, m, right);

    return;
}

LL sum(int A, int B, int node, int left, int right){
    LL res = 0;
	if(right<=left) return res;
	if(A<=left && right<=B){
		res += part[node];
		res += all[node] * (right-left);
		return res;
	}
	if(!(right<=A) && !(B<=left)) res += all[node] *(min(right,B) - max(left, A));
	else return res;

	int m = (left+right)/2;
	res += sum(A, B, node*2+1, left, m);
	res += sum(A, B, node*2+2, m, right);

    return res;
}

void init(){
	REP(i, 400040) all[i] = 0;
	REP(i, 400040) part[i] = 0;
    REP(i, N) add(i, i+1, A[i], 0, 0, N);
    return;
}

int main() {
    cin >> N >> Q;
    REP(i, N) scanf("%lld", &A[i]);
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
            cout << sum(a, b+1, 0, 0, N) << endl; 
        }
    }
    
    return 0;
}