#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll nCr(int n, int r) {
    double value = 1;
    for (int i = 1; i <= r; i++){
        value = value * (n - r + i) / i;
    }
    return (ll)value;
}

int main() {
    ll totalHands = nCr(52, 5);
    double probability;

    probability = (13 * nCr(4, 1) * nCr(12, 4)) / (totalHands *  1.0);
    cout << "High Card: " << probability << endl;

    probability = (13 * nCr(4, 2) * nCr(12, 3)) / (totalHands *  1.0);
    cout << "One Pair: " << probability << endl;

    probability = (nCr(13, 2) * nCr(4, 2) * nCr(4, 2) * nCr(11, 1)) / (totalHands *  1.0);
    cout << "Two Pair: " << probability << endl;

    probability = (13 * nCr(4, 3) * nCr(12, 2)) / (totalHands *  1.0);
    cout << "Three of a Kind: " << probability << endl;

    probability = (10 * pow(4, 5)) / (totalHands *  1.0);
    cout << "Straight: " << probability << endl;

    probability = (nCr(4, 1) * nCr(13, 5) - 10 * 4) / (totalHands *  1.0);
    cout << "Flush: " << probability << endl;

    probability = (nCr(13, 1) * nCr(4, 3) * nCr(12, 1) * nCr(4, 2)) / (totalHands *  1.0);
    cout << "Full House: " << probability << endl;

    probability = (13 * nCr(4, 4) * nCr(12, 1)) / (totalHands *  1.0);
    cout << "Four of a Kind: " << probability << endl;

    probability = (10 * 4) / (totalHands *  1.0);
    cout << "Straight Flush: " << probability << endl;

    probability = 4 / (totalHands *  1.0);
    cout << "Royal Flush: " << probability << endl;
    
    return 0;
}
