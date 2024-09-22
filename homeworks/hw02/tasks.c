#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void task7() {
    double a, b;
    while (true) {
        printf("a = ");
        scanf("%lf", &a);
        printf("b = ");
        scanf("%lf", &b);
        if (a > 0 && b > 0) {
            break;
        }
        else {
            printf("Invalid data: radius of an ellipse is a positive value.\n");
        }
    }
    printf("Area of an ellipse with the radiuses <%g> and <%g> = %g\n", a, b, a * b * M_PI);
}

double median(double a, double b, double c) {
    /*
    Calculates the length of a median that connects a vertex
    and a side with the length <a>.

    Args:
        a, b, c (double): Lengths of the sides.
    
    Returns:
        res (double): The length of the median.
    */
   return sqrt(2 * b * b + 2 * c * c - a * a) / 2;
}

double bisector(double a, double b, double c) {
    /*
    Calculates the length of a bisector that connects a vertex
    and a side with the length <a>.

    Args:
        a, b, c (double): Lengths of the sides.
    
    Returns:
        res (double): The length of the bisector.
    */  
   double s = (a + b + c) / 2;
   return 2 * sqrt(b * c * s * (s - a)) / (b + c);
}

double height(double a, double b, double c) {
    /*
    Calculates the length of a bheight that connects a vertex
    and a side with the length <a>.

    Args:
        a, b, c (double): Lengths of the sides.
    
    Returns:
        res (double): The length of the height.
    */  
   double s = (a + b + c) / 2;
   return 2 * sqrt(s * (s - a) * (s - b) * (s - c)) / a;
}

void task8() {
    double a, b, c;
    while (true) {
        printf("a = ");
        scanf("%lf", &a);
        printf("b = ");
        scanf("%lf", &b);
        printf("c = ");
        scanf("%lf", &c);
        if (a < b + c && b < a + c && c < a + b) {
            break;
        }
        else {
            printf("Invalid data: the triangle inequality doesn't hold.\n");
        }
    }
    printf("Median, constructed to the side with the length of %g: %g\n", a, median(a, b, c));
    printf("Median, constructed to the side with the length of %g: %g\n", b, median(b, a, c));
    printf("Median, constructed to the side with the length of %g: %g\n", c, median(c, b, a));
    printf("Bisector, constructed to the side with the length of %g: %g\n", a, bisector(a, b, c));
    printf("Bisector, constructed to the side with the length of %g: %g\n", b, bisector(b, a, c));
    printf("Bisector, constructed to the side with the length of %g: %g\n", c, bisector(c, b, a));
    printf("Height, constructed to the side with the length of %g: %g\n", a, height(a, b, c));
    printf("Height, constructed to the side with the length of %g: %g\n", b, height(b, a, c));
    printf("Height, constructed to the side with the length of %g: %g\n", c, height(c, b, a));
}

void task9() {
    double alpha, beta, gamma, r, area;
    while (true) {
        printf("alpha (in degrees) = ");
        scanf("%lf", &alpha);
        printf("beta (in degrees) = ");
        scanf("%lf", &beta);
        printf("c (in degrees) = ");
        scanf("%lf", &gamma);
        alpha = 180 * alpha / M_PI;
        beta = 180 * beta / M_PI;
        gamma = 180 * gamma / M_PI;
        if (fabs(alpha + beta + gamma - 180) > __DBL_EPSILON__ && alpha > 0 && beta > 0 && gamma > 0) {
            break;
        }
        else {
            printf("Invalid data. Try again.\n");
        }
    }
    printf("r (the radius of an inscribed circle) = ");
    scanf("%lf", &r);
    area = r * r * ((1 / tan(alpha / 2)) + (1 / tan(beta / 2)) + (1 / tan(gamma / 2)));
    printf("Area of the triangle = %g\n", area);
}

