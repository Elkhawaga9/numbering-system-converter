#include <iostream>
#include"algorithm"
#include"string"
#include<vector>
using namespace std;

void verify_decimal(string);
void verify_binary(string);
void verify_octal(string);
void verify_hexa(string);


string decimal_to_binary(string);
string decimal_to_octal(string);
string decimal_to_hexa(string);

string binary_to_decimal(string);
string binary_to_octal(string);
string binary_to_hexa(string);

string octa_to_decimal(string);
string octa_to_binary(string);
string octa_to_hexa(string);

string hexa_to_decimal(string);
string hexa_to_binary(string);
string hexa_to_octa(string);


bool flag = true;//if number is right ,continue//else end the program
int main()
{
	cout << "****************** Hello in my numbring converter system *****************\n\n";
	//while (true) {
		string num;
		int choice1, choice2;
		cout << "enter the number you want to convert: ";
		cin >> num;
		for (int i = 0;i < num.length();i++) num[i] = toupper(num[i]);
		cout << "\nenter the type of the number: ";
		cout << "\n1: Decimal\n";
		cout << "2: Binary\n";
		cout << "3: Octal\n";
		cout << "4: Hexadecimal\n";
		cin >> choice1;
		switch (choice1)
		{
		case 1:
			verify_decimal(num);
			break;
		case 2:
			verify_binary(num);
			break;
		case 3:
			verify_octal(num);
			break;
		case 4:
			verify_hexa(num);
			break;
		default:
			flag = false;
			cout << "\n you entered a non valid option,try again\n\n ";
		}
		if (flag)
		{
			cout << "you entered a valid number in valid system,let's continue:\n\n";
			cout << "enter the system you want to convert to\n";
			cout << "1: Decimal\n";
			cout << "2: Binary\n";
			cout << "3: Octal\n";
			cout << "4: Hexadecimal\n";
			cin >> choice2;
			if (choice1 == 1 && choice2 == 2) decimal_to_binary(num);
			else if (choice1 == 1 && choice2 == 3) decimal_to_octal(num);
			else if (choice1 == 1 && choice2 == 4) decimal_to_hexa(num);

			else if (choice1 == 2 && choice2 == 1) binary_to_decimal(num);
			else if (choice1 == 2 && choice2 == 3) binary_to_octal(num);
			else if (choice1 == 2 && choice2 == 4) binary_to_hexa(num);

			else if (choice1 == 3 && choice2 == 1) octa_to_decimal(num);
			else if (choice1 == 3 && choice2 == 2) octa_to_binary(num);
			else if (choice1 == 3 && choice2 == 4) octa_to_hexa(num);

			else if (choice1 == 4 && choice2 == 1) hexa_to_decimal(num);
			else if (choice1 == 4 && choice2 == 2) hexa_to_binary(num);
			else if (choice1 == 4 && choice2 == 3) hexa_to_octa(num);
			else if (choice1 == choice2) cout << "you want to convert to the same type of the number you entered \n";
			else cout << "unavailable choice \n";

			cout << "\n\n***************** Thank you for using our numbering system converter ********************* \n\n\n";
		}
		//flag = true;
	//}
}

void verify_decimal(string num)
{
	for (auto i : num)
	{
		if (i == 46 || (i >= 48 && i<=57)) continue;//the ascii code of the valid numbers
		else
		{
			cout << "\nthe number is not in a right format\n";
			flag = false;
			break;
		}
		
	}
}

void verify_binary(string num)
{
	for (auto i : num)
	{
		if (i == 46 || i == 48 || i == 49) continue;//the ascii code of the valid numbers
		else
		{
			cout << "\nthe number is not in a right format\n";
			flag = false;
			break;
		}

	}
}

void verify_octal(string num)
{
	for (auto i : num)
	{
		if (i == 46 || (i >= 48 && i <= 55)) continue;//the ascii code of the valid numbers
		else
		{
			cout << "\nthe number is not in a right format\n";
			flag = false;
			break;
		}

	}
}

void verify_hexa(string num)
{
	for (auto i : num)
	{
		if (i == 46 || (i >= 48 && i <= 57)|| (i >= 65 && i <= 70)) continue;//the ascii code of the valid numbers
		else
		{
			cout << "\nthe number is not in a right format\n";
			flag = false;
			break;
		}

	}
}


string decimal_to_binary(string num)
{
	int l = num.length();
	int num1 = stoi(num);
	vector<int>vec;
	while (num1 != 0)
	{
		vec.push_back(num1 % 2);
		num1 /= 2;
	}
	//printing the input and the output to the user 
	cout << num << " --> ";
	for (int i = vec.size() - 1;i >= 0;i--) cout << vec[i];
	return "0"; 
}

