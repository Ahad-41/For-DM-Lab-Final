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

set<string> Union(set<string> &A, set<string> &B) {
    set<string> unionSet;
    for (auto &u : A ) unionSet.insert(u);
    for (auto &u : B) unionSet.insert(u);
    return unionSet;
}

set<string> Intersection(set<string> &A, set<string> &B) {
    set<string> intersectionSet;
    for (auto &u : A) {
        if (B.find(u) != B.end()) {
            intersectionSet.insert(u);
        }
    }
    return intersectionSet;
}

void PrintUnionSet(set<string> &unionSet) {
    cout << "A ∪ B = {";

    bool first = true;
    for (auto &u : unionSet) {
        cout <<  (first ? "" : ", ") << u;
        first = false;
    }
    cout << "}\n";
}

void PrintIntersectionSet(set<string> &intersectionSet) {
    cout << "A ∩ B = {";

    bool first = true;
    for (auto &u : intersectionSet) {
        cout << (first ? "" : ", ") << u;
        first = false;
    }
    cout << "}\n";
}

int main()
{
    set<string> A = GetInput();
    set<string> B = GetInput();

    set<string> unionSet = Union(A, B);
    set<string> intersectionSet = Intersection(A, B);

    PrintUnionSet(unionSet);
    PrintIntersectionSet(intersectionSet);

    return 0;
}
