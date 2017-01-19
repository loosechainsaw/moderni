#include "stdafx.h"

#ifndef __UNEXPECTED_TOKEN_EXCEPTION__
#define __UNEXPECTED_TOKEN_EXCEPTION__

#include <exception>

namespace modern {
	namespace windows {
		namespace ini {
			class unexpected_token_exception : public std::exception {
			public:
				unexpected_token_exception() = default;
				char const* what() const override;
			};
		}
	}
}
#endif