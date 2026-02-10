#include <stdio.h>

int main() {
    int n;
    int arr[100];

   
    scanf("%d", &n);

    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int i = 0;
    int j = n - 1;
    int temp;

   
    while(i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }

    
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
