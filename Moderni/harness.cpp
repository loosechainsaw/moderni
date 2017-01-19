#include "stdafx.h"
#include <string>
#include <memory>
#include "reader.h"
#include <sstream>

int main()
{
	std::string contents;
	contents.append(";comment\n          [section1]\n   name    =   fred\nage =             35\n");

	std::stringstream stream{ contents };

	modern::windows::ini::reader reader{ stream };
	auto s = reader.read();

	return 0;
}

