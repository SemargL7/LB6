/* 
Створити шаблонний клас – одновимірний масив.   !

Тип елементів масиву визначається параметром шаблона (цілі числа, дійсні числа, символи або символьні рядки). !

Передбачити функції для виконання таких операцій: введення елементів у масив,
обчислення контрольної суми (сума кількостей одиниць у машинному зображенні елементів масиву),  
виведення елементів масиву на екран.    !
*/

#include <iostream>
//#include <cmath>
#include <string>

std::string to_binary_string(int n)
{
    std::string result;
    do
    {
        result += (char)('0' + (n % 2));
        n = n / 2;
    } while (n > 0);
    return result;
}

template <typename T>
class JustClass
{
private:
    T* v;
    int size;
public:
    JustClass() {}
    JustClass(T* v, int size) {
        this->v = v;
        this->size = size;
    }
    ~JustClass() {}

    void Input(T* v[], int size) {
        this->v = *v;
        this->size = size;
    }

    
    void DataTypeSize() {
        int a = 0;
        for (int i = 0; i < size; i++) {
            a += (int)v[i];
        }
        std::cout << to_binary_string(a)  << " mirrored"<< std::endl;
        
    }
    void Output() {
        for (int i = 0; i < size; i++) {
            std::cout << v[i] << "\t";
        }
        std::cout << std::endl;
    }

};



void example(int n) {
    int nn = 0;
    if (n == 0) {
        std::cout << "Size:";
        std::cin >> nn;
        char* arr = new char[nn];
        for (int i = 0; i < nn; i++) {
            std::cout << "[" << i + 1 << "]:";
            std::cin >> arr[i];
        }
        JustClass<char> examp;
        examp.Input(&arr, nn);
        std::cout << "Sum:" << std::endl;
        examp.DataTypeSize();
        std::cout << "Output:" << std::endl;
        examp.Output();
        delete[]arr;
    }
    else if (n == 1) {
        std::cout << "Size:";
        std::cin >> nn;
        int* arr = new int[nn];
        for (int i = 0; i < nn; i++) {
            std::cout << "[" << i + 1 << "]:";
            std::cin >> arr[i];
        }
        JustClass<int> examp;
        examp.Input(&arr, nn);
        std::cout << "Sum:" << std::endl;
        examp.DataTypeSize();
        std::cout << "Output:" << std::endl;
        examp.Output();
        delete[]arr;
    }
    else if (n == 2) {
        std::cout << "Size:";
        std::cin >> nn;
        double* arr = new double[nn];
        for (int i = 0; i < nn; i++) {
            std::cout << "[" << i + 1 << "]:";
            std::cin >> arr[i];
        }
        JustClass<double> examp;
        examp.Input(&arr, nn);
        std::cout << "Sum:" << std::endl;
        examp.DataTypeSize();
        std::cout << "Output:" << std::endl;
        examp.Output();
        delete[]arr;
    }
}



int main()
{
    char arrays_char[] = "132132123";
    int arrays_int[] = { 12,15,35,15,50 };
    double arrays_double[] = { 100.05,105.150,10551.9,10.9 };
    
    JustClass<char> e_ch(arrays_char, *(&arrays_char + 1) - arrays_char);
    JustClass<int> e_in(arrays_int, *(&arrays_int + 1) - arrays_int);
    JustClass<double> e_db(arrays_double, *(&arrays_double + 1) - arrays_double);

    std::cout << "Sum:" << std::endl;
    e_ch.DataTypeSize(); e_in.DataTypeSize(); e_db.DataTypeSize();
    std::cout << "Output:" << std::endl;
    e_ch.Output(); e_in.Output(); e_db.Output();


    std::cout << "Your example:" << std::endl;
    int n = 0;
    std::cout << "Char(0), Int(1), Double(2):";
    std::cin >> n;

    example(n);
    getchar(); getchar();
}