//graphic.h
#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include <graphics.h>

#include "mode/Rect.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define BATTLE_GROUND_X1 5
#define BATTLE_GROUND_X2 800
#define BATTLE_GROUND_Y2 (SCREEN_HEIGHT - BATTLE_GROUND_Y1)

class Graphic
{
public:
	static void Create();
	static void Destroy();

	static void DrawBattleGround();

	static int GetScreenWidth();
	static int GetScreenHeight();

private:
	static Rect m_rectScreen;
	static Rect m_rectBattleGround;
};

#endif

//maintank.h -----------------------------------------------------
#pragma once
#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "tank.h"

class MainTank : public Tank
{
public:
	MainTank()
	{
		m_pos.Set(300, 300);

		this->CalculateSphere();

		m_color = YELLOW;
		m_dir = Dir::UP;
		m_step = 2;
	}

	~MainTank() {}

	void SetDir(Dir dir);
	void Display();
	void Move();

protected:
	void CalculateSphere();

	void DrawTankBody();
};

#endif

//tank.h ---------------------------------------------------------

#ifndef __TANK_H__
#define __TANK_H__

#include "graphic.h"

enum Dir { UP, DOWN, LEFT, RIGHT };

class Tank
{
public:
	virtual void Display() = 0;
	virtual void Move() = 0;

protected:
	virtual void CalculateSphere() = 0;

	Point m_pos;
	Rect m_rectSphere;

	COLORREF m_color;

	Dir m_dir;

	int m_step;
};

#endif

//graphic.cpp ----------------------------------------------------
#include "graphic.h"

Rect Graphic::m_rectScreen;
Rect Graphic::m_rectBattleGround;

void Graphic::Create()
{
	m_rectScreen.Set(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	initgraph(SCREEN_WIDTH, SCREEN_WIDTH);
	setbkcolor(DARKGRAY);

	m_rectBattleGround.Set(BATTLE_GROUND_X1, BATTLE_GROUND_Y1, BATTLE_GROUND_X2, BATTLE_GROUND_Y2);
}

void Graphic::Destroy()
{
	closegraph();
}

void Graphic::DrawBattleGround()
{
	rectangle(m_rectBattleGround.GetStartPoint().GetX(), 
			  m_rectBattleGround.GetStartPoint().GetY(),
			  m_rectBattleGround.GetEndPoint().GetX(),
			  m_rectBattleGround.GetEndPoint().GetY() );
}

int Graphic::GetScreenWidth()
{
	return SCREEN_WIDTH;
}

int Graphic::GetScreenHeight()
{
	return SCREEN_HEIGHT;
}

Rect Graphic::GetBattleGround()
{
	return m_rectBattleGround;
}


//maintank.cpp ---------------------------------------------------
#include <pch.h>
#include "maintank.h"

void MainTank::SetDir(Dir dir)
{
	m_dir = dir;
}

void MainTank::DrawTankBody()
{
	fillrectangle(m_pos.GetX() - 6, m_pos.GetY() - 6, m_pos.GetX() + 6, m_pos.GetY() + 6);

	switch (m_dir)
	{
	case UP:
	case DOWN:
		fillrectangle(m_rectSphere.GetStartPoint().GetX(),
			m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetStartPoint().GetX() + 4,
			m_rectSphere.GetEndPoint().GetY());
		fillrectangle(m_rectSphere.GetEndPoint().GetX() - 4,
			m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetEndPoint().GetX(),
			m_rectSphere.GetEndPoint().GetY());
		break;
	case LEFT:
	case RIGHT:
		fillrectangle( m_rectSphere.GetStartPoint().GetX(),
			m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetEndPoint().GetX(),
			m_rectSphere.GetStartPoint().GetY() + 4 );
		fillrectangle( m_rectSphere.GetStartPoint().GetX(),
			m_rectSphere.GetEndPoint().GetY() - 4,
			m_rectSphere.GetEndPoint().GetX(),
			m_rectSphere.GetEndPoint().GetY() );
		break;
	default:
		break;
	}
}

void MainTank::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);

	DrawTankBody();

	switch (m_dir)
	{
	case UP:
		line( m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() - 15 );
		break;
	case DOWN:
		line( m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() + 15 );
	case LEFT:
		line( m_pos.GetX(), m_pos.GetY(), m_pos.GetX() - 15, m_pos.GetY() );
		break;
	case RIGHT:
		line( m_pos.GetX(), m_pos.GetY(), m_pos.GetX() + 15, m_pos.GetY() );
		break;
	default:
		break;
	}

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void MainTank::Move()  
{  
    switch (m_dir)  
    {  
    case UP:  
        m_pos.SetY(m_pos.GetY() - m_step);  
        if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())  
            m_pos.SetY(m_pos.GetY() + m_step);  
        break;  
    case DOWN:  
        m_pos.SetY(m_pos.GetY() + m_step);  
        if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())  
            m_pos.SetY(m_pos.GetY() - m_step);  
        break;  
    case LEFT:  
        m_pos.SetX(m_pos.GetX() - m_step);  
        if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())  
            m_pos.SetX(m_pos.GetX() + m_step);  
        break;  
    case RIGHT:  
        m_pos.SetX(m_pos.GetX() + m_step);  
        if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())  
            m_pos.SetX(m_pos.GetX() - m_step);  
        break;  
    default:  
        break;  
    }  
  
    CalculateSphere();  
}

