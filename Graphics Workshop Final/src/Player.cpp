#include "Player.h"

glm::vec3 Player::CreatePlayer()
{
	glm::vec3 Player;
	Player.x = 2.0f;
	Player.y = 0.2f;
	Player.z = 0.0f;
	return Player;
}

void Player::CreateLives()
{
	glm::vec3 Life;
	
	for (int i = 0; i < 3; i++)
	{
		Life.x = Xpos;
		Life.y = 0.05f;
		Life.z = 0.0f;
		LivesList.push_back(Life);
		Xpos += 0.4f;
	}
	return ;
}
