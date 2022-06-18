#include<bits/stdc++.h>
using namespace std;

#define MAX 100010
char T[MAX];
int n;
int RA[MAX], tempRA[MAX];
int PSuf[MAX], LCP[MAX], PLCP[MAX];
int SA[MAX], tempSA[MAX];
int c[MAX];

void CountingSort(int k){
    int sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for(int i=0; i<n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for(int i=sum=0; i<maxi; i++){
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for(int i=0; i<n; i++)
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for(int i=0; i<n; i++)
        SA[i] = tempSA[i];
}

void construct(){
    for(int i=0; i<n; i++)
        RA[i] = T[i];
    for(int i=0; i<n; i++)
        SA[i] = i;
    int r;
    for(int k = 1; k < n; k <<= 1){
        CountingSort(k);
        CountingSort(0);
        tempRA[SA[0]] = r = 0;
        for(int i=1; i<n; i++)
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] and RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : r++;
        for(int i=0; i<n; i++)
            RA[i] = tempRA[i];
        if(RA[SA[n-1] == n-1]) break;
    }
}

void ComputeLCP(){
    PSuf[SA[0]] = -1;
    for(int i=1; i<n; i++)
        PSuf[SA[i]] = SA[i-1];
    int L = 0;
    for(int i=0; i<n; i++){
        if(PSuf[i] == -1){
            PLCP[i] = 0;
            continue;
        }
        while(T[i + L] == T[PSuf[i] + L]) L++;
        PLCP[i] = L;
        L = max(L-1, 0);
    }
    for(int i=0; i<n; i++)
        LCP[i] = PLCP[SA[i]];
}

int main(){
    n = (int) strlen(gets(T));
    T[n++] = '$';
    construct();
    for(int i=0; i<n; i++)
        printf("%2d\t%s\n",SA[i], T+SA[i]);

return 0;
}
