#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int interpolationSearch(vector<int> &arr, int lo, int hi, int x) {
    int pos;
    if(lo <= hi &&  x >= arr[lo] && x <= arr[hi]) {
        pos = lo + (((double)(hi - lo) / (arr[hi] -  arr[lo])) * (x - arr[lo]));
        
        if(arr[pos] == x) { // x lebih besar
            return pos;
        }
        if(arr[pos] < x) { // x lebih kecil
            return interpolationSearch(arr, pos + 1, hi, x);
        }
        if(arr[pos] > x) { // x lebih besar
            return interpolationSearch(arr, lo, pos - 1, x);
        }
    }
    return -1;
}

int nearestChair(const std::vector<int>& data, int target) {
    if (data.empty()) return -1;

    auto it = std::lower_bound(data.begin(), data.end(), target);

    if (it == data.begin()) {
        return *it;
    }

    if (it == data.end()) {
        return data.back();
    }

    int val1 = *it;
    int val2 = *(it - 1);

    if (std::abs(val1 - target) < std::abs(val2 - target)) {
        return val1;
    } else {
        return val2;
    }
}

int main () {    
    
    int n, k, x, index;
    vector<int> available;

    cout << "Jumlah Kursi tersedia: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;
        available.push_back(k);
    }
    
    cout << "Mencari Kursi No: ";
    cin >> x;


    index = interpolationSearch(available, 0, available.size()-1, x);
    if (index == -1) {
        cout << "TIDAK TERSEDIA \n";
        cout << "KURSI TERSEDIA TERDEKAT: " << nearestChair(available, x);

    }
    else {
        cout << "TERSEDIA";
        cout << "data ditemukan di " << index << endl;
    }

    return 0;
}