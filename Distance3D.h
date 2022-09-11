#pragma once
/// <summary>
/// Функция находит кратчайшее расстояние между двумя отрезками в пространстве.
/// Данный алгоритм был взят ...
/// Алгоритм преобразовывает задачу к поиску минимума параметризованной функции. 
/// В конечном счёте происходит оптимизированный отбор 9 возможных кандидатов.
/// Для ускорения работы количество операций деления сведенно к минимуму. 
/// </summary>
/// <typeparam name="T1">Здесь может быть любой собственный тип точки,
///  который поддерживает операции "*,+,-", а также есть функция скалярного 
/// произведения Dot(point,point)</typeparam> 
/// <typeparam name="T2">Здесь может быть любой собственный тип отрезка,
/// который поддерживает доступ к точкам отрезка .first, .second</typeparam>
/// <typeparam name="T3">Здесь может быть собственный тип с плавающей точкой,
/// который имеет перегруженные операторы сравнения, математическими действия,
///	оператор "/=", а также функция sqrt()</typeparam>
/// <param name="line1">Первый отрезок</param>
/// <param name="line2">Второй отрезок</param>
/// <returns>Расстояние между отрезками</returns>
template<typename T1, typename T2, typename T3 = double>
T3 distance3Dbetweenlines(const T2& segment1, const T2& segment2) {
	T1 centrline1 = segment1.second - segment1.first;//P1-P0
	T1 centrline2 = segment2.second - segment2.first;//Q1-Q0
	T1 btwLine = segment1.first - segment2.first;//P0-Q0
	T3 a = Dot(centrline1, centrline1);
	T3 b = Dot(centrline1, centrline2);
	T3 c = Dot(centrline2, centrline2);
	T3 d = Dot(centrline1, btwLine);
	T3 e = Dot(centrline2, btwLine);
	T3 det = a * c - b * b;
	T3 bte, ctd, ate, btd, s, t;
	if (det > 0) {//Если две прямые не параллельны
		bte = b * e;
		ctd = c * d;
		if (bte <= ctd) { // s <= 0
			if (e <= 0) {
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
	else {//Если две прямые параллельны
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
