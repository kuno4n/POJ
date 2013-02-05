
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
const int MOD = 10007;

mat mul(mat &A, mat &B){
	mat C(SZ(A), VI(SZ(B[0])));
	REP(i, SZ(A)){
		REP(k, SZ(B)){
			REP(j, SZ(B[0])){
				C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % MOD;
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

int t, n;

int main() {
	cin >> t;
	REP(test, t){
		cin >> n;
		mat A(4, VI(4));
		A[0][0] = 2;
		A[0][1] = 1;
		A[0][2] = 1;
		A[0][3] = 0;
		A[1][0] = 1;
		A[1][1] = 2;
		A[1][2] = 0;
		A[1][3] = 1;
		A[2][0] = 1;
		A[2][1] = 0;
		A[2][2] = 2;
		A[2][3] = 1;
		A[3][0] = 0;
		A[3][1] = 1;
		A[3][2] = 1;
		A[3][3] = 2;
		A = pow(A, n);
		cout << A[0][0] << endl;
	}


	return 0;
}
