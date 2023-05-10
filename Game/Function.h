#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <queue>
#define MAX_SPEED 7
#define SPEED_OF_SPEED 0.35
#define PI 3.14159265358979

template <class Type1> class Vector {
private:
	Type1 x;
	Type1 y;
public:
	Vector() { this->x = 0; this->y = 0; }
	Vector(Type1 x, Type1 y) { this->x = x; this->y = y; }
	Type1 GetX() { return x; }
	Type1 GetY() { return y; }
	void SetX(Type1 x) { this->x = x; }
	void SetY(Type1 y) { this->y = y; }
	Vector<Type1> operator + (const Vector<Type1>& v) const { return Vector{ this->x + v.x, this->y }; }
	Vector<Type1> operator - (const Vector<Type1>& v) const { return Vector{ this->x - v.x, this->y }; }
	Vector<Type1> operator * (const Vector<Type1>& v) const { return Vector{ this->x, this->y + v.y }; }
	Vector<Type1> operator / (const Vector<Type1>& v) const { return Vector{ this->x, this->y - v.y }; }
	Vector<Type1> operator = (const Vector<Type1>& v) { this->y = v.y; this->x = v.x; return *this; }

	Vector<Type1> operator + (const double& v) const { return Vector{ this->x + v, this->y }; }
	Vector<Type1> operator - (const double& v) const { return Vector{ this->x - v, this->y }; }
	Vector<Type1> operator * (const double& v) const { return Vector{ this->x, this->y + v }; }
	Vector<Type1> operator / (const double& v) const { return Vector{ this->x, this->y - v }; }
	Vector<Type1> operator = (const int& v) { this->y = v; this->x = v; return *this; }
};

class Segment {
private:
	sf::RenderWindow* window;      // Указатель на окно, нужен для отрисовки
	sf::RectangleShape rectangle; // Собственно, сама Segment
	Vector<double> Coordinates;  // Координата y Segment (x мы задаем в коде)
	Vector<double> Speed;
	Vector<int> Size;
	std::queue<Vector<double>> trace; //last 10 place
public:
	Segment(sf::RenderWindow* window, double height, double width, int sizeX, int sizeY);
	// Метод для отрисовки Segment
	void draw_fair();
	void draw_trace();
	void draw_footprint();
	void draw();

	// Обработка клавиш
	void check_key();

	void update();
};

void draw_frame(sf::RenderWindow& window);
