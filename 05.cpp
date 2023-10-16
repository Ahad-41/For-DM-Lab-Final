#include <bits/stdc++.h>
using namespace std;

bool IsCharecterOrDigit(char &ch) {
    if (ch >= '0' and ch <= '9') return true;
    if (ch >= 'A' and ch <= 'Z') return true;
    if (ch >= 'a' and ch <= 'z') return true;
    return false;
}

vector<string> GetInput() {
    string s;
    getline(cin, s);
    int n = s.size();

    vector<string> elements;

    for (int i = 3; i < n; i++) {
        if (IsCharecterOrDigit(s[i])) {
            string currElement;
            while (IsCharecterOrDigit(s[i])) {
                currElement += s[i];
                i++;
            }
            elements.push_back(currElement);
        }
    }

    return elements;
}

void PrintAllSubset(vector<string> &elements) {
    int n = elements.size();
    int totalSubSet = (1 << n);
    cout << "|P(A)| = " << totalSubSet << endl;
    cout << "Subset of A = ";

    for (int i = 0; i < (1 << n); i++) {
        cout << "{";
        bool first = true;

        for (int j = 0; j < n; j++) {
            int check = i & (1 << j);
            if (check) {
                cout << (first ? "" : ", ") << elements[j];
                first = false;
            }
        }

        cout << (i == totalSubSet - 1 ? "}\n" : "}, ");
    }
}

int main()
{
    vector<string> elements = GetInput();
    PrintAllSubset(elements);

    return 0;
}
