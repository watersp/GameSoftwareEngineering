#pragma once
#include <cstdlib>
#include <iostream>

#include "Object.h"

#define MAX_OBJECT_COUNT 1000

class SceneMgr
{
public:
	SceneMgr();
	~SceneMgr();

	int AddActorObject(float x, float y);
	void DeleteActorObject(int index);
	void UpdateAllActorObjects();
	Object* GetActorObject(int index);
	int GetMaxObjectCount();

private:
	Object *m_actorObjects[MAX_OBJECT_COUNT];
	Object *m_bulletObjects[MAX_OBJECT_COUNT];
};

