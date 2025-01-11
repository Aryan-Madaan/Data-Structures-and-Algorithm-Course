//                                               Created by Aryan Madaan.
//---------------------------------------------------------------------------------------------------
#pragma optimize("O3",on)
#include <bits/stdc++.h>

#include <stdio.h>
using namespace std;
#define Expresso std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mod 1000000007
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long double ld;
typedef unsigned long long ull;
#define mp make_pair
#define ff first
#define ss second
#define pb(v) push_back(v)
#define INF 2e9
#define rep(i,n) for(int i =0;i<n;i++)
#define endl '\n'
const double eps = 1e-6, pi = acos(-1);
const char nl = '\n';
typedef vector<vector<int> > Matrix;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int randomize()
{
return (rand() % 1000);
}


//---------------------------------------------------------------------------------------------------

struct Edge{
    int read1;
    int overlap;
    int mismatch[2];
    int read2;
    Edge(int read_1, int read_2 = -1, int total_overlap = 0)
    {
       read1 = read_1;
       mismatch[0] =  -1;
       mismatch[1] = -1;
       read2 = read_2;
       overlap = total_overlap;
    }
};

typedef vector<Edge*> Edges;



int len_of_match(string& read1,string& read2, int* mismatch){
    rep(read_start, 100){
        int read_idx = read_start, max_mismatch_allowed = 2, num_of_mismatches = 0;

        mismatch[0] = mismatch[1] = -1;

        for(int read_2_idx=0; read_idx < 100;){
            if(read1[read_idx] != read2[read_2_idx]){
                if(num_of_mismatches < 2)
                    mismatch[num_of_mismatches] = read_idx;
                num_of_mismatches++;
            }

            ++read_idx;
            ++read_2_idx;

            if(num_of_mismatches > max_mismatch_allowed)
                break;
        }

        if(read_idx == 100)
            return 100 - read_start;
    }
    return -1;
}


Edges overLap_graph(vector<string>& reads, int n){
    Edges edges;
    set<int> visited;
    visited.insert(0);
    int curRead = 0;
    int last;
    bool finalEdge = false;

    while(visited.size() != n){
        last = edges.size();
        edges.push_back(new Edge(curRead));

        rep(i, n){
            if(visited.find(i) == visited.end()){

                int mismat[2] = {-1};
                int ovl;
                ovl = len_of_match(reads[curRead], reads[i], mismat);

                if(ovl > edges[last]->overlap){
                    edges[last]->overlap = ovl;
                    edges[last]->read2 = i;
                    edges[last]->mismatch[0] = mismat[0];
                    edges[last]->mismatch[1] = mismat[1];
                }
            }
        }

        curRead = edges[last]->read2;
        visited.insert(curRead);

        if(visited.size() == n && !finalEdge){
            visited.erase(0);
            finalEdge = true;
        }
    }
    return edges;
}

void get_new_genome(string& genome, Edges& edges, vector<string>& reads, int n){
    for(int i=0; i<edges.size(); i++){
        rep(j,2){
            int r1_num_of_mismatches = edges[i]->mismatch[j];

            if(r1_num_of_mismatches != -1){ 
                const Edge* read_1 = edges[i];
                const Edge* edge2 = edges[(i+1) % edges.size()];
                int r2_num_of_mismatches = r1_num_of_mismatches - 100 + read_1->overlap; 

                const Edge* edge3 = edges[(i+2) % edges.size()];

                int r3_num_of_mismatches = r2_num_of_mismatches - 100 + edge2->overlap;
                int r4_num_of_mismatches = r3_num_of_mismatches - 100 + edge3->overlap;

                if(r3_num_of_mismatches >= 0){
                    int mis_char1 = edge2->mismatch[0] - 100 + edge2->overlap;
                    int mis_char2 = edge2->mismatch[1] - 100 + edge2->overlap;
                    char correctChar = reads[read_1->read1][r1_num_of_mismatches];

                    if(mis_char1 != r3_num_of_mismatches && mis_char2 != r3_num_of_mismatches)
                        correctChar = reads[edge2->read2][r3_num_of_mismatches];
                    else if(r4_num_of_mismatches >= 0)
                        correctChar = reads[edge3->read2][r4_num_of_mismatches];

                    reads[read_1->read1][r1_num_of_mismatches] = reads[read_1->read2][r2_num_of_mismatches] = correctChar;
                }
            }
        }
    }
}

void final_genome_assembly(string& genome, const vector<string>& reads, int n, const Edges& edges){
    genome = reads[0];

    rep(i, edges.size()-1)
        genome += reads[edges[i]->read2].substr(edges[i]->overlap, 100 - edges[i]->overlap);

    genome = genome.substr(0, genome.size() - edges[edges.size()-1] -> overlap);
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        vector<string> reads;
        set<string> reads_unique;
        string genome;
        string read;

        while(cin >> read){
            reads_unique.insert(read);
        }

        for(auto r : reads_unique)
            reads.push_back(r);

        Edges edges = overLap_graph(reads, reads.size());

        get_new_genome(genome, edges, reads, reads.size());

        final_genome_assembly(genome, reads, reads.size(), edges);

        cout<<genome<<endl;
    }
}
/*
*/





//---------------------------------------------------------------------------------------------------
int main() {
   cout.precision(numeric_limits<double>::max_digits10);
       cout << setprecision(15) << fixed;
    Expresso
    solve();
    return 0;
}


