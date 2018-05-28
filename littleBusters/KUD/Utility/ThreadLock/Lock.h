#pragma once

#include <Windows.h>
#include <iostream>

namespace KUD {

	class Lock {

	public:
		Lock() = default;

		Lock(const Lock&) = delete;

		Lock(Lock&&) = delete;

		virtual void lock() = 0;

		virtual void unlock() = 0;

		virtual ~Lock() {}
		using LockObject = std::uint32_t;

	};

	/*
		this is example code
		KUD::SpinLock a;
		td::lock_guard<KUD::SpinLock> b(a);
	*/
	class SpinLock : Lock {
	public:
		SpinLock() {
		}
		virtual void lock() override {
			while (InterlockedCompareExchange(&_Locker, 1, 0) != 0) {
			}
		}
		virtual void unlock() override {
			InterlockedDecrement(&_Locker);

		}
		virtual ~SpinLock() {
		}
	private:
		LockObject  _Locker = 0;
	};

}
