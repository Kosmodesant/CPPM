#include "SecondaryFunction.h"


size_t utf8_strlen(std::string_view str)
{
	size_t c, i, ix, q;
	for (q = 0, i = 0, ix = str.length(); i < ix; i++, q++)
	{
		c = (unsigned char)str[i];
		if (c >= 0 && c <= 127) i += 0;
		else if ((c & 0xE0) == 0xC0) i += 1;
		else if ((c & 0xF0) == 0xE0) i += 2;
		else if ((c & 0xF8) == 0xF0) i += 3;
		else return 0;
	}
	return q;
}

// заголовок
void printHeader(std::string_view str)
{
	setlocale(LC_ALL, "ru_RU.UTF-8");	// задаем русский текст
	//system("chcp UTF-8");				// настраиваем кодировку консоли
	//system("chcp ANSI");				// настраиваем кодировку консоли
	//system("chcp 1251");				// настраиваем кодировку консоли
	//SetConsoleCP(CP_UTF8);
	//SetConsoleOutputCP(CP_UTF8);

	//SetConsoleTitleA("Заголовок");
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
	consoleCol(col::br_green);
	std::cout << str << "\n";
	for (auto i = 0; i < utf8_strlen(str); ++i) std::cout << "-";
	std::cout << "\n\n";
	consoleCol(col::cancel);
}

#ifdef _WIN32
void consoleCol(WORD color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#else
void consoleCol(const char* color)
{
	std::cout << color;
}
#endif
