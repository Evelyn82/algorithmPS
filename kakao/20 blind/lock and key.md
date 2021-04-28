<h2>자물쇠와 열쇠</h2>

> 문제 : https://programmers.co.kr/learn/courses/30/lessons/60059 

key와 lock의 최대 크기는 20인 2차원 배열이며, 크기가 작으니 brute force 를 적용한다.<br>

열쇠의 일부분이 자물쇠의 범위 밖에 있는채로 일치해도 정답이므로 **자물쇠를 margin**시킨다.<br>

<img width="450" alt="스크린샷 2021-04-27 오후 2 40 13" src="https://user-images.githubusercontent.com/54436228/116190976-7ff1fc00-a766-11eb-813f-3e2a6cc19d94.png">

위 그림처럼 margin하여 겹칠 수 있게 여분의 공간을 만든다.<br>


*** 

<h3>margin과 padding은 다르다.</h3>
<img width="403" alt="스크린샷 2021-04-27 오후 1 30 53" src="https://user-images.githubusercontent.com/54436228/116190490-b5e2b080-a765-11eb-93bd-3c7275a29ae8.png">

> 해당 그림은 https://coding-factory.tistory.com/187 에서 사용
