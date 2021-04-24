<h2>트리 트리오 중간값</h2>

[문제](https://programmers.co.kr/learn/courses/30/lessons/68937)

<img width="300" alt="트리 트리오 중간값" src="https://user-images.githubusercontent.com/54436228/115168357-927c8d80-a0f5-11eb-8b20-5f33e40aad19.png">

> 위 사진은 https://yabmoons.tistory.com/597 에서 사용


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
