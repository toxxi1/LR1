#include <iostream>
#include <string>
#include <vector>

#include <lib/lr1.h>
using namespace std;

int main() {
    vector<int> arr = { 1, 1, 1, 1, 1, };

    pair<int, vector<int>> result = abc(arr);
    if (result.first) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    for (int num : result.second) {
        cout << num << " ";
    }
    return 0;
}
