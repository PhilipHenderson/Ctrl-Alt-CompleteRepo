#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	m_pShip = new Ship();
	m_pShip->getTransform()->position = glm::vec2(400.0f, 300.0f); 
	addChild(m_pShip); 

	const SDL_Color blue = { 0, 0, 255, 255 };
	m_pStartLabel = new Label("~BreakFast Breakout~", "Consolas", 70, blue, glm::vec2(400.0f, 40.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pInstructionsLabel = new Label("By: Crtl+Alt+Complete", "Consolas", 20, blue, glm::vec2(400.0f, 250.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);

	// New Game Button
	m_pNewGameButton = new Button();
	m_pNewGameButton->getTransform()->position = glm::vec2(285.0f, 425.0f);

	// Start Button
	m_pResumeGameButton = new Button();
	m_pResumeGameButton->getTransform()->position = glm::vec2(285.0f, 500.0f);

	m_pResumeGameButton->addEventListener(CLICK, [&]()-> void
	{
		m_pResumeGameButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	});
	m_pResumeGameButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pResumeGameButton->setAlpha(128);
	});
	m_pResumeGameButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pResumeGameButton->setAlpha(255);
	});
	addChild(m_pResumeGameButton);
	m_pNewGameButton->addEventListener(CLICK, [&]()-> void
	{
		//Go Into Saved Game State
		m_pNewGameButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	});
	m_pNewGameButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pNewGameButton->setAlpha(128);
	});
	m_pNewGameButton->addEventListener(MOUSE_OUT, [&]()->void
		{
			m_pNewGameButton->setAlpha(255);
		});
	addChild(m_pNewGameButton);

	
}

