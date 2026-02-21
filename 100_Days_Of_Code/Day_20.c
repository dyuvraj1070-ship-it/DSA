#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefix_sum = 0;
    long long count = 0;

    // Using a large range for simplicity
    // (Assuming sum range won't exceed ±100000)
    int size = 200001;
    long long freq[size];
    
    for(int i = 0; i < size; i++)
        freq[i] = 0;

    int offset = 100000;  // To handle negative sums

    freq[offset] = 1;  // prefix_sum = 0 initially

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        count += freq[prefix_sum + offset];
        freq[prefix_sum + offset]++;
    }

    printf("%lld\n", count);

    return 0;
}