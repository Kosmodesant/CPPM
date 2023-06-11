#include "SecondFunction/SecondaryFunction.h"
#include "Parser/Parser.h"

using namespace std;

int main()
{
	printHeader("Курсовой проект \"Парсер INI-файлов\"");

	try
	{
		auto print_lambda = [](Parser& par, const parseVar_t& var)
		{
			cout << "  <"
				<< par.getSection() << "."
				<< par.getVarName() << "="
				<< var << ">\n";
		};

		Parser parser("../../../test2.ini");

		auto varValue = parser.get_value<double>("Section1.var1");
		print_lambda(parser, varValue);

		varValue = parser.get_value<int>("Section2.var1");
		print_lambda(parser, varValue);

		varValue = parser.get_value<std::string>("Section2.var2");
		print_lambda(parser, varValue);

		varValue = parser.get_value<double>("Section1.var2");
		print_lambda(parser, varValue);
	}
	catch (const exception& err)
	{
		consoleCol(col::br_red);
		cout << "\nОшибка типа: " << typeid(err).name() << "\n";
		cout << err.what() << "\n";
		consoleCol(col::cancel);
	}

	return 0;
}
