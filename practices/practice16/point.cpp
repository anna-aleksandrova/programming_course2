#include <iostream>
#include <cmath>

class Point2D {
    public:
        static int counter;
        Point2D(){counter++;}
        Point2D(double x_, double y_) {
        x = x_;
        y = y_;
        counter++;
        }
        void set_x(double x_) {x = x_;}
        void set_y(double y_) {y = y_;}
        double get_x() {return x;}
        double get_y() {return y;}
        static Point2D input();
        virtual void output();
        friend class Segment;
    protected:
        double x, y;
        int dimension = 2;
};

int Point2D::counter = 0;

Point2D Point2D::input() {
    double x, y;
    std::cout << "Enter coordinates of the Point2D:\n";
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    return Point2D(x, y);
}

void Point2D::output() {
    std::cout << "(" << x << ", " << y << ")";
}

class Point3D : public Point2D {
    public:
        static int counter;
        Point3D(){counter++;}
        Point3D(double x_, double y_, double z_) : Point2D(x_, y_) {
            z = z_;
        }
        static Point3D input();
        virtual void output();
        friend class Segment;
    private:
        double z;
        int dimension = 3;
};

int Point3D::counter = 0;

Point3D Point3D::input() {
    double x, y, z;
    std::cout << "Enter coordinates of the Point3D:\n";
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    std::cout << "z: ";
    std::cin >> z;
    return Point3D(x, y, z);
}

void Point3D::output() {
    std::cout << "(" << x << ", " << y << ", " << z << ")";
}

class Segment {
    public:
        Segment(Point2D start_, Point2D end_) {
            start2D = start_;
            end2D = end_;
            dimension = 2;
        }
        Segment(Point3D start_, Point3D end_) {
            start3D = start_;
            end3D = end_;
            dimension = 3;
        }
        static Segment input();
        void output();
        double length();
    private:
        Point2D start2D, end2D;
        Point3D start3D, end3D;
        int dimension;
};

Segment Segment::input() {
    int dimension;
    std::cout << "Enter the dimension: ";
    std::cin >> dimension;
    if (dimension == 2) {
        Point2D start = Point2D::input();
        Point2D end = Point2D::input();
        return Segment(start, end);
    }
    else {
        Point3D start = Point3D::input();
        Point3D end = Point3D::input();
        return Segment(start, end);
    }
}

void Segment::output() {
    if (dimension == 2) {
        std::cout << "start: ";
        start2D.output();
        std::cout << " ; end: ";
        end2D.output();
        std::cout << std::endl;
    }
    else {
        std::cout << "start: ";
        start3D.output();
        std::cout << " ; end: ";
        end3D.output();
        std::cout << std::endl;
    }
}

double Segment::length() {
    if (dimension == 2) {
        return sqrt(pow((end2D.x - start2D.x), 2) + pow((end2D.y - start2D.y), 2));
    }
    else {
        return sqrt(pow((end3D.x - start3D.x), 2) + pow((end3D.y - start3D.y), 2) + pow((end3D.z - start3D.z), 2));
    }
}

int main() {
    Segment s2D = Segment::input();
    Segment s3D = Segment::input();
    s2D.output();
    s3D.output();
    std::cout << s2D.length() << std::endl;
    std::cout << s3D.length() << std::endl;
}
