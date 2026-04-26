#include <iostream>
#include <cstring>  //äëÿ strcpy
#include <iomanip>  //äëÿ âûâîäà float
#include <fstream>
using namespace std;

const int numberOfExam = 3, numberOfTest = 5;

struct SessionGrades{
    int exam[numberOfExam];
    int test[numberOfTest];
};

struct Student{
    char name[30];
    bool gender;          //1 - æåíñêèé,0 - ìóæñêîé
    int group;
    int number;
    int libraryCard;
    struct SessionGrades sessionGrades;
};

struct Book{
    char author[30];
    char title[30];         //title - íàçâàíèå
    int year;
    int pageCount;          //page - ñòðàíèöà
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
    cout << "ÔÈÎ: " << student -> name << "\n";
    if (student -> gender){
        cout << "Ïîë: æåíñêèé\n";
    }
    else{
        cout << "Ïîë: ìóæñêîé\n";
    }
    cout << "Íîìåð ãðóïïû: " << student -> group << "\n";
    cout << "Íîìåð â ñïèñêå: " << student -> number << "\n";
    cout << "Íîìåð ÷èòàòåëüñêîãî áèëåòà: " << student -> libraryCard << "\n";
    cout << "Îöåíêè çà ýêçàìåíû ïî ìàò.àíàëèçó, àëãåáðå è ïðîãðàììèðîâàíèþ: ";
    for(int i=0; i<numberOfExam; i++)
        cout <<  student -> sessionGrades.exam[i];
    cout << "\n";
    cout << "Îöåíêè çà çà÷åòû ïî ìàò.àíàëèçó, àëãåáðå, ïðîãðàììèðîâàíèþ, ôèçèêå è ôèëîñîôèè: ";
    for(int i=0; i<numberOfTest; i++)
        cout <<  student -> sessionGrades.test[i];
    cout << endl << "\n";
}

void changeStudent(Student *student){
    cout << "Ââåäèòå ÔÈÎ ñòóäåíòà\n";
    cin.ignore();
    cin.getline(student -> name, 30);
    cout << "Ââåäèòå 1, åñëè ïîë æåíñêèé, è 0, åñëè ìóæñêîé\n";
    cin >> student -> gender;
    cout << "Ââåäèòå íîìåð ãðóïïû\n";
    cin >> student -> group;
    cout << "Ââåäèòå íîìåð â ñïèñêå ãðóïïû\n";
    cin >> student -> number;
    cout << "Ââåäèòå íîìåð ÷èòàòåëüñêîãî áèëåòà\n";
    cin >> student -> libraryCard;
    cout << "Ââåäèòå ÷åðåç ïðîáåë îöåíêè çà ýêçàìåíû ïî ìàò.àíàëèçó, àëãåáðå è ïðîãðàììèðîâàíèþ\n";
    for(int i=0; i<numberOfExam; i++)
        cin >>  student -> sessionGrades.exam[i];
    cout << "Ââåäèòå ÷åðåç ïðîáåë îöåíêè çà çà÷åòû ïî ìàò.àíàëèçó, àëãåáðå, ïðîãðàììèðîâàíèþ, ôèçèêå è ôèëîñîôèè\n";
    for(int i=0; i<numberOfTest; i++)
        cin >>  student -> sessionGrades.test[i];
    cout << endl;
}

