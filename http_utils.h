#pragma once

#include <map>
#include <string>
#include <vector>

namespace http_utils {

	struct utf_escape {
		std::string key;
		std::string value;
	};
	

	class HttpUtils {
		
		

		static std::vector<utf_escape> ascii_encoding; 
		

		public:
				
			HttpUtils();

			
			/*! Get a vector with each of the cookies in the Cookie
			 * request header.
			 */
			std::map<std::string, std::string> get_cookies(std::string cookie);

			
			/*! Parses the body string and decodes it as URI encoded.
			 *
			 * \param body String with the request body
			 *
			 * \return A map with the decoded elements.
			 */
			std::map<std::string, std::string> parse_URI_encoded_body(std::string body);
		
		private:

			void decode_URI_component(std::string &in_str);
	};

}
