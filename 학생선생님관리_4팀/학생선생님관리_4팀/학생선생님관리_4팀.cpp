#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 추상 클래스 Person
class Person {
protected:
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {}
    virtual void displayInfo() const = 0;
    virtual ~Person() {}
};

// 학생 점수를 템플릿으로 일반화
template <typename ScoreType>
class Student : public Person {
private:
    ScoreType 국어, 영어, 수학;
    string studentID;

public:
    Student(string name, int age, string studentID)
        : Person(name, age), 국어(0), 영어(0), 수학(0), studentID(studentID) {
    }

    void addScore(string subject, ScoreType score) {
        if (subject == "국어") 국어 = score;
        else if (subject == "영어") 영어 = score;
        else if (subject == "수학") 수학 = score;
        else {
            cout << "잘못된 과목명입니다!\n";
            return;
        }
        cout << subject << " 점수 추가 완료!\n";
    }

    void addScore(ScoreType k, ScoreType e, ScoreType m) {
        국어 = k;
        영어 = e;
        수학 = m;
        cout << "국어, 영어, 수학 점수 추가 완료!\n";
    }

    ScoreType getAverage() const {
        return (국어 + 영어 + 수학) / 3.0;
    }

    ScoreType getSubjectScore(int subject) const {
        if (subject == 1) return 국어;
        if (subject == 2) return 영어;
        if (subject == 3) return 수학;
        return 0;
    }
    void displayInfo() const override {
        cout << "학생: " << name << " (나이: " << age << ", ID: " << studentID << ")\n";
        cout << "점수 - 국어: " << 국어 << ", 영어: " << 영어 << ", 수학: " << 수학 << "\n";
        cout << "평균 점수: " << getAverage() << "\n";
    }

    string getID() const {
        return studentID;
    }
};

// Teacher 클래스
class Teacher : public Person {
private:
    string teachingSubject;
    string teacherID;

public:
    Teacher(string name, int age, string subject, string teacherID)
        : Person(name, age), teachingSubject(subject), teacherID(teacherID) {
    }

    void displayInfo() const override {
        cout << "교사: " << name << " (나이: " << age << ", ID: " << teacherID << ")\n";
        cout << "담당 과목: " << teachingSubject << "\n";
    }

    string getID() const {
        return teacherID;
    }
};

// 학생 및 교사 목록
vector<Student<int>> students;
vector<Teacher> teachers;

// 연산자 오버로딩 정의 (템플릿으로 수정)
template <typename ScoreType>
double operator+(double lhs, const Student<ScoreType>& rhs) {
    return lhs + rhs.getAverage();
}

// 나누기 연산 오버로딩 정의 (템플릿으로 수정)
template <typename ScoreType>
ScoreType operator/(const Student<ScoreType>& student, int n) {
    return (n != 0) ? student.getAverage() / n : 0.0;
}

// 초기 테스트 데이터 추가 함수
void initializeTestData() {
    students.push_back(Student<int>("김민수", 17, "S001"));
    students.push_back(Student<int>("이서연", 16, "S002"));
    students.push_back(Student<int>("김수현", 17, "S003"));
    students.push_back(Student<int>("이연기", 16, "S004"));
    students.push_back(Student<int>("이지연", 16, "S005"));

    teachers.push_back(Teacher("한동훈", 40, "국어", "T001"));
    teachers.push_back(Teacher("김지연", 50, "수학", "T002"));

    students[0].addScore(85, 90, 78);
    students[1].addScore(76, 82, 88);
    students[2].addScore(85, 90, 78);
    students[3].addScore(76, 82, 88);
    students[4].addScore(76, 82, 88);

    cout << "초기 테스트 데이터가 추가되었습니다!\n";
}
// 학생 추가 함수
void addStudent() {
    string name, studentID;
    int age;

    cout << "학생 이름: ";
    cin >> name;
    cout << "학생 나이: ";
    cin >> age;
    cout << "학생 ID: ";
    cin >> studentID;

    students.push_back(Student<int>(name, age, studentID));
    cout << "학생이 추가되었습니다!\n";
}

