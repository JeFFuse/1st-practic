#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 50;


struct Student {
    string name;
    string gender;
    int group_number;
    int list_number;
    int grades[8];
    float middle;
};


void create_student(Student students[], int& num_students) {
    if (num_students == MAX_STUDENTS) {
        cout << "Ошибка: достигнуто максимальное количество студентов." << endl;
        return;
    }

    Student new_student;

    cout << "Введите ФИО студента: ";
    cin.ignore();
    getline(cin, new_student.name);

    cout << "Введите пол студента: ";
    cin >> new_student.gender;


    cout << "Введите номер группы: ";
    cin >> new_student.group_number;

    cout << "Введите номер в списке группы: ";
    cin >> new_student.list_number;

    cout << "Введите оценки за экзамены и зачеты (8 оценок через пробел): ";
    for (int i = 0; i < 8; i++) {
        cin >> new_student.grades[i];
    }

    students[num_students] = new_student;
    num_students++;
}


void edit_student(Student students[], int num_students, int index) {

    if (index < 0 || index >= num_students) {
        cout << "Ошибка: индекс записи не существует." << endl;
        return;
    }

    Student& student = students[index];

    cout << "Введите ФИО студента: ";
    getline(cin, student.name);
    cin.ignore();

    cout << "Введите пол студента: ";
    getline(cin, student.gender);
    cin.ignore();

    cout << "Введите номер группы: ";
    cin >> student.group_number;

    cout << "Введите номер в списке группы: ";
    cin >> student.list_number;

    cout << "Введите оценки за экзамены и зачеты (8 оценок через пробел): ";
    for (int i = 0; i < 8; i++) {
        cin >> student.grades[i];
    }
}


void printStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Студент #" << i + 1 << endl;
        cout << "Имя: " << students[i].name << endl;
        cout << "Пол: " << students[i].gender << endl;
        cout << "Номер группы: " << students[i].group_number << endl;
        cout << "Номер в списке: " << students[i].list_number << endl;
        cout << "Оценка за экзамен: ";
        for (int j = 0; j < 8; j++) {
            cout << students[i].grades[j] << " ";
        }
        cout << endl << endl;
    }
}

void print_students_in_group(Student students[], int n, int group_number) {
    for (int i = 0; i < n; i++) {
        if (group_number == students[i].group_number) {
            cout << "Студент #" << i + 1 << endl;
            cout << "Имя: " << students[i].name << endl;
            cout << "Пол: " << students[i].gender << endl;
            cout << "Номер группы: " << students[i].group_number << endl;
            cout << "Номер в списке: " << students[i].list_number << endl;
            cout << "Оценка за экзамен: ";
            for (int j = 0; j < 8; j++) {
                cout << students[i].grades[j] << " ";
            }
            cout << endl << endl;
        }
    }

}

float get_middle_grades(Student students) {
    float sum = 0;
    for (int i = 0; i < 8; i++)
    {
        sum += students.grades[i];
    }
    return sum / 8;
}

void print_best(Student students[], int num_students) {
    for (int i = 0; i < num_students; i++)
    {
        for (int j = 0; j < num_students; j++)
        {
            float mgrades1 = get_middle_grades(students[i]);
            
            float mgrades2 = get_middle_grades(students[j]);
            if (mgrades1 > mgrades2) {
                swap(students[i], students[j]);
            }
        }
    }
}

void sex(Student students[], int num) {
    int male = 0;
    int female = 0;
    for (int i = 0; i < num; i++)
    {
        if (students[i].gender == "M" || students[i].gender == "m")
        {
            male+=1;
        }
        else if (students[i].gender == "F" || students[i].gender == "f")
        {
            female+=1;
        }
    }
    cout << endl << "Мальчиков в группе: " << male << endl << "Девочек в группе: " << female << endl;
}

