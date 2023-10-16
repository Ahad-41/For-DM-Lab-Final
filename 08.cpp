#include <bits/stdc++.h>
using namespace std;

int recursiveWay, iterativeWay;
int fibonacci_recursive(int n) {
    recursiveWay++;
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_iterative(int n) {
    if (n <= 1) return n;
    iterativeWay = 0;

    int a = 0, b = 1, result = 0;
    for (int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;
        b = result;
        iterativeWay++;
    }
    return result;
}



int main() {
    int n; cin >> n;

    int num = fibonacci_iterative(n);
    num = fibonacci_recursive(n);

    cout << "The number of operations in recursively: " << recursiveWay << endl;
    cout << "The number of operations in iteratively: " << iterativeWay << endl;
    return 0;
}
