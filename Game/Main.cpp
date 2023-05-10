#include "Function.h"

int main()
{
	// ������ ������� ���� ���������� :3
	int height = 768;
	int width = 1024;
	sf::RenderWindow window(sf::VideoMode(width, height), "Happy Segment", sf::Style::Default);

	// ������ �������

	Segment S(&window, height, width, 10, 100);

	while (window.isOpen())
	{
		// �������� ������������ ������������� (��� ������� ��������)
		window.setVerticalSyncEnabled(true);

		// ������������ ������� � �����
		sf::Event event;
		while (window.pollEvent(event))
		{
			// ���� ����� ����������� �� ������� �� Escape
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