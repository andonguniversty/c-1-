
# 🎓 학생/선생님 관리 프로그램

## 📌 프로젝트 개요
- **팀명**: 4팀  
- **팀원**: 전재민(팀장), 김준용, 김무진  
- **개발 기간**: 2024.04.01 ~ 2024.04.04 (4일)  
- **주요 기술**: C++, OOP, 연산자 오버로딩, 템플릿  

## 👥 팀원 역할 분담
| 이름 | 역할 | 주요 담당 업무 |
|------|-----|---------------|
| 전재민 | 프로젝트 관리 | 전체 설계, 코드 통합, Git 관리 |
| 김준용 | 개발 | Student 클래스 구현, 연산자 오버로딩 |
| 김무진 | 테스트/문서 | Teacher 클래스 구현, 보고서 작성 |

## 🏗️ 시스템 구조
```cpp
classDiagram
    Person <|-- Student
    Person <|-- Teacher
    class Person {
        <<abstract>>
        +string name
        +int age
        +virtual displayInfo() pure
    }
    class Student {
        -int korean
        -int english
        -int math
        -string studentID
        +addScore(string, int)
        +addScore(int, int, int)
        +getAverage() double
        +operator+(Student&) double
        +displayInfo() override

    class Teacher {
        +string teachingSubject
        +string teacherID
    }
```

## 🛠️ 핵심 기능
### 1. 다형성 구현
```cpp
void Person::displayInfo() = 0;  // 순수 가상 함수

// Student 구현
void displayInfo() override {
    cout << "학생: " << name << " (평균: " << getAverage() << ")";
}

// Teacher 구현
void displayInfo() override {
    cout << "교사: " << name << " (과목: " << teachingSubject << ")";
}
```

### 2. 연산자 오버로딩
```cpp
// 학생 평균 점수 합산
double Student::operator+(const Student& other) {
    return this->getAverage() + other.getAverage();
}
```

### 3. 성적 관리 기능
```cpp
// 단일/다중 과목 성적 추가
// 1과목 입력 (과목명 + 점수)
void addScore(string subject, int score) {
    setScore(subject, score);
}

// 3과목 한번에 입력 (국/영/수 순서)
void addScore(int kor, int eng, int math) {
    korean = kor;
    english = eng;
    this->math = math;
}

// 사용 예시
Student s;
s.addScore("국어", 90);  // 단일 과목 입력
s.addScore(80, 85, 90);  // 국/영/수 일괄 입력
```

## 📅 개발 일정
| 일차 | 주요 작업 |
|------|----------|
| 1일차 | 클래스 설계 |
| 2일차 | Student 구현 |
| 3일차 | Teacher 구현 |
| 4일차 | 통합 테스트 |

## 💡 성과 및 개선점
### ✅ 성공 요인
- 명확한 역할 분담
- 유지보수성
- Git을 활용한 협업
- 사용자 친화적 기능 추가
- 초기 테스트 데이터 활용

### 🔧 어려웠던 점
- 객체 지향 개념 적용 난이도
- 템플릿과 연산자 오버로딩
- 프로그램 예외처리

### 📌 보완할 점 및 개선 방향
1. 메모리 누수 방지 (동적 할당 사용 여부 확인하기)
2. 연산자 오버로딩의 적절성
   ```cpp
   //연산자 오버로딩 대신 함수로 구현
   template <typename ScoreType>
    double sumAverage(double lhs, const Student<ScoreType>& rhs) {
    return lhs + rhs.getAverage();
    }

   ```
3. "cls"나 줄바꿈을 통한 가독성 강화
   ```cpp
   system("cls");
   ```

## 📄실행화면
### 시작 메뉴

&nbsp;&nbsp;&nbsp;&nbsp;![메뉴화면](https://github.com/andonguniversty/c-1-/blob/main/image/%EB%A9%94%EB%89%B4%ED%99%94%EB%A9%B4.PNG)

### 학생 추가 메뉴

&nbsp;&nbsp;&nbsp;&nbsp;![학생추가](https://github.com/andonguniversty/c-1-/blob/main/image/%EA%B8%B0%EB%8A%A51.PNG)

### 교사 추가 메뉴

&nbsp;&nbsp;&nbsp;&nbsp;![교사추가](https://github.com/andonguniversty/c-1-/blob/main/image/%EA%B8%B0%EB%8A%A52.PNG)

### 학생 점수 추가

&nbsp;&nbsp;&nbsp;&nbsp;![개별과목성적](https://github.com/andonguniversty/c-1-/blob/main/image/%EA%B8%B0%EB%8A%A53_1.PNG)
&nbsp;&nbsp;&nbsp;&nbsp;![일괄과목성적](https://github.com/andonguniversty/c-1-/blob/main/image/%EA%B8%B0%EB%8A%A53_2.PNG)

### 개인 정보 열람

&nbsp;&nbsp;&nbsp;&nbsp;![개인정보열람](https://github.com/andonguniversty/c-1-/blob/main/image/%EA%B8%B0%EB%8A%A54.PNG)

### 과목별 모든 학생 평균

&nbsp;&nbsp;&nbsp;&nbsp;![개별과목평균](https://github.com/andonguniversty/c-1-/blob/main/image/%EA%B8%B0%EB%8A%A55_1.PNG)
&nbsp;&nbsp;&nbsp;&nbsp;![전체학생평균](https://github.com/andonguniversty/c-1-/blob/main/image/%EA%B8%B0%EB%8A%A55_2.PNG)

### 프로그램 종료

&nbsp;&nbsp;&nbsp;&nbsp;![종료](https://github.com/andonguniversty/c-1-/blob/main/image/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8%20%EC%A2%85%EB%A3%8C.PNG)

## 프로젝트 소감

### 🔹전재민(팀장)
**설계 단계에서 요구사항을 분석하고, 코드 구조를 정리하는 과정에서 협업의 중요성을 실감하였습니다. 코드 변경 사항을 효율적으로 관리하는 방법을 익힐 수 있었습니다.**
### 🔹김준용
**Student 클래스를 구현하는 과정에서 객체 지향 프로그래밍의 개념을 적응하는 경험을 할 수 있었습니다. 평균점수 계산 기능을 구현하면서 연산자 오버로딩의 원리를 깊게 이해할 수 있었습니다.**
### 🔹김무진
**교사 클래스를 구현하면서 상속과 다형성의 개념을 실제 코드에 적용해볼 수 있었습니다. 프로젝트 문서를 작성하면서 코드의 설계 의도와 기능을 명확하게 전달하는 것이 중요하다는 점을 깨달았습니다.**
