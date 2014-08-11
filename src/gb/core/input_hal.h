// ANDER MARTINEZ 2014

#pragma once
#include <stdint.h>

namespace gamelad{
	class InputHAL{
	public:
		enum Key{ UP, DOWN, LEFT, RIGHT, START, SELECT, A, B };
		InputHAL(void);
		~InputHAL(void);
		bool is_pressed(Key key);
	};
}
