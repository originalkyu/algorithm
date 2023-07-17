# algorithm
https://github.com/originalkyu/algorithm

### 개념 정리
https://github.com/originalkyu/algorithm/wiki
* Iterator
* vector
* lambda
* list comprehension
* strict weak ordering


### Week5 개념정리
* 그리디
    * 각 단계마다 지역적 최적해가 결과적으로 전역 최적해가 된다.
    * 그리디 문제의 조건
        * 최적부분구조를 가진다
        * 탐욕적 속성이 증명되어야한다.
    * 일단 풀기 -> DP로 풀기 -> 그리디로 풀기
* 라인 스위핑
* 투포인터
    * 두 개의 포인터로 탐색하는 알고리즘
    
### Week6 개념정리
* 이분탐색(이진탐색): 정렬된 배열에 특정원소가 있는지 O(log N) 만에 해결하는 알고리즘
* '이분탐색' 문제는 '최적화 문제'를 '결정'문제로 바꾸기도 한다. 
    * 최적화 문제란 최대화하라, 최소값을 찾아라 같은 문제.
    * 즉, "어느 지점이 최대인가?" 를 "가리키고있는 mid 지점이 최대인가?" 로 생각할 수 있다. 
* 이분탐색 알고리즘은 선형 탐색을 하기에는 너무 수가 클 때 이용한다
* 최대증가부분수열(LIS): 
이전에서 지금 것보다 작은 것 중에서 가장 큰 것을 카운트  O(n^2)
prev_list에 이전의 것을 저장하여 trace 한다. O(n^2)
lower_bound 이용 : O(n log n) => trace는 하지 못함
* LIS 문제는 시험에서 잘 나오지 않는다.


### Week7 개념정리
* DP(Dynamic Programming, 동적계획법)
    * 점화식 기반의 문제 풀이
    * 메모이제이션 : 이미 계산한 값을 저장해 두 번이상 벌어지는 로직에 그 값을 사용
    * DP의 조건
        * 참조투명성(외부 전역변수에 영향을 끼치지 않음) 그리고 입력을 제외한 외적요소에 결과값이 영향을 미치지 않음
        * Overlapping Subproblem : 겹치는 부분 문제
            * 피보나치수열 같은 구조
        * Optimal Substructure : 최적 부분구조
            * 지금의 최적해가 결론적으로 글로벌한 최적해가 됨
    * 쉽게 다음과 같이 파악이 가능
        * 완전 탐색
        * 경우의 수가 매우 큼
        * 메모이제이션이 가능(배열로 담기 가능)
    * 예를 들어 배열이 1000만 정도가 필요하다면 그리디 또는 다른 알고리즘으로 풀이한다.
    * DP를 하는 이유는 시간복잡도를 줄이기 위함
    * DP의 기본 구조
        * 기저사례
        * 메모이제이션
        * 로직
        * 초기화
    * DP 문제 중 경우의 수 문제 타입이 나오면 모두 더해서 해결한다.
    * DP의 종류
        * 바텀업(상향식) : 반복적 DP. 하위문제를 해결하고 그걸 기반으로 그 위에 하위문제를 해결
        * 탑다운(하향식) : 재귀적인 구조
    * 문제를 잘 정의하고 부분 문제들 사이의 관계를 파악한다.