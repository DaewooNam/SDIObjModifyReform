
// SDIObjModifyView.cpp: CSDIObjModifyView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SDIObjModify.h"
#endif

#include "SDIObjModifyDoc.h"
#include "SDIObjModifyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIObjModifyView

IMPLEMENT_DYNCREATE(CSDIObjModifyView, CView)

BEGIN_MESSAGE_MAP(CSDIObjModifyView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSDIObjModifyView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_DESTROY()
	ON_CBN_SELCHANGE(IDC_COMBO_OBJTYPE, &CSDIObjModifyView::OnCbnSelchangeDrawType)
	ON_CBN_SELCHANGE(IDC_COMBO_TOOLTYPE, &CSDIObjModifyView::OnCbnSelchangeToolType)
END_MESSAGE_MAP()

// CSDIObjModifyView 생성/소멸

CSDIObjModifyView::CSDIObjModifyView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_enObjType = OT_RECT; // 초기 그리기 = 사각형
	m_enToolType = TT_ADD; // 툴모드 초기화 == 추가모드
	
	m_DrawPt[PT_START].x = m_DrawPt[PT_START].y = m_DrawPt[PT_END].x = m_DrawPt[PT_END].y = 0;
	

	m_listObjs.clear(); // list 초기화 방법
	m_SelectObject = NULL; //포인터 초기화는 항상 해줘야함
	m_pSelBaseObject = NULL;


}

CSDIObjModifyView::~CSDIObjModifyView()
{
}

BOOL CSDIObjModifyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.



	return CView::PreCreateWindow(cs);
}

// CSDIObjModifyView 그리기

void CSDIObjModifyView::OnCbnSelchangeDrawType()
{

	//TRACE(" CSDIObjModifyView::OnCbnSelchangeDrawType()\n");

	int idx = m_ComboDrawType.GetCurSel();

	m_enObjType = (OBJTYPE)idx;


}

void CSDIObjModifyView::OnCbnSelchangeToolType()
{
	int idx = m_ComboToolType.GetCurSel();

	m_enToolType = (TOOLTYPE)idx;

}

MyObject * CSDIObjModifyView::IsCollsion(CPoint pt)
{
	MyObject* pObj = NULL; // null 아닐경우만 움직이게 된다.
	
	for each(auto p in m_listObjs)
	{
		CRect rc = { p->m_Pos[PT_START].x,p->m_Pos[PT_START].y,p->m_Pos[PT_END].x,p->m_Pos[PT_END].y };

		if (PtInRect(rc, pt)) // point 와 rect 값이 서로 충돌 하는지 확인
		{
			pObj = p;
			break;

		}

		//선택된 대각선 사각형 충돌 확인





	}

	return pObj;
}

void CSDIObjModifyView::OnDraw(CDC* pDC)
{
	CSDIObjModifyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	/*
	//list (순서중요)
	for each(auto pObj in m_listObjs) // 지우느건 불가능함  그리기만 가능
	{
		switch (pObj->enType)
		{
		case OT_RECT:
			pDC->Rectangle(pObj->m_Pos[PT_START].x, pObj->m_Pos[PT_START].y, pObj->m_Pos[PT_END].x, pObj->m_Pos[PT_END].y);
			break;
		case OT_ELL:
			pDC->Ellipse(pObj->m_Pos[PT_START].x, pObj->m_Pos[PT_START].y, pObj->m_Pos[PT_END].x, pObj->m_Pos[PT_END].y);
			break;
		case OT_LINE:
			pDC->MoveTo(pObj->m_Pos[PT_START]);
			pDC->LineTo(pObj->m_Pos[PT_END]);
			break;


		}

	}
	*/

	// 오브젝트들
	for each(auto p in m_listObjects)
	{
		p->Draw(pDC);

	}




	// m_drawpt
	
	if (m_enToolType == TT_ADD)
	{
		switch (m_enObjType)
		{
		case OT_RECT:
			pDC->Rectangle(m_DrawPt[PT_START].x, m_DrawPt[PT_START].y, m_DrawPt[PT_END].x, m_DrawPt[PT_END].y);
			break;
		case OT_ELL:
			pDC->Ellipse(m_DrawPt[PT_START].x, m_DrawPt[PT_START].y, m_DrawPt[PT_END].x, m_DrawPt[PT_END].y);
			break;
		case OT_LINE:
			pDC->MoveTo(m_DrawPt[PT_START]);
			pDC->LineTo(m_DrawPt[PT_END]);
			break;

		}

	}


	/*

	//선택된 오브젝트
	if (m_SelectObject != NULL)
	{
		CPoint ptStart = m_SelectObject->m_Pos[PT_START];
		CPoint ptEnd = m_SelectObject->m_Pos[PT_END];

		pDC->Rectangle(ptStart.x - 5, ptStart.y - 5, ptStart.x + 5, ptStart.y + 5);
		pDC->Rectangle(ptEnd.x - 5, ptStart.y - 5, ptEnd.x + 5, ptStart.y + 5);
		pDC->Rectangle(ptStart.x - 5, ptEnd.y - 5, ptStart.x + 5, ptEnd.y + 5);
		pDC->Rectangle(ptEnd.x - 5, ptEnd.y - 5, ptEnd.x + 5, ptEnd.y + 5);
	}
	*/

}


