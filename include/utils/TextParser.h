#pragma once
#include <fstream>
#include <string>

namespace A_Compiler{

    //! @note reading each line from file
    template<typename T>
    inline T readline(std::istream& ins){
        while (true) {
				if (ins.eof()) //We reached the end of file, or the user hit ctrl-d
					return T();
				T retval;
				ins >> retval;
				if (!ins) {
					ins.clear(); //Clear error code
					std::string s;
					ins >> s; //Remove the word that caused the error
					continue;
				}
				return retval;
			}
        return true;
    }

    //! @note Reading each line based on prompt
    template<class T>
    T readline(const std::string prompt = "") {
        while (true) {
            if (std::cin.eof()) //We reached the end of file, or the user hit ctrl-d
                return T(); //Alternatively, we could throw an exception
            T retval;
            // std::cout << prompt;
            std::cin >> retval;
            if (!std::cin) {
                std::cin.clear(); //Clear error code
                std::string s;
                std::cin >> s; //Remove the word that caused the error
                continue;
            }
            return retval;
        }
    }
};