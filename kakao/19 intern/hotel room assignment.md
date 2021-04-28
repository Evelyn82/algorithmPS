<h2>호텔 방 배정</h2>

> 문제 : https://programmers.co.kr/learn/courses/30/lessons/64063

코드작성보다 구현 방법을 찾는 게 중요하다는 것을 다시 한번 깨닫게 해준 문제다.<br>
알고리즘 처음 시작했을 땐 무작정 코드짜면서 고쳐나갔는데, 문제가 어려워지면서 잘못된 방법이라고 깨달았다.<br>
이 문제도 방법 찾는 데 오래 걸렸지만, 코드 작성은 10분도 안 걸렸다.<br>

A ~ F손님이 원하는 방 번호는 다음과 같다.<br>
<img width="264" alt="스크린샷 2021-04-26 오전 1 33 10" src="https://user-images.githubusercontent.com/54436228/116001434-61d5b000-a62f-11eb-92f1-6fe08637b137.png">

방 번호는 유일한 값이므로 map 을 사용한다.<br>
``` C++
map<long long, long long> mp;
```
map의 key는 방 번호이다.<br>
map의 value는 고객이 아니라 **key값인 방 번호를 기준으로 다음으로 사용가능한 방 번호**이다.<br>

<h3>A, B, C 고객은 자신이 원하는 방에 배정 받을 수 있다.</h3>
<img width="400" alt="스크린샷 2021-04-26 오전 1 38 40" src="https://user-images.githubusercontent.com/54436228/116001640-5a62d680-a630-11eb-843f-493ef6d3d1d6.png">

1, 3, 4는 이미 배정된 방이고 1이 가리키는 2번방은 **1번방을 배정받고 싶은 고객에겐 2번방을 배정한다**라는 의미이다.<br><br>

<h3>D 고객은 이미 배정이 완료된 1번방을 원한다.</h3>

1번방이 가리키는 2번방으로 배정하며 되고 그 결과는 다음과 같다.<br>

<img width="400" alt="스크린샷 2021-04-26 오전 1 46 50" src="https://user-images.githubusercontent.com/54436228/116001830-934f7b00-a631-11eb-8f15-9430ae8e2c5f.png"><br>


<h3>E 고객은 이미 배정이 완료된 3번방을 원한다.</h3>
<img width="350" alt="스크린샷 2021-04-26 오전 1 39 02" src="https://user-images.githubusercontent.com/54436228/116001700-b75e8c80-a630-11eb-9f40-0f26df0c8770.png">

findRoom 함수를 통해 3번방이 가리키는 4번방, 4번방이 가리키는 5번방을 다시 3번방이 가리키도록 한다.<br>
즉, 고객 E는 3번방 다음으로 배정받을 수 있는 5번방을 배정하면 되고 그 결과는 다음과 같다.<br>

<br><img width="408" alt="스크린샷 2021-04-26 오전 1 47 20" src="https://user-images.githubusercontent.com/54436228/116001827-8cc10380-a631-11eb-84ae-fb2ba49c131b.png"><br>


<h3>F 고객은 이미 배정이 완료된 1번방을 원한다.</h3>

findRoom 함수를 통해 6번방을 배정받으며 그 결과는 다음과 같다.<br>
<img width="550" alt="스크린샷 2021-04-26 오전 1 47 26" src="https://user-images.githubusercontent.com/54436228/116001899-e9242300-a631-11eb-98e4-6f8c3c2edd6a.png">


