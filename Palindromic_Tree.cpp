#include<bits/stdc++.h>
using namespace std;


/*

https://codeforces.com/contest/159/submission/72095061

*/

const int N =
int trans[N][26];
int node, t;
int len[N];
int link[N];
int a[N]; /// a[u] = number of nodes that can be visited from u
          /// by following suffix link.
char s[N]; /// 1 - based index
int suff[N], pref[N];

void init(){
    memset(trans, 0, sizeof trans);
    memset(len, 0, sizeof len);
    memset(link, 0, sizeof link);
    link[1] = 1;
    len[1] = -1;
    link[2] = 1;
    len[2] = 0;
    node = t = 2;
}

void extend(int p){ /// Online algorithm
    while(s[p - len[t] - 1] != s[p]) t = link[t];
    int x = link[t];
    int c = s[p] - 'a';
    while(s[p - len[x] - 1] != s[p]) x = link[x];
    if(!trans[t][c]){
        trans[t][c] = ++node;
        len[node] = len[t] + 2;
        link[node] = len[node] == 1 ? 2 : trans[x][c];
        a[node] = 1 + a[link[node]];
    }
    t = trans[t][c];
}

int main(){

    scanf("%s", s+1);
    int n = strlen(s+1);

    init();
    Lrep(i, 1, n){
        extend(i);
        suff[i] = a[t];
    }

    init();
    reverse(s + 1, s + n + 1);
    Lrep(i, 1, n){
        extend(i);
        ///pref[i] = pref[i-1] + a[t];
    }
    reverse(pref + 1, pref + n + 1);

    ll Res = 0;
    Lrep(i, 1, n-1)
        Res += (ll) suff[i]*pref[i+1];
    cout << Res << endl;

return 0;
}
