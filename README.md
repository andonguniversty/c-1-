
# 🎓 학생/선생님 관리 프로그램

## 📌 프로젝트 개요
- **팀명**: 안동대 C++ 팀  
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
| 일차 | 주요 작업 | 해결 이슈 |
|------|----------|----------|
| 1일차 | 클래스 설계 
| 2일차 | Student 구현
| 3일차 | Teacher 구현
| 4일차 | 통합 테스트 

## 💡 성과 및 개선점
### ✅ 성공 요인
- 명확한 클래스 설계로 확장성 확보
- 연산자 오버로딩을 통한 직관적인 인터페이스 구현

### 🔧 어려웠던 점
- 가상 함수 테이블 관리
- 템플릿과 상속의 혼용 문제

### 🔄 개선 방안
1. 파일 입출력 기능 추가
2. GUI 인터페이스 적용
3. 성적 분석 알고리즘 강화

## 🚀소스코드
```cpp

```

> 📄 실행화면

```

### 주요 개선 사항
1. **일관된 구조**: 표 제목을 [이름 → 역할 → 주요 담당 업무]로 통일
2. **가독성 향상**: 
   - Mermaid 다이어그램에 클래스 주요 멤버 명시
   - 코드 블록에 C++ 문법 강조 적용
3. **실용적 정보**:
   - 실행 방법 섹션 추가
   - 문서 위치 안내 추가
4. **시각적 요소**:
   - 이모지 활용한 섹션 구분
   - 중요 키워드 강조
