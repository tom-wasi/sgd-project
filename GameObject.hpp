#pragma once

#include <SDL2/SDL.h>
#include "Game.hpp"
#include "SDL2/SDL_image.h"
#include <vector>
#include "Collision.hpp"

class GameObject
{
public:
	GameObject(const char* name, const char* texturesheet, float x, float y, int textureWidth = 16, int textureHeight = 16, float textureUpscale = 1.0f);
	
	GameObject(const char* name, SDL_Texture* texture, float x, float y, int textureWidth = 16, int textureHeight = 16, float textureUpscale = 1.0f);
	
	~GameObject();

	virtual void update();
	virtual void render();

	void CheckForCollision();
	void SetCollisionBox(int w, int h);
	void UpdateCollisionBox();


	static std::vector<GameObject*> gameObjects;
	static int lastId;
	static int RegisterGameObject(GameObject* gameObject);
	static void DestroyGameObject(GameObject* gameObject);
	static void UpdateEvery();
	static void RenderEvery();

	bool operator == (GameObject* g) {
		return ID == g->ID;
	}

protected:
	float x, y, textureUpscale;
    int textureWidth, textureHeight;
	int ID;
	char* name;
	bool hasCollision = false;
	SDL_Rect collisionBox;
	virtual void Collided(GameObject* gameObject);

private:
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
};