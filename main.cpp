#include <iostream>
#include <cstring>  //для strcpy
#include <iomanip>  //для вывода float
#include <fstream>
using namespace std;

const int numberOfExam = 3, numberOfTest = 5;

struct SessionGrades{
    int exam[numberOfExam];
    int test[numberOfTest];
};

struct Student{
    char name[30];
    bool gender;          //1 - женский,0 - мужской
    int group;
    int number;
    int libraryCard;
    struct SessionGrades sessionGrades;
};

struct Book{
    char author[30];
    char title[30];         //title - название
    int year;
    int pageCount;          //page - страница
    int studentID;
};

Student newStudent(char* name, bool gender, int group, int number, int libraryCard, struct SessionGrades sessionGrades){
    if(out.is_open()){


    }
    strcpy(student.name, name);
    student.gender = gender;
    student.group = group;
    student.number = number;
    student.libraryCard = libraryCard;
    student.sessionGrades = sessionGrades;
    return student;
}

void outputStudent(Student *student){
    cout << "ФИО: " << student -> name << "\n";
    if (student -> gender){
        cout << "Пол: женский\n";
    }
    else{
        cout << "Пол: мужской\n";
    }
    cout << "Номер группы: " << student -> group << "\n";
    cout << "Номер в списке: " << student -> number << "\n";
    cout << "Номер читательского билета: " << student -> libraryCard << "\n";
    cout << "Оценки за экзамены по мат.анализу, алгебре и программированию: ";
    for(int i=0; i<numberOfExam; i++)
        cout <<  student -> sessionGrades.exam[i];
    cout << "\n";
    cout << "Оценки за зачеты по мат.анализу, алгебре, программированию, физике и философии: ";
    for(int i=0; i<numberOfTest; i++)
        cout <<  student -> sessionGrades.test[i];
    cout << endl << "\n";
}

void changeStudent(Student *student){
    cout << "Введите ФИО студента\n";
    cin.ignore();
    cin.getline(student -> name, 30);
    cout << "Введите 1, если пол женский, и 0, если мужской\n";
    cin >> student -> gender;
    cout << "Введите номер группы\n";
    cin >> student -> group;
    cout << "Введите номер в списке группы\n";
    cin >> student -> number;
    cout << "Введите номер читательского билета\n";
    cin >> student -> libraryCard;
    cout << "Введите через пробел оценки за экзамены по мат.анализу, алгебре и программированию\n";
    for(int i=0; i<numberOfExam; i++)
        cin >>  student -> sessionGrades.exam[i];
    cout << "Введите через пробел оценки за зачеты по мат.анализу, алгебре, программированию, физике и философии\n";
    for(int i=0; i<numberOfTest; i++)
        cin >>  student -> sessionGrades.test[i];
    cout << endl;
}

void outputStudents(Student *student, int studentCount){
    for(int i=0; i<studentCount; i++){
        cout << "Студент " << i+1 << ":\n";
        outputStudent(&student[i]);
    }
}

void outputByGroup(Student *student, int studentCount, int value){
    int count = 0;
    for(int i=0; i<studentCount; i++){
        if((student+i) -> group == value){
            outputStudent(&student[i]);
            count++;
        }
    }
    if(!count)
        cout << "Такой группы не существует\n\n";
}

float averageScore(Student *student){                    //average score - средний балл
    float sum = 0;
    for(int i = 0; i < numberOfExam; i++)
        sum += student->sessionGrades.exam[i];
    for(int i = 0; i < numberOfTest; i++)
        sum += student->sessionGrades.test[i];
    return sum/(numberOfExam + numberOfTest);
}

 void bubbleSort(Student *student, int studentCount){
    for(int i = 0; i < studentCount-1; i++){
        for(int j = 0; j < studentCount - i - 1; j++){
            if(averageScore(&student[j]) < averageScore(&student[j+1]))
                swap(student[j], student[j+1]);
        }
    }
 }

void topStudents(Student *student, int studentCount){
    Student sortedStudents[30];
    for(int i = 0; i < studentCount; i++)
        sortedStudents[i] = student[i];
    bubbleSort(sortedStudents, studentCount);
    cout << "Топ 5 студентов:\n";
    for (int i = 0; i < 5; i++){
        cout << sortedStudents[i].name << "\nБалл: " << fixed << setprecision(2) << averageScore(&sortedStudents[i]) << "\n\n";
    }
}

