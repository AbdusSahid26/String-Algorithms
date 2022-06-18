


Problem : https://codeforces.com/contest/963/problem/D
User    : Chilli
User    : Benq




/*

Let there be a set of strings with the total length m (sum of all lengths).
The Aho-Corasick algorithm constructs a data structure similar to a trie
with some additionallinks, andthenconstructsaﬁnitestatemachine(automaton)in
O(mk) time, where k is the size of the used alphabet.
Every vertex store k links.
*/

/*

Application :

1. Find all occurrences of all strings from a given set in a text.
2. Finding the lexicographical smallest string of a given length
   that doesn't match any given set of strings.
3. Finding the shortest string containing all given strings.
4. Finding the lexicographical smallest string of length L containing k strings.

*/


const int N = 1e5 + 5;
const int Alphabet = 26;

struct Aho{
    struct Vertex{ /// trie
        int Next[Alphabet]; /// Next[i] is the index of the vertex that we reach by following the character i, or -1 if there is no such edge.
        int Go[Alphabet];
        int Leaf = -1;  /// As a flag Leaf is associated to each vertex and it is true when any given string is correspond to a vertex.
        int P = -1;
        int Link = -1;
        int Leaflink = -1;
        char Pch;

        Vertex(int P = -1, char Ch = '$') : P(P), Pch(Ch){
            fill(begin(Next), end(Next), -1);
            fill(begin(Go), end(Go), -1);
        }
    };
    vector<Vertex> Retrieval; /// We store the trie as an array of vertex.
    vector<int> Result[N];
    Aho() : Retrieval(1) {}

    void Add_String(string const &s, int Pos){ /// This function add a string s to the trie.
        int v = 0;  /// we start at the root node v = 0;
        for(char Ch : s){     /// trie construction
            int c = Ch - 'a';
            if(Retrieval[v].Next[c] == -1){ /// there is no path for char 'c' from vertex v.
                Retrieval[v].Next[c] = Retrieval.sz; /// we generate a new vertex.
                Retrieval.emplace_back(v, Ch);  /// finally connect the newly created vertex with vertex v and labeled the new edge with char 'c'.
            }
            v = Retrieval[v].Next[c];
        }
        Retrieval[v].Leaf = Pos; /// we mark the last vertex bcz here our string terminate.
        /// Construction : Time Complexity   : O(n)
        ///                memory Complexity : O(mk)
    }

    /*
    Description of Get link , GO link : Construction of an Automaton from emaxx

    A suﬃx link for a vertex p is a edge that points to the longest
    proper suﬃx of the string corresponding to the vertex p.
    */

    int Get_Link(int v){
        if(Retrieval[v].Link == -1){
            if (v == 0 || Retrieval[v].P == 0) Retrieval[v].Link = 0; /// Suffix link of root vertex is itself.
            else Retrieval[v].Link = Go(Get_Link(Retrieval[v].P), Retrieval[v].Pch);
            Get_Link(Retrieval[v].Link);
            Retrieval[v].Leaflink = (Retrieval[Retrieval[v].Link].Leaf != -1) ? Retrieval[v].Link : Retrieval[Retrieval[v].Link].Leaflink;
        }
        return Retrieval[v].Link;
    }

    int Go(int v, char Ch){
        int c = Ch - 'a';
        if(Retrieval[v].Go[c] == -1){
            if(Retrieval[v].Next[c] != -1) Retrieval[v].Go[c] = Retrieval[v].Next[c];
            else Retrieval[v].Go[c] = v == 0 ? 0 : Go(Get_Link(v), Ch);
        }
        return Retrieval[v].Go[c];
        /// Time Complexity : Linear
    }
    void Find_String(string s){
        int v = 0;
        for(int i = 0; i < s.sz; i++){
            v = Go(v, s[i]);
            Get_Link(v);
            int Cur = Retrieval[v].Leaf == -1 ? Retrieval[v].Leaflink : v;
            while(Cur != -1){
                Result[Retrieval[Cur].Leaf].eb(i);
                Cur = Retrieval[Cur].Leaflink;
            }
        }
    }
};


int k[N];
string Pattern[N];

Aho Comp;

