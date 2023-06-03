#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void delDubls(vector<int>& vec)
{ 
	sort(vec.begin(), vec.end());
	vec.erase((unique(vec.begin(), vec.end())), vec.end());
}

template <typename VType>
ostream& operator<< (ostream& out, const vector<VType>& vect)
{
	for (const auto& val : vect) out << val << " ";
	return out;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<int> vec{ 1, 1, 2, 5, 6, 1, 2, 4 };
	cout << "[IN]: " << vec << endl;
	delDubls(vec);
	cout << "[OUT]: " << vec << endl;
	return 0;
}
