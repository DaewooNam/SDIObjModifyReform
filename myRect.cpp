#include "stdafx.h"
#include "myRect.h"

myRect::myRect(CPoint start, CPoint end, OBJTYPE type)
	:baseObject(start,end,type) // 부모와 대입하는 값이 같이 때문에 같이 사용하지 않음 //부모의 있는 기능을 사용할때.
								// 부모한테 있는 값을 자식이 다시한번 사용할때
								// 부모 생성사 호출 하면 대입하는 값이 생김

{								


}



void myRect::Draw(CDC* pDC)
{

	pDC->Rectangle(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);

	baseObject::Draw(pDC);


}


myRect::myRect()
{
}



myRect::~myRect()
{
}
