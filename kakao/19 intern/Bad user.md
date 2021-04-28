<h2>불량 사용자</h2>

- user_id : "frodo", "fradi", "crodo"
- banned_id : "fr*d*", "*rodo"
- 아이디들이 나열된 순서와 관계없이 아이디 목록의 내용이 동일하다면 같은 것으로 처리

위와 같이 입력이 주어졌을 떄 아래 그림과 같이 동일한 목록을 카운트하지 않는 처리해야 한다.<br>

<img width="500" alt="스크린샷 2021-04-28 오후 8 26 52" src="https://user-images.githubusercontent.com/54436228/116396383-4b626b00-a860-11eb-857a-51ecce4667a1.png">

**(frodo, crodo), (fradi, crodo), (fradi, frodo)** 로 겹치지 않는 3개의 목록이 나온다.<br>

- user_id는 최대 8개
- banned_id는 최대 8개로 user_id 개수이하의 값만 주어진다.
