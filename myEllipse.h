#pragma once
class myEllipse:public baseObject
{
public:
	void Draw(CDC* pDC);

	myEllipse(CPoint start, CPoint end, OBJTYPE type);



	myEllipse();
	virtual ~myEllipse();
};

