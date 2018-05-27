#pragma once


template <typename T>
struct SingleTon {
	SingleTon() {
		instance = nullptr;
	}
	T& getInstence(){
		if (!instance)
			instance = new T;
		return instance;
	}
	T * instance;

};