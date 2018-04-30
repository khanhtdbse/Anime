//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com
//   Facebook:https://www.facebook.com/adonis.harding

#include "CommonFunctions.hpp"

namespace ado
{
    std::string int_to_string(int integer)
    {
    	char character[10];

        //   In Visual Studio
        sprintf_s(character, "%d", integer);

        //   In CodeBlock
        //sprintf(character, "%d", integer);
        return std::string(character);
    }

    std::string float_to_string(float real_number)
    {
    	char character[10];

        //   In Visual Studio
        sprintf_s(character, "%.2f", real_number);

        //   In CodeBlock
        //sprintf(character, "%.2f", real_number);
        return std::string(character);
    }

    std::wstring int_to_wstring(int integer)
    {
    	char character[10];

        //   In Visual Studio
        sprintf_s(character, "%d", integer);

        //   In CodeBlock
        //sprintf(character, "%d", integer);

        std::string temp_string = std::string(character);
        std::wstring temp_wstring(temp_string.begin(), temp_string.end());
        return temp_wstring;
    }

    std::wstring float_to_wstring(float real_number)
    {
    	char character[10];

        //   In Visual Studio
        sprintf_s(character, "%.2f", real_number);

        //   In CodeBlock
        //sprintf(character, "%.2f", real_number);

    	std::string temp_string = std::string(character);
        std::wstring temp_wstring(temp_string.begin(), temp_string.end());
        return temp_wstring;
    }

    bool encrypt(int key, std::string path_file)
    {
        std::ifstream read(path_file, std::ios_base::binary);

        if (read)
		{
			read.seekg(0, read.end);
			int length = read.tellg();
			read.seekg(0, read.beg);
			char* buffer = new char[length];
			read.read(buffer, length);
			read.close();

			std::ofstream write(path_file, std::ios_base::binary);
			buffer[0] += key;
			write.clear();
			write.write(buffer, length);
			write.close();

			delete[] buffer;

			return true;
		}
		return false;
    }

    bool decrypt(int key, std::string path_file)
    {
    	std::ifstream read(path_file, std::ios_base::binary);

        if (read)
		{
			read.seekg(0, read.end);
			int length = read.tellg();
			read.seekg(0, read.beg);
			char* buffer = new char[length];
			read.read(buffer, length);
			read.close();

			std::ofstream write(path_file, std::ios_base::binary);
			buffer[0] -= key;
			write.clear();
			write.write(buffer, length);
			write.close();

			delete[] buffer;

			return true;
		}
		return false;
    }
}
