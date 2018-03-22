#pragma once
class baseObject //선언하지 않은 부모의 클래스를 넣어줌
{

public:
	CPoint		m_ptStart;
	CPoint		m_ptEnd;
	OBJTYPE		m_enType;
	bool		m_bSelect;

	baseObject* IsCollision(CPoint mousePt);
	void MoveObject(CPoint intervalPt);
	void SelectRect(CDC* pDC);
	
	virtual void Draw(CDC* pDC); //instance화 한다. 자식 재정의를 하기 위해 자식에서 재정의를 하지 않았을 경우 Error 값 나옴

	
	baseObject(CPoint start,CPoint end, OBJTYPE type);
	baseObject();
	virtual ~baseObject(); // ?????????

};

