#include <iostream> 
#include <vector>
#include <variant>

using namespace std;

variant<int, string, vector<int>> get_variant()
{
	srand(time(nullptr));
	int random_variable = rand() % 3;
	variant<int, string, vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

ostream& operator<< (ostream& out, const vector<int>& vect)
{
	for (const auto& val : vect) out << val << " ";
	return out;
}

ostream& operator<< (ostream& out, const variant<int, string, vector<int>>& var)
{
	visit([&out](auto& elem) { out << elem << endl; }, var);
	return out;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	auto var = get_variant();
	if (holds_alternative<int>(var)) get<int>(var) *= 2;// если int -> умножаем на 2
	cout << var << endl;
	return 0;
}
