#include <bits/stdc++.h>
using namespace std;

double largestTriangleArea(vector<vector<int>>& points) {
    double maxArea = 0;
    int n = points.size();

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int x3 = points[k][0], y3 = points[k][1];

                // Shoelace formula
                double area = abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0;

                // Print the points and area
                cout << "Triangle: (" << x1 << "," << y1 << "), ("
                     << x2 << "," << y2 << "), ("
                     << x3 << "," << y3 << ") -> Area: " << area << endl;

                maxArea = max(maxArea, area);
            }
        }
    }

    return maxArea;
}

int main() {
    vector<vector<int>> points = {{0,0}, {0,1}, {1,0}, {1,1}};
    double maxA = largestTriangleArea(points);
    cout << "Maximum triangle area: " << maxA << endl;
}
