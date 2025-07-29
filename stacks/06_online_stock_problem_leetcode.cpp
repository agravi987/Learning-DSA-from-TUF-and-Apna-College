#include <iostream>
#include <stack>
using namespace std;

/*
    Online Stock Span:
    - Each call to next(price) returns the span of the stock's price for that day.
    - Span = number of consecutive days (including today) the price was <= today's price.
    - Uses a monotonic stack to track previous prices and their spans.
*/

class StockSpanner {
private:
    // Stack stores pairs of (price, span)
    stack<pair<int, int>> st;

public:
    // Constructor
    StockSpanner() {}

    // Returns the span for today's price
    int next(int price) {
        int span = 1;

        // Pop all prices less than or equal to current and accumulate their spans
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current price and its span
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner spanner;

    // Sample input sequence
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);

    cout << "Online stock spans:\n";
    for (int i = 0; i < n; ++i) {
        cout << spanner.next(prices[i]) << " ";
    }
    cout << endl;

    return 0;
}