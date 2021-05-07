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

<h3>2개의 차가 m이상이면서 제일 작은 값</h3>

문제 : [2230 수 고르기](https://www.acmicpc.net/problem/2230)

2개의 차가 m이상일떄만 정답이 될 수 있으므로 low와 high 둘다 시작점 0에서 시작한다.<br>

1. 둘의 차 diff가 m보다 작을땐 high를 올려 더 큰 값을 찾는다. (diff가 m이상이 될때까지 high가 증가)
2. diff가 m이상이라는 것은 정답이 될 수 있는 조건이 되었다는 의미이므로 answer를 update하고 low를 증가 시켜 diff를 작게 만든다. (1번 조건에서 high를 증가시키면서 diff를 크게 만들기 때문에 이 지점에선 diff를 감소시키는 방향으로 만든다.)

```C++
    low = 0, high = 0;
    
    while(low <= high && high < v.size()){
        int diff = v[high]-v[low];
        if(diff >= m){  // 2
            answer = min(answer, diff);
            if(answer == m) break;
            low++;
        }
        else high++; // 1
    }
    return answer;
```

- while(low <= high) 는 low와 high가 같은 경우 즉, 1개의 원소값으로도 값을 처리할 수 있는 경우에 작성한다.
- while(low < high) 는 서로 다른값으로만 처리해야하는 경우이다.


