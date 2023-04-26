#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void print(const vector<int>& v, const string& str)
{
	cout << str << " данные: ";
	for (const auto& val : v) cout << val << " ";
	cout << endl;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	vector<int> vect{ 4, 7, 9, 14, 12 };
	print(vect, "Входные");
	for_each(begin(vect), end(vect),[](int& value) { if (value % 2) value *= 3; });
	print(vect, "Выходные");
	return 0;
}