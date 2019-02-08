// https://www.hackerrank.com/challenges/time-conversion/problem
// Solution is the timeConversion function, rest is pre-filled

#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    short hour = stoi(s.substr(0, 2));
    bool  pm   = (s[8] == 'P');

    //  12:00am
    if (hour == 12 && !pm)
        return "00" + s.substr(2, 6);
    //        1:00am - 11:00am      12:00pm
    else if ((hour < 12 && !pm) || (hour == 12 && pm))
        return s.substr(0, 8);
    // 1pm - 11pm
    else 
        return to_string(hour + 12) + s.substr(2, 6);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
