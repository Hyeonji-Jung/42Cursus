# test head1
## head 2

기능구현목록

[X] 스택 구현 (오늘)
    [X] 구조체 구조 짜기 (모든 정보 다 담고 있는)
    [X] 스택 노드 만들기
    [X] 어떤 변수 어디다 놓을지

[X] 인자 받아와서 파싱

[X] ra rb 뭐시기등 만들기

[ ] 예외처리 (내일)
    [X] 빈 문자열
    [X] 파라미터 없는 경우
    [X] 숫자 아닌 파라미터
    [ ] 유효하지 않은 명령
    [X] int_min / int_max 가 각각 여러번 들어올 시 중복검사 등이 잘 되는지

[ ] 함수 나누기
    [X] 메인 함수 - 매개변수 받아와서 배열이랑 스택에 저장, 배열 정렬 함수 호출, 재귀 함수 호출
    [ ] 재귀 함수
    [ ] 재귀 함수 내 5개의 액션 중에 재귀 아닌 3개
    [X] 맨 처음 배열 정렬
    [ ] 피봇 뽑기


12월 5일 todo리시이트
1. 스택 오늘 구현한거 잘 돌아가는가 확인 (완)
2. 매개변수 파싱 (완) : 배열정렬
3. 예외처리 같이합시도 왜냐면 양이 많거든~ (중복처리 빼고 완)
4. 재귀함수 호출 전까지 메인 다 해봅시다
5. 명령어 다 만들기 (완)
6. 만든거 확인해보기 (완)
7. 피봇뽑는함수 만들기

12월 11일 ToDoList
1. 중복 인자 들어왔을 시 에러처리
2. 들어온 인자 정렬하기 -> 정렬된 배열이 결과물로 나와야 함
3. 재귀함수 호출 전까지 메인 다 해야함 오늘은 기필코 끝낸다
4. 피봇 뽑는 함수 만들기
5. 재귀함수 Design하기 ,,,, 현재 스택 이런거 다 고려해서 ㄲ d오케이오케이

12월 12일 ToDo
1. 어제 만들던 재귀함수 마저 만들기 (현재 스택, depth 등 다 고려해서) ㅇㅋ
2. 피봇 뽑는 함수 검증해보기 ㅇㅋ???
3. 재귀함수 이용해 스택 정렬하고 출력해보기 ㅇㅋ
4. 최선을 다해 최적화하기 -> 하나하나 할때마다 기록해두자 !!! ㅁㄴㅇㅣㅏㅈ돠

12월  18일  투투두두리리스스트트
1. getAnyStack 함수 뜯어고치기
2. 정렬하기
3. 최적화하기
오늘 안에 다 뿌셔버린다 꼭 성공한다 제발ㅠㅠ,,,


그 뭐냐 그 A,B말고 그냥 re에서는 애니스택 그거 함수 쓰지 말고 바로 그냥 2로 나눵ㅋ?

