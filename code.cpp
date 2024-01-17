#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生信息结构体
typedef struct {
    char studentID[20];
    char name[20];
    char gender[10];
    char address[100];
    char phone[20];
    int chinese;
    int math;
    int english;
    int peerEvaluation;
    int morality;
    int teacherEvaluation;
    double averageScore;
    double totalScore;
    int rank;
} Student;

// 定义链表节点结构体
typedef struct Node {
    Student student;
    struct Node* next;
} Node;

// 全局变量，指向链表头节点
Node* head = NULL;

// 函数声明
void insertStudent();
void deleteStudent();
void browseStudent();
void calculateScores();
void searchStudent();
void searchComprehensiveInfo();
void displayStudent(Student student);
void displayComprehensiveInfo(Student student);
void saveToFile();
void loadFromFile();

int main() {
    loadFromFile();

    int choice;
    while (1) {
        printf("学生综合测评系统\n");
        printf("1. 录入学生信息\n");
        printf("2. 插入/修改学生信息\n");
        printf("3. 删除学生信息\n");
        printf("4. 浏览学生信息\n");
        printf("5. 计算学生成绩和综合测评成绩\n");
        printf("6. 学生数据查询\n");
        printf("7. 综合信息查询\n");
        printf("8. 保存数据到文件\n");
        printf("9. 退出\n");
        printf("请输入操作选项: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent();
                break;
            case 2:
                // 插入/修改学生信息
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                browseStudent();
                break;
            case 5:
                calculateScores();
                break;
            case 6:
                searchStudent();
                break;
            case 7:
                searchComprehensiveInfo();
                break;
            case 8:
                saveToFile();
                break;
            case 9:
                // 退出程序
                exit(0);
            default:
                printf("无效的选项，请重新输入。\n");
        }
    }

    return 0;
}

void insertStudent() {
    // 创建新的学生节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("请输入学生的学号: ");
    scanf("%s", newNode->student.studentID);
    printf("请输入学生的姓名: ");
    scanf("%s", newNode->student.name);
    printf("请输入学生的性别: ");
    scanf("%s", newNode->student.gender);
    printf("请输入学生的家庭住址: ");
    scanf("%s", newNode->student.address);
    printf("请输入学生的联系电话: ");
    scanf("%s", newNode->student.phone);
    printf("请输入学生的语文成绩: ");
    scanf("%d", &newNode->student.chinese);
    printf("请输入学生的数学成绩: ");
    scanf("%d", &newNode->student.math);
    printf("请输入学生的外语成绩: ");
    scanf("%d", &newNode->student.english);
    printf("请输入学生的同学互评分: ");
    scanf("%d", &newNode->student.peerEvaluation);
    printf("请输入学生的品德成绩: ");
    scanf("%d", &newNode->student.morality);
    printf("请输入学生的任课教师评分: ");
    scanf("%d", &newNode->student.teacherEvaluation);
    
    // 计算考试平均成绩和综合测评总分
    newNode->student.averageScore = (newNode->student.chinese + newNode->student.math + newNode->student.english) / 3.0;
    newNode->student.totalScore = newNode->student.averageScore * 0.6 + newNode->student.peerEvaluation * 0.1 + newNode->student.morality * 0.1 + newNode->student.teacherEvaluation * 0.2;

    // 将新节点插入链表头部
    newNode->next = head;
    head = newNode;
}