// 교사 추가 함수
void addTeacher() {
    string name, teacherID, subject;
    int age;

    cout << "교사 이름: ";
    cin >> name;
    cout << "교사 나이: ";
    cin >> age;
    cout << "교사 ID: ";
    cin >> teacherID;
    cout << "담당 과목: ";
    cin >> subject;

    teachers.push_back(Teacher(name, age, subject, teacherID));
    cout << "교사가 추가되었습니다!\n";
}
// 학생 찾기 함수
Student<int>* findStudentByID(const string& studentID) {
    for (auto& student : students) {
        if (student.getID() == studentID) {
            return &student;
        }
    }
    return nullptr;
}

// 교사 찾기 함수
Teacher* findTeacherByID(const string& teacherID) {
    for (auto& teacher : teachers) {
        if (teacher.getID() == teacherID) {
            return &teacher;
        }
    }
    return nullptr;
}
// 학생 점수 추가 함수
void addStudentScore() {
    string studentID;
    cout << "학생 ID 입력: ";
    cin >> studentID;

    Student<int>* student = findStudentByID(studentID);
    if (!student) {
        cout << "해당 ID의 학생을 찾을 수 없습니다!\n";
        return;
    }

    int choice;
    cout << "1. 각 과목 점수 직접 입력\n";
    cout << "2. 국어, 영어, 수학 점수 동시 입력\n";
    cout << "선택: ";
    cin >> choice;

    if (choice == 1) {
        string subject;
        int score;
        cout << "과목명(국어, 영어, 수학): ";
        cin >> subject;
        cout << "점수 입력: ";
        cin >> score;
        student->addScore(subject, score);
    }
    else if (choice == 2) {
        int k, e, m;
        cout << "국어, 영어, 수학 점수를 순서대로 입력: ";
        cin >> k >> e >> m;
        student->addScore(k, e, m);
    }
    else {
        cout << "잘못된 선택입니다!\n";
    }
}
// 정보 열람 함수
void displayPersonInfo() {
    string personID;
    cout << "학생 또는 교사의 ID 입력: ";
    cin >> personID;

    Student<int>* student = findStudentByID(personID);
    if (student) {
        student->displayInfo();
        return;
    }

    Teacher* teacher = findTeacherByID(personID);
    if (teacher) {
        teacher->displayInfo();
        return;
    }

    cout << "해당 ID의 학생 또는 교사를 찾을 수 없습니다!\n";
}

void displayTotalAverage() {
    if (students.empty()) {
        cout << "학생 데이터가 없습니다!\n";
        return;
    }

    double totalSum = 0;
    for (size_t i = 0; i < students.size(); i++) {
        if (i == 0)
            totalSum = students[i].getAverage(); // 첫 번째 학생의 평균 점수로 초기화
        else
            totalSum = totalSum + students[i]; // operator+ 활용
    }

    double totalAverage = totalSum / students.size(); // operator/ 활용

    cout << "전체 학생 총 과목 평균 점수: " << totalAverage << "\n";
}
// 과목별 모든 학생 평균 계산
void displaySubjectAverage() {
    int subject;
    cout << "1. 국어\n";
    cout << "2. 영어\n";
    cout << "3. 수학\n";
    cout << "4. 모든 학생 총 과목 평균\n";  // 
    cout << "선택: ";
    cin >> subject;

    if (subject == 4) {
        displayTotalAverage(); //  전체 평균 계산 함수 호출
        return;
    }

    double totalScore = 0;
    for (size_t i = 0; i < students.size(); i++) {
        totalScore = totalScore + students[i].getSubjectScore(subject);
    }

    double average = totalScore / students.size();
    string subjectName = (subject == 1) ? "국어" : (subject == 2) ? "영어" : "수학";

    cout << subjectName << " 과목의 전체 학생 평균 점수: " << average << "\n";
}
// 메인 메뉴
void showMenu() {
    //initializeTestData(); // 테스트 데이터 추가

    while (true) {
        cout << "\n===== 메뉴 =====\n";
        cout << "1. 학생 추가\n";
        cout << "2. 선생 추가\n";
        cout << "3. 학생 점수 추가\n";
        cout << "4. 학생/교사 정보 열람\n";
        cout << "5. 과목별 모든 학생 평균\n";
        cout << "0. 종료\n";
        cout << "선택: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: addTeacher(); break;
        case 3: addStudentScore(); break;
        case 4: displayPersonInfo(); break;
        case 5: displaySubjectAverage(); break;
        case 0: cout << "프로그램을 종료합니다.\n"; return;
        default: cout << "올바른 번호를 입력하세요!\n";
        }
    }
}

int main() {
    showMenu();
    return 0;
}
