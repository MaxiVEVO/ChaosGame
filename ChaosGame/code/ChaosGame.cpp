// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>

//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);
	 
	vector<Vector2f> vertices;
	vector<Vector2f> points;

	Font font;
	Text text;
	font.loadFromFile("font/ComicSansMs.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::Red);

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == Event::Closed)
		    {
					// Quit the game when the window is closed
					window.close();
		    }
		    if (event.type == sf::Event::MouseButtonPressed)
		    {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			    std::cout << "the left button was pressed" << std::endl;
			    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
	
			    if(vertices.size() < 3)
			    {
				vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			    else if(points.size() == 0)
			    {
				///fourth click
				///push back to points vector
				points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			}
		    }
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/
	
		if(points.size() > 0)
		{
			Vector2f randVert = vertices[rand() % 3], lastP = points.back(), newPoint; 
			double xv = randVert.x, yv = randVert.y, xp = lastP.x, yp = lastP.y; 
			newPoint.x = ((xv + xp) / 2);
			newPoint.y = ((yv + yp) / 2);
			points.push_back(newPoint);	
		    ///generate more point(s)
		    ///select random vertex
		    ///calculate midpoint between random vertex and the last point in the vector
		    ///push back the newly generated coord.
		}
	
		/*
		****************************************
		Draw
		****************************************
		*/
		window.clear();

		for(int i = 0; i < vertices.size(); i++)
		{
		    RectangleShape rect(Vector2f(5,5));
		    rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
		    rect.setFillColor(Color::Blue);
		    window.draw(rect);
		}

		///text display
		if (vertices.size() < 3)
		{
			text.setString("Click on any 3 points in the shape of a triangle");
		}
		else
		{
			text.setString("Click again to start");
		}
		window.draw(text);



		///TODO:  Draw points
		for (int i = 0; i < points.size(); i++)
		{
			RectangleShape pointsRect(Vector2f(1, 1));
			pointsRect.setPosition(Vector2f(points[i].x, points[i].y));
			pointsRect.setFillColor(Color::Blue);
			window.draw(pointsRect);
		}
		window.display();
	}
}
