#pragma once

#include <string>
#include <vector>

namespace http_utils {

	class HttpUtils {

		public:

			/*! Get a vector with each of the cookies in the Cookie
			 * request header.
			 */
			std::vector<std::string> get_cookies(std::string cookie);
	};

}
