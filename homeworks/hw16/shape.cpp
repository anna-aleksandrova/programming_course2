#include <iostream>
#include <cmath>

class Vector {
    public:
        Vector(){};
        Vector(double x_, double y_) {x = x_; y = y_;}
        void set_x(double x_) {x = x_;}
        void set_y(double y_) {y = y_;}
        double get_x() {return x;}
        double get_y() {return y;}
    private:
        double x, y;        
};

class Point {
    public:
        static int counter;
        Point(){counter++;}
        Point(double x_, double y_) {
            x = x_;
            y = y_;
            counter++;
        }
        ~Point() {counter--;}
        void set_x(double x_) {x = x_;}
        void set_y(double y_) {y = y_;}
        double get_x() {return x;}
        double get_y() {return y;}
        static Point input();
        void show() {std::cout << "(" << x << ", " << y << ")";}
        void operator+(Vector v) {
            x += v.get_x();
            y += v.get_y(); 
        }
        void rotate(double radians);
        friend class Segment;
    protected:
        double x, y;
};

int Point::counter = 0;

Point Point::input() {
    double x, y;
    std::cout << "Enter the coordinates:\n";
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    return Point(x, y);
}

void Point::rotate(double radians) {
    double temp = x * cos(radians) - y * sin(radians);
    y = x * sin(radians) + y * cos(radians);
    x = temp;
}

class Segment {
    public:
        Segment(){};
        Segment(Point start_, Point end_) {
            if (start_.x > end_.x) {
                start = end_;
                end = start_;
            }
            else {
                start = start_;
                end = end_;
            }
        }
        Segment(const Segment& s) {
            start = s.start;
            end = s.end;
        }
        static Segment input();
        void show();
        double length() {return sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2));}
        Point get_start() {return start;}
        Point get_end() {return end;}
        void operator+(Vector v) {start + v; end + v;}
        void rotate(double radians) {start.rotate(radians), end.rotate(radians);}
    private:
        Point start, end;
};

Segment Segment::input() {
    std::cout << "Start: \n";
    Point start = Point::input();
    std::cout << "End: \n";
    Point end = Point::input();
    return Segment(start, end);
}

void Segment::show() {
    std::cout << "start: ";
    start.show();
    std::cout << " ; end: ";
    end.show();
    std::cout << std::endl;
}

class Shape {
    public:
        virtual double measure1D() = 0;
        virtual double measure2D() = 0;
        virtual void move(Vector v) = 0;
        virtual void rotate(double radians) = 0;
        virtual void input() = 0;
        virtual void show() = 0;
};

class Polygonal : public Shape {
    public:
        virtual double measure1D() {
            Segment side1(ba1.get_start(), ba2.get_start());
            Segment side2(ba1.get_start(), ba2.get_start());
            return ba1.length() + ba2.length() + side1.length() + side2.length();}
        virtual void move(Vector v) {ba1 + v; ba2 + v;}
        virtual void rotate(double radians) {ba1.rotate(radians), ba2.rotate(radians);}
    protected:
        Segment ba1, ba2;
};

class Trapeze : public Polygonal {
    public:
        Trapeze(){};
        Trapeze(Segment ba1_, Segment ba2_) {ba1 = ba1_, ba2 = ba2_;}
        virtual void input() {
            std::cout << "Trapeze:\nLower base:\n";
            Segment ba1 = Segment::input();
            std::cout << "Upper base:\n";
            Segment ba2 = Segment::input();
        }
        virtual void show() {
            std::cout << "----------Trapeze----------\nBase 1: ";
            ba1.show();
            std::cout << "Base 2: ";
            ba2.show();
        }
        virtual double measure2D() {
            double h = fabs(ba2.get_start().get_y() - ba1.get_start().get_y());
            return h * (ba1.length() + ba2.length()) / 2;
        }
};

class Parallelogram : public Polygonal{
    public:
        Parallelogram(){};
        Parallelogram(Segment ba1_, Segment ba2_) {ba1 = ba1_, ba2 = ba2_;}
        virtual void input() {
            std::cout << "Parallelogram:\nLower base:\n";
            Segment ba1 = Segment::input();
            std::cout << "Upper base:\n";
            Segment ba2 = Segment::input();
        }
        virtual void show() {
            std::cout << "----------Parallelogram----------\nBase 1: ";
            ba1.show();
            std::cout << "Base 2: ";
            ba2.show();
        }
        virtual double measure2D() {
            double h = fabs(ba2.get_start().get_y() - ba1.get_start().get_y());
            return h * ba1.length();
        }
};

class Circle : public Shape {
    public:
        Circle(){};
        Circle(Point centre_, double radius_) {centre = centre_, radius = radius_;}
        virtual void input() {
            std::cout << "Circle:\nCentre:\n";
            Point centre = Point::input();
            std::cout << "Radius: ";
            std::cin >> radius;
        }
        virtual void show() {
            std::cout << "----------Circle----------\nCentre: ";
            centre.show();
            std::cout << std::endl << "Radius: " << radius << std::endl;
        }
        virtual double measure1D() {
            return 2 * M_PI * radius;}
        virtual double measure2D() {
            return M_PI * radius * radius;
        }
        virtual void move(Vector v) {centre + v;}
        virtual void rotate(double radians) {centre.rotate(radians);}
    protected:
        Point centre;
        double radius;
};

int main() {
    Circle c;
    c.input();
    c.show();
    std::cout << c.measure1D() << std::endl;
    std::cout << c.measure2D() << std::endl;
    c.move(Vector(2, 2));
    c.show();
    c.rotate(M_PI);
    c.show();
}
