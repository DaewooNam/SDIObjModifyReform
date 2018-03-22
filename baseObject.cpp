#include "stdafx.h"
#include "baseObject.h"


baseObject* baseObject::IsCollision(CPoint mousePt)
{
	CRect rc = { m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y };
	
	if (PtInRect(&rc,mousePt)) // 충돌 true, 아니면 false
	{
		m_bSelect = true;

		return this;
	}
	else
	{
		m_bSelect = false;

	}

	return NULL;

}

void baseObject::MoveObject(CPoint intervalPt)
{
	m_ptStart += intervalPt;
	m_ptEnd += intervalPt;
}

void baseObject::SelectRect(CDC* pDC)
{
	if (m_bSelect)
	{

		pDC->Rectangle(m_ptStart.x-5,m_ptStart.y-5,m_ptStart.x+5, m_ptStart.y + 5);
		pDC->Rectangle(m_ptEnd.x - 5, m_ptStart.y - 5, m_ptEnd.x + 5, m_ptStart.y + 5);
		pDC->Rectangle(m_ptStart.x - 5, m_ptEnd.y - 5, m_ptStart.x + 5, m_ptEnd.y + 5);
		pDC->Rectangle(m_ptEnd.x - 5, m_ptEnd.y - 5, m_ptEnd.x + 5, m_ptEnd.y + 5);

	}

}

void baseObject::Draw(CDC * pDC)
{
	if (m_bSelect)
		SelectRect(pDC);
}

baseObject::baseObject(CPoint start,CPoint end,OBJTYPE type) //변수 및 함수를 사용할 수 있음 초기화 구간
	//:m_ptStart(start),m_ptEnd(end), m_enType(type),m_bSelect(false) // 선언과 함께 초기화 할때 필요하다 (const 매개변수 때문에 만듦)
{
	m_ptStart = start;
	m_ptEnd   = end;
	m_enType  = type;
	m_bSelect = false;

}

baseObject::baseObject() //변수 및 함수를 사용할 수 있음 초기화 구간
{

}


baseObject::~baseObject()
{
}
