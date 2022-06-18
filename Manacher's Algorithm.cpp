/*

#include <bits/stdtr1c++.h>
using namespace std;
///Manacher's algorithm to generate longest palindromic substrings for all centers
/// When i is even, pal[i] = largest palindromic substring centered from str[i / 2]
/// When i is odd, pal[i] = largest palindromic substring centered between str[i / 2] and str[i / 2] + 1

vector <int> manacher(char *str){ /// hash = 784265
    int i, j, k, l = strlen(str), n = l << 1;
    vector <int> pal(n);
    for (i = 0, j = 0, k = 0; i < n; j = max(0, j - k), i += k){
        while (j <= i && (i + j + 1) < n && str[(i - j) >> 1] == str[(i + j + 1) >> 1]) j++;
        for (k = 1, pal[i] = j; k <= i && k <= pal[i] && (pal[i] - k) != pal[i - k]; k++){
            pal[i + k] = min(pal[i - k], pal[i] - k);
        }
    }

    pal.pop_back();
    return pal;
}

int main(){
    char str[100];
    while (scanf("%s", str)){
        auto v = manacher(str);
        for (auto it: v) printf("%d ", it);
        puts("");
    }
    return 0;
}


*/



#include<bits/stdc++.h>
using namespace std;

///https://codeforces.com/contest/1326/submission/73929550
int main(){

    string s;
    cin >> s;
    int n = s.size();
    vector<int> d1(n);
    for(int i=0, l=0, r = -1; i<n; i++){
        int k = (i > r) ? 1 : min(d1[l+r-i], r-i);
        while(0 <= i-k and i+k < n and s[i-k] == s[i+k])
            k++;
        d1[i] = k--;
        if(i + k > r){
            l = i - k;
            r = i + k;
        }
    }

    vector<int> d2(n);
    for(int i=0, l=0, r = -1; i<n; i++){
        int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(0<= i-k-1 and i+k<n and s[i-k-1] == s[i+k])
            k++;
        d2[i] = k--;
        if(i+k > r){
            l = i-k-1;
            r = i+k;
        }
    }

    cout << "first    : ";
    for(int i=0; i<n; i++){
        cout << d1[i] << ' ';
    }
    cout << endl;
    cout << "second   : ";
    for(int i=0; i<n; i++){
        cout << d2[i] << ' ';
    }
    cout << endl;

return 0;
}
