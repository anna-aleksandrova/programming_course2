#include <iostream>
#include <cstring>
#include <fstream>

#define LEN 100

class Person {
    public:
        Person(){};
        Person(std::string name_, unsigned int byear_) {
            name = name_;
            byear = byear_;
        }
        static Person input();
        virtual void show();
        friend std::ostream& operator<<(std::ostream& os, const Person& p);
        friend std::istream& operator>>(std::istream& is, Person& p);
    protected:
        std::string name;
        unsigned int byear;
};

Person Person::input() {
    std::string name;
    unsigned int byear;
    std::cout << "Enter the name: ";
    std::cin >> name;
    std::cout << "Enter the birth year: ";
    std::cin >> byear;
    Person p(name, byear);
    return p;
}

void Person::show() {
    std::cout << "Person: (name, birth year) = (" << name << " , " << byear << ")" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "Person: (name, birth year) = (" << p.name << " , " << p.byear << ")" << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Person& p) {
    is >> p.name >> p.byear;
    return is;
}

class Fellow : public Person {
    public:
        Fellow(){};
        Fellow(std::string name, unsigned int byear, std::string phone_number_) : Person(name, byear) {
            phone_number = phone_number_;
        }
        Fellow(const Fellow &f_) {
            name = f_.name;
            byear = f_.byear;
            phone_number = f_.phone_number;
        } 
        static Fellow input();
        void show();
        friend std::ostream& operator<<(std::ostream& os, const Fellow& p);
        friend std::istream& operator>>(std::istream& is, Fellow& p);
        friend class TelephoneDirectory;
    private:
        std::string phone_number;
};

Fellow Fellow::input() {
    std::string name, phone_number;
    unsigned int byear;
    std::cout << "Enter the name: ";
    std::cin >> name;
    std::cout << "Enter the birth year: ";
    std::cin >> byear;
    std::cout << "Enter the phone number: ";
    std::cin >> phone_number;
    return Fellow(name, byear, phone_number);
}

void Fellow::show() {
    std::cout << "Fellow: (name, birth year, phone_number) = (" << name << ", " << byear << ", " << phone_number << ")" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fellow& f) {
    os << f.name << " " << f.byear << " " << f.phone_number << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Fellow& f) {
    is >> f.name >> f.byear >> f.phone_number;
    return is;
}

class TelephoneDirectory {
    public:
        TelephoneDirectory(std::string filename_){
            list = new Fellow[LEN];
            amount = 0;
            filename = filename_;
        }
        TelephoneDirectory(Fellow *list_, unsigned int amount_, std::string filename_) {
            list = list_;
            amount = amount_;
            filename = filename_;
        }
        ~TelephoneDirectory() {delete[] list;}
        int add_fellow(Fellow f);
        std::string search_phonenumber(std::string last_number);
        int replace(std::string last_name, std::string new_number);
    private:
        Fellow* list;
        unsigned int amount;
        std::string filename;
};

int TelephoneDirectory::add_fellow(Fellow f) {
    std::ofstream fout;
    fout.open(filename, std::ios::app);
    if (fout) {
        fout << f.name << " " << f.byear << " " << f.phone_number << std::endl;
        fout.close();
        list[amount] = f;
        amount++;
        return 0;
    }
    else {
        std::clog << "Error during opening the file => your fellow wasn't added.\n";
        return 1;
    }
}

std::string TelephoneDirectory::search_phonenumber(std::string last_name) {
    for (int i = 0; i < amount; i++) {
        std::cout << list[i].name << std::endl;
        if (list[i].name == last_name) {
            return list[i].phone_number;
        }
    }
    return std::string("No contact with such a last name.\n");
}

int TelephoneDirectory::replace(std::string last_name, std::string new_number) {
    for (int i = 0; i < amount; i++) {
        if (list[i].name == last_name) {list[i].phone_number = new_number; break;}
        else {return 1;}
    }
    std::fstream file;
    file.open(filename, std::ios::out | std::ios::trunc);
    if (file) {
        for (int i = 0; i < amount; i++) {
            file << list[i].name << " " << list[i].byear << " " << list[i].phone_number << std::endl;
        }
        file.close();
        return 0;
    }
    else {
        return 0;
    }
}

int main() {
    Person p;
    std::cout << "Enter the person's data:\n";
    std::cin >> p;
    std::cout << p;

    Fellow f;
    std::cout << "Enter their fellow's data:\n";
    std::cin >> f;
    std::cout << f;
    f.show();

    TelephoneDirectory td_user("telephone_directory.txt");
    std::string answer;
    while (1) {
        std::cout << "Enter the data of the person: \n";
        std::cin >> f;
        std::cout << f;
        td_user.add_fellow(f);
        while (1) {
            std::cout << "Would you like to continue[y/n]:\n";
            std::cin >> answer;
            if (answer != std::string("y") && answer != std::string("n")) {continue;}
            else {break;}
        }
        if (answer == std::string("n")) {break;}
    }
    std::cout << td_user.search_phonenumber(std::string("2039481"));
    std::cout << td_user.replace(std::string("Brown"), std::string("1234567"));
}
