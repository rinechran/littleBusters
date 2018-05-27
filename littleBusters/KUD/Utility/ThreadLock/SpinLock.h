#pragma once

#include <Windows.h>

class Lock {
public:
	Lock() = default;

	Lock(const Lock&) = delete;

	Lock(Lock&&) = delete;

	virtual void lock() = 0;

	virtual void unLock() = 0;

	virtual ~Lock() {}
};

class SpinLock : Lock{
public:
	SpinLock(bool autoLock = true) {

	}
	virtual void lock() override {

	}
	virtual void unLock() override {

	}
	virtual ~SpinLock() {

	}
private:

};