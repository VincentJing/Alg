#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int bp(string &s, unordered_set<string> &flag, int start)
{
    if (start == s.size())
        return 0;

    int res = 0;
    string cur;

    for (int end = start; end < s.size(); ++end)
    {
        cur.push_back(s[end]);

        if (flag.count(cur))
            continue;

        flag.insert(cur);

        res = max(res, 1 + bp(s, flag, end + 1));

        flag.erase(cur);
    }

    return res;
}

int get_nums(string s)
{
    unordered_set<string> flag;

    return bp(s, flag, 0);
}

int main()
{
    string s = "abacaba";

    int res = get_nums(s);

    cout << "Res is " << res << endl;
}
