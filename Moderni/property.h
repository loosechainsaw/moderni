#include "stdafx.h"

#ifndef __PROPERTY__
#define __PROPERTY__

#include <string>

namespace modern {
	namespace windows {
		namespace ini {

			class property{
			public:
				property(std::string name, std::string value);
				property(property&) = default;
				property& operator = (property&) = default;
				property(property&&) noexcept = default;
				property& operator = (property&&) noexcept = default;
				std::string const& name() const;
				std::string const& value() const;
			private:
				std::string name_;
				std::string value_;
			};
		}
	}
}

#endif