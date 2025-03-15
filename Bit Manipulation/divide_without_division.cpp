// Divide two integers without using multiplication, division and mod operator


class Solution {
    public:
        int divide(int dividend, int divisor) {
            if (dividend == divisor) return 1; // Edge case
    
            // Handle overflow case separately
            if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    
            bool sign = (dividend < 0) == (divisor < 0); // True if both have the same sign
    
            long long n = abs((long long)dividend); // Convert to long long before abs()
            long long d = abs((long long)divisor);
            long long ans = 0;
    
            while (n >= d) {
                int count = 0;
                while (n >= (d << (count + 1))) {
                    count++;
                }
                ans += (1LL << count);
                n -= (d << count);
            }
    
            return sign ? ans : -ans;
        }
    };
    