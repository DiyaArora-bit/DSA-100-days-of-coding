#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int x;
    scanf("%d", &x);

    int low = 0, high = n - 1;
    int found = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == x) {
            found = 1;
            break;
        } else if(arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if(found)
        printf("FOUND\n");
    else
        printf("NOT FOUND\n");

    return 0;
}