void MainTank::CalculateSphere()
{
	switch (m_dir)
	{
	case UP:
	case DOWN:
		m_rectSphere.Set(m_pos.GetX() - 13, m_pos.GetY() - 10, m_pos.GetX() + 13, m_pos.GetY() + 10);
		break;
	case LEFT:
	case RIGHT:
		m_rectSphere.Set(m_pos.GetX() - 10, m_pos.GetY() - 13, m_pos.GetX() + 10, m_pos.GetY() + 13);
		break;
	default:
		break;
	}
}
//main.cpp --------------------------------------------------------
#pragma warning(disable:4996) //do not print warning code:4996 

#include <cstdio>
#include <cstring>
#include <iostream>
#include <time.h>

#include "pch.h"
#include "conio.h"
#include "graphic.h"
#include "maintank.h"

#define MAX_TANKS 10

//using namespace std;

void main()
{
	srand((unsigned)time(NULL));

	Graphic::Create();

	MainTank mainTank;

	Tank* pTank[MAX_TANKS];

	for (int i = 0; i < MAX_TANKS; i++)
	{
		pTank[i] = new EnemyTank();
	}

	bool loop = true;
	bool skip = false;
	while (loop)
	{
		if (kbhit())
		{
			int key = getch();

			switch (key)
			{
				// Up  
			case 72:
				mainTank.SetDir(Dir::UP);
				break;
				// Down  
			case 80:
				mainTank.SetDir(Dir::DOWN);
				break;
				// Left  
			case 75:
				mainTank.SetDir(Dir::LEFT);
				break;
				// Right  
			case 77:
				mainTank.SetDir(Dir::RIGHT);
				break;
			case 224: // 方向键高8位  
				break;
				// Esc  
			case 27:
				loop = false;
				break;
				// Space  
			case 32:
				break;
				// Enter  
			case 13:
				if (skip)
					skip = false;
				else
					skip = true;
				break;
			default:
				break;
			}
		}

		if (!skip)
		{
			cleardevice();

			Graphic::DrawBattleGround();

			mainTank.Move();
			mainTank.Display();

			for (int i = 0; i < MAX_TANKS; i++)
			{
				pTank[i]->Move();
				pTank[i]->Display();
			}
		}

		Sleep(200);
	}

	for (int i = 0; i < MAX_TANKS; i++)
	{
		delete pTank[i];
	}

	Graphic::Destroy();
}
//point.h ----------------------------------------------------------
#ifndef __POINT_H__
#define __POINT_H__

class Point
{
public:
	Point(int x = 0, int y = 0) : m_x(x), m_y(y) {};
	~Point(){};

