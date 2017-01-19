#include "stdafx.h"
#include "property.h"
modern::windows::ini::property::property(std::string name, std::string value) : name_{ std::move(name) }, value_{ std::move(value) }
{

}

std::string const& modern::windows::ini::property::name() const {
	return this->name_;
}

std::string const& modern::windows::ini::property::value() const {
	return this->value_;
}