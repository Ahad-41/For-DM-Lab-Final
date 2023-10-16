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

void PrintComplementSet(set<string> &U, set<string> &A) {
    set<string> complement;
    for (auto &u : U) {
        if (A.find(u) == A.end()) complement.insert(u);
    }

    cout << "\n\nComplement Set = {";

    bool first = true;
    for (auto &u : complement) {
        cout <<  (first ? "" : ", ") << u;
        first = false;
    }
    cout << "}\n";
}

int main()
{
    set<string> U = GetInput();
    set<string> A = GetInput();

    PrintComplementSet(U, A);

    return 0;
}