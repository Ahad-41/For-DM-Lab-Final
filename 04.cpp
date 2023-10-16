#include <bits/stdc++.h>
using namespace std;

bool IsCharecterOrDigit(char ch) {
    if (ch >= '0' and ch <= '9') return true;
    if (ch >= 'A' and ch <= 'Z') return true;
    if (ch >= 'a' and ch <= 'z') return true;
    return false;
}

set<string> GetInput() {
    string s;
    getline(cin, s);
    int n = s.size();

    set<string> elements;

    for (int i = 3; i < n; i++) {
        if (IsCharecterOrDigit(s[i])) {
            string currElement;
            while (IsCharecterOrDigit(s[i])) {
                currElement += s[i];
                i++;
            }
            elements.insert(currElement);
        }
    }

    return elements;
}

void PrintCartesianProduct(set<string> &A, set<string> &B) {
    cout << "A X B = ";
    bool first = true;
    for (auto &u : A) {
        for (auto &v : B) {
            if (!first) cout << ", ";
            cout << "{" << u << ", " << v << "}";
            first = false;
        }
    }
}

set<string> Difference(set<string> &A, set<string> &B) {
    set<string> difference;
    for (auto &u : A) {
        if (B.find(u) == B.end()) {
            difference.insert(u);
        }
    }
    return difference;
}

set<string> Union(set<string> &A, set<string> &B) {
    set<string> unionSet;
    for (auto &u : A ) unionSet.insert(u);
    for (auto &u : B) unionSet.insert(u);
    return unionSet;
}

void PrintSymmetricDifference(set<string> &A, set<string> &B) {
    set<string> firstSet = Difference(A, B);
    set<string> secondSet = Difference(B, A);
    set<string> unionSet = Union(firstSet, secondSet);

    cout << "\n\nSymmetric difference = {";

    bool first = true;
    for (auto &u : unionSet) {
        cout <<  (first ? "" : ", ") << u;
        first = false;
    }
    cout << "}\n";
}

int main()
{
    set<string> A = GetInput();
    set<string> B = GetInput();

    PrintCartesianProduct(A, B);
    PrintSymmetricDifference(A, B); // A ∆ B = (A - B) ∪ (B - A)

    return 0;
}
