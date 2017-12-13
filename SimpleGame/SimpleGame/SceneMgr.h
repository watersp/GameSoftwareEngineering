#pragma once
#include <cstdlib>
#include <iostream>

#include "Renderer.h"
#include "Object.h"

#define MAX_OBJECT_COUNT 1000

#define OBJECT_CHARACTER 0
#define OBJECT_BUILDING 1
#define OBJECT_BULLET 2
#define OBJECT_ARROW 3

class SceneMgr
{
public:
	SceneMgr(int width, int height);
	~SceneMgr();

	int AddActorObject(float x, float y, int type);
	void DeleteActorObject(int index);
	void UpdateAllActorObjects(float elapsedTime);
	Object* GetActorObject(int index);
	int GetMaxObjectCount();
	void DrawAllObjects();

private:
	bool BoxBoxCollisionTest(float minX, float minY, float maxX, float maxY, float minX1, float minY1, float maxX1, float maxY1);
	void DoCollisionTest();
	Object *m_actorObjects[MAX_OBJECT_COUNT];
	Object *m_bulletObjects[MAX_OBJECT_COUNT];

	Renderer *m_renderer;

	int m_windowWidth;
	int m_windowHeight;

	GLuint m_texCharacter = 0;
	GLuint m_texBuilding = 0;
};