void outputStudents(Student *student, int studentCount){
    for(int i=0; i<studentCount; i++){
        cout << "Ñòóäåíò " << i+1 << ":\n";
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
        cout << "Òàêîé ãðóïïû íå ñóùåñòâóåò\n\n";
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
    cout << "Òîï 5 ñòóäåíòîâ:\n";
    for (int i = 0; i < 5; i++){
        cout << sortedStudents[i].name << "\nÁàëë: " << fixed << setprecision(2) << averageScore(&sortedStudents[i]) << "\n\n";
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
    cout << "Êîëè÷åñòâî æåíùèí: " << numberOfWomen << "\n";
    cout << "Êîëè÷åñòâî ìóæ÷èí: " << numberOfMen << "\n\n";
}

bool noScholarship(Student *student){           //scholarship -  ñòèïåíäèÿ
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
    cout << "Ñòóäåíòû, íå ïîëó÷àþùèå ñòèïåíäèþ:\n";
    bool count = false;
    for (int i = 0; i < studentCount; i++){
        if(noScholarship(&student[i])){
            outputStudent(&student[i]);
            count = true;
        }
    }
    if(count == false)
        cout << "Òàêèõ ñòóäåíòîâ íåò\n\n";
    cout << "Ñòóäåíòû, ó÷àùèåñÿ íà 4 è 5:\n";
    count = false;
    for (int i = 0; i < studentCount; i++){
        if(foursAndFives(&student[i])){
            outputStudent(&student[i]);
            count = true;
        }
    }
    if(count == false)
        cout << "Òàêèõ ñòóäåíòîâ íåò\n\n";
    cout << "Ñòóäåíòû, ó÷àùèåñÿ íà îòëè÷íî:\n";
    count = false;
    for (int i = 0; i < studentCount; i++){
        if(averageScore(&student[i]) == 5){
            outputStudent(&student[i]);
            count = true;
        }
    }
    if(count == false)
        cout << "Òàêèõ ñòóäåíòîâ íåò\n\n";
}

void takeBook(Book *book, int bookCount, int value){
    char name[30];
    cout << "Ââåäèòå íàçâàíèå êíèãè:\n";
    cin.ignore();
    cin.getline(name, 30);
    for (int i = 0; i < bookCount; i++){
        if(strcmp(name, book[i].title)==0){
            if(!(book[i].studentID)){
                book[i].studentID = value;
                cout << "Êíèãà òåïåðü ó ñòóäåíòà\n\n";
            }
            else
                cout << "Ýòó êíèãó óæå êòî-òî çàáðàë\n\n";
            return;
        }
    }
        cout << "Òàêîé êíèãè â áèáëèîòåêå íåò\n\n";
}

void returnBook(Book *book, int bookCount, int value){
    bool flag = false;
    cout << "Êíèãè, êîòîðûå áðàë ñòóäåíò:\n";
    for(int i = 0; i < bookCount; i++){
        if(book[i].studentID == value){
            cout << book[i].title << "\n";
            flag = true;
        }
    }
    if(!flag){
        cout << "Ñòóäåíò íå áðàë íè îäíîé êíèãè\n\n";
        return;
    }
    cout << "Ââåäèòå íàçâàíèå êíèãè, êîòîðóþ õîòèòå âåðíóòü:\n";
    char name[30];
    cin.ignore();
    cin.getline(name, 30);
    for(int i = 0; i < bookCount; i++){
        if(strcmp(name, book[i].title)==0){
            if(book[i].studentID == value){
                book[i].studentID = 0;
                cout << "Êíèãà " << book[i].title << " âîçâðàùåíà\n\n";
                return;
            }
        }
    }
    cout << "Ââåäåíû íåâåðíûå äàííûå, ïðîèçîøëà îøèáêà\n\n";
}

void outputBook(Book *book){
    cout << "Àâòîð êíèãè: " << book -> author << "\n";
    cout << "Íàçâàíèå êíèãè: " << book -> title << "\n";
    cout << "Ãîä íàïèñàíèÿ: " << book -> year << "\n";
    cout << "Êîëè÷åñòâî ñòðàíèö: " << book -> pageCount << "\n";
    cout << "ID ñòóäåíòà, âçÿâøåãî êíèãó: " << book -> studentID << "\n";
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
        cout << "Âûáåðèòå îïåðàöèþ:\n"
                "1 - Ñîçäàíèå íîâîé çàïèñè î ñòóäåíòå\n"
                "2 - Âíåñåíèå èçìåíåíèé â óæå èìåþùóþñÿ çàïèñü\n"
                "3 - Âûâîä âñåõ äàííûõ î ñòóäåíòàõ\n"
                "4 - Âûâîä èíôîðìàöèè îáî âñåõ ñòóäåíòàõ âûáðàííîé ãðóïïû\n"
                "5 - Âûâîä òîïà ñàìûõ óñïåøíûõ ñòóäåíòîâ ñ íàèâûñøèì ïî ðåéòèíãó ñðåäíèì áàëëîì çà ïðîøåäøóþ ñåññèþ\n"
                "6 - Âûâîä êîëè÷åñòâà ñòóäåíòîâ ìóæñêîãî è æåíñêîãî ïîëà\n"
                "7 - Âûâîä äàííûõ î ñòóäåíòàõ, êîòîðûå íå ïîëó÷àþò ñòèïåíäèþ; ó÷àòñÿ òîëüêî íà «õîðîøî» è «îòëè÷íî»; ó÷àòñÿ òîëüêî íà «îòëè÷íî»\n"
                "8 - Âûâîä äàííûõ î ñòóäåíòàõ, èìåþùèõ âûáðàííûé íîìåð â ñïèñêå\n"
                "9 - Âûâîä èíôîðìàöèè î âûáðàííîì ñòóäåíòå\n"
                "10 - Âûäà÷à áèáëèîòåêîé êíèãè ñòóäåíòó\n"
                "11 - Ñäà÷à êíèãè â áèáëèîòåêó\n"
                "12 - Âûâîä èíôîðìàöèè î êíèãå\n"
                "13 - Âûâîä èíôîðìàöèè î âñåõ êíèãàõ\n"
                "0 - êîíåö\n\n";
        cin >> choice;
        switch(choice){
            case 1:{
                char name[30];
                bool gender;
                int group, number, libraryCard;
                struct SessionGrades sessionGrades;
                cout << "Ââåäèòå ÔÈÎ ñòóäåíòà\n";
                cin.ignore();
                cin.getline(name, 30);
                cout << "Ââåäèòå 1, åñëè ïîë æåíñêèé, è 0, åñëè ìóæñêîé\n";
                cin >> gender;
                cout << "Ââåäèòå íîìåð ãðóïïû\n";
                cin >> group;
                cout << "Ââåäèòå íîìåð â ñïèñêå ãðóïïû\n";
                cin >> number;
                cout << "Ââåäèòå íîìåð ÷èòàòåëüñêîãî áèëåòà\n";
                cin >> libraryCard;
                cout << "Ââåäèòå ÷åðåç ïðîáåë îöåíêè çà ýêçàìåíû ïî ìàò.àíàëèçó, àëãåáðå è ïðîãðàììèðîâàíèþ\n";
                for(int i=0; i<numberOfExam; i++)
                    cin >> sessionGrades.exam[i];
                cout << "Ââåäèòå ÷åðåç ïðîáåë îöåíêè çà çà÷åòû ïî ìàò.àíàëèçó, àëãåáðå, ïðîãðàììèðîâàíèþ, ôèçèêå è ôèëîñîôèè\n";
                for(int i=0; i<numberOfTest; i++)
                    cin >> sessionGrades.test[i];
                students[studentCount] = newStudent(name, gender, group, number, libraryCard, sessionGrades);
                studentCount++;
                cout << "Ñòóäåíò äîáàâëåí!\n\n";
                break;
            }
            case 2:{
                cout << "Âûáåðèòå íîìåð ñòóäåíòà, ÷üè äàíííûå âû õîòèòå èçìåíèòü\n";
                int value;
                cin >> value;
                if (value < 1 || value > studentCount){
                    cout << "Ââåäåíî íåâåðíîå çíà÷åíèå\n\n";
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
                cout << "Ââåäèòå íîìåð ãðóïïû\n";
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
                cout << "Ââåäèòå íîìåð ñòóäåíòà â ñïèñêå\n";
                int value;
                cin >> value;
                for(int i=0; i<studentCount; i++){
                    if(students[i].number == value)
                        outputStudent(&students[i]);
                }
                break;
            }
            case 9:{
                cout << "Ââåäèòå íîìåð ñòóäåíòà (îò 1 äî " << studentCount << ")\n";
                int value;
                cin >> value;
                outputStudent(&students[value-1]);
                break;
            }
            case 10:{
                int value;
                bool flag = false;
                cout << "Ââåäèòå ÷èòàòåëüñêèé áèëåò ñòóäåíòà:\n";
                cin >> value;
                for(int i = 0; i < studentCount; i++){
                    if(students[i].libraryCard == value){
                        takeBook(books, bookCount, value);
                        flag = true;
                    }
                }
                if(!flag)
                    cout << "Ñòóäåíòà ñ òàêèì ÷èòàòåëüñêèì áèëåòîì íå ñóùåñòâóåò\n\n";
                break;
            }
            case 11:{
                int value;
                bool flag = false;
                cout << "Ââåäèòå ÷èòàòåëüñêèé áèëåò ñòóäåíòà:\n";
                cin >> value;
                for(int i = 0; i < studentCount; i++){
                    if(students[i].libraryCard == value){
                        returnBook(books, bookCount, value);
                        flag = true;
                    }
                }
                if(!flag)
                    cout << "Ñòóäåíòà ñ òàêèì ÷èòàòåëüñêèì áèëåòîì íå ñóùåñòâóåò\n\n";
                break;
            }
            case 12:{
                cout << "Ââåäèòå íàçâàíèå êíèãè\n";
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
                cout << "Ââåäåíî íåâåðíîå çíà÷åíèå\n";
        }
    }
    while(choice);
    out.close();
    return 0;
}
