// CDlgPosition.cpp: 구현 파일
//

#include "../../pch.h"
#include "../../YEYTotalProject.h"
#include "CDlgPosition.h"
#include "afxdialogex.h"


// CDlgPosition 대화 상자

IMPLEMENT_DYNAMIC(CDlgPosition, CDialog)

CDlgPosition::CDlgPosition(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_POSITION, pParent)
{
	m_strMoveData = "";
	m_strDlgPosition = "";
	m_nMainDlgSizeX = 0;
	m_nMainDlgSizeY = 0;
	m_RadioIndex = -1;

	m_nMainDlgSizeX = 0;
	m_nClientDlgSizeX = 0;
	m_nClientDlgSizeY = 0;

	m_nCtrlIndex = 0;

	m_pDlgPositionChild = new CDlgPositionChild;
}

CDlgPosition::~CDlgPosition()
{
	if (m_pDlgPositionChild != NULL)		//이놈은 소멸자에서 진행한다.
	{
		delete m_pDlgPositionChild;
		m_pDlgPositionChild = NULL;
	}
	
}

void CDlgPosition::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_POSITION_PRINT, m_strMoveData);
	DDX_Text(pDX, IDC_DLG_SIZE_PRINT, m_strDlgSize);
	DDX_Text(pDX, IDC_DLG_POSITION_PRINT, m_strDlgPosition);
	DDX_Text(pDX, IDC_EDIT_DLGSIZE_X, m_nMainDlgSizeX);
	DDX_Text(pDX, IDC_EDIT_DLGSIZE_Y, m_nMainDlgSizeY);
	DDX_Text(pDX, IDC_EDIT_DLGSIZE_CLIENT_X, m_nClientDlgSizeX);
	DDX_Text(pDX, IDC_EDIT_DLGSIZE_CLIENT_Y, m_nClientDlgSizeY);
}


BEGIN_MESSAGE_MAP(CDlgPosition, CDialog)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BTN_CHANGE_DLG_SIZE, &CDlgPosition::OnBnClickedBtnChangeDlgSize)
	ON_BN_CLICKED(IDC_BTN_CHANGE_DLG_CLIENT_SIZE, &CDlgPosition::OnBnClickedBtnChangeDlgClientSize)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BTN_SAVE_SPECIFIC_POS, &CDlgPosition::OnBnClickedBtnSaveSpecificPos)
	ON_BN_CLICKED(IDC_BTN_SAVE_SPECIFIC_POS_CLIENT, &CDlgPosition::OnBnClickedBtnSaveSpecificPosClient)
	ON_BN_CLICKED(IDC_BTN_CHANGE_BACKGROUND_COLOR, &CDlgPosition::OnBnClickedBtnChangeBackgroundColor)
	ON_BN_CLICKED(IDC_BTN_DOMODAL_OPEN, &CDlgPosition::OnBnClickedBtnDomodalOpen)
	ON_BN_CLICKED(IDC_BTN_NEW_CREATE_OPEN, &CDlgPosition::OnBnClickedBtnNewCreateOpen)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_CHANGE_TEXT_COLOR, &CDlgPosition::OnBnClickedBtnChangeTextColor)
END_MESSAGE_MAP()


// CDlgPosition 메시지 처리기

//MainFrame에서 Mouse And Dialog 위치 값 받아서 멤버변수에 저장함 ****************************************************************Start
void CDlgPosition::SetWindowPosAndRect(CRect rt)
{
	m_rtWindow = rt;

	//Invalidate() 함수의 인자로 TRUE는 기본값이고,
	//요녀석은 화면의 배경색을 포함해서 재출력을 하라는것이고,
	//FALSE는 배경색은 그냥 내비두고 그외부분을 재출력하라는 것이다.
	//인자에 따라 이렇게 다르더군
	//Invalidate(false)->WM_PAINT
	//Invalidate(true)->WM_ERASEBKGND->WM_PAINT
	Invalidate(FALSE);
}

CRect CDlgPosition::GetWindowPosAndRect()
{
	return m_rtWindow;
}

void CDlgPosition::SetMousePos(CPoint pt)
{
	m_ptMouse = pt;
	Invalidate(FALSE);
}

CPoint CDlgPosition::GetMousePos()
{
	return m_ptMouse;
}
//MainFrame에서 Mouse And Dialog 위치 값 받아서 멤버변수에 저장함 ****************************************************************End

