#include "Barricade.h"

std::vector<glm::vec3> Barricade::CreateBarricades()
{
	float Xpos = 0.35f;
	float Ypos = 0.6f;
	glm::vec3 barricade;
	std::vector<glm::vec3> BarricadeList;

	for (int y = 0; y < 3; y++)
	{
		BarricadeCounter = 0;
		for (int x = 0; x < 12; x++)
		{
			barricade.x = Xpos;
			barricade.y = Ypos;
			if (BarricadeCounter == 3)
			{	
				Xpos += 1;
				BarricadeCounter = 0;
			}
			else
			{
				Xpos += 0.15f;
				BarricadeCounter++;
			}
			BarricadeList.push_back(barricade);
			
		}
		Xpos = 0.35f;
		Ypos -= 0.12f;

	}
	return BarricadeList;
}

std::vector<glm::vec3> Barricade::AlienBarricadeCollision(std::vector<glm::vec3> BarricadeList, std::vector<glm::vec3> AlienList)
{
	glm::vec3 Alien;
	glm::vec3 Barricade;
	float AlienX;
	float AlienY;
	float AlienLeft;
	float AlienRight;
	float AlienDown;
	float AlienTop;

	for (int i = 0; i < BarricadeList.size(); i++)
	{
		
		Barricade = BarricadeList.at(i);
		
		


		for (int j = 0; j < AlienList.size(); j++)
		{
			Alien = AlienList.at(j);
			AlienX = Alien.x;
			AlienY = Alien.y;
			AlienLeft = Alien.x - 0.15f;
			AlienRight = Alien.x + 0.15f;
			AlienDown = Alien.y - 0.1f;
			AlienTop = Alien.y + 0.1f;

			if (Barricade.x > AlienLeft && Barricade.x < AlienRight && Barricade.y<AlienTop && Barricade.y>AlienDown)
			{
				
				BarricadeList.erase(BarricadeList.begin() + i);

				break;
			}


		}


	}
	return BarricadeList;
}
