#pragma once

#include "File.h"

namespace libCom
{

	class CFileRead : public CFile
	{
	private:
		long fileSize{ 0 };

	public:
		CFileRead(std::string _filename) : CFile{ _filename, "rb" } {}



	};

}
