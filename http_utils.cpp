#include "http_utils.h"
#include <string>
#include <utility>
#include <vector>
#include "string_utils.h"

using namespace http_utils;
using namespace string_utils;

/*!
 * Extracts each cookie, encapsulated in the HTTP request header Cookie
 * value string, into an element of a vector.
 *
 * \return Vector with the extracted cookies.
 */
std::map<std::string, std::string> HttpUtils::get_cookies(std::string cookie)
{
	StringUtils str_utils;
	std::map<std::string, std::string> cookies_map;

	std::vector<std::string> cookies = str_utils.split(cookie, ';');
	
	for (auto p = cookies.begin(); p != cookies.end(); ++p) {
		str_utils.trim(*p);
		// split the cookie name from the value
		std::vector<std::string> item = str_utils.split(*p, '=');
		if (item.begin() != item.end()) {
			cookies_map.insert( std::pair<std::string, std::string>(item[0], item[1]) );
		}
	}
	
	return cookies_map;
}



std::map<std::string, std::string> HttpUtils::parse_URI_encoded_body(std::string body)
{
	StringUtils str_utils;
	std::vector<std::string> elements = str_utils.split(body, '&');

	std::map<std::string, std::string> elements_map;
	
	for (auto p = elements.begin(); p != elements.end(); ++p) {
		str_utils.trim(*p);
		// split the cookie name from the value
		std::vector<std::string> item = str_utils.split(*p, '=');
		if (item.begin() != item.end()) {
			elements_map.insert( std::pair<std::string, std::string>(item[0], item[1]) );
		}
	}

	return elements_map;
}