void numberOfWomenAndMen(Student *student, int studentCount){
    int numberOfWomen = 0, numberOfMen = 0;
    for(int i=0; i<studentCount; i++){
        if((student+i) -> gender)
            numberOfWomen++;
        else
            numberOfMen++;
    }
    cout << "Количество женщин: " << numberOfWomen << "\n";
    cout << "Количество мужчин: " << numberOfMen << "\n\n";
}

bool noScholarship(Student *student){           //scholarship -  стипендия
    for(int i = 0; i < numberOfExam; i++){
        if(student->sessionGrades.exam[i] == 2 || student->sessionGrades.exam[i] == 3)
            return true;
    }
    for(int i = 0; i < numberOfTest; i++){
        if(student->sessionGrades.test[i] == 2 || student->sessionGrades.test[i] == 3)
            return true;
        }
    return false;
}

bool foursAndFives(Student *student){
    for(int i = 0; i < numberOfExam; i++){
        if(student->sessionGrades.exam[i] == 2 || student->sessionGrades.exam[i] == 3)
            return false;
    }
    for(int i = 0; i < numberOfTest; i++){
        if(student->sessionGrades.test[i] == 2 || student->sessionGrades.test[i] == 3)
            return false;
        }
    return true;
}

void studentGrades(Student *student, int studentCount){
    cout << "Студенты, не получающие стипендию:\n";
    bool count = false;
    for (int i = 0; i < studentCount; i++){
        if(noScholarship(&student[i])){
            outputStudent(&student[i]);
            count = true;
        }
    }
    if(count == false)
        cout << "Таких студентов нет\n\n";
    cout << "Студенты, учащиеся на 4 и 5:\n";
    count = false;
    for (int i = 0; i < studentCount; i++){
        if(foursAndFives(&student[i])){
            outputStudent(&student[i]);
            count = true;
        }
    }
    if(count == false)
        cout << "Таких студентов нет\n\n";
    cout << "Студенты, учащиеся на отлично:\n";
    count = false;
    for (int i = 0; i < studentCount; i++){
        if(averageScore(&student[i]) == 5){
            outputStudent(&student[i]);
            count = true;
        }
    }
    if(count == false)
        cout << "Таких студентов нет\n\n";
}

void takeBook(Book *book, int bookCount, int value){
    char name[30];
    cout << "Введите название книги:\n";
    cin.ignore();
    cin.getline(name, 30);
    for (int i = 0; i < bookCount; i++){
        if(strcmp(name, book[i].title)==0){
            if(!(book[i].studentID)){
                book[i].studentID = value;
                cout << "Книга теперь у студента\n\n";
            }
            else
                cout << "Эту книгу уже кто-то забрал\n\n";
            return;
        }
    }
        cout << "Такой книги в библиотеке нет\n\n";
}

void returnBook(Book *book, int bookCount, int value){
    bool flag = false;
    cout << "Книги, которые брал студент:\n";
    for(int i = 0; i < bookCount; i++){
        if(book[i].studentID == value){
            cout << book[i].title << "\n";
            flag = true;
        }
    }
    if(!flag){
        cout << "Студент не брал ни одной книги\n\n";
        return;
    }
    cout << "Введите название книги, которую хотите вернуть:\n";
    char name[30];
    cin.ignore();
    cin.getline(name, 30);
    for(int i = 0; i < bookCount; i++){
        if(strcmp(name, book[i].title)==0){
            if(book[i].studentID == value){
                book[i].studentID = 0;
                cout << "Книга " << book[i].title << " возвращена\n\n";
                return;
            }
        }
    }
    cout << "Введены неверные данные, произошла ошибка\n\n";
}

void outputBook(Book *book){
    cout << "Автор книги: " << book -> author << "\n";
    cout << "Название книги: " << book -> title << "\n";
    cout << "Год написания: " << book -> year << "\n";
    cout << "Количество страниц: " << book -> pageCount << "\n";
    cout << "ID студента, взявшего книгу: " << book -> studentID << "\n";
    cout << endl;
}

void outputBooks(Book *book, int bookCount){
    for(int i=0; i<bookCount; i++)
        outputBook(&book[i]);
}

