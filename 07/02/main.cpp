#include <iostream>
#include <set>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	size_t count = 0;
	cout << "[IN]: " << endl;
	cin >> count;
	set<int, greater<int>> valueSet;
	for (size_t i = 0; i < count; ++i)
	{
		int v;
		cin >> v;
		valueSet.insert(v);
	}

	cout << "[OUT]:" << endl;
	for (const auto& v : valueSet)
	{
		cout << v << endl;
	}
}