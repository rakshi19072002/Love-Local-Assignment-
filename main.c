#include <stdio.h>
#include <stdlib.h>
void findElements(int nums[], int n) {
    if (n == 0) return; // Empty array
    int count1 = 0, count2 = 0, candidate1 = nums[0], candidate2 = nums[0];
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate1)
            count1++;
        else if (nums[i] == candidate2)
            count2++;
        else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate1)
            count1++;
        else if (nums[i] == candidate2)
            count2++;
    }
    if (count1 > n / 3)
        printf("%d ", candidate1);
    if (count2 > n / 3)
        printf("%d ", candidate2);
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *nums = (int *)malloc(size * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Output: ");
    findElements(nums, size);
    free(nums); // Free dynamically allocated memory
    return 0;
}

/*
The algorithm used in the provided C code is called the Boyer-Moore Majority Vote algorithm. Here's how it works:

Initialization:
Two candidate elements (`candidate1` and `candidate2`) and their corresponding counters (`count1` and `count2`) are initialized.
The counters keep track of the frequency of the candidate elements.
First Iteration:
The algorithm iterates through the array.
For each element in the array:
If the element matches either `candidate1` or `candidate2`, the respective counter is incremented.
If it doesn't match either candidate and one of the counters is at zero, the new element becomes a candidate with its counter set to 1.
If neither counter is zero, both counters are decremented.
Second Iteration:
The algorithm reiterates through the array to count the occurrences of the identified candidates (`candidate1` and `candidate2`).
Verification:
After counting the occurrences, it checks whether each candidate appears more than ⌊ n/3 ⌋ times in the array.
If so, it prints the candidate(s) that satisfy this condition.
The Boyer-Moore Majority Vote algorithm efficiently identifies potential candidates for elements that appear more than ⌊ n/3 ⌋ times in an array by discarding pairs of different elements and progressively narrowing down the candidates based on their frequency in the array.
*/