1. 매개변수가 이미 정렬되어 있으면 , 저기 그 출력없이 종료
2. 출력 리스트로 -> 목요일에 (ra rra / rb rrb 상쇄, pb pa 상쇄)
((https://hi0seon.tistory.com/entry/42Seoul-pushswap-%ED%92%80%EC%9D%B4-%EA%B3%BC%EC%A0%95), 
(https://profq.tistory.com/31))

//전체가 3개일때
A
{
    - 정렬되있으면 리턴
    - if min, max 중 하나가 맨 뒤일때 (getanystack에 기준 상 맨뒤)
        - if max가 맨뒤
            if idx0 > idx1 => sa
        - if min이 맨뒤
            if idx0 > idx1 => sa
            rra
    - if min, max 중 하나가 맨앞
        - if max가 맨앞
            ra
            if idx0 > idx1 => sa
        - if min이 맨앞
            ra
            if idx0 > idx1 => sa
            rra
}

B
{
    max가 맨 앞일때, 중간일때, 맨 뒤일때
    - 정렬되있으면 리턴
    - if min, max가 맨 뒤일때 (getanystack에 기준 상 맨뒤)
        - if max가 맨두ㅣ
            if idx0 < idx1 => sb
            rrb
        - if min이 맨뒤
            if idx0 < idx1 => sb
    - if min, max 중 하나가 맨앞
        - if max가 맨앞
            rb
            if idx0 < idx1 => sb
            rrb
        - if min이 맨앞
            rb
            if idx0 < idx1 => sb
}

//sort three에서 전체가 3개가 아닐때
A
{
    - 정렬되있으면 리턴
    - if min, max 중 하나가 맨앞
        - if max가 맨앞
            sa ra sa rra
            if idx0 > idx1 => sa
        - if min이 맨앞
            ra
            if idx0 > idx1 => sa
            rra
    - 맨 뒤일때 (getanystack에 기준 상 맨뒤)
        - if max가 맨뒤
            if idx0 > idx1 => sa
        - if min이 맨뒤
            if idx0 > idx1 => sa
            ra sa rra sa
}

B
{
    - 정렬되있으면 리턴
    - if min, max 중 하나가 맨앞
        - if max이 맨앞
            rb
            if idx0 < idx1 => sb
            rrb
        - if min가 맨앞
            sb rb sb rrb
            if idx0 < idx1 => sb
    - 맨 뒤일때 (getanystack에 기준 상 맨뒤)
        - if max가 맨뒤
            if idx0 < idx1 => sb
            rb sb rrb sb
        - if min가 맨뒤
            if idx0 < idx1 => sb
}


3. 5개 이하로 바꾸고 하드코딩해보기 (현재 17)
    - 1개 2개 done
    - 3개는 sa ra (or sb rb) 최대 2개 명령어로 가능할듯
    - 4개?
    - 5개?

목요일리스트
- 3개일때 저거 이제 코딩으로 만들기
- 4개 5개 조건 잘 충족하는지
- 출력 리스트로 하고 조건에 맞춰서 중복제거하기




- 헤더 변수 이름 바꿔라 done
- 지우는 함수
- 에스 리스트 노드 레프트 안쓰면 삭제
- 함수이름변경 snake로
- 명령어 최적화

12월 24일 머야 크리스마스이브네? 암튼 투두리스트
- 리스트에서 ra rra처럼 상쇄되는 거 삭제하는 함수
- ra rb -> rr처럼 합쳐지는 명령어 합쳐주는 함수




//찐막
- 맥스노드 3개말고 n개 되도록 하고 그거 sort util로 옮기기


only 4개일때

A
{
	if max나 min 중 하나라도 idx 0일 경우 
		if max가 idx 0 => ra sort_three_a
		if min가 idx 0 => ra sort_three_a rra 
	if max나 min 중 하나라도 idx 3인 경우
		if max가 idx 3 => sort_three_a 
		if min가 idx 3 => sort_three_a rra
	if maxrk idx 2 => rra sort_three_a
	if min이 idx 2 => rra sort_three_a rra
}

B
{
	if max나 min 중 하나라도 idx 0일 경우 
		if min가 idx 0 => rb sort_three_b
		if max가 idx 0 => rb sort_three_b rrb 
	if max나 min 중 하나라도 idx 3인 경우
		if max가 idx 3 => sort_three_b rrb 
		if min가 idx 3 => sort_three_b
	if max가 idx 2 => rrb sort_three_b rrb
	if min이 idx 2 => rrb sort_three_b
}



정렬된게 있는(고정된게 있는) 4개일때

A
{
	if max나 min 중 하나라도 idx 0일 경우
		if max가 idx 0 => x
		if min가 idx 0 => ra sort_three_a rra
	if max나 min 중 하나라도 idx 3인 경우
		if max가 idx 3 => sort_three_a 
		if min가 idx 3 => x
	if max이 idx 2 => x
	if min이 idx 2 => x
}

B
{
    if max나 min 중 하나라도 idx 0일 경우 
		if max가 idx 0 => rb sort_three_b rrb
		if min가 idx 0 => x
	if max나 min 중 하나라도 idx 3인 경우
		if max가 idx 3 => x
		if min가 idx 3 => sort_three_b 
	if max이 idx 2 => x
	if min이 idx 2 => x
}




only 5개일때

A
{
    pb ra pb ra pb rra rra sa 3개 pa pa pa 13 ~ 14개
    
    if max가 idx 4일때 => sort_four_a
    if min이 idx 0일때 => ra sort_four_a rra
}

B
{
    if max이 idx 0일때 => rb sort_four_b rrb
    if min가 idx 4일때 => sort_four_b
}


not only 5개
A
{
    if max가 idx 4일때 => sort_four_a
    if min이 idx 0일때 => ra sort_four_a rra
}

B
{
    if max이 idx 0일때 => rb sort_four_b rrb
    if min가 idx 4일때 => sort_four_b
}

테스터
https://github.com/minckim42/push_swap_tester.git
https://github.com/laisarena/push_swap_tester.git