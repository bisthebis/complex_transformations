#include <iostream>
#include <SFML/Graphics.hpp>

sf::Vector2f squarePlusOne(const sf::Vector2f& z) {
    return sf::Vector2f(z.x * z.x - z.y * z.y + 1, z.x * z.y * 2);
}
sf::Vector2f multiplyByI(const sf::Vector2f& z)
{
    return {-z.y, z.x};
}
sf::Vector2f ZtoCoords(const sf::Vector2f& z)
{
    return sf::Vector2f(500 + z.x, 500 - z.y); //Y axis inverted
}
sf::Vector2f CoordstoZ(const sf::Vector2f& coords)
{
    return sf::Vector2f(coords.x - 500, -coords.y + 500); //Y axis inverted
}

int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 4;
	settings.minorVersion = 5;


	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Plan complexe", sf::Style::Close | sf::Style::Titlebar, settings);
   	sf::RectangleShape xAxis(sf::Vector2f(1000,10)), yAxis(sf::Vector2f(10,1000));

   	sf::View view = window.getView();
   	view.zoom(5);
   	window.setView(view);

   	xAxis.setPosition(0, 495); xAxis.setFillColor(sf::Color::Red);
    yAxis.setPosition(495, 0); yAxis.setFillColor(sf::Color::Red);
    sf::CircleShape image;
    image.setFillColor(sf::Color::Green);
    image.setRadius(10);
    image.setPosition(750, 750);


	while (window.isOpen())
	{
		sf::Event event;
        	while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed)
			window.close();

		}

	window.clear();
	{
	    auto mouseCoords = sf::Vector2f(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y));
        auto z = CoordstoZ(mouseCoords);
        auto fz = squarePlusOne(z);
        auto coords = ZtoCoords(fz);
        image.setPosition(coords);
	}
	window.draw(xAxis);
	window.draw(yAxis);
	window.draw(image);
	window.display();
	}

	return 0;
}
