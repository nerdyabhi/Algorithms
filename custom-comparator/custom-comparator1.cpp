#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool mycomparator(int a, int b)
{
    return a > b;
    // true means it won't change anything
    // false condition means it'll swap the numbers
    // easy peasy
}

int main()
{

    vector<int> arr{1, 23, 12, 4, 29, 10, 20};

    //sort(arr.begin(), arr.end(), mycomparator);
    sort(arr.begin(), arr.end(), greater<int>());

    for (auto it : arr)
        cout << it << " ";
    cout << endl;

    return 0;
}