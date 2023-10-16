#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n, arr[N], dp[N];

int lis(int i) {
    if (dp[i] != -1) return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (arr[j] < arr[i]) {
            ans = max(ans, lis(j) + 1);
        }
    }
    return dp[i] = ans;
}

int lds(int i) {
    if (dp[i] != -1) return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (arr[j] > arr[i]) {
            ans = max(ans, lds(j) + 1);
        }
    }
    return dp[i] = ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = -1;
    }

    cout << "Longest Increasing Subsequence: " << lis(n-1) << endl;

    for (int i = 0; i < n; i++) dp[i] = -1; 
    cout << "Longest Decreasing Subsequence: " << lds(n-1) << endl; 
}