	Point & operator = (const Point &p)
	{
		m_x = p.m_x;
		m_y = p.m_y;

		return *this;
	}

	void Set(int x, int y);

	void SetX(int x);
	void SetY(int y);

	int GetX();
	int GetY();

private:
	int m_x;
	int m_y;
};

#endif

//point.cpp -------------------------------------------------------
#include "point.h"

void Point::Set(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Point::SetX(int x)
{
	m_x = x;
}

void Point::SetY(int y)
{
	m_y = y;	
}

int Point::GetX()
{
	return m_x;
}

int Point::GetY()
{
	return m_y;
}

//rect.h ----------------------------------------------------------
#ifndef __RECTANGLE__H_
#define __RECTANGLE__H_

#include "point.h"

class Rect
{
public:
	Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : 
		m_startPoint(x1, y1), m_endPoint(x2, y2) {};
	Rect(const Point p1, const Point p2) : 
		m_startPoint(p1), m_endPoint(p2) {};
	~Rect() {};

	Rect &operator = (const Rect &rect)
	{
		m_startPoint = rect.GetStartPoint();
		m_endPoint = rect.GetEndPoint();

		return *this;
	}

	void Set(const Point pStart, const Point pEnd);
	void Set(int x1, int y1, int x2, int y2);

	void SetStartPoint(const Point p);
	void SetEndPoint(const Point p);

	Point GetStartPoint() const;
	Point GetEndPoint() const;

	int GetWidth();
	int GetHeight();

private:
	void Check();

	Point m_startPoint;
	Point m_endPoint;
};

#endif

//rect.cpp --------------------------------------------------------
#include "rect.h"

void Rect::Set(Point pStart, Point pEnd)
{
	m_startPoint = pStart;
	m_endPoint = pEnd;
}

void Rect::Set(int x1, int y1, int x2, int y2)
{
	m_startPoint.Set(x1, y1);
	m_endPoint.Set(x2, y2);
}

void Rect::SetStartPoint(Point p)
{
	m_startPoint = p;
} 

void Rect::SetEndPoint(Point p)
{
	m_endPoint = p;
}

Point Rect::GetStartPoint() const
{
	return m_startPoint;
}

Point Rect::GetEndPoint() const
{
	return m_endPoint;
}

int Rect::GetWidth()
{
	return m_endPoint.GetX() - m_startPoint.GetX();
}

int Rect::GetHeight()
{
	return m_endPoint.GetY() - m.m_startPoint.GetY();
}

void Rect::Check()
{
	if( m_startPoint.GetX() > m_endPoint.GetX() ||
		m_startPoint.GetY() > m_endPoint.GetY() )
	{
		Point p = m_startPoint;
		m_startPoint = m_endPoint;
		m_endPoint = p;
	}
}

//enemytank.h ----------------------------------------------------

#ifndef __ENEMY_TANK__
#define __ENEMY_TANK__

#include "tank.h"

class EnemyTank : public Tank
{
public:
	EnemyTank()
	{
		RandomTank();
	}

	~EnemyTank(){}

	void Display();
	void Move();

protected:
	void CalculateSphere();
	void RandomTank();
};

#endif

//enemytank.cpp

#include "enemytank.h"

void EnemyTank::RandomTank()
{
	m_pos.SetX( rand() % Graphic::GetBattleGround().GetWidth() );
	m_pos.SetY( rand() % Graphic::GetBattleGround().GEtHeight() );
	m_color = white;
	m_dir = (Dir)(Dir::UP + (rand() % 4));
	m_step = 2;
}

void EnemyTank::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	fillrectangle(m_pos.GetX() - 6, m_pos.GetY() - 6, m_pos.GetX() + 6, m_pos.GetY() + 6);  
  
    fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetStartPoint().GetY(),  
        m_rectSphere.GetStartPoint().GetX() + 4, m_rectSphere.GetStartPoint().GetY() + 4);  
    fillrectangle(m_rectSphere.GetEndPoint().GetX() - 4, m_rectSphere.GetStartPoint().GetY(),  
        m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetStartPoint().GetY() + 4);  
  
    fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetEndPoint().GetY() - 4,  
        m_rectSphere.GetStartPoint().GetX() + 4, m_rectSphere.GetEndPoint().GetY());  
    fillrectangle(m_rectSphere.GetEndPoint().GetX() - 4, m_rectSphere.GetEndPoint().GetY() - 4,  
        m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetEndPoint().GetY());  
  
    switch (m_dir)  
    {  
    case UP:  
        line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() - 15);  
        break;  
    case DOWN:  
        line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() + 15);  
        break;  
    case LEFT:  
        line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() - 15, m_pos.GetY());  
        break;  
    case RIGHT:  
        line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() + 15, m_pos.GetY());  
        break;  
    default:  
        break;  
    }  
  
    setcolor(color_save);  
    setfillcolor(fill_color_save);  
}

