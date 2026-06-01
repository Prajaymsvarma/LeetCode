class Solution {
public:
    int reverse(int x) {
        int num = x;
        int rem = 0;
        int n = 0;

        while (num != 0)
        {
            rem = num % 10;

            if (n < INT_MIN / 10 || n > INT_MAX / 10)
            {
                return 0;
            }

            n = (n * 10) + rem;
            num = num / 10;
        }

        return n;
    }
}; 