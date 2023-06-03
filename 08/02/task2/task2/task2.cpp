#include <iostream>
#include <set>
#include <vector>
#include <list>

using namespace std;

template <class N>
void print_container(const N& cont, const string& str)
{
	cout << str << ": ";

	for (auto it = cont.cbegin(); it != cont.cend(); ++it)
		cout << *it << " ";
	cout << endl;

}

int main()
{
	setlocale(LC_ALL, "Russian");

	set<string> test_set = { "one", "two", "three", "four" };
	list<string> test_list = { "one", "two", "three", "four" };
	print_container(test_list, "test_list");
	vector<string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector, "test_vector");
	return 0;
}
