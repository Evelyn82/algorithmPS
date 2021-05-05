#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());

    int answer = 0;
    int low = 1, high = distance;
    while (low <= high) {
        int mid = (low + high) / 2;

        int del = 0, prev = 0;
        for (int i = 0; i < rocks.size(); ++i) {
            if (mid > rocks[i] - prev) del++;
            else prev = rocks[i];
        }
        if (distance - prev < mid) del++;

        if (del <= n) {
            low = mid + 1;
            answer = max(answer, mid);
        }
        else high = mid-1;
    }
    return answer;
}
