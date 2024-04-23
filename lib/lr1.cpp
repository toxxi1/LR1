#include "lr1.h"
using namespace std;

bool is_decreasing(vector<int> arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void replace_negatives(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < 0) {
            arr[i] *= arr[i];
        }
    }
}


pair <bool, vector<int>> abc(vector<int>& arr) {
    bool is_decreasing_order = is_decreasing(arr);
    if (is_decreasing_order) {
        return make_pair(is_decreasing_order, arr);
    }
    else {
        replace_negatives(arr);
        return make_pair(is_decreasing_order, arr);
    }
}
