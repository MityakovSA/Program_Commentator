#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	std::string::size_type pos_b, pos_e;
	string name, str;
	cout << "Enter file name: ";
	cin >> name;
	ifstream file(name);
	if (!file.is_open())
	{
		cout << "File don't exist!\n";
		system("pause");
		return 1;
	}
	while (getline(file, str))
	{
		pos_b = str.find("/**");
		if (pos_b == string::npos)
		{
			continue;
		}
		else
		{
			pos_b = str.find("\\func");
			if (pos_b == string::npos)
			{
				getline(file, str);
				pos_b = str.find("\\func");
				pos_e = str.find("*/");
				if (pos_e == string::npos)
				{
					cout << str.substr(pos_b + 6) << "\n";
				}
				else
				{
					cout << str.substr(pos_b + 6, pos_e - (pos_b + 6)) << "\n";
				}
			}
			else
			{
				pos_e = str.find("*/");
				if (pos_e == string::npos)
				{
					cout << str.substr(pos_b + 6) << "\n";
				}
				else
				{
					cout << str.substr(pos_b + 6, pos_e - (pos_b + 6)) << "\n";
				}
			}
		}
	}
	file.close();
	system("pause");
	return 0;
}