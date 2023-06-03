#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include "windows.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	string input;
	cout << "[IN]: ";
	getline(cin, input);

	unordered_map<char, unsigned int> charMap;
	for (const auto& c : input)
	{
		auto it = charMap.find(c);

		if (it == charMap.end())
		{
			charMap.insert({ c, 1 });
		}
		else
		{
			++((*it).second);
		}
	}

	// Переупорядочиваем
	multimap<unsigned int, char, greater<char>> charOrderMap;
	for (const auto& [c, count] : charMap)
	{
		charOrderMap.insert({ count, c });
	}

	// Выводим на экран
	cout << "[OUT]:" << endl;
	for (const auto& [count, c] : charOrderMap)
	{
		cout << c << ": " << count << endl;
	}
}