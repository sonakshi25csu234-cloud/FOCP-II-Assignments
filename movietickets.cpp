#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;

    map<int, set<int> > booked;
    map<int, int> count;

    while (Q--) {
        string type;
        cin >> type;

        if (type == "BOOK") {
            int x, y;
            cin >> x >> y;

            if (booked[y].count(x) || count[y] == 100)
                cout << "false\n";
            else {
                booked[y].insert(x);
                count[y]++;
                cout << "true\n";
            }
        }

        else if (type == "CANCEL") {
            int x, y;
            cin >> x >> y;

            if (!booked[y].count(x))
                cout << "false\n";
            else {
                booked[y].erase(x);
                count[y]--;
                cout << "true\n";
            }
        }

        else if (type == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;

            if (booked[y].count(x))
                cout << "true\n";
            else
                cout << "false\n";
        }

        else if (type == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;

            cout << 100 - count[y] << "\n";
        }
    }

    return 0;
}