//WM_PAINT에서 호출하여 Dialog Event 처리를 통한 Dialog 위치 변경 및 사이즈 변경 실시간 데이터 출력 ****************************************************************Start
void CDlgPosition::DialogPosPrint()
{
	CString strValue = "";
	
	//CRect rt;
	//GetWindowRect(&rt);	//이거를쓰면 윈도우 기준 다이얼로그 위치 알수있음

	strValue.Format("Width : %0d , Height : %0d", GetWindowPosAndRect().Width(), GetWindowPosAndRect().Height());
	SetDlgItemText(IDC_DLG_SIZE_PRINT, strValue);

	strValue.Format("X : %0d, Y : %0d", GetWindowPosAndRect().TopLeft().x, GetWindowPosAndRect().TopLeft().y);
	SetDlgItemText(IDC_DLG_POSITION_PRINT, strValue);
	
}
//WM_PAINT에서 호출하여 Dialog Event 처리를 통한 Dialog 위치 변경 및 사이즈 변경 실시간 데이터 출력 ****************************************************************End


//MainFrame으로 부터 받아온 데이터를 출력하는 함수****************************************************************Start
void CDlgPosition::MousePosPrint()
{
	CClientDC dc(this);
	CString strPosition = "";

	//DC로 그린모슴
	strPosition.Format("X : %04d , Y : %04d", m_ptMouse.x, m_ptMouse.y);
	dc.TextOut(171, 33, strPosition);

	//Static에 출력한 모습
	m_strMoveData.Format("X : %04d , Y : %04d", m_ptMouse.x, m_ptMouse.y);
	SetDlgItemText(IDC_STATIC_POSITION_PRINT, m_strMoveData);
}
//MainFrame으로 부터 받아온 데이터를 출력하는 함수****************************************************************End

void CDlgPosition::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	MousePosPrint();
	DialogPosPrint();
}

void CDlgPosition::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialog::OnMouseMove(nFlags, point);
	m_ptMouse = point;

	MousePosPrint();
	DialogPosPrint();
}

