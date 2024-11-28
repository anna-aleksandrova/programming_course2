#include <iostream>
#include <fstream>

#define AMOUNT 3

using str = std::string;
std::string d = " ";

class Person {
    public:
        Person(){};
        Person(str last, str first, str middle, str uni) {
            last_name = last;
            first_name = first;
            middle_name = middle;
            university = uni;
        }
        str get_university() {return university;}
        friend std::istream& operator>>(std::istream& in, Person& p);
        friend std::ostream& operator<<(std::ostream& out, Person& p);
    protected:
        str last_name, first_name, middle_name, university;
};

std::istream& operator>>(std::istream& in, Person& p) {
    in >> p.last_name >> p.first_name >> p.middle_name >> p.university;
    return in;
}

std::ostream& operator<<(std::ostream& out, Person& p) {
    out << p.last_name + d + p.first_name + d + p.middle_name << std::endl;
    out << "University: " << p.university << std::endl;
    return out;
}

class Student : virtual public Person {
    public:
        Student(){};
        Student(str l, str f, str m, str u, unsigned int course_, str group_) : Person(l, f, m, u) {
            course = course_;
            group = group_;
        }
        friend std::istream& operator>>(std::istream& in, Student& s);
        friend std::ostream& operator<<(std::ostream& out, Student& s);
    protected:
        unsigned int course;
        str group;
};

std::istream& operator>>(std::istream& in, Student& s) {
    in >> s.last_name >> s.first_name >> s.middle_name >> s.university >> s.course >> s.group;
    return in;
}

std::ostream& operator<<(std::ostream& out, Student& s) {
    out << s.last_name + d + s.first_name + d + s.middle_name << std::endl;
    out << "University: " << s.university << std::endl;
    out << "Course: " << s.course << std::endl;
    out << "Group: " << s.group << std::endl;
    return out;
}

class Lecturer : virtual public Person {
    public:
        Lecturer(){};
        Lecturer(str l, str f, str m, str u, str position_, unsigned int salary_) : Person(l, f, m, u) {
            position = position_;
            salary = salary_;
        }
        friend std::istream& operator>>(std::istream& in, Lecturer& lect);
        friend std::ostream& operator<<(std::ostream& out, Lecturer& lect);
    protected:
        str position;
        unsigned int salary;
};

std::istream& operator>>(std::istream& in, Lecturer& lect) {
    in >> lect.last_name >> lect.first_name >> lect.middle_name >> lect.university >> lect.position >> lect.salary;
    return in;
}

std::ostream& operator<<(std::ostream& out, Lecturer& lect) {
    out << lect.last_name + d + lect.first_name + d + lect.middle_name << std::endl;
    out << "University: " << lect.university << std::endl;
    out << "Position: " << lect.position << std::endl;
    out << "Salary: " << lect.salary << std::endl;
    return out;
}

class PostGraduate : public Lecturer, public Student {
    public:
        PostGraduate(){};
        PostGraduate(str l, str f, str m, str u, unsigned int c, str g, str p, unsigned int s) : Lecturer(l, f, m, u, p, s), Student(l, f, m, u, c, g), Person(l, f, m, u) {};
        friend std::istream& operator>>(std::istream& in, PostGraduate& p);
        friend std::ostream& operator<<(std::ostream& out, PostGraduate& p);
};

std::istream& operator>>(std::istream& in, PostGraduate& p) {
    in >> p.last_name >> p.first_name >> p.middle_name >> p.university >> p.course >> p.group >> p.position >> p.salary;
    return in;
}

std::ostream& operator<<(std::ostream& out, PostGraduate& p) {
    out << p.last_name + d + p.first_name + d + p.middle_name << std::endl;
    out << "University: " << p.university << std::endl;
    out << "Course: " << p.course << std::endl;
    out << "Group: " << p.group << std::endl;
    out << "Position: " << p.position << std::endl;
    out << "Salary: " << p.salary << std::endl;
    return out;
}

int main() {
    Person *people = new Person[AMOUNT];
    Person p;
    Student s;
    Lecturer lect;
    PostGraduate postgrad;
    std::string answer;
    for (int i = 0; i < AMOUNT; i++) {
        std::cout << "Choose: Person[p], Student[s], Lecturer[l], Postgraduate[post]: ";
        std::cin >> answer;
        if (answer == "p") {std::cin >> people[i];}
        else {
            if (answer == "s") {
                std::cin >> s;
                people[i] = s;
            }
            if (answer == "l") {
                std::cin >> lect;
                people[i] = lect;
            }
            if (answer == "post") {
                std::cin >> postgrad;
                people[i] = postgrad;
            }
        }
    }
    for (int i = 0; i < AMOUNT; i++) {
        std::cout << people[i].get_university() << std::endl;
    }
}
