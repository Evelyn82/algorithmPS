<h2>외벽 점검</h2>

> 문제 : https://programmers.co.kr/learn/courses/30/lessons/60062

- weak의 길이는 최대 15 : 15개의 지점에서 탐색 시작을 시작한다.
- dist의 길이는 최대 8 : 8!(=40,320)개의 경우의 수이므로 next_permutation을 이용하여 모든 경우를 다 적용시켜본다.

레스토랑의 구조는 원형이므로 weak의 마지막 지점과 weak의 시작 지점이 연결되어있다.<br>
dist(각 친구가 1시간 동안 이동가능한 거리)는 순서에 상관없이 적용가능하다.<br>
weak(레스토랑 취약 지점)은 **연속적으로 접근**해야 한다.<br>
즉, weak의 마지막 지점에서 탐색을 시작할 땐 처음 지점으로 되돌아 가야되므로 weak를 확장시켜 되돌아 가는 불편을 없앤다.<br>

<img width="650" alt="스크린샷 2021-04-27 오후 9 27 53" src="https://user-images.githubusercontent.com/54436228/116242213-aa60ab00-a7a0-11eb-9442-2bd56b9ddd51.png">

위와 같이 기존 값에 n(외벽의 길이)을 더하여 추가하면 되는데, 기존 weak 배열의 2배로마 확장하면 된다.<br>
weak 마지막 지점(10)에서 탐색을 시작할때 끝나는 점이 1바퀴 후인 마지막 지점의 이전 지점(6)이기 떄문이다.<br>
쉽게 말해 외벽의 1바퀴만 접근하면 되지, 1바퀴를 넘기는 접근은 필요는 없기 떄문이다.<br>

<h3>weak[1]=5에서 탐색 시작 + dist 순서 : 3, 4, 1, 2 일때</h3>

<img width="650" alt="스크린샷 2021-04-27 오후 9 28 02" src="https://user-images.githubusercontent.com/54436228/116242955-64f0ad80-a7a1-11eb-8023-7d524a4e6f78.png">

dist(1명이 1시간동안 이동가능한 거리) 3이 5지점에서 시작한다.<br>
5지점에서 시작하면 1시간동안 8까지 갈 수 있다.<br>
weak 5와 6을 처리할 수 있다는 의미이다.<br>

그 다음 dist4 는 weak6 이후의 지점인 weak10부터 시작하면 되고, 이는 upper_bound를 이용하여 해당 index를 바로 찾을 수 있다.<br>


<h3>weak[2]=6에서 탐색 시작 + dist 순서 : 1, 2, 3, 4 일때</h3>

<img width="650" alt="스크린샷 2021-04-27 오후 9 28 10" src="https://user-images.githubusercontent.com/54436228/116241809-43db8d00-a7a0-11eb-9812-73582c5e085c.png">

위와 같이 dist 1, 2, 3은 weak6만 처리 가능하지 다음으로 넘어갈 수 없다.<br>
upper_bound를 사용하면 dist4가 weak6부터 처리하도록 설정된다.<br>
하지만 위의 경우 weak 를 1바퀴 돌지 못하고 dist 순서가 끝나기 때문에 틀린 경우다.<br>
