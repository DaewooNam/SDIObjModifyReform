
// SDIObjModifyView.h: CSDIObjModifyView 클래스의 인터페이스
//

#pragma once


class CSDIObjModifyView : public CView
{
protected: // serialization에서만 만들어집니다.
	CSDIObjModifyView();
	DECLARE_DYNCREATE(CSDIObjModifyView)

// 특성입니다.
public:
	CSDIObjModifyDoc* GetDocument() const;

	list<baseObject*> m_listObjects;
	baseObject*		  m_pSelBaseObject;


// 작업입니다.
public:
	
	list<MyObject*>		m_listObjs;		  //오브젝트 정보파일
	OBJTYPE				m_enObjType;	  //그릴 타입
	CPoint				m_DrawPt[PT_MAX]; //드레그 시 보여줄 정보(정점) 
	TOOLTYPE			m_enToolType;     //추가모드, 수정모드

	//COMBO CONTROL(주소값을 받는게 아니라 직접 그리게 된다.)
	CComboBox			m_ComboDrawType;  
	CStatic				m_StaticDrawType;

	CComboBox			m_ComboToolType;
	CStatic				m_StaticToolType;

	afx_msg void OnCbnSelchangeDrawType(); //함수 생성
	afx_msg void OnCbnSelchangeToolType();


	//충돌함수 ,bool 값이 아니라 값의 주소를 받느게 편함
	MyObject* IsCollsion(CPoint pt);
	MyObject* m_SelectObject;

	//이동
	CPoint				m_ptOldMouse;


// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CSDIObjModifyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // SDIObjModifyView.cpp의 디버그 버전
inline CSDIObjModifyDoc* CSDIObjModifyView::GetDocument() const
   { return reinterpret_cast<CSDIObjModifyDoc*>(m_pDocument); }
#endif

