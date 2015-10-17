#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "actor.hpp"

namespace lava
{
	class Player : public Actor
	{
	private:
		float vx;
		float vy;
		sf::RectangleShape rect;
		float charge;
		
		static const float A = 1100.0;
		static const float MINJUMP = 200.0;
		static const float MAXJUMP = 1000.0;
		
	public:
		Player();
		
		void update(float delta);
		void render(sf::RenderWindow* window);
		void jump();
		float getCharge();
		bool charging;
		
		float getX() { return rect.getPosition().x; }
		float getY() { return rect.getPosition().y; }
	};
}

#endif