#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    int comparison;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            comparison = i+1;
            break;
        }
    }
    return comparison;
}

int binarySearch(int arr[], int n, int x) {
    int comparison = 1;
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) break;
        else if (arr[mid] > x) high = mid-1;
        else low = mid+1;
        comparison++;
    }
    return comparison;
}

int main()
{
    int n, x; cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Number of Comparison in Linear Search: " << linearSearch(arr, n, x) << endl;
    cout << "Number of Comparison in Binary Search: " << binarySearch(arr, n, x) << endl;
}