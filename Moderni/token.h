#include "stdafx.h"

#ifndef __TOKEN__
#define __TOKEN__

#include <string>
#include "token_type.h"

namespace modern {
	namespace windows {
		namespace ini {

			class token {
			public:
				token(modern::windows::ini::token_type type, std::string lexeme);
				token(token const&) = default;
				token& operator = (token const&) = default;
				token(token&&) = default;
				token& operator = (token&&) = default;
				std::string const& lexeme() const;
				modern::windows::ini::token_type type() const;
			private:
				modern::windows::ini::token_type type_;
				std::string lexeme_;
			};
		}
	}
}
#endif