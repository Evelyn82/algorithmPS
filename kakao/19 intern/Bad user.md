<h2>불량 사용자</h2>

- user_id : "frodo", "fradi", "crodo"
- banned_id : "fr*d*", "*rodo"
- 아이디들이 나열된 순서와 관계없이 아이디 목록의 내용이 동일하다면 같은 것으로 처리

위와 같이 입력이 주어졌을 떄 아래 그림과 같이 동일한 목록을 카운트하지 않는 처리해야 한다.<br>

<img width="500" alt="스크린샷 2021-04-28 오후 8 26 52" src="https://user-images.githubusercontent.com/54436228/116396383-4b626b00-a860-11eb-857a-51ecce4667a1.png">

**(frodo, crodo), (fradi, crodo), (fradi, frodo)** 로 겹치지 않는 3개의 목록이 나온다.<br>

- user_id는 최대 8개
- banned_id는 최대 8개로 user_id 개수이하의 값만 주어진다.

범위가 작으니 brute force를 적용시킨다.<br>
각각의 banned_id에 일치하는 id를 찾기 위해 모든 user_id와 비교한다. : O(n^2) = 8 * 8<br>
동일 목록을 카운트 하지 않기 위해 visited 처리를 해준다.<br>

banned_id에 일치하는 목록을 bit 연산자로 차리하고, 모든 부분이 매칭되면 set에 insert하여 count 한다.<br>
