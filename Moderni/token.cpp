#include "stdafx.h"
#include "token.h"

modern::windows::ini::token::token(token_type type, std::string lexeme) : type_{ type }, lexeme_{ std::move(lexeme) }
{
}

modern::windows::ini::token_type modern::windows::ini::token::type() const {
	return this->type_;
}

std::string const& modern::windows::ini::token::lexeme() const {
	return this->lexeme_;
}