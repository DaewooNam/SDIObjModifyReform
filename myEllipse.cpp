#include "stdafx.h"
#include "myEllipse.h"


void myEllipse::Draw(CDC * pDC)
{
	pDC->Ellipse(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
	
	baseObject::Draw(pDC);// �θ��� draw ���� ȣ������ �ݺ� �۾��ϴ°��� �ְ�ȭ ���ش�.

}

myEllipse::myEllipse(CPoint start, CPoint end, OBJTYPE type)
	:baseObject(start,end,type)
{
}

myEllipse::myEllipse()
{
}


myEllipse::~myEllipse()
{
}
