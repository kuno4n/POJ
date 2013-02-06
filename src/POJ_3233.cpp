
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

typedef vector < VI > mat;
int n, k, m;

mat mul(mat &A, mat &B){
	mat C(SZ(A), VI(SZ(B[0])));
	REP(i, SZ(A)){
		REP(k, SZ(B)){
			REP(j, SZ(B[0])){
				C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % m;
			}
		}
	}
	return C;
}

mat pow(mat A, LL n){
	mat B(SZ(A), VI(SZ(A)));
	REP(i, SZ(A)) B[i][i] = 1;
	while(n > 0){
		if(n&1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}


int main() {
    cin >> n >> k >> m;
    mat AA(n*2, VI(n*2));
    mat BB(n*2, VI(n));
    REP(i, n) REP(j, n) {
        cin >> AA[i][j];
        AA[i][j] %= m;
        AA[i][j+n] = 0;
        if(i == j){
            AA[i+n][j] = 1;
            AA[i+n][j+n] = 1;
        }
        else{
            AA[i+n][j] = 0;
            AA[i+n][j+n] = 0;
        }
    }
    REP(i, n) REP(j, n){
        if(i == j) BB[i][j] = 1;
        else BB[i][j] = 0;
        BB[i+n][j] = 0;
    }
    mat AAA = pow(AA, k+1);
    mat CC = mul(AAA, BB);
    REP(i, n) REP(j, n){
        int res = CC[i+n][j];
        if(i == j) res = (res+m-1)%m;
        cout << res << (j==n-1 ? "\n" : " ");
    }



	return 0;
}
