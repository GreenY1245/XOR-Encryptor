// TypeDef_Trickery.cpp : Defines the entry point for the console application.
//
// XOR_Cryptor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#define _ if
#define __ else
#define ___ while
#define ____ for
#define _____ do
#define ______ this
#define _______ int
#define ________ string
#define _________ auto
#define __________ double
#define ___________ bool
#define ____________ void
#define _____________ class
#define ______________ private
#define _______________ public

using namespace std;

_____________ FileCryptor {
______________:
	________ file, crypto_file, filePath;
	_______ length;
_______________:

	FileCryptor() : file("NULL"), length(0) {}
	FileCryptor(________ file, _______ length) : file(file), length(length) {}

	____________ GetFilePath() {
		________ userinput;
		system("cls");
		cout << "input absolute file path: ";
		cin >> userinput;
		______->filePath = userinput;
	}

	____________ LoadFile() {
		ifstream filestream(______->filePath);
		________ line, fullFile;
		___ (!filestream.eof()) {
			std::getline(filestream, line);
			fullFile += line;
			fullFile.push_back('\n');
			______->length++;
		}
		______->file = fullFile;
		filestream.close();
		//std::cout << "DEBUG FILE OUT:\n" << ______->file << "\n\n";
	}

	____________ WriteBack() const {
		ofstream filestream(______->filePath);
		_ (filestream.is_open()) {
			filestream << ______->crypto_file;
			cout << "File written" << endl << endl;
		}
		__ {
			try {
				filestream << ______->crypto_file;
			}
			catch (std::exception ex) {
				ex.what();
			}
		}
		filestream.close();
	}

	____________ XOR_FILE() {
		______->crypto_file = ______->file;
		_________ cryptoKey = 'ð';
		____ (_________ temp = 0; temp < ______->crypto_file.size() - 1; temp++) {
			______->crypto_file[temp] ^= cryptoKey;
		}
		std::cout << std::endl << "Encrypted Data::\n" << crypto_file << "\n\n";
	}

	____________ Encrypt() {
		GetFilePath();
		LoadFile();
		XOR_FILE();
		WriteBack();
	}

};


_______ main() {
	_________ *fc = new FileCryptor();
	fc->Encrypt();
	delete fc;
	return 0;
}