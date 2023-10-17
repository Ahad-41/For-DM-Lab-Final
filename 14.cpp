#include <bits/stdc++.h>
using namespace std;

int n, x[51], y[51];
bool visited[51];
vector<int> tour;

double calculateDistance(int i, int j) {
    return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

int findNearestCity(int currentCity) {
    double minDistance = 1e9;
    int nearestCity = -1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false and i != currentCity) {
            double distance = calculateDistance(currentCity, i);
            if (distance < minDistance) {
                minDistance = distance;
                nearestCity = i;
            }
        }
    }
    return nearestCity;
}

void nearestNeighborTSP() {
    int currentCity = 1; // Start from the first city
    tour.push_back(currentCity);
    visited[currentCity] = true;

    for (int i = 2; i <= n; ++i) {
        int nearestCity = findNearestCity(currentCity);
        tour.push_back(nearestCity);
        visited[nearestCity] = true;
        currentCity = nearestCity;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    nearestNeighborTSP();

    cout << "TSP Tour: ";
    for (auto &u : tour) cout << u << " ";
    cout << endl;

    return 0;
}
