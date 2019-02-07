// https://www.hackerrank.com/challenges/strong-password/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    bool has[4] = {};

    for (int i = 0; i < n; i++) {
        if (password[i] >= 33 && password[i] <= 47)  has[0] = 1; // Range 33-47  is special
        if (password[i] >= 48 && password[i] <= 57)  has[1] = 1; // Range 48-57  is integers
        if (password[i] >= 65 && password[i] <= 91)  has[2] = 1; // Range 65-91  is upper
        if (password[i] >= 97 && password[i] <= 122) has[3] = 1; // Range 97-122 is lower
    }

    unsigned short total = 0;
    for (short i = 0; i < 4; i++) if (!has[i]) total++;

    return (n + total < 6) ? 6 - n : total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
