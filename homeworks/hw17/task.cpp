#include <iostream>
#include <fstream>

class OpeningError : public std::exception {
    public:
        const char* what() const noexcept {
            return "Can't open the file.";
        }
};

class NumberIndexError : public std::exception {
    public:
        const char* what() const noexcept {
            return "No number with such an index in the file.";
        }
};

class RowIndexError : public std::exception {
    public:
        const char* what() const noexcept {
            return "No row with such an index in the file.";
        }
};

class RowNumberError : public std::exception {
    public:
        const char* what() const noexcept {
            return "No number with such an index in the row.";
        }
};

class ReadingError : public std::exception {
    public:
        const char* what() const noexcept {
            return "Can't read from the file.";
        }
};

class Row_Overflow : public std::exception {
    public:
        const char* what() const noexcept {
            return "Can't write more rows than allowed into the file.";
        }
};

class Number_Overflow : public std::exception {
    public:
        const char* what() const noexcept {
            return "Can't write more numbers than allowed into the file.";
        }
};

class Textfile {
    public:
        Textfile(std::string filename_, unsigned int number_am_, unsigned int row_am_) {
            filename = filename_;
            number_am = number_am_;
            row_am = row_am_;
            sizes = new size_t[row_am];
        }
        Textfile(std::string filename_, double* array[2], size_t sizes[2]);
        ~Textfile() {delete[] sizes;}
        void write(double* array, size_t size, bool end);
        double* input_array(unsigned int size);
        void input_console();
        void show();
        double number(unsigned int index);
        void append(double* array, size_t size);
        void del(unsigned int row_number, unsigned int index);
    private:
        std::string filename;
        unsigned int number_am = 0, row_am = 0, current_number_am = 0, current_row_am = 0;
        size_t *sizes;
};

void Textfile::write(double* array, size_t size, bool end) {
    try {
        std::ofstream fout(filename, std::ios::out|std::ios::app);
        if (!fout.is_open()) {throw OpeningError();}
        else {
            if (end == true) {
                for (int i = 0; i < size; i++) {fout << array[i] << " ";}
                fout << std::endl;
                fout.close();
            }
            else {
                for (int i = 0; i < size; i++) {fout << array[i] << " ";}
                fout.close();
            }
        }
    }
    catch (OpeningError& e) {std::cout << e.what() << std::endl;}
}

double* Textfile::input_array(unsigned int size) {
    double* array = new double[size];
    for (int i = 0; i < size; i++) {std::cin >> array[i];}
    return array;
}

void Textfile::input_console() {
    unsigned int size;
    for (int i = 0; i < row_am; i++) {
        std::cout << "Enter the amount of numbers in the " << i + 1 << " row: ";
        try {
            std::cin >> size;
            if (current_number_am + size > number_am) {throw Number_Overflow();}
            else{
                current_number_am += size;
                double* array = input_array(size);
                write(array, size, true);
                delete[] array;
            }
        }
        catch(Number_Overflow& e) {
            std::cout << e.what() << std::endl;
            break;
        }
    }
}

Textfile::Textfile(std::string filename_, double* array[2], size_t sizes_[2]) {
    filename = filename_;
    row_am = 2;
    sizes = sizes_;
    for (int i = 0; i < 2; i++) {
        write(array[i], sizes[i], true);
        number_am += sizes[i];
        current_number_am += sizes[i];
        current_row_am++;
    }
}

void Textfile::show() {
    try {
        std::ifstream fin(filename);
        if (!fin.is_open()) {
            throw OpeningError();
        }
        else {
            double temp;
            while (!fin.eof()) {
                for (int j = 0; j < row_am; j++) {
                    for (int i = 0; i < sizes[j]; i++) {
                        fin >> temp;
                        std::cout << temp << " ";
                    }
                    std::cout << std::endl;
                }
            }
            fin.close();
        }
    }
    catch (OpeningError& e) {
        std::cout << e.what() << std::endl;
    }
}

double Textfile::number(unsigned int index) {
    double temp;
    try {
        if (index > current_number_am) {
            throw NumberIndexError();
        }
        try {
            std::fstream fin(filename, std::ios::in);
            if (!fin.is_open()) {throw OpeningError();}
            for (int i = 0; i <= index; i++) {
                fin >> temp;
            }
        }
        catch (OpeningError& e) {std::cout << e.what() << std::endl;}
    }
    catch (NumberIndexError& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return temp;
}

void Textfile::append(double* array, size_t size) {
    try {
        if (current_number_am + size > number_am) {throw Number_Overflow();}
        if (current_row_am + 1 > row_am) {throw Row_Overflow();}
        write(array, size, true);
        sizes[current_row_am] = size;
        current_number_am += size;
        current_row_am++;
    }
    catch (Number_Overflow& e) {std::cout << e.what() << std::endl;}
    catch (Row_Overflow& e) {std::cout << e.what() << std::endl;}
}

void Textfile::del(unsigned int row_number, unsigned int index) {
    try {
        if (row_number > current_row_am) {throw RowIndexError();}
        std::cout << sizes[row_number] << std::endl;
        if (index > sizes[row_number]) {throw RowNumberError();}
        try {
            std::ifstream fin(filename, std::ios::in);
            std::ofstream fout("temp.txt", std::ios::out);
            if (!fin.is_open() || !fout.is_open()) {throw OpeningError();}
            double temp;
            while (!fin.eof()) {
                for (int i = 0; i < row_am; i++) {
                    for (int j = 0; j < sizes[i]; j++) {
                        if (i == row_number && j == index) {continue;}
                        fin >> temp;
                        fout << temp << " ";
                    }
                    fout << std::endl;
                }
            }
            fin.close();
            fout.close();
            std::remove(filename.c_str());
            std::rename("temp.txt", filename.c_str());
        }
        catch(OpeningError& e) {std::cout << e.what() << std::endl;}
        if (sizes[row_number] == 1) {row_am--;}
        number_am--;

    }
    catch(RowIndexError& e) {std::cout << e.what() << std::endl;}
    catch(RowNumberError& e) {std::cout << e.what() << std::endl;}
}

int main() {
    double row1[5] = {1, 2, 3, 4, 5};
    Textfile file("test2.txt", 20, 3);
    file.append(row1, 5);
    file.del(0, 2);
}
