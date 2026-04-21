#include <bits/stdc++.h>
using namespace std;

bool solve(vector<char>& letters, unordered_map<char, int>& mp,
           vector<bool>& used, string a, string b, string c) {

    // If all letters assigned
    if (letters.empty()) {
        auto getNum = [&](string s) {
            long long num = 0;
            for (char ch : s)
                num = num * 10 + mp[ch];
            return num;
        };

        // Leading zero check
        if (mp[a[0]] == 0 || mp[b[0]] == 0 || mp[c[0]] == 0)
            return false;

        if (getNum(a) + getNum(b) == getNum(c)) {
            cout << "Solution:\n";
            for (auto &p : mp)
                cout << p.first << " = " << p.second << endl;
            return true;
        }
        return false;
    }

    char ch = letters.back();
    letters.pop_back();

    for (int d = 0; d <= 9; d++) {
        if (!used[d]) {
            mp[ch] = d;
            used[d] = true;

            if (solve(letters, mp, used, a, b, c))
                return true;

            used[d] = false;
            mp.erase(ch);
        }
    }

    letters.push_back(ch);
    return false;
}

int main() {
    string a, b, c;
    cout << "Enter word1: ";
    cin >> a;
    cout << "Enter word2: ";
    cin >> b;
    cout << "Enter result: ";
    cin >> c;

    // Collect unique letters
    set<char> s;
    for (char ch : a) s.insert(ch);
    for (char ch : b) s.insert(ch);
    for (char ch : c) s.insert(ch);

    if (s.size() > 10) {
        cout << "Too many unique letters (max 10 allowed)\n";
        return 0;
    }

    vector<char> letters(s.begin(), s.end());
    unordered_map<char, int> mp;
    vector<bool> used(10, false);

    if (!solve(letters, mp, used, a, b, c))
        cout << "No solution found\n";

    return 0;
}