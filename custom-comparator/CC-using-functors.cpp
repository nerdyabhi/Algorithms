#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class myComparator
{
    bool operator()(int a, int b) { return a > b; }
};

int main()
{

    vector<int> arr{1, 23, 12, 4, 29, 10, 20};

    sort(arr.begin(), arr.end(), myComparator()); // basically the same thing but different thing
    // sort(arr.begin(), arr.end(), greater<int>());

    for (auto it : arr)
        cout << it << " ";
    cout << endl;

    return 0;
}