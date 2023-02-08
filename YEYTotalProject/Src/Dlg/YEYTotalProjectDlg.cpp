
// YEYTotalProjectDlg.cpp: 구현 파일
//

#include "../../pch.h"
#include "../../framework.h"
#include "../../YEYTotalProject.h"
#include "YEYTotalProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CYEYTotalProjectDlg 대화 상자



CYEYTotalProjectDlg::CYEYTotalProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YEYTOTALPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	m_pDlgCalendar	= new CCalendarDlg(this);
	m_pDlgFileIO	= new CDlgFileIO(this);
	m_pDlgPosition = new CDlgPosition(this);
	m_pDlgButtonCtrl = new CDlgButtonCtrl(this);
	m_pDlgGridCtrl = new CDlgGridCtrl(this);
	m_pDlgRegistry = new CDlgRegistry(this);

}

CYEYTotalProjectDlg::~CYEYTotalProjectDlg()
{
	if (m_pDlgCalendar)
	{
		delete m_pDlgCalendar;
		m_pDlgCalendar = NULL;
	}
	if (m_pDlgFileIO)
	{
		delete m_pDlgFileIO;
		m_pDlgFileIO = NULL;
	}
	if (m_pDlgPosition)
	{
		delete m_pDlgPosition;
		m_pDlgPosition = NULL;
	}
	if (m_pDlgButtonCtrl)
	{
		delete m_pDlgButtonCtrl;
		m_pDlgButtonCtrl = NULL;
	}
	if (m_pDlgGridCtrl)
	{
		delete m_pDlgGridCtrl;
		m_pDlgGridCtrl = NULL;
	}
	if (m_pDlgRegistry)
	{
		delete m_pDlgRegistry;
		m_pDlgRegistry = NULL;
	}
}

void CYEYTotalProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_CONTROL, m_TreeCtrl);
}

BEGIN_MESSAGE_MAP(CYEYTotalProjectDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CONTROL, &CYEYTotalProjectDlg::OnTvnSelchangedTreeControl)
	ON_WM_MOVING()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZING()
END_MESSAGE_MAP()


// CYEYTotalProjectDlg 메시지 처리기

BOOL CYEYTotalProjectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	TreeCtrlSetting();
	DialogCreation();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CYEYTotalProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CYEYTotalProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CYEYTotalProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Tree Ctrl***************************************************************************************************************Start
void CYEYTotalProjectDlg::TreeCtrlSetting()
{

	m_TreeRoot = m_TreeCtrl.InsertItem((LPCTSTR)"Project", 0, 0,TVI_ROOT ,TVI_LAST);
	m_hParent1 = m_TreeCtrl.InsertItem((LPCTSTR)"Control", 0, 0, m_TreeRoot, TVI_LAST);
	m_hChild1 = m_TreeCtrl.InsertItem((LPCTSTR)"Calendar", 0, 0, m_hParent1, TVI_LAST);
	m_hChild1 = m_TreeCtrl.InsertItem((LPCTSTR)"File Input & Output", 1, 0, m_hParent1, TVI_LAST);
	m_hChild1 = m_TreeCtrl.InsertItem((LPCTSTR)"Mouse & Dialog", 1, 0, m_hParent1, TVI_LAST);
	m_hChild1 = m_TreeCtrl.InsertItem((LPCTSTR)"Button Control", 1, 0, m_hParent1, TVI_LAST);
	m_hChild1 = m_TreeCtrl.InsertItem((LPCTSTR)"Grid Control", 1, 0, m_hParent1, TVI_LAST);
	m_hChild1 = m_TreeCtrl.InsertItem((LPCTSTR)"Registry & environment Value", 1, 0, m_hParent1, TVI_LAST);
	
	m_hParent2 = m_TreeCtrl.InsertItem((LPCTSTR)"기타 프로젝트_Made by YEY", 0, 0, m_TreeRoot, TVI_LAST);
	m_hChild2 = m_TreeCtrl.InsertItem((LPCTSTR)"Toast Test", 0, 0, m_hParent2, TVI_LAST);

}


void CYEYTotalProjectDlg::OnTvnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_hSelected = m_TreeCtrl.GetSelectedItem();
	DialogShow();
	*pResult = 0;
}
//Tree Ctrl***************************************************************************************************************END

