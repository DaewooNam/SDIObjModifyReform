#pragma once


class myRect : public baseObject
{
public:
	void Draw(CDC* pDC); //자식이 있을시 virtual 값을 사용하게 된다.
	myRect(CPoint start, CPoint end, OBJTYPE type);
	
	myRect();
	virtual ~myRect();
};

