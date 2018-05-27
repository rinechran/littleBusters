#pragma once

#include <Windows.h>
#include <iostream>

namespace NUD {
	using LockObject = std::uint32_t;
	enum class LOCK_KIND {
		AUTO_LOCK,
		MANUAL
	};
	class Lock {
	public:
		Lock() = default;

		Lock(const Lock&) = delete;

		Lock(Lock&&) = delete;

		virtual void lock() = 0;

		virtual void unLock() = 0;

		virtual ~Lock() {}
	};


	template <LOCK_KIND>
	class SpinLock;

	template<>
	class SpinLock<LOCK_KIND::AUTO_LOCK> : Lock {
	public:
		SpinLock(LockObject &object) {
			this->_Locker = &object;
			lock();
		}
		virtual void lock() override {
			while (InterlockedCompareExchange(_Locker, 1, 0) != 0) {
			}
		}
		virtual void unLock() override {
			InterlockedDecrement(_Locker);

		}
		virtual ~SpinLock() {
			unLock();
		}
	private:
		LockObject * _Locker = 0;
	};
	template<>
	class SpinLock<LOCK_KIND::MANUAL> : Lock {
	public:

		SpinLock(LockObject &object) {
			this->_Locker = &object;
		}
		virtual void lock() override {
			while (InterlockedCompareExchange(_Locker, 1, 0) != 0) {
			}
		}
		virtual void unLock() override {
			InterlockedDecrement(_Locker);

		}
		virtual ~SpinLock() {
		}
	private:
		LockObject * _Locker = 0;
	};


}
