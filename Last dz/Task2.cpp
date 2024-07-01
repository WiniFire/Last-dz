#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, string> translitMap = {
	{'а', "a"}, {'б', "b"}, {'в', "v"}, {'г', "h"}, {'ґ', "g"},
	{'д', "d"}, {'е', "e"}, {'є', "ie"}, {'ж', "zh"}, {'з', "z"},
	{'и', "y"}, {'і', "i"}, {'ї', "i"}, {'й', "i"}, {'к', "k"},
	{'л', "l"}, {'м', "m"}, {'н', "n"}, {'о', "o"}, {'п', "p"},
	{'р', "r"}, {'с', "s"}, {'т', "t"}, {'у', "u"}, {'ф', "f"},
	{'х', "kh"}, {'ц', "ts"}, {'ч', "ch"}, {'ш', "sh"}, {'щ', "shch"},
	{'ю', "iu"}, {'я', "ia"}
};

void transliterate() {
	string inputFile = "file2.1.txt";
	string outputFile = "file2.2.txt";
	ifstream inFile(inputFile);
	ofstream outFile(outputFile);
	if (inFile.is_open()) {
		cout << "Файл №1 успішно відкрито!\n";
	}
	else
	{
		cout << "Не вдалось відкрити файл №1!\n";
		return;
	}

	if (outFile.is_open()) {
		cout << "Файл №1 успішно відкрито!\n";
	}
	else
	{
		cout << "Не вдалось відкрити файл №1!\n";
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