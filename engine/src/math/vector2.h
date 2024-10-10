#pragma once
#include <utils/logger.h>
#include <cassert>
#include <utils/dll_macros.h>

class __declspec(dllexport) Vector2 {
public:
	float x = 0;
	float y = 0;
	static int a;

	Vector2();
	Vector2(float x, float y);

	static const Vector2 zero;
	static const Vector2 one;

	Vector2 operator* (float mul) {
		return Vector2{ x * mul, y * mul };
	}

	Vector2 operator/ (float div) {
		if (div == 0) {
			LOG_ERROR_INFO();
		}
		assert(div != 0);
		return Vector2{ x / div, y / div };
	}

	Vector2 operator+ (Vector2 other) {
		return Vector2{ x + other.x, y * other.y };
	}

	Vector2 operator+= (Vector2 other) {
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	bool operator== (Vector2 other) {
		return this->x == other.x && this->y == other.y;
	}
};

