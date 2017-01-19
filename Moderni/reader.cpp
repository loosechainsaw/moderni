#include "stdafx.h"
#include "reader.h"
#include <algorithm>

modern::windows::ini::reader::reader(std::istream& stream) : lexer_{ stream}
{

}

std::vector<modern::windows::ini::section> modern::windows::ini::reader::read() {
	std::vector<modern ::windows::ini::section> sections;

	while (lexer_.fetch_next_token())
	{
		auto section = parse_section();
		sections.push_back(std::move(section));
	}

	return sections;
}


bool modern::windows::ini::reader::match_current(token_type type) 
{
	return this->lexer_.current().type() == type;
}

bool modern::windows::ini::reader::consume_token() {
	return this->lexer_.fetch_next_token();
}

modern::windows::ini::token const& modern::windows::ini::reader::get_token_matching(token_type type)  {
	return this->lexer_.current();
}

modern::windows::ini::property modern::windows::ini::reader::parse_property() {
	auto property_name_token = this->lexer_.current();
	auto const& name = property_name_token.lexeme();

	if (!consume_token())
		throw modern::windows::ini::unexpected_token_exception();

	if (!match_current(token_type::equals))
		throw unexpected_token_exception();

	if (!consume_token())
		throw unexpected_token_exception();

	if (!match_current(token_type::text))
		throw unexpected_token_exception();

	auto property_value_token = this->lexer_.current();
	auto const& value = property_value_token.lexeme();

	property p { std::move(name), std::move(value)};

	return p;
}

std::vector<modern::windows::ini::property> modern::windows::ini::reader::parse_properties() {
	std::vector<property> p;

	if (!consume_token())
		return p;

	while (!match_current(token_type::left_square_bracket)) {
		p.push_back(parse_property());
		if (!consume_token())
			break;
	}

	return p;
}

modern::windows::ini::section modern::windows::ini::reader::parse_section() {
	if (!match_current(token_type::left_square_bracket))
		throw unexpected_token_exception{};

	if (!consume_token())
		throw unexpected_token_exception{};

	auto& token = get_token_matching(token_type::text);

	modern::windows::ini::section s{ token.lexeme() };

	if (!consume_token())
		throw unexpected_token_exception{};

	if (!match_current(token_type::right_square_bracket))
		throw unexpected_token_exception{};

	auto properties = parse_properties();

	std::for_each(std::begin(properties), std::end(properties), [&s](modern::windows::ini::property& ref) {
		s.push_back(std::move(ref));
	});

	return s;

}

