#include "stdafx.h"

#ifndef __SECTION__
#define __SECTION__

#include <string>
#include <vector>
#include "property.h"


namespace modern {
	namespace windows {
		namespace ini {

			class section {
			public:
				explicit section(std::string name);
				void push_back(modern::windows::ini::property property);
			private:
				std::string name_;
				std::vector<modern::windows::ini::property> properties_;
			};
		}
	}
}

#endif