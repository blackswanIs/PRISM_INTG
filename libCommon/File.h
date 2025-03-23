#pragma once

#include "config.h"
#include <iostream>
#include <string>

namespace libCom
{
	class CFile
	{
	private:
		FILE* filePtr;
		std::string filename;
		std::string mode;

	public:
		CFile() : filePtr{ nullptr }, filename{ "" }, mode{""} {}
		CFile(std::string _fname, std::string _md) : filePtr{ nullptr }, filename{ _fname }, mode{_md} {}

		bool Open()
		{
			if (filename == "")
			{
				std::cout << "There is no filename" << std::endl;
				return false;
			}
			
			if (filePtr == nullptr)
			{
				if (fopen_s(&filePtr, filename.c_str(), mode.c_str()) == NULL)
				{
					std::cout << "file open success" << std::endl;
					return true;
				}
				else
				{
					std::cout << "file open fail" << std::endl;
					return false;
				}
			}
		}

	};

}

