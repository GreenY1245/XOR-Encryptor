// XOR_Cryptor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class FileCryptor {
private:
	std::string file, crypto_file, filePath;
	int length;
public:

	FileCryptor() : file("NULL"), length(0) {}
	FileCryptor(std::string file, int length) : file(file), length(length) {}

	void GetFilePath() {
		std::string userinput;
		system("cls");
		std::cout << "input absolute file path: ";
		std::cin >> userinput;
		this->filePath = userinput;
	}

	void LoadFile() {
		std::ifstream filestream(this->filePath);
		std::string line, fullFile;
		while (!filestream.eof()) {
			std::getline(filestream, line);
			fullFile += line;
			fullFile.push_back('\n');
			this->length++;
		}
		this->file = fullFile;
		filestream.close();
		//std::cout << "DEBUG FILE OUT:\n" << this->file << "\n\n";
	}

	void WriteBack() const {
		std::ofstream filestream(this->filePath);
		if (filestream.is_open()) {
			filestream << this->crypto_file;
			std::cout << "File written" << std::endl << std::endl;
		} else {
			try {
				filestream << this->crypto_file;
			}
			catch (std::exception ex) {
				ex.what();
			}
		}
		filestream.close();
	}

	void XOR_FILE() {
		this->crypto_file = this->file;
		//std::cout << "DEBUG FILE OUT:\n" << this->crypto_file << "\n\n";
		auto cryptoKey = 'đ';
		for (auto temp = 0; temp < this->crypto_file.size()-1; temp++) {
			this->crypto_file[temp] ^= cryptoKey;
		}
		std::cout << std::endl << "Encrypted Data::\n" << crypto_file << "\n\n";
	}

	void Encrypt() {
		GetFilePath();
		LoadFile();
		XOR_FILE();
		WriteBack();
	}

};


int main()
{
	auto *fc = new FileCryptor();
	fc->Encrypt();
	delete fc;
    return 0;
}