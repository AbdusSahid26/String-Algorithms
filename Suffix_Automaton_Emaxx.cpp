#include<bits/stdc++.h>
using namespace std;

/// if(we consider the size k of the alphabet as a constant)
/// Memory Complexity : O(n)
/// Time Complexity   : O(n)
/// Construction Complexity : O(n)
/// else both the time and memory complexity is O(n log k)


struct state{
    int len;
    int link;
    bool terminal;
    map<char, int> next; /// A list of transition
};

const int N = 1e5 + 10;
state st[N << 1];
int cnt[N];  /// cnt[x] has occurrences of state x
int sz;
int last;  /// Let last be the state corresponding to the entire
           /// string before adding the character c.

void init(){
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    st[0].terminal = false;
    ++sz;
}

void extend(char c){
    int cur = sz++;
    cnt[cur] = 1;
    st[cur].len = st[last].len + 1;
    st[cur].terminal = false;
    int p;
    for(p = last; p != -1 and !st[p].next.count(c); p = st[p].link){
        st[p].next[c] = cur; /// here we add a transition to the state cur.
    }
    if(p == -1) st[cur].link = 0; /// 0 state
    else{  /// we have found a state p, from which there exists a transition through the letter c
        int q = st[p].next[c];
        if(st[p].len + 1 == st[q].len){
            st[cur].link = q;
        }
        else{
            int proxy = sz++;
            st[proxy].terminal = false;
            st[proxy].len = st[p].len + 1;
            st[proxy].next = st[q].next;
            st[proxy].link = st[q].link;
            for( ; p != -1 and st[p].next[c] == q; p = st[p].link){
                st[p].next[c] = proxy;
            }
            st[q].link = st[cur].link = proxy;
        }
    }
    last = cur;
}

//vector<int> terminals;
//int te = last;
//while(te > 0){
//    terminals.push_back(te);
//    te = st[te].link;
//}

void Find_Terminal(){
    int node = last;
    while(node){
        st[node].terminal = true;
        node = st[node].link;
    }
}

void Print_Automaton(){
    for(int i=0; i<sz; i++){
        cout << "Current state                             : " << i << '\n';
        cout << "Is it terminal                            : " << st[i].terminal << '\n';
        cout << "Max len of substring in current node      : " << st[i].len << '\n';
        cout << "Transition in automaton from current node : \n";
        for(auto p: st[i].next)
            cout << p.first << " -> " << p.second << '\n';
        cout << "Suffix link from current node             : " << st[i].link << '\n';
        cout << '\n';
    }
}



int main(){

    string str;
    cin >> str;

    init();
    for(int i=0; i<str.size(); i++){
        extend(str[i]);
    }
    Find_Terminal();
    Print_Automaton();

return 0;
}
