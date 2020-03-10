#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

double f(double x){
	return (double) pow(x,2);
}

// <type>& <name> => Reference to <name>
// <reference>-><name> => like <object>.<name> but for references

class Graph {
	private:
		sf::Color linecolor    = sf::Color( 95 , 95 , 95 , 255);
		sf::Color epsiloncolor = sf::Color(180 , 30 , 50 , 255);
		sf::Color deltacolor   = sf::Color(180 , 30 , 50 , 255);
		double scaleX          = 1;
		double scaleY          = 1;
		double offsetX         = 0;
		double offsetY         = 0;
		double epsilon         = 10;
		double delta(double e){
			return std::min(e,(double)2/3);
		};
	public:
		// contructor
		Graph(
				double sX,
				double sY,
				sf::RenderWindow& w
				){
			scaleX = sX;
			scaleY = sY;
			offsetY = w.getSize().y/2;
			offsetX = w.getSize().x/2;
			std::cout << "Created a graph " << std::endl;
		}
		// destructor
		~Graph(){
			std::cout << "Deleted a graph" << std::endl;
		}
		double function(double x){
			return pow(x,2);
		}
		void draw(sf::RenderWindow& w){
			/* std::cout << scale << std::endl; */
			sf::CircleShape shape(1.f);
			shape.setFillColor(linecolor);

			for (int i = 0; i < w.getSize().x; ++i) {
				shape.setPosition(
						i,
						offsetY - this->function(
								(i-offsetX)*scaleX
							)*scaleY
						);
				w.draw(shape);
			}

			drawEpsilon(w);
		}
		void drawEpsilon(sf::RenderWindow& w){
			sf::Color color(180,30,50,255);
			sf::RectangleShape shape;
			shape.setFillColor(epsiloncolor);
			shape.setSize(sf::Vector2f(w.getSize().x,2));
			shape.setPosition(0,offsetY - epsilon*scaleY);
			w.draw(shape);
		};
		// getters and setters
		void setScaleX(double sX){
			scaleX = sX;
		}
		void setScaleY(double sY){
			scaleY = sY;
		}
		double getScaleX(){
			return scaleX;
		}
		double getScaleY(){
			return scaleY;
		}
};

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "Epsilon Delta");
	Graph g(0.1, 1, window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		g.setScaleY(g.getScaleY()*1.0001);
		g.setScaleX(g.getScaleX()*1.0001);

		// std::cout << window.getSize().x << ", " << window.getSize().x << std::endl;
        window.clear();
		g.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
