#pragma once

#include <concepts>

namespace Utils
{
	template <typename T> concept Lerpable = requires(T t) { 0.5f * (t - t); };

	template <typename T>
	requires Lerpable<T>
	T Lerp(T a, T b, float t)
	{
		return t * (b - a);
	}
}