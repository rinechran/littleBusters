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

		class ImpleUnhanderFiter {
		public:
			ImpleUnhanderFiter() :fn(nullptr){}

			void operator()() {
				fn();
			}

			template <typename T>
			bool operator==(T &&oth) {
				return fn == oth;
			}
			template <typename T>
			bool operator!=(T &&oth) {
				return fn != oth;
			}
			

			void operator=(std::function<void()> othFn) {
				this->fn.swap(othFn);
			}

		private:
			std::function<void()> fn;

		} ImpleUnhanderFiters;

		LONG __stdcall unhanderExceptFiter(PEXCEPTION_POINTERS exceptionPointer) {
			ImpleUnhanderFiters();
			return 0;
		}
		void SetUnhanderExcept() {
			SetUnhandledExceptionFilter(unhanderExceptFiter);
		}



	}
}