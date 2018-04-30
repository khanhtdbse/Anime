//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com
//   Facebook:https://www.facebook.com/adonis.harding

#ifndef _CommonFunctions_HPP_
#define _CommonFunctions_HPP_

#include <Windows.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>

namespace ado
{
	//   Convert int to string
    std::string int_to_string(int integer);

    //   Convert float to string with two decimal digits
    std::string float_to_string(float real_number);

    //   Convert int to string
    std::wstring int_to_wstring(int integer);

    //   Convert float to string with two decimal digits
    std::wstring float_to_wstring(float real_number);

    bool encrypt(int key, std::string path_file);
    bool decrypt(int key, std::string path_file);
}

#endif // _CommonFunctions_HPP_