void EnemyTank::Move()  
{  
    switch (m_dir)  
    {  
    case UP:  
        m_pos.SetY(m_pos.GetY() - m_step);  
        if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())  
            m_pos.SetY(m_pos.GetY() + m_step);  
        break;  
    case DOWN:  
        m_pos.SetY(m_pos.GetY() + m_step);  
        if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())  
            m_pos.SetY(m_pos.GetY() - m_step);  
        break;  
    case LEFT:  
        m_pos.SetX(m_pos.GetX() - m_step);  
        if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())  
            m_pos.SetX(m_pos.GetX() + m_step);  
        break;  
    case RIGHT:  
        m_pos.SetX(m_pos.GetX() + m_step);  
        if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())  
            m_pos.SetX(m_pos.GetX() - m_step);  
        break;  
    default:  
        break;  
    }  
  
    CalculateSphere();  
}

void EnemyTank::CalculateSphere()
{
	switch (m_dir)  
    {  
    case UP:  
    case DOWN:  
        m_rectSphere.Set(m_pos.GetX() - 13, m_pos.GetY() - 10, m_pos.GetX() + 13, m_pos.GetY() + 10);  
        break;  
    case LEFT:  
    case RIGHT:  
        m_rectSphere.Set(m_pos.GetX() - 10, m_pos.GetY() - 13, m_pos.GetX() + 10, m_pos.GetY() + 13);  
        break;  
    default:  
        break;  
    }  
}

//enemytank.h -----------------------------------------------------

#ifndef __ENEMY_TANK__
#define __ENEMY_TANK__

#include "tank.h"

#define MAX_STEP 10

class EnemyTank : public Tank
{
	EnemyTank()
	{
		RandomTank();
	}

	~EnemyTank(){}

	void Display();
	void Move();

protected:
	void CalculateSphere();
	void RandomTank();
	void RandomDir(int type);

	int m_stepCnt;	
};

#endif

// 

void EnemyTank::RandomTank()
{
	m_pos.SetX(rand() % Graphic::GetBattleGround().GetWidth());
	m_pos.SetY(rand() % Graphic::GetBattleGround().GetHeight());
	m_color = WHITE;
	m_dir = (Dir)(Dir::UP + (rand() % 4));
	m_step = 2;
	m_stepCnt = rand() % MAX_STEP;
}

void EnemyTank::RandomDir(int type)
{
	if(type == 1)
	{
		Dir dir;
		while( (dir = (Dir)(Dir::UP + (rand() % 4))) == m_dir )
		{
			//Do nothing
		}

		m_dir = dir;
	}
	else
	{
		m_dir = (Dir)(Dir::UP + (rand() % 4));
	}
}

