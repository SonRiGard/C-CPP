#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr1 = &arr[4];  // Points to the last element (50)
    int *ptr2 = &arr[1];  // Points to the second element (20)

    // Subtracting pointers
    int diff = ptr1 - ptr2;  // Difference in number of elements between ptr1 and ptr2

    printf("Difference between ptr1 and ptr2: %d\n", diff); // Should print 3

    return 0;
}
