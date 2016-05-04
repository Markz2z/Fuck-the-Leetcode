#include <iostream>

using namespace std;

int get_k_num(int array1[], int array2[], int k) {
    if(k==1)
        return array1[0] < array2[0] ? array1[0] : array2[0];
    int half_idx = k/2;
    if(array1[half_idx-1] < array2[half_idx-1]) {
        return get_k_num(array1+half_idx, array2, k-half_idx);
    }else
        return get_k_num(array1, array2+half_idx, k-half_idx);
}

int main() {
    int array1[5] = {1,4,9,11,15};
    int array2[5] = {2,3,10,12,19};
    cout << get_k_num(array1, array2, 8) << endl;
    return 1;
}
