#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
	for (int i = 0; i < MAX_OBJECT_COUNT; i++)
	{
		m_actorObjects[i] = NULL;
		m_bulletObjects[i] = NULL;
	}
}


SceneMgr::~SceneMgr()
{
}

int SceneMgr::AddActorObject(float x, float y)
{
	//Find empty slot
	for (int i = 0; i < MAX_OBJECT_COUNT; i++)
	{
		if (m_actorObjects[i] == NULL)
		{
			//success!
			//float x = 250.f * 2.f * ((float)std::rand()/(float)RAND_MAX - 0.5f);
			// y = 250.f * 2.f * ((float)std::rand()/(float)RAND_MAX - 0.5f);
			m_actorObjects[i] = new Object(x, y);
			return i;
		}
	}

	//slots are full
	std::cout << "slots are full \n";
	return -1;
}

void SceneMgr::DeleteActorObject(int index)
{
	if (m_actorObjects[index] != NULL)
	{
		delete m_actorObjects[index];
		m_actorObjects[index] = NULL;
	}
}

void SceneMgr::UpdateAllActorObjects()
{
	for (int i = 0; i < MAX_OBJECT_COUNT; i++)
	{
		if (m_actorObjects[i] != NULL)
		{
			if (m_actorObjects[i]->GetLife() < 0.0001f)
			{
				//kill object
				delete m_actorObjects[i];
				m_actorObjects[i] = NULL;
			}
			else
			{
				m_actorObjects[i]->Update();
			}
		}
		if (m_bulletObjects[i] != NULL)
		{
			m_bulletObjects[i]->Update();
		}
	}
}

Object* SceneMgr::GetActorObject(int index)
{
	return m_actorObjects[index];
}

int SceneMgr::GetMaxObjectCount()
{
	return MAX_OBJECT_COUNT;
}
