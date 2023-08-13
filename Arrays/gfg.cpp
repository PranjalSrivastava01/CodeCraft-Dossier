#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n = 0;
    cin >> n;
    int k = 1;
    while (n >= k)
    {
        n = n - k;
        k++;
    }
    cout << k-1;
}
