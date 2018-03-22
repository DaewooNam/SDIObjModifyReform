#include "stdafx.h"
#include "myLine.h"


void myLine::Draw(CDC * pDC)
{
	pDC->MoveTo(m_ptStart);
	pDC->LineTo(m_ptEnd);


	baseObject::Draw(pDC);
}

myLine::myLine(CPoint start, CPoint end, OBJTYPE type)
	: baseObject(start,end,type)
{


}

myLine::myLine()
{
}


myLine::~myLine()
{
}
