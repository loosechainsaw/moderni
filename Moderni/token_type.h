#include "stdafx.h"

#ifndef __TOKEN_TYPE__
#define __TOKEN_TYPE__

namespace modern {
	namespace windows {
		namespace ini {
			enum class token_type {
				equals,
				left_square_bracket,
				right_square_bracket,
				text
			};

		}
	}
}

#endif