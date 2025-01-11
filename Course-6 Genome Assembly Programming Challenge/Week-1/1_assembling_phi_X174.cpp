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

int calculateOverlap(const string &a, const string &b) {
    int maxOverlap = 0;
    int lenA = a.size();
    int lenB = b.size();

    for (int i = 1; i <= lenA; i++) {
        bool match = true;
        for (int j = 0; j < i; j++) {
            if (a[lenA - i + j] != b[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            maxOverlap = i;
        }
    }
    return maxOverlap;
}

vector<vector<int>> precomputeOverlaps(const vector<string> &reads) {
    int n = reads.size();
    vector<vector<int>> overlapMatrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                overlapMatrix[i][j] = calculateOverlap(reads[i], reads[j]);
            }
        }
    }

    return overlapMatrix;
}

string assembleGenome(const vector<string> &reads, const vector<vector<int>> &overlapMatrix) {
    unordered_set<int> visited;
    int n = reads.size();
    string genome = reads[0];
    visited.insert(0);

    int currentRead = 0;

    while (visited.size() < n) {
        int maxOverlap = -1;
        int nextRead = -1;

        for (int i = 0; i < n; i++) {
            if (visited.count(i)) continue;
            if (overlapMatrix[currentRead][i] > maxOverlap) {
                maxOverlap = overlapMatrix[currentRead][i];
                nextRead = i;
            }
        }

        if (nextRead != -1) {
            genome += reads[nextRead].substr(maxOverlap);
            visited.insert(nextRead);
            currentRead = nextRead;
        } else {
            break;
        }
    }

    int circularOverlap = calculateOverlap(genome, genome.substr(0, 100));
    genome = genome.substr(0, genome.size() - circularOverlap);

    return genome;
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        vector<string> reads;
        string read;
        unordered_map<string,bool> mpp;

        int input_size = 1618;

        rep(i,input_size){
           
            cin >> read;

            // we do not need duplicate reads, therefore only pushing them to array when no duplicates found
            if(mpp.find(read)!=mpp.end())
            {
                continue;   
            }
            else
            {
                mpp[read]=1;
            }
            
            reads.push_back(read);
        }

        vector<vector<int>> overlapMatrix = precomputeOverlaps(reads);

        string genome = assembleGenome(reads, overlapMatrix);

        cout << genome;
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


