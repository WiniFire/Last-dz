#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void fromStrDeleteWords(string& line, string* wordsToDelete, short wordsCount, short lineLen)
{
	string result = "";
	string wordSave = "";

	for (short i = 0; i < lineLen; i++) {
		if (line[i] != ' ' && line[i] != ',' && line[i] != '.' && line[i] != '!' && line[i] != '?' && line[i] != ':' && line[i] != ';') wordSave += line[i];
		else
		{
			bool breakActive = false;
			for (short j = 0; j < wordsCount; j++) {
				if (wordSave == wordsToDelete[j])
				{
					breakActive = true;
					break;
				}
			}
			if (breakActive)
			{
				result += line[i];
				wordSave = "";
			}
			else
			{
				result += wordSave + line[i];
				wordSave = "";
			}
		}
	}

	line = result;
}

void deleteBadWords()
{
	ifstream file1_1;
	ifstream file1_1BadWords;
	ofstream file1_2;
	file1_1.open("File1.1.txt");
	file1_1BadWords.open("File1.1-BadWords.txt");
	file1_2.open("File1.2.txt");

	if (file1_1.is_open())
	{
		cout << "���� �1 ������ �������!\n";
	}
	else
	{
		cout << "�� ������� ������� ���� �1!\n";
		return;
	}
	if (file1_2.is_open())
	{
		cout << "���� �2 ������ �������!\n";
	}
	else
	{
		cout << "�� ������� ������� ���� �2!\n";
		return;
	}
	if (file1_1BadWords.is_open())
	{
		cout << "���� � ����������� ������� ������ �������!\n\n";
	}
	else
	{
		cout << "�� ������� ������� ���� � ����������� �������!\n";
		return;
	}

	string lineBadWords = "";
	getline(file1_1BadWords, lineBadWords);
	short lineBadWordsLen = size(lineBadWords);

	short wordsCount = 0;
	if (lineBadWordsLen != 0)
	{
		wordsCount = 1;
		for (short i = 0; i < lineBadWordsLen; i++) {
			if (lineBadWords[i] == ' ') wordsCount++;
		}
	}

	string* badWords = new string[wordsCount];

	string saveWord1 = "";
	short indexCount1 = 0;
	for (short i = 0; i < lineBadWordsLen; i++) {
		if (lineBadWords[i] != ' ') saveWord1 += lineBadWords[i];
		else
		{
			badWords[indexCount1] = saveWord1;
			indexCount1++;
			saveWord1 = "";
		}
	}
	badWords[indexCount1] = saveWord1;

	string line1 = "";


	while (getline(file1_1, line1)) {
		short lineLen = size(line1);
		fromStrDeleteWords(line1, badWords, wordsCount, lineLen);
		file1_2 << line1 + "\n";
	}

	file1_2.close();
	file1_1.close();
	file1_1BadWords.close();

	delete[] badWords;
}