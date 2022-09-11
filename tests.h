#pragma once
#include <iostream>
#include <chrono>
#include "Distance3D.h"
#include "OwnSegmentPoint.h"
class Timer {
public:
	using clock = std::chrono::high_resolution_clock;
	using measure = std::chrono::duration<double>; // секунды (с зап€той)
	Timer() { m_start = clock::now(); }
	~Timer() {
		std::cout << std::chrono::duration_cast<measure>(
			clock::now() - m_start).count() << std::endl;
	}
private:
	std::chrono::time_point<clock> m_start;
};
class tests {
public:
	tests() = delete;
	static void testParal() {
		Segment segment1 = { Point{2,0,0}, Point{0,0,0} };
		Segment segment2 = { Point{2,2,0}, Point{0,2,0} };
		if (fabs(distance3Dbetweenlines<Point, Segment>(segment1, segment2) - 2) < 0.00000001) {
			std::cout << "testParal() is correct" << std::endl;
		}
		else {
			std::cout << "testParal() is wrong" << std::endl;
		}
	}
	static void testPerp() {
		Segment segment1 = { Point{2,0,0}, Point{0,0,0} };
		Segment segment2 = { Point{1,2,0}, Point{1,4,0} };
		if (fabs(distance3Dbetweenlines<Point, Segment>(segment1, segment2) - 2) < 0.00000001) {
			std::cout << "testParal() is correct" << std::endl;
		}
		else {
			std::cout << "testParal() is wrong" << std::endl;
		}
	}
	static void testCross() {
		Segment segment1 = { Point{2,0,0}, Point{0,0,0} };
		Segment segment2 = { Point{1,2,0}, Point{1,-4,0} };
		if (fabs(distance3Dbetweenlines<Point, Segment>(segment1, segment2)) < 0.00000001) {
			std::cout << "testParal() is correct" << std::endl;
		}
		else {
			std::cout << "testParal() is wrong" << std::endl;
		}
	}
	//кратчайшее рассто€ние не перпендикул€р
	static void testNonPerp() {
		Segment segment1 = { Point{2,0,0}, Point{0,0,0} };
		Segment segment2 = { Point{5,4,0}, Point{8,4,0} };
		if (fabs(distance3Dbetweenlines<Point, Segment>(segment1, segment2) - 5) < 0.00000001) {
			std::cout << "testParal() is correct" << std::endl;
		}
		else {
			std::cout << "testParal() is wrong" << std::endl;
		}
	}
	static void testCrossNotTuch() {
		Segment segment1 = { Point{5,0,0}, Point{0,0,0} };
		Segment segment2 = { Point{3,-2,4}, Point{3,2,4} };
		if (fabs(distance3Dbetweenlines<Point, Segment>(segment1, segment2) - 4) < 0.00000001) {
			std::cout << "testParal() is correct" << std::endl;
		}
		else {
			std::cout << "testParal() is wrong" << std::endl;
		}
	}
	static void getAllTests() {
		tests::testParal();
		tests::testPerp();
		tests::testCross();
		tests::testNonPerp();
		tests::testCrossNotTuch();
	}

	static void bencmarking(int iter) {
		Segment segment1 = { Point{5,0,0}, Point{0,0,0} };
		Segment segment2 = { Point{3,-2,4}, Point{3,2,4} };
		std::cout << "Benchmarking(iterations=" << iter << "): ";
		Timer time;
		for (int i = 0; i < iter; ++i) {
			distance3Dbetweenlines<Point, Segment>(segment1, segment2);
		}
	}
};

