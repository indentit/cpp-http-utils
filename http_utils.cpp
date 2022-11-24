#include "http_utils.h"
#include <regex>
#include <string>
#include <utility>
#include <vector>
#include "string_utils.h"

using namespace http_utils;
using namespace string_utils;

std::vector<utf_escape> HttpUtils::ascii_encoding; 

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
			// URI decode with regex
			//item[0] 
			decode_URI_component(item[0]);	
			decode_URI_component(item[1]);	

			elements_map.insert( std::pair<std::string, std::string>(item[0], item[1]) );
		}
	}

	return elements_map;
}


void HttpUtils::decode_URI_component(std::string &str)
{
	for (auto p = ascii_encoding.begin(); p != ascii_encoding.end(); ++p) {
		std::regex pat { p->key };
		str = std::regex_replace(str, pat, p->value);
	}	
}


HttpUtils::HttpUtils()
{
	utf_escape entry;

	entry.key = "%20";
	entry.value = " ";
	ascii_encoding.push_back(entry);
			
	entry.key = "%21";
	entry.value = "!";
	ascii_encoding.push_back(entry);

	entry.key = "%22";
	entry.value = "\"";
	ascii_encoding.push_back(entry);


	entry.key = "%23";
	entry.value = "#";
	ascii_encoding.push_back(entry);

	entry.key = "%24";
	entry.value = "$";
	ascii_encoding.push_back(entry);

	entry.key = "%25";
	entry.value = "%";
	ascii_encoding.push_back(entry);

	entry.key = "%26";
	entry.value = "&";
	ascii_encoding.push_back(entry);

	entry.key = "%27";
	entry.value = "\'";
	ascii_encoding.push_back(entry);

	entry.key = "%2B";
	entry.value = "+";
	ascii_encoding.push_back(entry);

	entry.key = "%2C";
	entry.key = ",";
	ascii_encoding.push_back(entry);

	entry.key = "%2F";
	entry.value = "/";
	ascii_encoding.push_back(entry);

	entry.key = "%3A";
	entry.value = ":";
	ascii_encoding.push_back(entry);

	entry.key = "%3B";
	entry.value = ";";
	ascii_encoding.push_back(entry);

	entry.key = "%3C";
	entry.value = "<";
	ascii_encoding.push_back(entry);

	entry.key = "%3D";
	entry.value = "=";
	ascii_encoding.push_back(entry);

	entry.key = "%3E";
	entry.value = ">";
	ascii_encoding.push_back(entry);

	entry.key = "%3F";
	entry.value = "?";
	ascii_encoding.push_back(entry);

	entry.key = "%40";
	entry.value = "@";
	ascii_encoding.push_back(entry);

	entry.key = "%5B";
	entry.value = "[";
	ascii_encoding.push_back(entry);

	entry.key = "%5C";
	entry.value = "\\";
	ascii_encoding.push_back(entry);

	entry.key = "%5D";
	entry.value = "]";
	ascii_encoding.push_back(entry);

	entry.key = "%5E";
	entry.value = "^";
	ascii_encoding.push_back(entry);

	entry.key = "%60";
	entry.value = "`";
	ascii_encoding.push_back(entry);

	entry.key = "%7B";
	entry.value = "{";
	ascii_encoding.push_back(entry);

	entry.key = "%7C";
	entry.value = "|";
	ascii_encoding.push_back(entry);

	entry.key = "%7D";
	entry.value = "}";
	ascii_encoding.push_back(entry);

	entry.key = "%7E";
	entry.value = "~";
	ascii_encoding.push_back(entry);

	entry.key = "%E2%82%AC";
	entry.value = "€";
	ascii_encoding.push_back(entry);

}
