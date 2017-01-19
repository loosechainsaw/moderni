#include "stdafx.h"
#include "unexpected_token_exception.h"


char const* modern::windows::ini::unexpected_token_exception::what() const {
	return "Unexpected token received";
}