void EnemyTank::Move()  
{  
    switch (m_dir)  
    {  
    case UP:  
        m_pos.SetY(m_pos.GetY() - m_step);  
        if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())  
        {  
            m_pos.SetY(m_pos.GetY() + m_step);  
            this->RandomDir(1);  
        }  
        break;  
    case DOWN:  
        m_pos.SetY(m_pos.GetY() + m_step);  
        if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())  
        {  
            m_pos.SetY(m_pos.GetY() - m_step);  
            this->RandomDir(1);  
        }  
        break;  
    case LEFT:  
        m_pos.SetX(m_pos.GetX() - m_step);  
        if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())  
        {  
            m_pos.SetX(m_pos.GetX() + m_step);  
            this->RandomDir(1);  
        }  
        break;  
    case RIGHT:  
        m_pos.SetX(m_pos.GetX() + m_step);  
        if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())  
        {  
            m_pos.SetX(m_pos.GetX() - m_step);  
            this->RandomDir(1);  
        }  
        break;  
    default:  
        break;  
    }  
  
    CalculateSphere();  
  
    m_stepCnt++;  
    if (m_stepCnt >= MAX_STEP)  
    {  
        m_stepCnt = 0;  
        this->RandomDir(0);  
    }  
}  

//object.h
#ifndef __OBJECT_H__
#ifndef __OBJECT_H__

#include "Graphic.h"

enum Dir {UP, DOWN, LEFT, RIGHT};

class Object
{
public:
	virtual void Display() = 0;

	virtual void Move() = 0;

	virtual bool Isappera() = 0;		

	virtual void Boom(list<Object*>& lstBombs) = 0;

protected:
	virtual void CalculateSphere() = 0; //bullet sphere calculate

	Point m_pos;
	Rect m_rectSphere;

	COLORREF m_color;
	Dir m_dir;

	bool m_bDisappear;
	int m_step;
};

#endif

//tank.h

#ifndef __TANK_H__
#define __TANK_H__

#include "object.h"
#include "pch.h"

#include <list>
 
using namespace std;

class Tank : public Object
{
public:
	Tank()
	{
		m_pos.Set(300, 300);

		this->CalculateSphere();

		m_color = YELLOW;
		m_dir = Dir :: UP;
		m_step = 4;

		m_bDisappear = false;
	}

	~Tank() {}

	void Display()
	{
		//Display
	}

	void move()
	{
		//move;
	}

	//shoot
	void shoot(list<Object*>& lstBullets)
	{
		//shoot
	}

	bool IsDisappear()
	{
		return m_bDisappear;
	}

protected:
	void CalculateSphere()
	{
		//Calculate Sphere
	}
};

#endif

//bullet.h

#ifndef __BULLET_H__
#define __BULLET_H__

#include "object.h"
#include "pch.h"

class Bullet : public Object
{
public:
	Bullet();
	Bullet{Point pos, Dir dir, COLORREF color};
	~Bullet();

	void Display();

	void Move();

	bool IsDisappear()
	{
		return m_bDisappear;
	}

protected:
	void Calculate();
};

#endif

//bomb.h
#ifndef __BOMB_H__
#define __BOMB_H__

#include "pch.h"
#include "object.h"

enum BombType
{
	LARGE,
	SMALL
};

class Bomb : public Object
{
public:
	Bomb();
	Bomb(Point pos, BombType type);
	~Bomb() {};
}                  

//bullet.cpp
#include "bullet.h"
#include <pch.h>

Bullet :: Bullet()
{

}

Bullet :: Bullet(Point pos, Dir, dir, COLORREF color)
{
	m_pos = pos;
	m_dir = dir;
	m_color = color;

	m_step = 20;

	m_bDisappear = false;

	CalculateSphere();
}

Bullet :: ~Bullet()
{

}

//draw graphic
void Bullet :: Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor;

	setfillcolor(m_color);
	setcolor(m_color);

	fillcircle(m_pos.GetX() - 1, m_pos.GetY() - 1, 4);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

