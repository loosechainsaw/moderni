#include "stdafx.h"

#ifndef __READER__
#define __READER__

#include <vector>
#include "token.h"
#include "section.h"
#include "unexpected_token_exception.h"
#include "lexer.h"
#include <istream>

namespace modern {
	namespace windows {
		namespace ini {

			class reader {
			public:
				reader(std::istream& stream);
				std::vector<modern::windows::ini::section> read();
			private:

				bool match_current(modern::windows::ini::token_type type);
				bool consume_token();
				token const& get_token_matching(modern::windows::ini::token_type type);
				modern::windows::ini::property parse_property();
				std::vector<modern::windows::ini::property> parse_properties();
				modern::windows::ini::section parse_section();
				modern::windows::ini::lexer lexer_;
			};
		}
	}
}

#endif