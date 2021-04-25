<h2>트리 트리오 중간값</h2>

문제 : https://programmers.co.kr/learn/courses/30/lessons/68937


- 탐색 1 : 임의의 노드 1에서 가장 먼 노드를 찾는다 : 노드4
- 탐색 2 : 노드 4에서 가장 먼 노드를 찾는다 : 노드 2

<img width="400" alt="스크린샷 2021-04-24 오후 12 09 17" src="https://user-images.githubusercontent.com/54436228/115945275-f0dead00-a4f5-11eb-9df2-8f106a3c908c.png">

위의 경우만 보면 2번의 탐색이면 해결된다. 하지만 아래의 반례를 통해 2번의 탐색만으로 해결할 수 없음을 알 수 있다.<br>
<img width="600" alt="스크린샷 2021-04-24 오후 12 09 27" src="https://user-images.githubusercontent.com/54436228/115945279-f76d2480-a4f5-11eb-8946-c366df33f988.png">

- 탐색 1 : 임의의 노드 1에서 가장 먼 노드를 찾는다 : 노드 4, 노드 5 (총 2개를 찾았다.)
- 탐색 2 : 그중 1개인 노드 5에서 가장 먼 노드르 찾는다 : 노드 2 (이전 단계에서 여러 노드 중 1개를 고를땐 아무거나 골라도 된다.)
- 탐색 3 : 노드 2에서 가장 먼 노드를 찾는다 : 노드 4, 노드 5

탐색 2까지만 했다면 지름 - 1 을 반환 : WA<br>
하지만 탐새 3까지하니 지름 2개를 발견했으니 지름을 반환 : AC<br>

<h5>왼쪽은 struct로 구현했을 때의 결과</h5>

```C++
struct Node{
  vector<Node*> child;
};
```
<h5>오른쪽은 vector로 구현했을 때의 결과</h5>

```C++
vector<vector<int>> adj 
```

<img width="410" alt="스크린샷 2021-04-24 오전 11 43 28" src="https://user-images.githubusercontent.com/54436228/115944750-aa3b8380-a4f2-11eb-9b8c-16d1decab8e7.png">

vector로만 구현했을때가 조금 더 빠르다.<br>
