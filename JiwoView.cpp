
// JiwoView.cpp: CJiwoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Jiwo.h"
#endif

#include "JiwoDoc.h"
#include "JiwoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJiwoView

IMPLEMENT_DYNCREATE(CJiwoView, CFormView)

BEGIN_MESSAGE_MAP(CJiwoView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SELECT_COLOR, &CJiwoView::OnSelectColor)
	ON_COMMAND(ID_SIZE_4, &CJiwoView::OnSize4)
	ON_COMMAND(ID_SIZE_8, &CJiwoView::OnSize8)
	ON_COMMAND(ID_SIZE_16, &CJiwoView::OnSize16)
	ON_COMMAND(ID_SIZE_32, &CJiwoView::OnSize32)
END_MESSAGE_MAP()

// CJiwoView 생성/소멸

CJiwoView::CJiwoView() noexcept
	: CFormView(IDD_JIWO_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CJiwoView::~CJiwoView()
{
}

void CJiwoView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CJiwoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CJiwoView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CJiwoView 인쇄

BOOL CJiwoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CJiwoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CJiwoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CJiwoView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CJiwoView 진단

#ifdef _DEBUG
void CJiwoView::AssertValid() const
{
	CFormView::AssertValid();
}

void CJiwoView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CJiwoDoc* CJiwoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJiwoDoc)));
	return (CJiwoDoc*)m_pDocument;
}
#endif //_DEBUG


// CJiwoView 메시지 처리기
int n;
COLORREF Col;
CPoint opnt;
void CJiwoView::OnMouseMove(UINT nFlags, CPoint point)
{
	
	CPen pen(PS_SOLID, n, Col);
	CClientDC dc(this);
	dc.SelectObject(&pen);
	if (nFlags & MK_LBUTTON) {
		dc.MoveTo(opnt);
		dc.LineTo(point);
	}
	opnt = point;

	CFormView::OnMouseMove(nFlags, point);
}


void CJiwoView::OnSelectColor()
{
	CColorDialog dlg; //클래스의 객체 dlg를 생성합니다. 이 객체는 색상 대화 상자를 나타냅니다
	if (dlg.DoModal() == IDOK) {  //함수를 호출하여 색상 대화 상자를 엽니다. 사용자가 대화 상자에서 "확인" 버튼을 클릭하면, IDOK가 반환되어 조건문이 참이 됩니다.
		Col = dlg.GetColor();
	}
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CJiwoView::OnSize4()
{
	n = 4;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CJiwoView::OnSize8()
{
	n = 8;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CJiwoView::OnSize16()
{
	n = 16;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CJiwoView::OnSize32()
{
	n = 32;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