//New DIALOG Creation*****************************************************************************************************start
void CYEYTotalProjectDlg::DialogCreation()
{
#define WINDOW_SIZE_H 850
#define WINDOW_SIZE_V 600
#define WINDOW_START_X 280
#define WINDOW_START_Y 10

	//Dialog Creation
	m_pDlgCalendar->Create(CCalendarDlg::IDD, this);
	m_pDlgCalendar->MoveWindow(WINDOW_START_X, WINDOW_START_Y, WINDOW_SIZE_H, WINDOW_SIZE_V);

	m_pDlgFileIO->Create(CDlgFileIO::IDD, this);
	m_pDlgFileIO->MoveWindow(WINDOW_START_X, WINDOW_START_Y, WINDOW_SIZE_H, WINDOW_SIZE_V);

	m_pDlgPosition->Create(CDlgPosition::IDD, this);
	m_pDlgPosition->MoveWindow(WINDOW_START_X, WINDOW_START_Y, WINDOW_SIZE_H, WINDOW_SIZE_V);

	m_pDlgButtonCtrl->Create(CDlgButtonCtrl::IDD, this);
	m_pDlgButtonCtrl->MoveWindow(WINDOW_START_X, WINDOW_START_Y, WINDOW_SIZE_H, WINDOW_SIZE_V);

	m_pDlgGridCtrl->Create(CDlgGridCtrl::IDD, this);
	m_pDlgGridCtrl->MoveWindow(WINDOW_START_X, WINDOW_START_Y, WINDOW_SIZE_H, WINDOW_SIZE_V);

	m_pDlgRegistry->Create(CDlgRegistry::IDD, this);
	m_pDlgRegistry->MoveWindow(WINDOW_START_X, WINDOW_START_Y, WINDOW_SIZE_H, WINDOW_SIZE_V);

	//DialogShow();
}

void CYEYTotalProjectDlg::DialogShow()
{
	CString strCurText = "";
	strCurText = m_TreeCtrl.GetItemText(m_hSelected);
	//AfxMessageBox(strCur);

	m_pDlgCalendar->ShowWindow(SW_HIDE);
	m_pDlgFileIO->ShowWindow(SW_HIDE);
	m_pDlgPosition->ShowWindow(SW_HIDE);
	m_pDlgButtonCtrl->ShowWindow(SW_HIDE);
	m_pDlgGridCtrl->ShowWindow(SW_HIDE);
	m_pDlgRegistry->ShowWindow(SW_HIDE);

	if (strCurText == "Calendar")
		m_pDlgCalendar->ShowWindow(SW_SHOW);
	else if (strCurText == "File Input & Output")
		m_pDlgFileIO->ShowWindow(SW_SHOW);
	else if (strCurText == "Mouse & Dialog")
		m_pDlgPosition->ShowWindow(SW_SHOW);
	else if (strCurText == "Button Control")
		m_pDlgButtonCtrl->ShowWindow(SW_SHOW);
 	else if (strCurText == "Grid Control")
 		m_pDlgGridCtrl->ShowWindow(SW_SHOW);
	else if (strCurText == "Registry & environment Value")
		m_pDlgRegistry->ShowWindow(SW_SHOW);
	
}
//************************************************************************************************************************END


//Set Data Main -> Child*****************************************************************************************************start
void CYEYTotalProjectDlg::OnMoving(UINT fwSide, LPRECT pRect)
{
	CDialog::OnMoving(fwSide, pRect);
	
	CRect rt;
	rt.top = pRect->top;
	rt.bottom = pRect->bottom;
	rt.left = pRect->left;
	rt.right = pRect->right;

	m_pDlgPosition->SetWindowPosAndRect(rt);
}
//***************************************************************************************************************************End

void CYEYTotalProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialog::OnMouseMove(nFlags, point);
	CRect rt;

	GetWindowRect(&rt);
	m_pDlgPosition->SetWindowPosAndRect(rt);
	m_pDlgPosition->SetMousePos(point);
}


void CYEYTotalProjectDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialog::OnSizing(fwSide, pRect);

	CRect rt;

	GetWindowRect(&rt);
	m_pDlgPosition->SetWindowPosAndRect(rt);
}