void deleteStudent() {
    char studentID[20];
    printf("请输入要删除的学生学号: ");
    scanf("%s", studentID);

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->student.studentID, studentID) == 0) {
            // 找到要删除的学生节点
            if (previous == NULL) {
                // 要删除的节点是头节点
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("成功删除学生信息。\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("未找到学号为%s的学生。\n", studentID);
}

void browseStudent() {
    Node* current = head;

    while (current != NULL) {
        displayStudent(current->student);
        current = current->next;
    }
}

void calculateScores() {
    Node* current = head;

    while (current != NULL) {
        current->student.averageScore = (current->student.chinese + current->student.math + current->student.english) / 3.0;
        current->student.totalScore = current->student.averageScore * 0.6 + current->student.peerEvaluation * 0.1 + current->student.morality * 0.1 + current->student.teacherEvaluation * 0.2;
        current = current->next;
    }
}

void searchStudent() {
    char studentID[20];
    printf("请输入要查询的学生学号: ");
    scanf("%s", studentID);

    Node* current = head;

    while (current != NULL) {
        if (strcmp(current->student.studentID, studentID) == 0) {
            displayStudent(current->student);
            return;
        }
        current = current->next;
    }

    printf("未找到学号为%s的学生。\n", studentID);
}

void searchComprehensiveInfo() {
    char studentID[20];
    printf("请输入要查询的学生学号: ");
    scanf("%s", studentID);

    Node* current = head;

    while (current != NULL) {
        if (strcmp(current->student.studentID, studentID) == 0) {
            displayComprehensiveInfo(current->student);
            return;
        }
        current = current->next;
    }

    printf("未找到学号为%s的学生。\n", studentID);
}

void displayStudent(Student student) {
    printf("学号: %s\n", student.studentID);
    printf("姓名: %s\n", student.name);
    printf("性别: %s\n", student.gender);
    printf("家庭住址: %s\n", student.address);
    printf("联系电话: %s\n", student.phone);
    printf("语文成绩: %d\n", student.chinese);
    printf("数学成绩: %d\n", student.math);
    printf("外语成绩: %d\n", student.english);
    printf("同学互评分: %d\n", student.peerEvaluation);
    printf("品德成绩: %d\n", student.morality);
    printf("任课教师评分: %d\n", student.teacherEvaluation);
    printf("\n");
}

void displayComprehensiveInfo(Student student) {
    printf("学号: %s\n", student.studentID);
    printf("姓名: %s\n", student.name);
    printf("性别: %s\n", student.gender);
    printf("家庭住址: %s\n", student.address);
    printf("联系电话: %s\n", student.phone);
    printf("语文成绩: %d\n", student.chinese);
    printf("数学成绩: %d\n", student.math);
    printf("外语成绩: %d\n", student.english);
    printf("考试平均成绩: %.2lf\n", student.averageScore);
    printf("同学互评分: %d\n", student.peerEvaluation);
    printf("品德成绩: %d\n", student.morality);
    printf("任课教师评分: %d\n", student.teacherEvaluation);
    printf("综合测评总分: %.2lf\n", student.totalScore);
    printf("\n");
}

void saveToFile() {
    FILE* file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("无法打开文件。\n");
        return;
    }

    Node* current = head;

    while (current != NULL) {
        fprintf(file, "%s %s %s %s %s %d %d %d %d %d %d %.2lf %.2lf %d\n",
                current->student.studentID, current->student.name, current->student.gender, current->student.address,
                current->student.phone, current->student.chinese, current->student.math, current->student.english,
                current->student.peerEvaluation, current->student.morality, current->student.teacherEvaluation,
                current->student.averageScore, current->student.totalScore, current->student.rank);
        current = current->next;
    }

    fclose(file);
    printf("成功保存数据到文件。\n");
}

void loadFromFile() {
    FILE* file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("无法打开文件。\n");
        return;
    }

    char studentID[20];
    char name[20];
    char gender[10];
    char address[100];
    char phone[20];
    int chinese;
    int math;
    int english;
    int peerEvaluation;
    int morality;
    int teacherEvaluation;
    double averageScore;
    double totalScore;
    int rank;

    while (fscanf(file, "%s %s %s %s %s %d %d %d %d %d %d %lf %lf %d",
                  studentID, name, gender, address, phone, &chinese, &math, &english,
                  &peerEvaluation, &morality, &teacherEvaluation, &averageScore, &totalScore, &rank) == 14) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        strcpy(newNode->student.studentID, studentID);
        strcpy(newNode->student.name, name);
        strcpy(newNode->student.gender, gender);
        strcpy(newNode->student.address, address);
        strcpy(newNode->student.phone, phone);
        newNode->student.chinese = chinese;
        newNode->student.math = math;
        newNode->student.english = english;
        newNode->student.peerEvaluation = peerEvaluation;
        newNode->student.morality = morality;
        newNode->student.teacherEvaluation = teacherEvaluation;
        newNode->student.averageScore = averageScore;
        newNode->student.totalScore = totalScore;
        newNode->student.rank = rank;

        // 将新节点插入链表头部
        newNode->next = head;
        head = newNode;
    }

    fclose(file);
    printf("成功从文件加载数据。\n");
}
