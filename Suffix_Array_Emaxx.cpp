#include<bits/stdc++.h>
using namespace std;

/*


https://codeforces.com/problemset/problem/432/D


*/


const int N = 1e5 + 10;
int dp[N][24];
int Log[N];

struct SuffixArray{

    vector<vector<int>> Keep;
    vector<int> CycleShifts(string const& s){
        int n = s.size();
        const int alphabet = 256; /// Complete ASCII range as alphabet

        vector<int> perm(n), eclass(n), cnt(max(alphabet, n), 0);
        for(int i=0; i<n; i++) cnt[s[i]]++;
        for(int i=1; i<alphabet; i++) cnt[i] += cnt[i-1];
        for(int i=0; i<n; i++) perm[--cnt[s[i]]] = i;

        eclass[perm[0]] = 0;
        int classes = 1;
        for(int i=1; i<n; i++){
            if(s[perm[i]] != s[perm[i-1]]) classes++;
            eclass[perm[i]] = classes - 1;
        }

        /// Time Complexity   : O(n log n)
        /// Memory Complexity : O(n)

        /// If we consider the size of the alphabet k into account then
        /// Time Complexity   : O((n+k)log n)
        /// Memory Complexity : O(n+k)

        Keep.emplace_back(eclass);

        vector<int> permn(n), eclassn(n);
        for(int h=0; (1<<h)<n; ++h){
            for(int i=0; i<n; i++){
                permn[i] = perm[i] - (1 << h);
                if(permn[i] < 0) permn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for(int i=0; i<n; i++) cnt[eclass[permn[i]]]++;
            for(int i=1; i<classes; i++) cnt[i] += cnt[i-1];
            for(int i=n-1; i>=0; i--) perm[--cnt[eclass[permn[i]]]] = permn[i];

            eclassn[perm[0]] = 0;
            classes = 1;
            for(int i=1; i<n; i++){
                pair<int, int> cur = {eclass[perm[i]], eclass[(perm[i] + (1 << h)) % n]};
                pair<int, int> prev = {eclass[perm[i-1]], eclass[(perm[i-1] + (1 << h)) % n]};
                if(cur != prev) classes++;
                eclassn[perm[i]] = classes - 1;
            }
            eclass.swap(eclassn);
            Keep.emplace_back(eclass);
        }
        return perm;
    }

    int LCPofTwoSubStrings(int i, int j, int n){
        int res = 0;
        for(int k = log2(n); k>=0; k--){
            if(Keep[k][i] == Keep[k][j]){
                res += 1 << k;
                i += 1 << k;
                j += 1 << k;
                /// Memory Complexity : O(s log s) additional memory.
            }
        }
        return res;
    }

    vector<int> LCP_Construction(string const& s, vector<int>& p, vector<int>& rank){
        /// Kasai's Algorithm.
        /// TC : O(n)
        int n = s.size();
        for(int i=0; i<n; i++) rank[p[i]] = i;
        /// rank will give us the position of a suffix in the sorted list of suffixes.
        int k = 0;
        vector<int> lcp(n-1, 0);
        for(int i=0; i<n; i++){
            if(rank[i] == n-1){
                k = 0;
                continue;
            }
            int j = p[rank[i] + 1];
            while(i + k < n and j + k < n and s[i+k] == s[j+k]) k++;
            lcp[rank[i]] = k;
            if(k) k--;
        }
        return lcp;
    }

    void LogTable_Construction(){
        Log[1] = 0;
        for(int i=2; i<N; i++) Log[i] = Log[i >> 1] + 1;
    }

    void SparseTable_Construction(vector<int> lcp, int n){
        LogTable_Construction();
        for(int i=0; i< n; i++) dp[i][0] = lcp[i];

        for(int j=1; (1<<j)<=n; j++)
            for(int i=1; i+(1<<j)<=n; i++)
                dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
    }

    int RMQ_Query(int l, int r){
        int k = Log[r - l + 1];
        return min(dp[l][k], dp[r - (1 << k) + 1][k]);
    }

    int Occurrences(int l, int r, int key){
        int left = l;
        int res = 0;
        while(l <= r){
            int mid = (l + r + 1) >> 1;
            if(RMQ_Query(left, mid - 1) < key) r = mid - 1;
            else{
                res = mid;
                l = mid + 1;
            }
        }
        return res - left + 1;
    }
}String;

///  Application :
///  1. Finding the smallest cycle shift.
///  2. Finding a substring in a string.
///  3. Comparing two substrings of a string.
///  4. Longest common prefix of two substrings with additional memory.
///  5. Longest common prefix of two substrings without additional memory.
///  6. Number of different substrings.


int main(){

    string str;
    cin >> str;
    str += '$';
    vector<int> perm = String.CycleShifts(str);

    int n = str.size();
    vector<int> rank(n);
    vector<int> lcp = String.LCP_Construction(str, perm, rank);
    String.SparseTable_Construction(lcp, n-1);

    vector<pair<int, int>> matches;
    matches.push_back({n-1, 1});
    for(int i=1; i<n-1; i++){
        int len = n-i-1;
        if(len == String.LCPofTwoSubStrings(0, i, n)){
            int times = String.Occurrences(rank[i], n-1, len);
            matches.push_back({len, times});
        }
    }
    sort(matches.begin(), matches.end());
    cout << matches.size() << endl;
    for(int i=0; i<matches.size(); i++){
        cout << matches[i].first << ' ' << matches[i].second << endl;
    }

return 0;
}
