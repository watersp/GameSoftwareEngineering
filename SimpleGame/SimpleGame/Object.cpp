#include "stdafx.h"
#include "Object.h"
#include <math.h>


Object::Object(float x, float y)
{
	m_x = x;
	m_y = y;
	m_vX = 1;
	m_vY = 0;

	m_size = 70;
	m_color[0] = 1;
	m_color[1] = 0;
	m_color[2] = 0;
	m_color[3] = 1;
}


Object::~Object()
{
	
}

void Object::Update()
{
	float elapsedTime = 1.5;
	m_x = m_x + m_vX * elapsedTime;
	m_y= m_y + m_vY * elapsedTime;

	m_size = 30 * (sin(m_x)+1)/2;
	m_color[0] = cos(m_x);
	m_color[1] = 1-cos(m_x);

	if (m_x > 250)
	{
		m_vX = -m_vX;
	}

	if (m_x < -250)
	{
		m_vX = -m_vX;
	}
}