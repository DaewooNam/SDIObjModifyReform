#include "stdafx.h"
#include "myRect.h"

myRect::myRect(CPoint start, CPoint end, OBJTYPE type)
	:baseObject(start,end,type) // �θ�� �����ϴ� ���� ���� ������ ���� ������� ���� //�θ��� �ִ� ����� ����Ҷ�.
								// �θ����� �ִ� ���� �ڽ��� �ٽ��ѹ� ����Ҷ�
								// �θ� ������ ȣ�� �ϸ� �����ϴ� ���� ����

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