string decimal_to_octal(string num)
{
	int l = num.length();
	int num1 = stoi(num);
	vector<int>vec;
	while (num1 != 0)
	{
		vec.push_back(num1 % 8);
		num1 /= 8;
	}
	//printing the input and the output to the user 
	cout << num << " --> ";
	for (int i = vec.size() - 1;i >= 0;i--) cout << vec[i];
	return "0";
}

string decimal_to_hexa(string num)
{
	int l = num.length();
	int num1 = stoi(num);
	vector<int>vec;

	while (num1 != 0)
	{
		vec.push_back(num1 % 16);
		num1 /= 16;
	}
	//printing the input and the output to the user 
	cout << num << " --> ";
	for (int i = vec.size() - 1;i >= 0;i--)
	{
		if (vec[i] == 10)cout << "A";
		else if (vec[i] == 11)cout << "B";
		else if (vec[i] == 12)cout << "C";
		else if (vec[i] == 13)cout << "D";
		else if (vec[i] == 14)cout << "E";
		else if (vec[i] == 15)cout << "F";
		else cout << vec[i];
	}
	return "0";
}


string binary_to_decimal(string num)
{
	int l = num.length();
	int res = 0;
	string num1 = num;
	for (int i = l - 1;i >= 0;i--)
	{
		if (num1[i] == '1') res += pow(2, l-i-1);
	}
	cout << num<<" --> "<<res;
	return "0";
}

string binary_to_octal(string num)
{
	string res = "";
	string input = num;
	int l = num.length();
	while (l % 3 != 0)
	{
		num.insert(0, 1, '0');
		l += 1;
	}
	for (int i = 0;i < l;i += 3)
	{
		if (num[i] == '0' && num[i + 1] == '0' && num[i + 2] == '0') res.append("0");
		else if (num[i] == '0' && num[i + 1] == '0' && num[i + 2] == '1')res.append("1");
		else if (num[i] == '0' && num[i + 1] == '1' && num[i + 2] == '0') res.append("2");
		else if (num[i] == '0' && num[i + 1] == '1' && num[i + 2] == '1') res.append("3");
		else if (num[i] == '1' && num[i + 1] == '0' && num[i + 2] == '0') res.append("4");
		else if (num[i] == '1' && num[i + 1] == '0' && num[i + 2] == '1') res.append("5");
		else if (num[i] == '1' && num[i + 1] == '1' && num[i + 2] == '0') res.append("6");
		else if (num[i] == '1' && num[i + 1] == '1' && num[i + 2] == '1') res.append("7");
	}
	cout << input << " --> " << res;
	return res;
}

string binary_to_hexa(string num)
{
	string input = num;
	int l = num.length();
	while (l % 4 != 0)
	{
		num.insert(0, 1, '0');
		l += 1;
	}
	string res = "";
	for (int i = 0;i < l;i += 4)
	{
		if (num[i] == '0' && num[i + 1] == '0' && num[i + 2] == '0' && num[i + 3] == '0') res.append("0");
		else if (num[i] == '0' && num[i + 1] == '0' && num[i + 2] == '0' && num[i + 3] == '1') res.append("1");
		else if (num[i] == '0' && num[i + 1] == '0' && num[i + 2] == '1' && num[i + 3] == '0') res.append("2");
		else if (num[i] == '0' && num[i + 1] == '0' && num[i + 2] == '1' && num[i + 3] == '1') res.append("3");
		else if (num[i] == '0' && num[i + 1] == '1' && num[i + 2] == '0' && num[i + 3] == '0') res.append("4");
		else if (num[i] == '0' && num[i + 1] == '1' && num[i + 2] == '0' && num[i + 3] == '1') res.append("5");
		else if (num[i] == '0' && num[i + 1] == '1' && num[i + 2] == '1' && num[i + 3] == '0') res.append("6");
		else if (num[i] == '0' && num[i + 1] == '1' && num[i + 2] == '1' && num[i + 3] == '1') res.append("7");
		else if (num[i] == '1' && num[i + 1] == '0' && num[i + 2] == '0' && num[i + 3] == '0') res.append("8");
		else if (num[i] == '1' && num[i + 1] == '0' && num[i + 2] == '0' && num[i + 3] == '1') res.append("9");
		else if (num[i] == '1' && num[i + 1] == '0' && num[i + 2] == '1' && num[i + 3] == '0') res.append("A");
		else if (num[i] == '1' && num[i + 1] == '0' && num[i + 2] == '1' && num[i + 3] == '1') res.append("B");
		else if (num[i] == '1' && num[i + 1] == '1' && num[i + 2] == '0' && num[i + 3] == '0') res.append("C");
		else if (num[i] == '1' && num[i + 1] == '1' && num[i + 2] == '0' && num[i + 3] == '1') res.append("D");
		else if (num[i] == '1' && num[i + 1] == '1' && num[i + 2] == '1' && num[i + 3] == '0') res.append("E");
		else if (num[i] == '1' && num[i + 1] == '1' && num[i + 2] == '1' && num[i + 3] == '1') res.append("F");
	}
	cout << input << " --> " << res;
	return res;
}