//MainFrame의 데이터를 받아서 다이얼로그의 위치를 변환하는 작업**********************************************************Start
void CDlgPosition::OnBnClickedBtnChangeDlgSize()
{
	UpdateData(TRUE);
	CString strValue = "";
	CRect rect;
	
	strValue.Format("Width : %d , Height : %d( W & H must be higher than 500 )", GetWindowPosAndRect().Width(), GetWindowPosAndRect().Height());
	//현재 설정된 값을 알려주기 위함
	AfxMessageBox(strValue);

	if (m_nMainDlgSizeX < 500 || m_nMainDlgSizeY < 500)
		return;
	   
	//MainFrame의 다이얼로그에 접근하여 처리하는 방법. 
	AfxGetMainWnd()->GetWindowRect(&rect);
	AfxGetMainWnd()->MoveWindow(rect.left, rect.top, m_nMainDlgSizeX, m_nMainDlgSizeY);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
//MainFrame의 데이터를 받아서 다이얼로그의 위치를 변환하는 작업**********************************************************End

//Client Rect을 사용하여 위치를 가져옴**********************************************************End
void CDlgPosition::OnBnClickedBtnChangeDlgClientSize()
{
	UpdateData(TRUE);

	CRect r;
	GetClientRect(&r);  // 현재 윈도우의 '클라이언트 영역 좌표'를 구함.
	if (m_nClientDlgSizeX < 300 || m_nClientDlgSizeY < 300)
	{
		AfxMessageBox("300보다 큰수 넣으세요.");
		return;
	}
	MoveWindow(280, 10, m_nClientDlgSizeX, m_nClientDlgSizeY);

}
//Client Rect을 사용하여 위치를 가져옴**********************************************************End


//MainFrame Left Top 위치를 기준으로 Print Scrreen 하는방법**********************************************************Start
void CDlgPosition::OnBnClickedBtnSaveSpecificPos()
{
	CWnd* pWndDesktop = GetDesktopWindow();
	CWindowDC ScrDC(pWndDesktop);

	CClientDC dc(this);

	CRect WindowRT, Rect;

	AfxGetMainWnd()->GetWindowRect(&WindowRT);	//Window 화면 기준 Main dialog위치의 시작지점 Left Top.
	//GetWindowRect(&WindowRT);	//Window 화면 기준 현재 해당하는 다이얼로그 (자식다이얼로그면 자식위치시작지점을 나타냄 Left Top이)
	//GetClientRect(&Rect);	//자식 다이얼로그면 자식의 좌측상당 그래서 무조건 left top은 0,0이된다

	int sx = WindowRT.left;
	int sy = WindowRT.top;

	int cx = GetDlgItemInt(IDC_EDIT_WIDTH_MAIN);
	int cy = GetDlgItemInt(IDC_EDIT_HEIGHT_MAIN);
	
	cx = cx + (cx % 4);
	cy = cy + (cy % 4);
	
	if (sx < 10 || sy < 10)
	{
		AfxMessageBox("Size가 10보다 작으면 어카니?");
		return;
	}

	CImage pImage;
	pImage.Create(cx, cy, ScrDC.GetDeviceCaps(BITSPIXEL));
	CDC* pDC = CDC::FromHandle(pImage.GetDC());

	pDC->BitBlt(0, 0, cx, cy, &ScrDC, sx, sy, SRCCOPY);
	pImage.ReleaseDC();

	pImage.Save("./TestFolder/specific.jpg", Gdiplus::ImageFormatJPEG);

	::ShellExecute(NULL, "open", "D:\\YEY\\12345.jpg", NULL, NULL, SW_SHOW);
}
//MainFrame Left Top 위치를 기준으로 Print Scrreen 하는방법**********************************************************End

//Child 기준 Left Top 위치를 기준으로 Print Scrreen 하는방법**********************************************************Start
void CDlgPosition::OnBnClickedBtnSaveSpecificPosClient()
{
	CWnd* pWndDesktop = GetDesktopWindow();
	CWindowDC ScrDC(pWndDesktop);

	CClientDC dc(this);

	CRect WindowRT, Rect;

	//AfxGetMainWnd()->GetWindowRect(&WindowRT);	//Window 화면 기준 Main dialog위치의 시작지점 Left Top.
	GetWindowRect(&WindowRT);	//Window 화면 기준 현재 해당하는 다이얼로그 (자식다이얼로그면 자식위치시작지점을 나타냄 Left Top이)
	//GetClientRect(&Rect);	//자식 다이얼로그면 자식의 좌측상당 그래서 무조건 left top은 0,0이된다

	int sx = WindowRT.left;
	int sy = WindowRT.top;

	int cx = GetDlgItemInt(IDC_EDIT_WIDTH_CLLENT);
	int cy = GetDlgItemInt(IDC_EDIT_HEIGHT_CLIENT);

	cx = cx + (cx % 4);
	cy = cy + (cy % 4);

	if (sx < 10 || sy < 10)
	{
		AfxMessageBox("Size가 10보다 작으면 어카니?");
		return;
	}

	CImage pImage;
	pImage.Create(cx, cy, ScrDC.GetDeviceCaps(BITSPIXEL));
	CDC* pDC = CDC::FromHandle(pImage.GetDC());

	pDC->BitBlt(0, 0, cx, cy, &ScrDC, sx, sy, SRCCOPY);
	pImage.ReleaseDC();

	pImage.Save("./TestFolder/specific.jpg", Gdiplus::ImageFormatJPEG);

	::ShellExecute(NULL, "open", "D:\\YEY\\12345.jpg", NULL, NULL, SW_SHOW);
}
//Child 기준 Left Top 위치를 기준으로 Print Scrreen 하는방법**********************************************************End


void CDlgPosition::OnBnClickedBtnChangeBackgroundColor()
{
	BOOL bCheckUse = FALSE;

	for (int i = 0; i < 2 ; i++)
	{
		bCheckUse = ((CButton*)GetDlgItem(IDC_RADIO_BACK_DRAW_1 + i))->GetCheck();

		if (bCheckUse == TRUE)
			m_RadioIndex = i;
	}

	m_nCtrlIndex = eStatic;

	SendMessage(WM_ERASEBKGND);
	Invalidate(FALSE);
}

//return TRUE가 아니면 배경색은 변경되지 않는다. 슈발**********************************************************Start
BOOL CDlgPosition::OnEraseBkgnd(CDC* pDC)
{
	CClientDC dc(this);
	BOOL bCheckUse = FALSE;
	COLORREF cl;

	m_BackGroundBrushColor.DeleteObject();
	cl = RGB(GetDlgItemInt(IDC_BACKGROUND_R), GetDlgItemInt(IDC_BACKGROUND_G), GetDlgItemInt(IDC_BACKGROUND_B));
	m_BackGroundBrushColor.CreateSolidBrush(cl);

	if (m_RadioIndex == 0 )
	{
		CRect rect;
		GetClientRect(rect);
		dc.FillSolidRect(rect, cl);

	}
	else if (m_RadioIndex == 1)
	{
		CRect winRC;
		GetClientRect(winRC);
		
		CBrush* pOldBrush = dc.SelectObject(&m_BackGroundBrushColor);
		dc.Rectangle(winRC);
		dc.SelectObject(pOldBrush);
	}

	return TRUE;
}
//return TRUE가 아니면 배경색은 변경되지 않는다. 슈발**********************************************************End

//배경색을 변경했으면 Ctrl 색도 변경해야 한다*********************************************Start
HBRUSH CDlgPosition::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	m_BackGroundBrushColor.DeleteObject();

	COLORREF cl, cl2;
	cl = RGB(GetDlgItemInt(IDC_BACKGROUND_R), GetDlgItemInt(IDC_BACKGROUND_G), GetDlgItemInt(IDC_BACKGROUND_B));
	cl2 = RGB(GetDlgItemInt(IDC_BACKGROUND_TEXT_R), GetDlgItemInt(IDC_BACKGROUND_TEXT_G), GetDlgItemInt(IDC_BACKGROUND_TEXT_B));

	if (GetDlgItemInt(IDC_BACKGROUND_R) == 0 && GetDlgItemInt(IDC_BACKGROUND_G) == 0 && GetDlgItemInt(IDC_BACKGROUND_B) == 0)
		cl = RGB(240, 240, 240);

	m_BackGroundBrushColor.CreateSolidBrush(cl);

	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (nCtlColor == CTLCOLOR_STATIC && m_nCtrlIndex == 0)
	{
		pDC->SetBkColor(cl);
		pDC->SetTextColor(cl2);
		return m_BackGroundBrushColor;
	}
	else if (m_nCtrlIndex == 2)
	{
		pDC->SetTextColor(cl2);
		pDC->SetBkColor(cl);
	}
		
	return hbr;
}
//배경색을 변경했으면 Ctrl 색도 변경해야 한다*********************************************End

