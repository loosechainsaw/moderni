#include "stdafx.h"
#include "lexer.h"
#include "token.h"

modern::windows::ini::lexer::lexer(std::istream& stream) : contents_{ stream }, current_token_{ nullptr }
{

}

bool modern::windows::ini::lexer::fetch_next_token() {

	if (!contents_.eof()) {
		strip_white_space();
		strip_comments();
		strip_white_space();

		if (end_of_file())
			return false;

		if (contents_.peek() == '[') {
			contents_.get();
			current_token_ = std::make_unique<token>(token_type::left_square_bracket, std::string{ "[" });
		}
		else if (contents_.peek() == ']') {
			contents_.get();
			current_token_ = std::make_unique<token>(token_type::right_square_bracket, std::string{ "]" });
		}
		else if (contents_.peek() == '=') {
			contents_.get();
			current_token_ = std::make_unique<token>(token_type::equals, std::string{ "=" });
		}
		else {
			std::string text;
			while(!end_of_file())
			{
				if (isspace(contents_.peek()) || contents_.peek() == '[' || contents_.peek() == ']')
					break;

				auto c = contents_.get();

				std::string t(1, c);
				text.append(t);
			}
			current_token_ = std::make_unique<token>(token_type::text, text);
		}

		return true;

	}

	return false;

}

modern::windows::ini::token& modern::windows::ini::lexer::current() {
	return *current_token_.get();
}

bool modern::windows::ini::lexer::has_current_token() const {
	return current_token_.get() != nullptr;
}

bool modern::windows::ini::lexer::end_of_file() const {
	return contents_.eof();
}

void modern::windows::ini::lexer::strip_white_space() {
	while(!end_of_file()){
		if (iswspace(contents_.peek())) {
			contents_.get(); // eat whitespace
			continue;
		}
		break;
	}
}

void modern::windows::ini::lexer::strip_comments() {
	if (contents_.peek() == ';') {
		contents_.get(); // eat ;
		while(!end_of_file()){

			auto current = contents_.get(); // eat up until \n

			if (current == '\n') {
				break;
			}
		}

	}
}