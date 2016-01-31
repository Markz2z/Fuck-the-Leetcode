#include "stdio.h"
#include "stdlib.h"

int binary_search(int* num, int length, int target) {
    int low = 0;
    int high = length-1;
    int mid;
    for(mid=(high+low)/2;high>=low;mid=(high+low)/2) {
        if(num[mid]>target) {
            high = mid-1;
        }else if(num[mid]<target) {
            low = mid+1;
        }else {
            return 1;
        }
    }
    return 0;
}

int main() {
    int num[10] = {1, 10, 100, 102, 105, 107, 110, 115, 567, 1026};
    printf("%d\n", binary_search(num, 10, 108));   

}
