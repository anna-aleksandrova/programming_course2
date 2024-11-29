#include <iostream>
#include <vector>

class Auto {
    public:
        Auto(){}
        Auto(std::string name_, std::string model_, int number_, int ident_) {
            name = name_;
            model = model_;
            number = number_;
            identificator = ident_;
        }
        std::string get_model() {return model;}
        int get_identificator() {return identificator;}
        friend std::istream& operator>>(std::istream& in, Auto& a);
        friend std::ostream& operator<<(std::ostream& out, Auto& a);
    private:
        std::string name, model;
        int number, identificator;
};

std::istream& operator>>(std::istream& in, Auto& a) {
    std::cout << "Enter the name, model, number and identificator: ";
    in >> a.name >> a.model >> a.number >> a.identificator;
    return in;
}

std::ostream& operator<<(std::ostream& out, Auto& a) {
    out << "Name: " << a.name << std::endl;
    out << "Model: " << a.model << std::endl;
    out << "Number: " << a.number << std::endl;
    out << "Identificator: " << a.identificator << std::endl;
    return out;
}

int main() {
    std::vector<Auto> autos;
    std::string answer;
    Auto a;
    while(1) {
        std::cout << std::endl;
        std::cin >> a;
        autos.push_back(a);
        std::cout << "Continue entering[y/n]: ";
        std::cin >> answer;
        if (answer == "n") {break;}
    }
    std::string model;
    std::cout << "Enter the needed model: ";
    std::cin >> model;
    std::cout << "Identificators of the owners of auto with model <" << model << ">:" << std::endl;
    for (auto a:autos) {
        if (a.get_model() == model) {std::cout << a.get_identificator() << std::endl;}
    }
}
