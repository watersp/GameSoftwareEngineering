/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"

#include "Renderer.h"
#include "SceneMgr.h"
#include "Object.h"

#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"


Renderer *g_Renderer = NULL;
SceneMgr *g_SceneMgr = NULL;

bool g_LButtonDown = false;

void RenderScene(void)
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	g_Renderer->DrawSolidRect(
		0,
		0,
		0,
		500,
		0,
		0,
		0,
		0.2
	);

	g_SceneMgr->UpdateAllActorObjects();
	
	for (int i = 0; i < g_SceneMgr->GetMaxObjectCount(); i++)
	{
		if (g_SceneMgr->GetActorObject(i) != NULL)
		{
			// Renderer Test
			g_Renderer->DrawSolidRect(
				g_SceneMgr->GetActorObject(i)->m_x,
				g_SceneMgr->GetActorObject(i)->m_y,
				0,
				g_SceneMgr->GetActorObject(i)->m_size,
				g_SceneMgr->GetActorObject(i)->m_color[0],
				g_SceneMgr->GetActorObject(i)->m_color[1],
				g_SceneMgr->GetActorObject(i)->m_color[2],
				g_SceneMgr->GetActorObject(i)->m_color[3]
			);
		}
	}
	
	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

//button
//GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, GLUT_RIGHT_BUTTON
//state
//GLUT_UP, GLUT_DOWN
void MouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		g_LButtonDown = true;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (g_LButtonDown)
		{
			//clicked
			for (int i = 0; i < 100; i++)
				g_SceneMgr->AddActorObject(x-250, -y+250);
		}
		g_LButtonDown = false;
	}

	RenderScene();
}

void MotionInput(int x, int y)
{
	if (g_LButtonDown)
	{
		//clicked
		for (int i = 0; i < 100; i++)
		{
			//g_SceneMgr->AddActorObject(x - 250, -y + 250);
		}
	}
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMotionFunc(MotionInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	g_SceneMgr = new SceneMgr();
	/*for (int i = 0; i < g_SceneMgr->GetMaxObjectCount(); i++)
	{
		g_SceneMgr->AddActorObject();
	}*/

	glutMainLoop();

	delete g_Renderer;
	delete g_SceneMgr;

    return 0;
}

