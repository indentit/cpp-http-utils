#include "http_utils.h"
#include <string>
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
std::vector<std::string> HttpUtils::get_cookies(std::string cookie)
{
	StringUtils str_utils;

	std::vector<std::string> cookies = str_utils.split(cookie, ';');
	
	
	return cookies;
}