void without_money(Student students[], int num) {
    cout << endl << "Без стипендии: ";
    int dd = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j  = 0; j  < 8; j ++)
        {
            if (students[i].grades[j] == 3)
            {
                if (dd > 0)
                {
                    cout << ", ";
                }
                cout << students[i].name;
                dd++;
                break;
            }
        }
    }
    if (dd == 0) {
        cout << "таких нету";
    }
    cout << endl;
}

void horoshist(Student students[], int num) {
    bool once_three = false;
    int dd = 0;
    int five = 0;
    cout << "Хорошисты: ";
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 8; j++) {
            if ((students[i].grades[j] == 5))
            {
                five++;
            }
            if ((students[i].grades[j] == 3))
            {
                once_three = true; 
                
            }
        }
        if ((once_three == false) && (five != 8)) {
            if (dd > 0)
            {
                cout << ", ";
            }

            cout << students[i].name;
            dd++;
        }
        once_three = false;
        five = 0;
    }
    if (dd == 0) {
        cout << "таких нету";
    }
    cout << endl;
}

void otlich(Student students[], int num) {
    bool once_three = false;
    int dd = 0;
    int five = 0;
    cout << "Отличники: ";
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 8; j++) {
            if ((students[i].grades[j] == 5))
            {
                five++;
            }
        }
        if (five == 8) {
            if (dd > 0)
            {
                cout << ", ";
            }

            cout << students[i].name;
            dd++;
        }
        once_three = false;
        five = 0;
    }
    if (dd == 0) {
        cout << "таких нету";
    }
    cout << endl << endl;
}

void print_students_in_list(Student students[], int n, int list) {
    for (int i = 0; i < n; i++) {
        if (list == students[i].list_number) {
            cout << "Студент #" << i + 1 << endl;
            cout << "Имя: " << students[i].name << endl;
            cout << "Пол: " << students[i].gender << endl;
            cout << "Номер группы: " << students[i].group_number << endl;
            cout << "Номер в списке: " << students[i].list_number << endl;
            cout << "Оценка за экзамен: ";
            for (int j = 0; j < 8; j++) {
                cout << students[i].grades[j] << " ";
            }
            cout << endl << endl;
        }
    }

}

int main() {
    Student students[MAX_STUDENTS];
    int num_students = 0;
    int menu_;
    setlocale(LC_ALL, "Russian");
    
    while (true)
    {
        cout << "Выберете операцию:" << endl;
        cout << "1. Добавить студента " << endl;
        cout << "2. Редактировать информацию о студенте" << endl;
        cout << "3. Показать информацию о студентах" << endl;
        cout << "4. Информация о группе" << endl;
        cout << "5. Топ студентов" << endl;
        cout << "6. Студенты мужского и женского пола" << endl;
        cout << "7. Студенты без стипендии; хорошисты и отличники; только отличники" << endl;
        cout << "8. Студенты по номеру в списке" << endl;
        cout << "0. Выход" << endl;
        cin >> menu_;
        switch (menu_)
        {
        case 1:
            create_student(students, num_students);
            break;
        case 2:
            int index;
            cout << endl << endl << "Введите индекс: ";
            cin >> index;
            edit_student(students, num_students, index - 1);
            break;
        case 3:
            printStudents(students, num_students);
            break;
        case 4:
            int gr_num;
            cout << "Введите группу: ";
            cin >> gr_num;
            cout << endl;
            print_students_in_group(students, num_students, gr_num);
            break;

        case 5:
            print_best(students, num_students);
            printStudents(students, num_students);
            break;
        case 6:
            sex(students, num_students);
            break;
        case 7:
            without_money(students, num_students);
            horoshist(students, num_students);
            otlich(students, num_students);
            break;
        case 8:
            int li_num;
            cout << "Введите номер: ";
            cin >> li_num;
            cout << endl;
            print_students_in_list(students, num_students, li_num);
            break;
        case 0:
            exit(0);

        default:
            break;
        }
    }

    return 0;
}
