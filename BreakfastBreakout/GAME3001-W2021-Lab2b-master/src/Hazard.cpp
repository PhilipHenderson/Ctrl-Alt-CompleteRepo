#include "Hazard.h"
#include "TextureManager.h"

Hazard::Hazard()
{
	TextureManager::Instance()->load("../Assets/textures/Knife.png", "knife");

	auto size = TextureManager::Instance()->getTextureSize("knife");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(HAZARD);


}

Hazard::~Hazard()
= default;

void Hazard::draw()
{
	TextureManager::Instance()->draw("knife",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void Hazard::update()
{
}

void Hazard::clean()
{
}