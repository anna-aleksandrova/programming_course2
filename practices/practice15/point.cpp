#include <iostream>
#include <cstring>
#include <cmath>

#define LEN 100

// it's assumed that we work in the arithmetic vector space of dimension 2
class Point {
    double x, y;
    public:
        static int counter;
        Point(){counter++;}
        Point(double x_, double y_) {
        x = x_;
        y = y_;
        counter++;
    }
        void set_x(double x_) {x = x_;}
        void set_y(double y_) {y = y_;}
        double get_x() {return x;}
        double get_y() {return y;}
        static Point input();
        void output();
};

int Point::counter = 0;

Point Point::input() {
    double x_, y_;
    std::cout << "Enter coordinates of the point:\n";
    std::cout << "x: ";
    std::cin >> x_;
    std::cout << "y: ";
    std::cin >> y_;
    return Point(x_, y_);
}

void Point::output() {
    std::cout << "(" << x << ", " << y << ")\n";
}

class Polygon {
    Point *vertices;
    int vertices_amount = 0;
    public:
        Polygon(){
            Point *vertices = new Point[LEN];
        }
        ~Polygon(){
            delete[] vertices;
        }
        static Polygon input();
        void output();
        int vert_amount() {return vertices_amount;}
        double perimeter();
};

Polygon Polygon::input() {
    Polygon p;
    std::cout << "Enter the polygon:\n";
    std::string answer("y");
    int i = 0;
    while (answer == "y") {
        p.vertices[i] = Point::input();
        i++;
        std::cout << "Would you to continue?[y/n]\n";
        std::cin >> answer;
    }
    p.vertices_amount = i;
    Point::counter = 0;
    return p;
}

void Polygon::output() {
    std::cout << "The polygon: \n";
    for (int i = 0; i < vertices_amount; i++) {
        vertices[i].output();
    }
}

double vector_norm(Point start, Point end) {
    return sqrt(pow((end.get_x() - start.get_x()), 2) + pow((end.get_y() - start.get_y()), 2));
}

double Polygon::perimeter() {
    double res = 0;
    for (int i = 0; i < vertices_amount - 1; i++) {
        res += vector_norm(vertices[i], vertices[i+1]);
    }
    res += vector_norm(vertices[vertices_amount-1], vertices[0]);
    return res;
}

int main() {
    Polygon p = Polygon::input();
    p.output();
    std::cout << "The amount of vertices in the polygon: " << p.vert_amount() << std::endl;
    std::cout << "The perimeter of the polygon: " << p.perimeter() << std::endl;
}