int main()
{
    setlocale(0, "");
    system("chcp 1251 > nul");
    ofstream file("file.txt");
    int choice;
    const int numberOfExam = 3, numberOfTest = 5;
    int studentCount = loadStudentsFromFile(students, "students.txt");
    int bookCount = loadBooksFromFile(books, "books.txt");
    do{
        cout << "Выберите операцию:\n"
                "1 - Создание новой записи о студенте\n"
                "2 - Внесение изменений в уже имеющуюся запись\n"
                "3 - Вывод всех данных о студентах\n"
                "4 - Вывод информации обо всех студентах выбранной группы\n"
                "5 - Вывод топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию\n"
                "6 - Вывод количества студентов мужского и женского пола\n"
                "7 - Вывод данных о студентах, которые не получают стипендию; учатся только на «хорошо» и «отлично»; учатся только на «отлично»\n"
                "8 - Вывод данных о студентах, имеющих выбранный номер в списке\n"
                "9 - Вывод информации о выбранном студенте\n"
                "10 - Выдача библиотекой книги студенту\n"
                "11 - Сдача книги в библиотеку\n"
                "12 - Вывод информации о книге\n"
                "13 - Вывод информации о всех книгах\n"
                "0 - конец\n\n";
        cin >> choice;
        switch(choice){
            case 1:{
                char name[30];
                bool gender;
                int group, number, libraryCard;
                struct SessionGrades sessionGrades;
                cout << "Введите ФИО студента\n";
                cin.ignore();
                cin.getline(name, 30);
                cout << "Введите 1, если пол женский, и 0, если мужской\n";
                cin >> gender;
                cout << "Введите номер группы\n";
                cin >> group;
                cout << "Введите номер в списке группы\n";
                cin >> number;
                cout << "Введите номер читательского билета\n";
                cin >> libraryCard;
                cout << "Введите через пробел оценки за экзамены по мат.анализу, алгебре и программированию\n";
                for(int i=0; i<numberOfExam; i++)
                    cin >> sessionGrades.exam[i];
                cout << "Введите через пробел оценки за зачеты по мат.анализу, алгебре, программированию, физике и философии\n";
                for(int i=0; i<numberOfTest; i++)
                    cin >> sessionGrades.test[i];
                students[studentCount] = newStudent(name, gender, group, number, libraryCard, sessionGrades);
                studentCount++;
                cout << "Студент добавлен!\n\n";
                break;
            }
            case 2:{
                cout << "Выберите номер студента, чьи даннные вы хотите изменить\n";
                int value;
                cin >> value;
                if (value < 1 || value > studentCount){
                    cout << "Введено неверное значение\n\n";
                    break;
                }
                changeStudent(&students[value-1]);
                break;
            }
            case 3:{
                outputStudents(students, studentCount);
                break;
            }
            case 4:{
                cout << "Введите номер группы\n";
                int value;
                cin >> value;
                cout << "\n";
                outputByGroup(students, studentCount, value);
                break;
            }
            case 5:{
                topStudents(students, studentCount);
                break;
            }
            case 6:{
                numberOfWomenAndMen(students, studentCount);
                break;
            }
            case 7:{
                studentGrades(students, studentCount);
                break;
            }
            case 8:{
                cout << "Введите номер студента в списке\n";
                int value;
                cin >> value;
                for(int i=0; i<studentCount; i++){
                    if(students[i].number == value)
                        outputStudent(&students[i]);
                }
                break;
            }
            case 9:{
                cout << "Введите номер студента (от 1 до " << studentCount << ")\n";
                int value;
                cin >> value;
                outputStudent(&students[value-1]);
                break;
            }
            case 10:{
                int value;
                bool flag = false;
                cout << "Введите читательский билет студента:\n";
                cin >> value;
                for(int i = 0; i < studentCount; i++){
                    if(students[i].libraryCard == value){
                        takeBook(books, bookCount, value);
                        flag = true;
                    }
                }
                if(!flag)
                    cout << "Студента с таким читательским билетом не существует\n\n";
                break;
            }
            case 11:{
                int value;
                bool flag = false;
                cout << "Введите читательский билет студента:\n";
                cin >> value;
                for(int i = 0; i < studentCount; i++){
                    if(students[i].libraryCard == value){
                        returnBook(books, bookCount, value);
                        flag = true;
                    }
                }
                if(!flag)
                    cout << "Студента с таким читательским билетом не существует\n\n";
                break;
            }
            case 12:{
                cout << "Введите название книги\n";
                char title[30];
                cin.ignore();
                cin.getline(title, 30);
                for(int i = 0; i < bookCount; i++){
                    if(strcmp(title, books[i].title)==0)
                        outputBook(&books[i]);
                }
                break;
            }
            case 13:{
                outputBooks(books, bookCount);
                break;
            }
            default:
                cout << "Введено неверное значение\n";
        }
    }
    while(choice);
    out.close();
    return 0;
}
