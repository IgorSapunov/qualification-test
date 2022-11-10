#include<iostream>
#include<cctype>
#include<algorithm>
#include<sstream>
using namespace std;

string Converter(string& str) {
	for (int it = 0; it < str.size(); ++it) {
		if (isupper(str[it]) > 0) {
			str[it] = tolower(str[it]);
		}
	}
	string result = str;
	for (int it = 0; it < str.size(); ++it) {
		if (count(begin(str), end(str), str[it]) > 1) {
			result[it] = ')';
			for (auto i = next(begin(str), it); i < end(str); ++i) {
				if (*i == str[it]) {
					result[distance(begin(str), i)] = ')';
				}
			}
		}
		else {
			result[it] = '(';
		}

	}
	return result;
}

int main() {
	string target;
	getline(cin, target, '\n');
	cout << Converter(target);
}