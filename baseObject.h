#pragma once
class baseObject //�������� ���� �θ��� Ŭ������ �־���
{

public:
	CPoint		m_ptStart;
	CPoint		m_ptEnd;
	OBJTYPE		m_enType;
	bool		m_bSelect;

	baseObject* IsCollision(CPoint mousePt);
	void MoveObject(CPoint intervalPt);
	void SelectRect(CDC* pDC);
	
	virtual void Draw(CDC* pDC); //instanceȭ �Ѵ�. �ڽ� �����Ǹ� �ϱ� ���� �ڽĿ��� �����Ǹ� ���� �ʾ��� ��� Error �� ����

	
	baseObject(CPoint start,CPoint end, OBJTYPE type);
	baseObject();
	virtual ~baseObject(); // ?????????

};

