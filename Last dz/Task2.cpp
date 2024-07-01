#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, string> translitMap = {
	{'�', "a"}, {'�', "b"}, {'�', "v"}, {'�', "h"}, {'�', "g"},
	{'�', "d"}, {'�', "e"}, {'�', "ie"}, {'�', "zh"}, {'�', "z"},
	{'�', "y"}, {'�', "i"}, {'�', "i"}, {'�', "i"}, {'�', "k"},
	{'�', "l"}, {'�', "m"}, {'�', "n"}, {'�', "o"}, {'�', "p"},
	{'�', "r"}, {'�', "s"}, {'�', "t"}, {'�', "u"}, {'�', "f"},
	{'�', "kh"}, {'�', "ts"}, {'�', "ch"}, {'�', "sh"}, {'�', "shch"},
	{'�', "iu"}, {'�', "ia"}
};

void transliterate() {
	string inputFile = "file2.1.txt";
	string outputFile = "file2.2.txt";
	ifstream inFile(inputFile);
	ofstream outFile(outputFile);
	if (inFile.is_open()) {
		cout << "���� �1 ������ �������!\n";
	}
	else
	{
		cout << "�� ������� ������� ���� �1!\n";
		return;
	}

	if (outFile.is_open()) {
		cout << "���� �1 ������ �������!\n";
	}
	else
	{
		cout << "�� ������� ������� ���� �1!\n";
		return;
	}

	char char1;
	while (inFile.get(char1)) {
		if (translitMap.find(char1) != translitMap.end()) {
			outFile << translitMap[char1];
		}
		else {
			outFile << char1;
		}
	}

	inFile.close();
	outFile.close();
}