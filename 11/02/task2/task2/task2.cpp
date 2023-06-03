#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class big_integer
{
private:
    string number;

public:
    big_integer() = default;

    big_integer(const string& value) : number(value) {}

    big_integer(string&& value) : number(std::move(value)) {}

    big_integer(const big_integer& other) = default;

    big_integer(big_integer&& other) noexcept = default;

    big_integer& operator=(const big_integer& other) = default;

    big_integer& operator=(big_integer&& other) noexcept = default;

    friend big_integer operator+(const big_integer& lhs, const big_integer& rhs)
    {
        string result;
        int carry = 0;
        int i = lhs.number.length() - 1;
        int j = rhs.number.length() - 1;

        while (i >= 0 || j >= 0 || carry != 0)
        {
            int digit1 = (i >= 0) ? (lhs.number[i] - '0') : 0;
            int digit2 = (j >= 0) ? (rhs.number[j] - '0') : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            result.push_back(digit + '0');

            i--;
            j--;
        }

        reverse(result.begin(), result.end());

        return big_integer(move(result));
    }

    friend big_integer operator*(const big_integer& lhs, int rhs)
    {
        string result;
        int carry = 0;
        int i = lhs.number.length() - 1;

        while (i >= 0 || carry != 0)
        {
            int digit = (i >= 0) ? (lhs.number[i] - '0') : 0;

            int product = digit * rhs + carry;
            carry = product / 10;
            int remainder = product % 10;
            result.push_back(remainder + '0');

            i--;
        }

        reverse(result.begin(), result.end());

        return big_integer(move(result));
    }

    friend ostream& operator<<(ostream& os, const big_integer& num)
    {
        os << num.number;
        return os;
    }
};

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    cout << result; // 193099

    return 0;
}