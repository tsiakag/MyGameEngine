#pragma once
#include <Windows.h>

namespace MyGameEngine {

	class Timer {
	private:
		LARGE_INTEGER m_Start;
		double m_frequency;

	public:
		Timer() {
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_frequency = 1.00f / frequency.QuadPart;
			QueryPerformanceCounter(&m_Start);
		}

		void reset() {
			QueryPerformanceCounter(&m_Start);
		}

		float elapsed() {
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - m_Start.QuadPart;
			return (float)(cycles * m_frequency);
		}


	};


}