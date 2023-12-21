#include <stdio.h>
// Iteration 
/* 
Pseudocode:
function digit_sum_iter(n):
    sum = 0
    while n > 0:
        sum = sum + n % 10
        n = n / 10
    return sum

1. Start with a sum of 0.
2. As long as the number is greater than 0, repeat the following steps:
    - Add the last digit of the number to the sum. We can get the last digit by taking the remainder when the number is divided by 10.
    - Remove the last digit from the number. We can do this by dividing the number by 10 and discarding the remainder.
3. Once the number is 0, we added all its digits.
*/

int digit_sum_iter(int n) {
    int sum = 0;
    while (n > 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

// Recursion
/*
Pseudocode:
function digit_sum_recur(n):
    if n == 0:
        return 0
    else:
        return n % 10 + digitSum(n / 10)


1. If the number is 0, the sum of its digits is also 0.
2. If the number is not 0, the sum of its digits is the last digit plus the sum of the digits in the rest of the number. 
    We can get the last digit by taking the remainder when the number is divided by 10, and we can get the rest of the number by dividing by 10 and discarding the remainder.
3. To get the sum of the digits in the rest of the number, apply the same process again.
4. The recursion ends when the number is 0, and at that point, the sum of its digits is 0. 
    So we start with a sum of 0 and keep adding digits until there are no more digits left.
*/
int digit_sum_recur(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + digit_sum_recur(n / 10);
    }
}

int main() {
    int n = 21112023;                   
    printf("Iteration\n");
    printf("the sum of digit by iteration method is: ");
    printf("%d", digit_sum_iter(n));
    printf("\n\nRecursion\n");
    printf("the sum of digit by recursion method is: ");
    printf("%d", digit_sum_recur(n));
    return 0;
}

/*
calculate the complexity

* iteration method:
- For each digit in the number, we perform two operations: addition and division.
- so the total number of operations we perform is proportional to the number of digits => the time complexity of the algorithm is O(d).
in my case,the natural number is 21112023, it has 8 digits => the complexity is: O(8)

* recursion method:
- we also perform two operations for each digit
- However, we using recursion, we also have to consider the storage space for the recursive call stack. 
Each recursive call requires us to store some information, so we can continue from the right place after the recursive call finishes.
- we need separate storage space for each recursive call, and the number of recursive calls is proportional to the number of digits. 
=> The complexity is also O(d) because we’re still performing two operations for each digit.
similarly, the complexity of my case "21112023" is: O(8)
*/



