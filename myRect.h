#pragma once


class myRect : public baseObject
{
public:
	void Draw(CDC* pDC); //�ڽ��� ������ virtual ���� ����ϰ� �ȴ�.
	myRect(CPoint start, CPoint end, OBJTYPE type);
	
	myRect();
	virtual ~myRect();
};

