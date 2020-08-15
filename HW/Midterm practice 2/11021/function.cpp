#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include "function.h"

using namespace std;

void RleCodec::encode()
{
    char t = code_str[0];
    char temp = t;
    int cnt = 0;
    int Cnt, rest;
    string os;
    for(auto c : code_str){
        if(t == c){
            cnt++;
        }
        else{
            Cnt = cnt/26;
            rest = cnt%26;
            for(int i = 0; i < Cnt; i++){
                os.push_back('Q');
                os.push_back('Z');
                os.push_back(temp);
            }
            os.push_back('Q');
            os.push_back(rest + 64);
            os.push_back(temp);
            t = temp = c;
            cnt = 1;
        }
    }
    Cnt = cnt/26;
    rest = cnt%26;
    for(int i = 0; i < Cnt; i++){
        os.push_back('Q');
        os.push_back('Z');
        os.push_back(temp);
    }
    os.push_back('Q');
    os.push_back(rest + 64);
    os.push_back(temp);
    encoded = true;
    code_str = os;
}

void RleCodec::decode()
{
	std::stringstream os;
	//std::string int_str;
	char q = 'A';
	char number = ' ';
	int cnt;
	for (auto c : code_str) {
        if (q=='A') {
            q = c;
		}else if(number == ' '){
            number = c;
		}
        else {
            cnt = number - 'A' +1;
            for (int i=0; i<cnt; ++i)
                os << c;
			number = ' ';
			q = 'A';
		}
	}

	code_str = os.str();
	encoded = false;
}