//자식 다이얼로그를 생성하는 방법1 - DoModal**********************************************************Start
//0. 리소스 탭에서 다이얼로그 생성을하고, 클래스를 생성까지한다.
//1. Header File 을 추가한다.
//2. Header파일의 클래스를 멤버 변수로 호출한다.
void CDlgPosition::OnBnClickedBtnDomodalOpen()
{
	CDlgPositionChild DlgPositionChild;
	DlgPositionChild.DoModal();		//얘가 종료되기 전까지 다른 Dialog는 건드릴수 없음.
}
//자식 다이얼로그를 생성하는 방법1 - DoModal**********************************************************End



//자식 다이얼로그를 생성하는 방법1 - 생성자 New로 생성**********************************************************Start
void CDlgPosition::OnBnClickedBtnNewCreateOpen()
{
	//if (m_pDlgPositionChild != NULL)		//이놈은 소멸자에서 진행한다.
	//	delete m_pDlgPositionChild;

	//m_pDlgPositionChild = new CDlgPositionChild;	//이놈은 생성자에서 진행한다. 매번생성하면 안됨. 메모리 누수
	m_pDlgPositionChild->DestroyWindow();	//생성된 놈을 계속 Create 하려다보면 에러가 발생하기 때문에 DestoryWidnow진행
	m_pDlgPositionChild->Create(IDD_DLG_POSITION_CHILD);
	m_pDlgPositionChild->ShowWindow(SW_SHOW);	//얘가 실행되더라도 아무작업이나 해도됨.
	
}
//자식 다이얼로그를 생성하는 방법1 - 생성자 New로 생성**********************************************************End




void CDlgPosition::OnBnClickedBtnChangeTextColor()
{
	m_nCtrlIndex = eTest;
	Invalidate(FALSE);
}