void task10() {
    double a, b, c, alpha, beta, gamma;
    while (true) {
        printf("a = ");
        scanf("%lf", &a);
        printf("b = ");
        scanf("%lf", &b);
        printf("c = ");
        scanf("%lf", &c);
        if (a < b + c && b < a + c && c < a + b) {
            break;
        }
        else {
            printf("Invalid data: the triangle inequality doesn't hold.\n");
        }
    }
    alpha = acos((b * b + c * c - a * a) / (2 * b * c));
    beta = acos((a * a + c * c - b * b) / (2 * a * c));
    gamma = acos((a * a + b * b - c * c) / (2 * a * b));
    printf("The angle between the sides %g and %g = %g (rad)\n", b, c, alpha);
    printf("The angle between the sides %g and %g = %g (deg)\n", b, c, alpha * 180 / M_PI);
    printf("The angle between the sides %g and %g = %g (rad)\n", a, b, gamma);
    printf("The angle between the sides %g and %g = %g (deg)\n", a, b, gamma * 180 / M_PI);
    printf("The angle between the sides %g and %g = %g (rad)\n", a, c, beta);
    printf("The angle between the sides %g and %g = %g (deg)\n", a, c, beta * 180 / M_PI);
}

void task11() {
    double r, h, volume;
    while (true) {
        printf("r = ");
        scanf("%lf", &r);
        printf("h = ");
        scanf("%lf", &h);
        if (r >= 0 && h >= 0) {
            break;
        }
        else {
            printf("Invalid data: no negative values are allowed.\n");
        }
    }
    volume = h * M_PI * r * r;
    printf("The volume of the cylinder = %g\n", volume);
}

void task12() {
    double r, h, volume;
    while (true) {
        printf("r = ");
        scanf("%lf", &r);
        printf("h = ");
        scanf("%lf", &h);
        if (r >= 0 && h >= 0) {
            break;
        }
        else {
            printf("Invalid data: no negative values are allowed.\n");
        }
    }
    volume = h * M_PI * r * r / 3;
    printf("The volume of the cone = %g\n", volume);
}

void task13() {
    double r, R;
    while (true) {
        printf("r (inner radius) = ");
        scanf("%lf", &r);
        printf("R (outer radius) = ");
        scanf("%lf", &R);
        if (r <= 0 || R <= 0) {
            printf("Invalid data: radiuses must have positive values.\n");
        }
        else if (r > R) {
            printf("Invalid data: the inner radius can't be greater than the outer radius.\n");
        }
        else {
            break;
        }
    }
    printf("The volume of the torus = %g\n", 2 * M_PI * M_PI * r * r * R);
}

void task15() {
    double x, y, x_2, y_2, temp, f1, f2, f3;
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);
    temp = x + y;
    f1 = temp * temp * temp;
    temp = x * x * y * y;
    f2 = temp * (1 + x * y + temp * temp);
    x_2 = x * x;
    y_2 = y * y;
    f3 = (x + x_2) * (1 + x_2) + (y + y_2) * (1 + y_2);
    printf("f1(%g, %g) = %g\n", x, y, f1);
    printf("f2(%g, %g) = %g\n", x, y, f2);
    printf("f3(%g, %g) = %g\n", x, y, f3);
}

void task16() {
    double x0, y0, x, y, distance, a, b, c;
    printf("x0 = ");
    scanf("%lf", &x0);
    printf("y0 = ");
    scanf("%lf", &y0);
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);
    distance = sqrt(pow(x - x0, 2) + pow(y - y0, 2));
    printf("a) The distance between the points (%g, %g) and (%g, %g) = %g\n", x0, y0, x, y, distance);

    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);
    distance = fabs(a * x0 + b * y0 + c) / sqrt(a * a + b * b);
    printf("b) The distance between the point (%g, %g) and the line <%g * x + %g * y + %g = 0> is equal to%g\n", x0, y0, a, b, c, distance);

    while (true) {
        printf("a = ");
        scanf("%lf", &a);
        printf("b = ");
        scanf("%lf", &b);
        printf("c = ");
        scanf("%lf", &c);
        if (fabs(a * b - 1) < __DBL_EPSILON__) {
            printf("Invalid data: a * b mustn't be equal to 1.\n");
        }
        else {
            break;
        }
    }
    x = - b * c * (a - 1) / (1 - a * b) - c;
    y = c * (a - 1) / (1 - a * b);
    distance = sqrt(pow(x - x0, 2) + pow(y - y0, 2));
    printf("c) The distance between the point (%g, %g) and the point of the intersection of the lines " 
    "<x + %g * y + %g = 0> and <%g * x + y + %g = 0> is equal to %g\n", x0, y0, b, c, a, c, distance);
}

