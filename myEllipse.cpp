#include "stdafx.h"
#include "myEllipse.h"


void myEllipse::Draw(CDC * pDC)
{
	pDC->Ellipse(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
	
	baseObject::Draw(pDC);// 부모의 draw 값을 호충해줘 반복 작업하는것을 최고화 해준다.

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
