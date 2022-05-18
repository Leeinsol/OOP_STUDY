#include <iostream>
#include <cstring>
using namespace std;

int main() {
	const char *str1 = "Hi";
	const char *str2 = "Hello";
	char str3[30];

	cout << strlen(str1) << endl;
	cout << strlen(str2) << endl;

	if (strcmp(str1, str2) == 0) {
		cout << "같은 문자열" << endl;
	}
	else {
		cout << "다른 문자열" << endl;
	}

	strcpy(str3, str1);
	cout << str3 << endl;
	strcat(str3, str2);
	cout << str3 << endl;

	return 0;
}