double th(double x) {
    return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}

double th_der(double x) {
    return 4 / pow((exp(x) + exp(-x)), 2);
}

double bent(double x) {
    return (sqrt(x * x + 1) - 1) / 2 + x;
}

double bent_der(double x) {
    return x / (2 * sqrt(x * x + 1)) + 1;
}

double softSign(double x) {
    return x / (1 + fabs(x));
}

double softSign_der(double x) {
    if (x > 0) {
        return 1 / pow(1 + x, 2);
    }
    else {
        return 1 / pow(1 - x, 2);
    }
}

double softPlus(double x) {
    return log(1 + exp(x));
}

double softPlus_der(double x) {
    return 1 - 1 / (1 + exp(x));
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double sigmoid_der(double x) {
    return 1 / (exp(x) * (1 + exp(-x)) * (1 + exp(-x)));
}

double invsqrt(double x, double alpha) {
    return x / sqrt(1 + alpha * x * x);
}

double invsqrt_der(double x, double alpha) {
    return (fabs(1 + alpha * x * x) - alpha * x * x) / pow(1 + alpha * x * x, 3/2);
}

double sigmweight(double x) {
    return x / (1 + exp(-x));
}

double sigmweight_der(double x) {
    return (exp(-x) * (x - 1) + 1) / pow(1 + exp(-x), 2);
}

void task17() {
    double x, alpha;
    printf("x = ");
    scanf("%lf", &x);
    printf("alpha = ");
    scanf("%lf", &alpha);
    printf("a) th(%g) = %g,\n   th'(%g) = %g\n", x, th(x), x, th_der(x));
    printf("b) bent(%g) = %g,\n   bent'(%g) = %g\n", x, bent(x), x, bent_der(x));
    printf("c) softSign(%g) = %g,\n", x, softSign(x));
    if (fabs(x) < __DBL_EPSILON__) {
        printf("   The derivative of a function <softSign> at the point <%g> doesn't exist.\n", x);
    }
    else {
        printf("   softSign'(%g) = %g\n", x, softSign_der(x));
    }
    printf("d) arctg(%g) = %g,\n   arctg'(%g) = %g\n", x, atan(x), x, 1 / (1 + x * x));
    printf("e) gauss(%g) = %g,\n   gauss'(%g) = %g\n", x, exp(- x * x), x, -2 * x * exp(- x * x));
    printf("f) softPlus(%g) = %g,\n   softPlus'(%g) = %g\n", x, softPlus(x), x, softPlus_der(x));
    printf("g) sigmoid(%g) = %g,\n   sidmoid'(%g) = %g\n", x, sigmoid(x), x, sigmoid_der(x));
    if (alpha < 0 && (fabs(x - (1 / sqrt(fabs(alpha)))) < __DBL_EPSILON__ || fabs(x + (1 / sqrt(fabs(alpha)))) < __DBL_EPSILON__ )) {
        printf("h) Function <invsqrt> is undefined at the point <%g>.\n", x);
    }
    else {
        printf("h) invsqrt(%g, %g) = %g,\n   invsqrt'(%g, %g) = %g\n", x, alpha, invsqrt(x, alpha), x, alpha, invsqrt_der(x, alpha));

    }
    printf("i) sigmweight(%g) = %g,\n   sigmweight'(%g) = %g\n", x, sigmweight(x), x, sigmweight_der(x));
}

int main() {
    task17();
}
