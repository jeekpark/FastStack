# FastStack

std::stack의 변형 스택입니다.
- 내부 컨테이너: std::vector<T>로 고정함.
- 추가 기능
  - Reserve: 메모리 재할당을 방지하기 위한 메모리 확보 함수
  - Capacity: 최대로 Push할 수 있는 요소의 수
- 장점: 미리 Reserve로 확보된 Capacity내의 Push/Pop은 메모리 재할당없이 고성능 스택 활용이 가능함.
- 단점: Capacity를 넘는 요소를 Push할 경우 메모리 재할당이 발생하기 때문에 호출자가 Push를 카운트하거나 확인해야함. (원래 C/C++는 호출자가 많은 책임을 진다.)