// CSDIObjModifyView 인쇄


void CSDIObjModifyView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSDIObjModifyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSDIObjModifyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSDIObjModifyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CSDIObjModifyView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSDIObjModifyView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSDIObjModifyView 진단

#ifdef _DEBUG
void CSDIObjModifyView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIObjModifyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIObjModifyDoc* CSDIObjModifyView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIObjModifyDoc)));
	return (CSDIObjModifyDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIObjModifyView 메시지 처리기


void CSDIObjModifyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(m_enToolType == TT_ADD)  //추가모드시
		m_DrawPt[PT_START] = point;
	else//편집 모드시
	{
		
		for each(auto p in m_listObjects)
			p->m_bSelect = false;


		for each(auto p in m_listObjects)
		{
			m_pSelBaseObject = p->IsCollision(point);
			if (m_pSelBaseObject)
				break;
		}

		m_SelectObject = IsCollsion(point); //충돌이 되고 안되고의 주소값을 받아주게 됨 ex) 충돌 안되시 NULL 값 이 입력으로 들어감 

		Invalidate(); 


		if (m_pSelBaseObject) //오브젝트가 존재한다면
		{
			m_ptOldMouse = point;

		}

	}

	
	CView::OnLButtonDown(nFlags, point);
}


void CSDIObjModifyView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	if (m_enToolType == TT_ADD)  //추가모드시
	{
		m_DrawPt[PT_END] = point;
		
		switch (m_enObjType)
		{
		case OT_RECT:
		{
			myRect * pObj = new myRect(m_DrawPt[PT_START], m_DrawPt[PT_END], m_enObjType);
			m_listObjects.push_back(pObj);
			break;

		}
		case OT_ELL:
		{
			myEllipse * pObj = new myEllipse(m_DrawPt[PT_START], m_DrawPt[PT_END], m_enObjType);
			m_listObjects.push_back(pObj);
			break;

		}

		case OT_LINE:
		{
			myLine * pObj = new myLine(m_DrawPt[PT_START], m_DrawPt[PT_END], m_enObjType);
			m_listObjects.push_back(pObj);
			break;

		}
		}
		
		
		/*
		MyObject* pObj = new MyObject;
		pObj->enType = m_enObjType; // 타입 (사각형, 타원, 라인)
		pObj->m_Pos[PT_START] = m_DrawPt[PT_START];
		pObj->m_Pos[PT_END] = m_DrawPt[PT_END];

		m_listObjs.push_back(pObj);
		*/
	}
	//편집 모드시
	else
	{
		/*
		if (m_SelectObject)
		{
			CPoint ptInver = point - m_ptOldMouse;
			
			
			m_SelectObject->m_Pos[PT_START] = m_SelectObject->m_Pos[PT_START] + ptInver;
			m_SelectObject->m_Pos[PT_END] = m_SelectObject->m_Pos[PT_END] + ptInver;
			
			m_ptOldMouse = point;


			Invalidate();

		}
		*/

	}




	Invalidate(); //ondraw 값을 실행 시켜줌 다시한번

	CView::OnLButtonUp(nFlags, point);
}


void CSDIObjModifyView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (nFlags & VK_LBUTTON)
	{

		if (m_enToolType == TT_ADD) //추가모드
		{
			m_DrawPt[PT_END] = point;
		}
		else //편집모드
		{
			if (m_pSelBaseObject)

			{
				CPoint ptInver = point - m_ptOldMouse;

				m_pSelBaseObject->MoveObject(ptInver);

				m_ptOldMouse = point;
				Invalidate();


			}
		}
	
	}


	CView::OnMouseMove(nFlags, point);
}


void CSDIObjModifyView::OnDestroy()
{
	CView::OnDestroy();


	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	for each(auto pObj in m_listObjs)
	{
		delete pObj;

	}

	m_listObjs.clear();
}


void CSDIObjModifyView::OnInitialUpdate() //view 가 만들어 지고 나서 초기화 되는 함수
{
	CView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
	// 스타틱
	CRect rc2 = { 10,12,90,30 };
	m_StaticDrawType.Create("DrawType", 0,rc2,this,IDC_STATIC_OBJTYPE);
	m_StaticDrawType.ShowWindow(SW_SHOW);



	// 콤보박스
	CRect rc = {100,10,230,200};

	m_ComboDrawType.Create(CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,rc,this,IDC_COMBO_OBJTYPE);

	m_ComboDrawType.ShowWindow(SW_SHOW);

	m_ComboDrawType.AddString("Rectangle");
	m_ComboDrawType.AddString("Ellipse");
	m_ComboDrawType.AddString("Line");

	m_ComboDrawType.SetCurSel(OT_RECT);



	// tool type
	// 스타틱
	CRect rc3 = { 10,42,90,70 };
	m_StaticToolType.Create("ToolType", 0, rc3, this, IDC_STATIC_TOOLTYPE);
	m_StaticToolType.ShowWindow(SW_SHOW);




	CRect rc4 = { 100,40,230,240 };
	m_ComboToolType.Create(CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP, rc4, this, IDC_COMBO_TOOLTYPE);

	m_ComboToolType.ShowWindow(SW_SHOW);
	m_ComboToolType.AddString("ADD");
	m_ComboToolType.AddString("MODIFYT");
	
	m_ComboToolType.SetCurSel(TT_ADD);

}