//move
void Bulle :: Move()
{
	switch(m_dir)
	{
	case UP:  
        m_pos.SetY(m_pos.GetY() - m_step);  
        CalculateSphere();  
        if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())  
        {  
            m_bDisappear = true;  
        }  
        break;  
    case DOWN:  
        m_pos.SetY(m_pos.GetY() + m_step);  
        CalculateSphere();  
        if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())  
        {  
            m_bDisappear = true;  
        }  
        break;  
    case LEFT:  
        m_pos.SetX(m_pos.GetX() - m_step);  
        CalculateSphere();  
        if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())  
        {  
            m_bDisappear = true;  
        }  
        break;  
    case RIGHT:  
        m_pos.SetX(m_pos.GetX() + m_step);  
        CalculateSphere();  
        if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())  
        {  
            m_bDisappear = true;  
        }  
        break;  
    default:  
        break;  
	}
}

void Bullet :: CalculateSphere()
{
	m_rectSphere.Set(m_pos.GetX() - 2, m_pos.GetY() - 2, m_pos.GetX() + 2, m_pos.GetY() + 2);
}

//maintank.h
class MainTank : public Tank
{
public:
	MainTank() : Tank()
	{
		m_pos.Set(300, 300);

		this->CalculateSphere();

		m_color = YELLOW;
		m_dir = Dir :: UP;
		m_step = 4;
	}

	~ MainTank() {}

	void SetDir(Dir dir);
	void Display();
	void Move();
	void Shoot(list<Object*> &lstBullets);

protected:
	void CalculateSphere();

	void DrawTankBody();
}

void MainTank :: Shoot(list<Object*> &lstBullets)
{
	Bullet *pBullet = new Bullet(m_pos, m_dir, m_color);

	lstBullets.push_back(pBullet);
}

//main.cpp
#pragma warning(disable:4996)  
  
#include <iostream>  
#include <conio.h>  
#include <time.h>  
  
#include <list>  
  
#include "Graphic.h"  
#include "MainTank.h"  
#include "EnemyTank.h"  
  
using namespace std;  
  
#define MAX_TANKS 10  
  
void main()  
{  
    srand((unsigned)time(NULL));  
  
    Graphic::Create();  
  
    MainTank mainTank;  
  
    list<Tank*> lstTanks;  
    lstTanks.clear();  
  
    for (int i = 0; i < MAX_TANKS; i++)  
    {  
        lstTanks.push_back(new EnemyTank());  
    }  
  
    list<Object*> lstBullets;  
    lstBullets.clear();  
  
    bool loop = true;  
    bool skip = false;  
    while (loop)  
    {  
        if (kbhit())  
        {  
            int key = getch();  
  
            switch (key)  
            {  
            // Up  
            case 72:  
                mainTank.SetDir(Dir::UP);  
                break;  
            // Down  
            case 80:   
                mainTank.SetDir(Dir::DOWN);  
                break;  
            // Left  
            case 75:   
                mainTank.SetDir(Dir::LEFT);  
                break;  
            // Right  
            case 77:   
                mainTank.SetDir(Dir::RIGHT);  
                break;  
            case 224: // 方向键高8位  
                break;  
            // Esc  
            case 27:  
                loop = false;  
                break;  
            // Space  
            case 32:  
                  mainTank.Shoot(lstBullets);  
                break;  
            // Enter  
            case 13:  
                if (skip)  
                    skip = false;  
                else  
                    skip = true;  
                break;  
            default:   
                break;  
            }  
        }  
  
        if (!skip)  
        {  
            cleardevice();  
  
            Graphic::DrawBattleGround();  
  
            mainTank.Move();  
            mainTank.Display();  
  
            for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); it++)  
            {  
                (*it)->Move();  
                (*it)->Display();  
            }  
  
            for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end();)  
            {  
                (*it)->Move();  
  
                if ((*it)->IsDisappear())  
                {  
  
                    delete *it;  
                    it = lstBullets.erase(it);  
                    continue;  
                }  
  
                (*it)->Display();  
                it++;  
            }  
        }  
  
        Sleep(200);  
    }  
  
  
    // Destroy  
    for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); it++)  
    {  
        delete *it;  
    }  
    lstTanks.clear();  
  
    for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end(); it++)  
    {  
        delete *it;  
    }  
    lstBullets.clear();  
  
    Graphic::Destroy();  
}  