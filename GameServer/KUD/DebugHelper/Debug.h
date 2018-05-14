#pragma once

#include <iostream>


namespace KUD {
	template <class T>
	void DEBUGMSG(T &&msg) {
#ifdef _DEBUG
		std::cout << msg << std::endl;
#endif // DEBUG
	}
	/*
		char * + __LINE__ operator not implement
		
	*/
}