

//Синтаксическая ошибка 
#include <iostream>

int main()
{
    int a = 100;
    int b = 200;
    int c = 2 * (a + b;// пропущена скобка

    /*
    int a = 100;
    int b = 200;
    int c = 2 * (a + b);//  верно;*/


//Семантическая ошибка
#include <iostream>

    int main()
    {
        int num = 8;
        while (num != 10) {
            num += 1;
        }
        return 0;
    }

//#include <iostream>
//    int main() {
//        int num = 8;
//        while (num < 10) {
//            num += 1;
//            if (num > 9 && num < 11); доп условие выхода из бесконечного цикла
//            std::cout << num;
//        }
//        return 0;
//    }

    // ошибка линковки

// отсутсвует в каталоге проекта файл header.h


