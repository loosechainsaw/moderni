#include "stdafx.h"

#ifndef __LEXER__
#define __LEXER__

#include <string>
#include <memory>
#include <istream>
#include "token.h"

namespace modern {
	namespace windows {
		namespace ini {

			class lexer {
			public:
				explicit lexer(std::istream& stream);
				bool fetch_next_token();
				modern::windows::ini::token& current();
				bool has_current_token() const;
			private:

				bool end_of_file() const;
				void strip_white_space();
				void strip_comments();

				std::istream& contents_;
				std::unique_ptr<modern::windows::ini::token> current_token_;
			};
		}
	}
}


#endif