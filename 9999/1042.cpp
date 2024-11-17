#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

#define A 0
#define C 1
#define G 2
#define T 3

using namespace std;

string DNA;
unordered_map<int, int> codonTable;
int _dp[2500][2500];

int dp(int s, int e)
{
    if (_dp[s][e] != 0)
        return _dp[s][e];
    if (e - s <= 3)
    {
        if (e - s == 3)
        {
            int codon = parseCodon(DNA.substr(s, 3));
            if (codonTable.find(codon) != codonTable.end())
            {
                return 1;
            }
        }
        return 0;
    }

    int codon = parseCodon(DNA.substr(s, 3));

    if (codonTable.find(codon) != codonTable.end())
    {
        return 1 + dp(s + 3, e);
    }
    else
    {
        return max(dp(s + 1, e), dp(s, e));
    }
}

int parseNucleotide(char nucleotide)
{
    switch (nucleotide)
    {
    case 'A':
        return A;
    case 'C':
        return C;
    case 'G':
        return G;
    case 'T':
        return T;
    }
    throw "Invalid nucleotide";
}

int parseCodon(string codon)
{
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        ret <<= 2;
        ret |= parseNucleotide(codon[i]);
    }
    return ret;
}

int hashString(string str)
{
    int hash = 0;
    int m = 1e9 + 9;
    int p = 31;
    for (int i = 0; i < str.length(); i++)
    {
        hash = (hash * p + str[i] - 'a' + 1) % m;
    }
    return hash;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int codons;

    cin >> DNA;
    cin >> codons;

    for (int i = 0; i < codons; i++)
    {
        string codonKey, codonValue;
        cin >> codonKey >> codonValue;
        codonTable[parseCodon(codonKey)] = hashString(codonValue);
    }
}