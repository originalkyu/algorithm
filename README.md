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
* 투포인터


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
