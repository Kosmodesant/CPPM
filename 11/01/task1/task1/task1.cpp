#include <vector>
#include <iostream>

using namespace std;

template <class Vtype>
void move_vectors(vector<Vtype>& where, vector<Vtype>& from)
{
	cout << "\nmove_vectors\n\n";
	where = move(from);
}

template <class Vtype>
void print(const vector<Vtype>& vec, const string& str);

int main(int argc, char** argv)
{

	vector <string> one = { "test_string1", "test_string2" };
	vector <string> two;

	print<string>(one, "one");
	print<string>(two, "two");

	move_vectors<string>(two, one);

	print<string>(one, "one");
	print<string>(two, "two");

	return 0;
}

template <class Vtype>
inline void print(const vector<Vtype>& vec, const string& str)
{
	if (!vec.empty())
	{
		cout << "vector " << str << ":\n";
		for (const auto& elem : vec) cout << elem << "\n";
	}
}