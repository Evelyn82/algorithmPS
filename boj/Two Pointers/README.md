<h2>two pointer (sliding window)</h2>

2개의 지점을 움직여가며 O(N) 시간복잡도로 모든 범위를 탐색하는 알고리즘이다.<br>

<h3>2개의 합이 0에 가까운 값을 찾는다.</h3>

문제 : [2470 두 용액](https://www.acmicpc.net/problem/2470)

정렬된 상태를 보면 음수로 시작하여 양수로 끝난다.<br>
1. low를 시작점에 high를 끝점에 두고 두 지점의 합 sum을 구한다.
2. 현재 정답 answer보다 0에 더 가까운 수라면 update를 해야한다. 
3. 두 지점의 합 sum이 0 보다 크다는 것은 **abs(high) > abs(low)** 이므로 high를 -- 연산한다.
4. 두 지점의 합 sum이 0 보다 작다는 것은 **abs(low) > abs(high)** 이므로 low를 ++ 연산한다.

```C++
    low = 0, high = v.size()-1;
    
    while(low < high){
        int diff = v[low] + v[high];  // 1
        
        if(answer > abs(diff)) {  // 2
            answer = abs(diff);
            if(answer==0) break;
        }
        if(diff > 0) high--;  // 3
        else low++; // 4
    }
    return answer;
```

<h3>3개의 합이 0에 가까운 값을 찾는다.</h3>

문제 : [2473 새 용액](https://www.acmicpc.net/problem/2473)

위 2470번의 응용이며 한 지점 x를 기준으로 **low = x+1, high = N-1** 으로 설정하여 위 방법으로 두 지점을 찾아내면 된다.<br>

***

<h3>2개의 차가 M이상이면서 제일 작은 값</h3>

```C++
    low = 0, high = 0;
    
    while(low <= high && high < v.size()){
        int diff = v[high]-v[low];
        if(diff >= m){
            answer = min(answer, diff);
            if(answer == m) break;
            low++;
        }
        else high++;
    }
    return answer;
```

