#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int convert_decimal(int num, int base);
int convert_binary(int num);
int convert_octal(int num);
int convert_hexadecimal(int num);
int convert_number(int input_number, int source_base, int target_base);
bool Validate(int num, int source);

int main() {
	int input_number, source_base, target_base;
	char answer;

	cout << "Welcome to the Numbering System Calculator!";
	cout << setfill('-') << setw(80) << endl;

	do {
		cout << "\nPlease enter the following inputs: \n";
		cout << "The number to convert: \n>> ";
		cin >> input_number;
		cout << "The source base (i.e., the base to convert from):\n>> ";
		cin >> source_base;
		cout << "The target base  (i.e., the base to convert from):\n>> ";
		cin >> target_base;
		
		//check source base and target base
		if (source_base != 2 && source_base != 8 && source_base != 10 && source_base != 16) {
			cout << "Invalid source base";
			break;
		}
		if (target_base != 2 && target_base != 8 && target_base != 10 && target_base != 16) {
			cout << "Invalid target base";
			break;
		}

		if (Validate(input_number, source_base)) {
		cout << "\nThe result of converting the number " << input_number << " from base " << source_base << " to " << target_base << " is: \n";
		cout << ">> " << convert_number(input_number, source_base, target_base);
		}
		else {
			cout << "Wrong format entered.";
		}

		cout << "\n\nDo you want to continue with other number?";
		cout << "\nEnter (Y) to continue \nEnter (N) to continue \n>>";
		cin >> answer;
		if (answer == 'N' || answer == 'n') {
			cout << "\nQuitting calculator...Thank You!";
		}
	} while (answer == 'Y' || answer == 'y');
}

int convert_decimal(int num, int base) {
	int r, total{ 0 }, i{ 0 };
	while (num > 0) {
		r = num % 10;
		total = total +( r * pow(base, i));
		num = num / 10;
		i++;
	}
	return total;
}

int convert_binary(int num) {
	int r, total{ 0 }, i{ 0 };
	while (num > 0) {
		r = num % 2;
		total = total + (r * pow(10, i));
		num = num / 2;
		i++;
	}
	return total;
}

int convert_octal(int num) {
	int r, total{ 0 }, i{ 0 };
	while (num > 0) {
		r = num % 8;
		total = total + (r * pow(10, i));
		num = num / 8;
		i++;
	}
	return total;
}

int convert_hexadecimal(int num) {
	int r, total{ 0 }, i{ 0 };
	while (num > 0) {
		r = num % 16;
		total = total + (r * pow(10, i));
		num = num / 16;
		i++;
	}
	return total;
}
int convert_number(int input_number, int source_base, int target_base) {
	int converted_num{ 0 };
	if (target_base == 10) {
		converted_num = convert_decimal(input_number, source_base);
	}
	else if (target_base == 2) {
		converted_num = convert_binary(convert_decimal(input_number, source_base));
	}
	else if (target_base == 8) {
		converted_num = convert_octal(convert_decimal(input_number, source_base));
	}
	else if (target_base == 16) {
		converted_num = convert_hexadecimal(convert_decimal(input_number, source_base));
	}

	return converted_num;
}
bool Validate(int num, int source) {
	int r{ 0 }, i{ 0 };
	if (source == 8) {
		while (num > 0) {
			r = num % 10;
			num /= 10;
			i++;
			if (r > 7)
				return false;
		}
		if (r > 7) {
			return false;
		}
	}

	else if (source == 2) {
		while (num > 0) {
			r = num % 10;
			num /= 10;
			i++;
			if (r != 1 && r != 0)
				return false;
		}
		if (r != 1 && r != 0) {
			return false;
		}
	}

 }

