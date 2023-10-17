#include <bits/stdc++.h>
using namespace std;

int n, r, arr[500];

void permutation(int arr[], int l, int r)  { 
    if (l == r) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
        return;
    }  
    for (int i = l; i <= r; i++)  { 
        swap(arr[l], arr[i]); 
        permutation(arr, l+1, r); 
        swap(arr[l], arr[i]); 
    } 
} 

void combination(int arr[], int n, int r, int index, int data[], int i) {
	if (index == r) {
		for (int j = 0; j < r; j++) cout << data[j] << " ";
		cout << endl;
		return;
	}

	if (i >= n) return;

	data[index] = arr[i];
	combination(arr, n, r, index + 1, data, i + 1);
	combination(arr, n, r, index, data, i+1);
}

int main()
{
    cin >> n >> r;
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Permutation\n";
    permutation(arr, 0, n-1);

    int data[r];
    cout << "\nCombination\n";
	combination(arr, n, r, 0, data, 0);
    
	return 0;
}

/*
1 2 3 -- r = 2

1 2
2 1
1 3
3 1
2 3
3 2

r-com
1 2
1 3
2 3
*/
