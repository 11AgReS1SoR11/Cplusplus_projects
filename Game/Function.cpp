#include "Function.h"

Segment::Segment(sf::RenderWindow* window, double height, double width, int sizeX, int sizeY) {
	this->window = window;
	this->Size = { sizeX, sizeY };
	this->Speed = { 0, 0 };
	this->Coordinates = { width / 2, height / 2 };
	Vector<double> tr(0, 0);
	for (int i = 0; i < 20; i++) this->trace.push(tr); // заполняю первые 10 элементов следа
	// Устанавливаю размер для ракетки с помощью Vector2f
	this->rectangle.setSize(sf::Vector2f(sizeX, sizeY));
	// Для удобства перенесу основную точку из левого верхнего угла в центр
	this->rectangle.setOrigin(sizeX / 2, sizeY / 2);
	// И устанавливаем Segment в начальные позиции
	this->rectangle.setPosition(width / 2, height / 2);

	this->rectangle.setFillColor(sf::Color(100, 0, 250));
}

sf::CircleShape Triangle(int size, int x, int y, int RED, int GREEN, int BLUE) {
	sf::CircleShape triangle(size, 3);
	triangle.setOrigin(size, 0);
	triangle.setPosition(x, y);
	triangle.setFillColor(sf::Color(RED, GREEN, BLUE));
	return triangle;
}

void Segment::draw_fair() {
	int len_small = this->Size.GetX() * 2, len_medium = this->Size.GetX() * 3, len_big = this->Size.GetX() * 4;
	sf::CircleShape Small_Triangle1 = Triangle(len_small, this->Coordinates.GetX(), this->Coordinates.GetY() - this->Size.GetY() / 2 - 1.5 * len_small, 250, 0, 0),
		Small_Triangle2 = Triangle(len_small, this->Coordinates.GetX(), this->Coordinates.GetY() + this->Size.GetY() / 2 + 1.5 * len_small, 250, 0, 0),
		Medium_Triangle1 = Triangle(len_medium, this->Coordinates.GetX(), this->Coordinates.GetY() - this->Size.GetY() / 2 - 1.5 * len_medium, 250, 150, 0),
		Medium_Triangle2 = Triangle(len_medium, this->Coordinates.GetX(), this->Coordinates.GetY() + this->Size.GetY() / 2 + 1.5 * len_medium, 250, 150, 0),
		Big_Triangle1 = Triangle(len_big, this->Coordinates.GetX(), this->Coordinates.GetY() - this->Size.GetY() / 2 - 1.5 * len_big, 250, 250, 0),
		Big_Triangle2 = Triangle(len_big, this->Coordinates.GetX(), this->Coordinates.GetY() + this->Size.GetY() / 2 + 1.5 * len_big, 250, 250, 0);
	Small_Triangle2.rotate(180); Medium_Triangle2.rotate(180); Big_Triangle2.rotate(180);
	// Для движения down
	if (this->Speed.GetY() > MAX_SPEED * 0.9)
		this->window->draw(Big_Triangle1);

	if (this->Speed.GetY() > MAX_SPEED * 0.6)
		this->window->draw(Medium_Triangle1);

	if (this->Speed.GetY() > MAX_SPEED * 0.2)
		this->window->draw(Small_Triangle1);

	// Для движения up
	if (this->Speed.GetY() < -MAX_SPEED * 0.9)
		this->window->draw(Big_Triangle2);

	if (this->Speed.GetY() < -MAX_SPEED * 0.6)
		this->window->draw(Medium_Triangle2);

	if (this->Speed.GetY() < -MAX_SPEED * 0.2)
		this->window->draw(Small_Triangle2);

	if (this->Coordinates.GetY() - this->Size.GetY() / 2 <= 0 + 40 && this->Speed.GetY() < 0) this->Speed.SetY(this->Speed.GetY() * -1);
	else if (this->Coordinates.GetY() + this->Size.GetY() / 2 >= this->window->getSize().y - 40) this->Speed.SetY(this->Speed.GetY() * -1);
	if (this->Coordinates.GetX() <= 0 + 40 && this->Speed.GetX() < 0) this->Speed.SetX(this->Speed.GetX() * -1);
	else if (this->Coordinates.GetX() >= this->window->getSize().x - 40) this->Speed.SetX(this->Speed.GetX() * -1);
}

void Segment::draw_footprint() {
	sf::RectangleShape seg;
	seg.setSize(sf::Vector2f(this->Size.GetX(), this->Size.GetY()));
	seg.setFillColor(sf::Color(100, 0, 100, 60));
	seg.setOrigin(this->Size.GetX() / 2, this->Size.GetY() / 2);

	for (int i = 0; i < this->trace.size() - 2; i++) {
		Vector<double> CurVec(this->trace.front().GetX(), this->trace.front().GetY());

		seg.setPosition(CurVec.GetX(), CurVec.GetY());
		this->trace.push(CurVec);
		this->trace.pop();


		this->window->draw(seg);
	}
}

void Segment::draw_trace() {
	this->draw_fair();
	this->draw_footprint();
}

void Segment::draw() {
	draw_trace();
	this->rectangle.setPosition(this->Coordinates.GetX(), this->Coordinates.GetY());
	this->window->draw(this->rectangle);
}

void Segment::check_key() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		//std::cout << this->Speed.GetY() << std::endl;
		if (this->Speed.GetY() < -MAX_SPEED) return;
		//std::cout << (this->Speed / SPEED_OF_SPEED).GetY() << std::endl;
		this->Speed = this->Speed / SPEED_OF_SPEED;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (this->Speed.GetY() > MAX_SPEED) return;
		this->Speed = this->Speed * SPEED_OF_SPEED;
	}
	else {
		if (this->Speed.GetY() > 1) this->Speed = this->Speed / SPEED_OF_SPEED;
		else if (this->Speed.GetY() < -1) this->Speed = this->Speed * SPEED_OF_SPEED;
		else this->Speed.SetY(0);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (this->Speed.GetX() < -MAX_SPEED) return;
		this->Speed = this->Speed - SPEED_OF_SPEED;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (this->Speed.GetX() > MAX_SPEED) return;
		this->Speed = this->Speed + SPEED_OF_SPEED;
	}
	else {
		if (this->Speed.GetX() > 1) this->Speed = this->Speed - SPEED_OF_SPEED;
		else if (this->Speed.GetX() < -1) this->Speed = this->Speed + SPEED_OF_SPEED;
		else this->Speed.SetX(0);
	}
}

void Segment::update() {
	check_key();

	this->Coordinates = this->Coordinates * this->Speed; //this->y += this->speedY;
	this->Coordinates = this->Coordinates + this->Speed; //this->x += this->speedX;
	this->trace.push(this->Coordinates);
	this->trace.pop();
}

void draw_frame(sf::RenderWindow& window) {
	sf::RectangleShape line(sf::Vector2f(20, window.getSize().y - 40));
	line.setFillColor(sf::Color(250, 0, 0, 200));

	line.setPosition(20, 20);
	window.draw(line); //right
	line.setPosition(window.getSize().x - 40, 20);
	window.draw(line); //left
	line.setPosition(20 + 20, 20);
	line.setSize(sf::Vector2f(window.getSize().x - 40 - 40, 20));
	window.draw(line); //up
	line.setPosition(20 + 20, window.getSize().y - 40);
	window.draw(line); //down
}