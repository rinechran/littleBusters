#pragma once



template <typename T>
struct SingleTon {

	T& getInstence(){
		static T intence;
		return intence;
	}

};