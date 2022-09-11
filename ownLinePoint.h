#pragma once
struct Point {
	double x;
	double y;
	double z;
};
Point operator+(Point point1, Point point2) {
	return Point{ point1.x + point2.x, point1.y + point2.y, point1.z + point2.z };
}
Point operator-(Point point1, Point point2) {
	return Point{ point1.x - point2.x, point1.y - point2.y, point1.z - point2.z };
}
Point operator*(double num, Point point) {
	return Point{ point.x * num, point.y * num, point.z * num };
}

struct Line {
	Point first;
	Point second;
};

double Dot(const Point& first, const Point& second) {
	return first.x * second.x + first.y * second.y + first.z * second.z;
}