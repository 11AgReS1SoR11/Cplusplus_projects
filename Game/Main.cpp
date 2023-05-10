#include "Function.h"

int main()
{
	// Создаю главное окно приложения :3
	int height = 768;
	int width = 1024;
	sf::RenderWindow window(sf::VideoMode(width, height), "Happy Segment", sf::Style::Default);

	// Создаю отрезок

	Segment S(&window, height, width, 10, 100);

	while (window.isOpen())
	{
		// Включаем вертикальную синхронизацию (для плавной анимации)
		window.setVerticalSyncEnabled(true);

		// Обрабатываем события в цикле
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Окно будет закрываться по нажатию на Escape
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
		}

		draw_frame(window);
		S.update();
		S.draw();

		window.display();
		window.clear();
	}
	return 0;
}