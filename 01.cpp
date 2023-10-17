#include <bits/stdc++.h>
using namespace std;

int main() {
    bool p, q; cin >> p >> q;
    
    bool conjunction = p && q;
    bool disjunction = p || q;
    bool exclusiveOr = (p || q) && !(p && q);
    bool conditional = !p || q;
    bool biconditional = (p && q) || (!p && !q);
    
    cout << "Conjunction (p AND q): " << conjunction << endl;
    cout << "Disjunction (p OR q): " << disjunction << endl;
    cout << "Exclusive OR (p XOR q): " << exclusiveOr << endl;
    cout << "Conditional (p -> q): " << conditional << endl;
    cout << "Biconditional (p <-> q): " << biconditional << endl;
    
    return 0;
}
