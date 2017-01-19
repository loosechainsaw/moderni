#include "stdafx.h"
#include "section.h"
#include <utility>

modern::windows::ini::section::section(std::string name) : name_{ std::move(name) } {

}

void modern::windows::ini::section::push_back(modern::windows::ini::property property)
{
	properties_.push_back(std::move(property));
}
