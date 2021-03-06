#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Actor.hpp"
#include "GameOverEvent.hpp"
#include "EventManager.hpp"
#include "Platform.hpp"
#include <ctime>


namespace lava
{
	class Player : public Actor
	{
	private:
		float vx;
		float vy;
		sf::Texture playerTexture;
		sf::Sprite playerSprite; 
		sf::Clock clock;
		float charge;

		static const int MINJUMP = 200;
		static const int MAXJUMP = 1000;
		static const int JETPACK_JUMP = 560;
		static const int POWERUP_TIME = 8;
		static const int VX = 200;
		lava::eventManager *manager;
		
	public:
		Player(sf::Texture *playerTexture, lava::eventManager *manager);
		
		void update(float delta);
		void stickToPlatform(float delta, float vx, float vy);
		void render(sf::RenderWindow* window);
		void jump();
		void jetpackJump();
		void die();
		void land(float y);
		void hitByRock(float rockVy);
		void applyPowerup(int type);
		float getCharge();
		bool charging;
		bool moveLeft;
		bool moveRight;
		bool isHit;
		bool isFalling() { return vy > 0; }
		bool faceLeft;
		void hitByFire();
		bool immune;
		void highJump();
		
		int score; 
		int extra = 0;
		bool alive;
		bool landed;
		const char* powerup;
		float powerupDelta;
		int life = 2;

		float getX() { return playerSprite.getPosition().x; }
		float getY() { return playerSprite.getPosition().y; }
		const char* getPowerup() { return powerup; }
		sf::Sprite getSprite() { return playerSprite; }
		void resetPosition();
	};
}

#endif
