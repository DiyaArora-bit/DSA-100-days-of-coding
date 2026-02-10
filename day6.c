#include <stdio.h>

int main() {
    int n;
    int arr[100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int j = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    for(int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
