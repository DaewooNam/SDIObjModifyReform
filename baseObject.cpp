#include "stdafx.h"
#include "baseObject.h"


baseObject* baseObject::IsCollision(CPoint mousePt)
{
	CRect rc = { m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y };
	
	if (PtInRect(&rc,mousePt)) // �浹 true, �ƴϸ� false
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

baseObject::baseObject(CPoint start,CPoint end,OBJTYPE type) //���� �� �Լ��� ����� �� ���� �ʱ�ȭ ����
	//:m_ptStart(start),m_ptEnd(end), m_enType(type),m_bSelect(false) // ����� �Բ� �ʱ�ȭ �Ҷ� �ʿ��ϴ� (const �Ű����� ������ ����)
{
	m_ptStart = start;
	m_ptEnd   = end;
	m_enType  = type;
	m_bSelect = false;

}

baseObject::baseObject() //���� �� �Լ��� ����� �� ���� �ʱ�ȭ ����
{

}


baseObject::~baseObject()
{
}
