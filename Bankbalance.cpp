#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;

    map<int, long long> acc;

    while (Q--) {
        string type;
        cin >> type;

        if (type == "CREATE") {
            int x;
            long long y;
            cin >> x >> y;

            if (acc.count(x)) {
                acc[x] += y;
                cout << "false\n";
            } else {
                acc[x] = y;
                cout << "true\n";
            }
        }

        else if (type == "DEBIT") {
            int x;
            long long y;
            cin >> x >> y;

            if (!acc.count(x) || acc[x] < y)
                cout << "false\n";
            else {
                acc[x] -= y;
                cout << "true\n";
            }
        }

        else if (type == "CREDIT") {
            int x;
            long long y;
            cin >> x >> y;

            if (!acc.count(x))
                cout << "false\n";
            else {
                acc[x] += y;
                cout << "true\n";
            }
        }

        else if (type == "BALANCE") {
            int x;
            cin >> x;

            if (!acc.count(x))
                cout << -1 << "\n";
            else
                cout << acc[x] << "\n";
        }
    }

    return 0;
}
