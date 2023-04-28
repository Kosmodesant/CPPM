

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
        int num = 0;
        while (num < 100) //бесконечныцй цикл
        {
            std::cout << count << ' ';
        }
        return 0;
    }

    //#include <iostream>
    //
    //    int main()
    //    {
    //        int num = 0;
    //     ...
    // 
    //        while (num == 100) // четкое условие
    //        {
    //            std::cout << count << ' ';
    //        }
    //        return 0;
    //    }


