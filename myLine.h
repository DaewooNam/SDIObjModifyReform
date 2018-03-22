#pragma once
class myLine : public baseObject
{
public:

	void Draw(CDC* pDC);

	myLine(CPoint start, CPoint end, OBJTYPE type);


	myLine();
	virtual ~myLine();
};

