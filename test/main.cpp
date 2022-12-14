#include "http_utils.h"
#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace http_utils;

int main(void)
{
	HttpUtils http_utils;
	std::string cookie = "session_token2=aaaa; session_token=1667995240";

	std::map<std::string, std::string> cookies = http_utils.get_cookies(cookie);
	std::cout << "session_token=" << cookies["session_token"] << "\n";
	std::cout << "session_token2=" << cookies["session_token2"] << "\n";

	std::string cookie2 = "session_token2=aaaa";
	cookies = http_utils.get_cookies(cookie2);
	std::cout << "session_token=" << cookies["session_token"] << "\n";
	std::cout << "session_token2=" << cookies["session_token2"] << "\n";
	
	std::string cookie3;
	cookies = http_utils.get_cookies(cookie3);
	std::cout << "session_token=" << cookies["session_token"] << "\n";
	std::cout << "session_token2=" << cookies["session_token2"] << "\n";
	
	std::string cookie4 = "session_token2=aaaa;";
	cookies = http_utils.get_cookies(cookie4);
	std::cout << "session_token=" << cookies["session_token"] << "\n";
	std::cout << "session_token2=" << cookies["session_token2"] << "\n";


	std::string body = "_si=xxxx";
	std::map<std::string, std::string> elements = http_utils.parse_URI_encoded_body(body);
	std::cout << "body element _si=" << elements["_si"];

	// regex replace test
	std::string in {"first-name=Paulo&last-name=Gouveia&email=a%21e.com&password=%221234567890"};
	std::regex pat {"%22"};
	std::string format {"\""};
	std::cout << "\nregex replace: " << std::regex_replace(in, pat, format);

	std::map<std::string, std::string> elems = http_utils.parse_URI_encoded_body(in);
	std::cout << "\nfirst-name:" << elems["first-name"] << "\n";
	std::cout << "email:" << elems["email"] << "\n";
	std::cout << "pwd:" << elems["password"] << "\n";

	return 0;
}
