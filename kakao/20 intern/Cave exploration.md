<h2>동굴 탐험</h2>

> 문제 : https://programmers.co.kr/learn/courses/30/lessons/67260

- path 배열로 0을 기준으로 단방향 트리를 만든다.<br>
- 단방향 트리에 order 배열을 단방향으로 추가한다.<br>

**order 배열의 규칙에 맞게 모든 방을 탐험할 수 있는지 판별하는 문제이다.**

- 왼쪽 그림과 같이 **cycle이 생기지 않는 경우** 모든 방을 탐험할 수 있는 경로가 반드시 존재한다.<br>
> 0 3 6 7 4 1 8 5

- 오른쪽 그림과 같이 **cycle이 생기는 경우** 탐험할 수 없다.<br>
  - 7을 방문하기 위해선 8을 먼저 방문해야한다.
  - 8을 방문하기 위해선 1을 먼저 방문해야한다.
  - 1을 방문하기 위해선 4를 먼저 방문해야한다.
  - 4를 방문하기 위해선 7을 먼저 방문해야한다. <- 이부분에서 cycle이 발생됨을 알 수 있다.

<img width="800" alt="스크린샷 2021-04-22 오전 11 40 40" src="https://user-images.githubusercontent.com/54436228/115647918-9ad80100-a35f-11eb-9cb4-64726c02c7bc.png">

> 해당 그림은 프로그래머스 카카오 문제에서 사용

**내가 탐색하고자 하는 노드가 나에게로 온 경로에서 이미 방문이 한 경우 cycle임을 처리한다.**<br>


```C++
bool isCycle(int n){
    nowPath[n]=true; // 현재 탐색하는 경로에 속한다.
    
    for(pair<int, bool>& next : adj[n]){
        if(nowPath[next.first]) return true; // 다음 노드 현재 경로에 벌써 속해있다면 cycle이므로 바로 return
        if(isCycle(next.first)) return true; // 현재 경로에 속하지 않았다면 next를 기준으로 탐색 시작
    }
    nowPath[n]=false; // 현재 경로의 탐색을 종료하므로 false
    return false;
}
```

위의 코드로 cycle을 찾아낼 수 있지만 효율성 테스트에서 TLE를 받는다.<br>

방의 개수 n은 최대 200,000이다.<br>
아래 트리와 같이 노드 5는 14, 15의 자식만 갖고, 노드 1,2,3,4 는 200,000개를 모두 채운 트리를 통해 TLE 발생이유를 찾을 수 있다.<br>
<img width="400" alt="스크린샷 2021-04-28 오후 3 22 07" src="https://user-images.githubusercontent.com/54436228/116355959-91eea000-a835-11eb-98ff-9253cfdd294c.png">

> 위 그림에선 노드 20부터 그리는 것을 생략했다.

order로 (14 -> 1), (14 -> 2), (14 -> 3), (14 -> 4)가 입력되면 아래와 같은 트리로 변경된다.<br>
<img width="400" alt="스크린샷 2021-04-28 오후 3 22 16" src="https://user-images.githubusercontent.com/54436228/116356393-2b1db680-a836-11eb-9caf-cfb7378936cb.png">

- 노드 1, 2, 3, 4를 탐색한 결과 cycle이 발견되지 않아 노드 5의 탐색을 시작한다.
- 노드 5의 자식인 노드 14는 1, 2, 3, 4와 연결되었기 때문에 노드 1, 2, 3, 4를 다시 탐색해야한다.
- 이런 부분 때문에 TLE가 발생된 것을 알 수 있다.

order 입력으로 인한 최악의 경우는 O(n^2) = 40,000,000,000 이다.<br>
> 모든 각각의 노드에서 자신을 제외한 모든 노드로 다시 가야되는 상황

