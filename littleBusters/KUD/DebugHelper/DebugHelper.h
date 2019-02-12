#pragma once

#include <iostream>
#include <Windows.h>
#include <functional>
#include <DbgHelp.h>

#pragma comment(lib,"dbghelp.lib")



namespace KUD {
	namespace DEBUG {

		template <class T>
		void MSG(T &&msg) {
#ifdef _DEBUG
			std::cout << msg << std::endl;
#endif // DEBUG
		}

	}
}