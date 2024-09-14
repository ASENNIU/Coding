#include <bits/stdc++.h>
using namespace std;

void process()
{
    int length;
    cin >> length;
    vector<int> arr1(length + 1), arr2(length + 1), result;
    for (int idx = 1; idx <= length; idx++)
        cin >> arr1[idx], arr1[idx]--;
    int count1 = 0, count0 = 0, transitions = 0, temp1 = 0, temp0 = 0;
    for (int idx = 1; idx <= length; idx++)
    {
        cin >> arr2[idx];
        if (arr2[idx] == 0)
        {
            result.push_back(arr1[idx]);
            if (arr1[idx])
                count1++;
            else
                count0++;
        }
        else
        {
            if (arr1[idx])
                temp1++;
            else
                temp0++;
        }
    }
    if (temp1 && !count1)
    {
        result.push_back(1);
    }
    if (temp0 && !count0)
    {
        result.push_back(0);
    }
    for (int idx = 1; idx < result.size(); idx++)
    {
        if (result[idx] != result[idx - 1])
            transitions++;
    }

    cout << transitions << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases--)
        process();
    return 0;
}