<h2>메뉴 리뉴얼</h2>

> 문제 : https://programmers.co.kr/learn/courses/30/lessons/72411

- 최대 주문은 20가지이다.
- 1개의 주문당 최대 10개까지만 가능하다.
- course 는 2부터 10이하로 주어진다.

course가 2부터 10까지 주어졌고, 20개의 주문 모두 10가지씩 했을 떄의 경우의 수는 다음과 같다.<br>

<img width="700" alt="스크린샷 2021-04-26 오후 9 44 52" src="https://user-images.githubusercontent.com/54436228/116084343-a9fcdd00-a6d8-11eb-8886-26d1b6717eb0.png">

길이가 10인 1개의 주문으로 2부터 10까지의 조합의 총 개수는 1013가지이다.<br>
최대 20개의 주문일 떄는 1013 X 20 = 20260 가지이다.<br>
최악의 경우 20260가지이므로 brute force로 해결가능하다.<br>

메뉴를 골라내는 것은 순서에 상관없는 조합이며, map에 적용시킬땐 sorted 상태로 insert한다.<br>
map 보다 unordered_map을 사용하여 더 빠른 시간에 해결가능하다.<br>
