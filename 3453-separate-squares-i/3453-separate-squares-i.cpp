#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;

        for (auto &sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)(sq[1] + sq[2]));
        }
        for (int iter = 0; iter < 100; iter++) {
            double mid = (low + high) / 2.0;
            double below = 0.0, above = 0.0;

            for (auto &sq : squares) {
                double y = sq[1];
                double l = sq[2];
                double top = y + l;

                if (mid >= top) {
                    below += l * l;
                } else if (mid <= y) {
                    above += l * l;
                } else {
                    below += (mid - y) * l;
                    above += (top - mid) * l;
                }
            }

            if (above > below)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
