#pragma once
/// <summary>
/// ������� ������� ���������� ���������� ����� ����� ��������� � ������������.
/// ������ �������� ��� ���� ...
/// �������� ��������������� ������ � ������ �������� ����������������� �������. 
/// � �������� ����� ���������� ���������������� ����� 9 ��������� ����������.
/// ��� ��������� ������ ���������� �������� ������� �������� � ��������. 
/// </summary>
/// <typeparam name="T1">����� ����� ���� ����� ����������� ��� �����,
///  ������� ������������ �������� "*,+,-", � ����� ���� ������� ���������� 
/// ������������ Dot(point,point)</typeparam> 
/// <typeparam name="T2">����� ����� ���� ����� ����������� ��� �������,
/// ������� ������������ ������ � ������ ������� .first, .second</typeparam>
/// <typeparam name="T3">����� ����� ���� ����������� ��� � ��������� ������,
/// ������� ����� ������������� ��������� ���������, ��������������� ��������,
///	�������� "/=", � ����� ������� sqrt()</typeparam>
/// <param name="line1">������ �������</param>
/// <param name="line2">������ �������</param>
/// <returns>���������� ����� ���������</returns>
template<typename T1, typename T2, typename T3 = double>  
T3 distance3Dbetweenlines(const T2& line1, const T2& line2) {
	T1 centrline1 = line1.second - line1.first;//P1-P0
	T1 centrline2 = line2.second - line2.first;//Q1-Q0
	T1 btwLine = line1.first - line2.first;//P0-Q0
	T3 a = Dot(centrline1, centrline1);
	T3 b = Dot(centrline1, centrline2);
	T3 c = Dot(centrline2, centrline2);
	T3 d = Dot(centrline1, btwLine);
	T3 e = Dot(centrline2, btwLine);
	T3 det = a * c - b * b;
	T3 bte, ctd, ate, btd, s, t;
	if (det > 0) {//���� ��� ������ �� �����������
		bte = b * e;
		ctd = c * d;
		if (bte <= ctd) { // s <= 0
			if (e <= 0 ){
				if (-d >= a) {
					s = 1;
				}
				else if (-d > 0) {
					s = -d / a;
				}
				else {
					s = 0;
				}
				t = 0;
			}
			else if (e < c) {
				s = 0;
				t = e / c;
			}
			else {
				if (b - d >= a) {
					s = 1;
				}
				else if (b - d > 0) {
					s = (b - d) / a;
				}
				else {
					s = 0;
				}
				t = 1;
			}
		}
		else { //s > 0
			s = bte - ctd;
			if (s >= det) {
				if (b + e <= 0) {
					if (-d <= 0) {
						s = 0;
					}
					else if (-d < a) {
						s = -d / a;
					}
					else {
						s = 1;
					}
					t = 0;
				}
				else if (b + e < c) {
					s = 1;
					t = (b + e) / c;
				}
				else {
					if (b - d <= 0) {
						s = 0;
					}
					else if (b - d < a) {
						s = (b - d) / a;
					}
					else {
						s = 1;
					}
					t = 1;
				}
			}
			else {
				ate = a * e;
				btd = b * d;
				if (ate <= btd) {
					if (-d <= 0) {
						s = 0;
					}
					else if (-d >= a) {
						s = 1;
					}
					else {
						s = -d / a;
					}
					t = 0;
				}
				else {
					t = ate - btd;
					if (t >= det) {
						if (b - d <= 0) {
							s = 0;
						}
						else if (b - d >= a) {
							s = 1;
						}
						else {
							s = (b - d) / a;
						}
						t = 1;
					}
					else {
						s /= det;
						t /= det;
					}
				}
			}
		}
	}
	else {//���� ��� ������ �����������
	if (e <= 0) {
		if (-d <= 0) {
			s = 0;
		}
		else if (-d >= a) {
			s = 1;
		}
		else {
			s = -d / a;
		}
		t = 0;
	}
	else if (e >= c) {
		if (b - d <= 0) {
			s = 0;
		}
		else if (b - d >= a) {
			s = 1;
		}
		else {
			s = (b - d) / a;
		}
		t = 1;
	}
	else {
		s = 0;
		t = e / c;
	}
	}
	T1 db = btwLine + s * centrline1 - t * centrline2;
	return sqrt(Dot(db, db));
}