string octa_to_decimal(string num)
{
	int l = num.length();
	int res = 0;
	string sub1 = num;
	for (int i = l - 1;i >= 0;i--)
	{
		if (sub1[i] == '1') res += 1 * pow(8, l-i-1);
		else if(sub1[i] == '2') res += 2 * pow(8, l - i - 1);
		else if (sub1[i] == '3') res += 3 * pow(8, l - i - 1);
		else if (sub1[i] == '4') res += 4 * pow(8, l - i - 1);
		else if (sub1[i] == '5') res += 5 * pow(8, l - i - 1);
		else if (sub1[i] == '6') res += 6 * pow(8, l - i - 1);
		else if (sub1[i] == '7') res += 7 * pow(8, l - i - 1);
	}
	cout << num<<" --> "<<res;
	return "0";
}


string octa_to_binary(string num)
{
	string res = "";
	for (auto i : num)
	{
		if (i == '0') res.append("000");
		else if (i == '1') res.append("001");
		else if (i == '2') res.append("010");
		else if (i == '3')res.append("011");
		else if (i == '4') res.append("100");
		else if (i == '5') res.append("101");
		else if (i == '6') res.append("110");
		else if (i == '7') res.append("111");
	}
	cout << num << " --> " << res;
	return res;
}


string octa_to_hexa(string num)
{
	//calling functions will print values on the screen
	cout << "first we will covert from octal to binary\n";
	string temp = octa_to_binary(num);
	cout << "\n";
	cout << "and then we will convert it to hexadecimal \n";
	string res = binary_to_hexa(temp);
	return "0";
}

string hexa_to_decimal(string num)
{
	int l = num.length();
	int res = 0;
	string sub1 = num;
	for (int i = l - 1;i >= 0;i--)
	{
		if (sub1[i] == '1') res += 1 * pow(16, l - i - 1);
		else if (sub1[i] == '2') res += 2 * pow(16, l - i - 1);
		else if (sub1[i] == '3') res += 3 * pow(16, l - i - 1);
		else if (sub1[i] == '4') res += 4 * pow(16, l - i - 1);
		else if (sub1[i] == '5') res += 5 * pow(16, l - i - 1);
		else if (sub1[i] == '6') res += 6 * pow(16, l - i - 1);
		else if (sub1[i] == '7') res += 7 * pow(16, l - i - 1);
		else if (sub1[i] == '8') res += 8 * pow(16, l - i - 1);
		else if (sub1[i] == '9') res += 9 * pow(16, l - i - 1);
		else if (sub1[i] == 'A') res += 10 * pow(16, l - i - 1);
		else if (sub1[i] == 'B') res += 11 * pow(16, l - i - 1);
		else if (sub1[i] == 'C') res += 12 * pow(16, l - i - 1);
		else if (sub1[i] == 'D') res += 13 * pow(16, l - i - 1);
		else if (sub1[i] == 'E') res += 14 * pow(16, l - i - 1);
		else if (sub1[i] == 'F') res += 15 * pow(16, l - i - 1);

	}
	cout << num<<" --> "<<res;
	return "0";
}

string hexa_to_binary(string num)
{
	string res = "";
	for (auto i : num)
	{
		if (i == '0') res.append("0000");
		else if (i == '1') res.append("0001");
		else if (i == '2') res.append("0010");
		else if (i == '3') res.append("0011");
		else if (i == '4') res.append("0100");
		else if (i == '5') res.append("0101");
		else if (i == '6')res.append("0110");
		else if (i == '7')res.append("0111");
		else if (i == '8')res.append("1000");
		else if (i == '9') res.append("1001");
		else if (i == 'A')res.append("1010");
		else if (i == 'B') res.append("1011");
		else if (i == 'C') res.append("1100");
		else if (i == 'D') res.append("1101");
		else if (i == 'E') res.append("1110");
		else if (i == 'F')res.append("1111");
	}
	cout << num << " --> " << res;
	return res;
}

string hexa_to_octa(string num)
{
	//calling functions will print values on the screen
	cout << "first we will covert from hexadecimal to binary\n";
	string temp = hexa_to_binary(num);
	cout << "\n";
	cout << "and then we will convert it to octal \n";
	string res =  binary_to_octal(temp);
	return "0";
}
