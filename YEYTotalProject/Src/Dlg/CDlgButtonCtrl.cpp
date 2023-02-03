// CDlgButtonCtrl.cpp: 구현 파일
//

#include "../../pch.h"
#include "../../YEYTotalProject.h"
#include "CDlgButtonCtrl.h"
#include "afxdialogex.h"


// CDlgButtonCtrl 대화 상자

IMPLEMENT_DYNAMIC(CDlgButtonCtrl, CDialog)

CDlgButtonCtrl::CDlgButtonCtrl(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_BUTTON, pParent)
{
}

CDlgButtonCtrl::~CDlgButtonCtrl()
{
}

void CDlgButtonCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_CLICK_COLOR, m_CheckClickColor);
	DDX_Control(pDX, IDC_BTN_IMG_INPUT, m_BtnImageInput);
	DDX_Control(pDX, IDC_CHECK_COLOR_CHANGE, m_BtnColorChange);
}


// CDlgButtonCtrl 메시지 처리기
BEGIN_MESSAGE_MAP(CDlgButtonCtrl, CDialog)
	ON_BN_CLICKED(IDC_CHECK_CLICK_COLOR, &CDlgButtonCtrl::OnBnClickedCheckClickColor)
	ON_BN_CLICKED(IDC_BTN_IMG_INPUT, &CDlgButtonCtrl::OnBnClickedBtnImgInput)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CHECK_COLOR_CHANGE, &CDlgButtonCtrl::OnBnClickedCheckColorChange)
END_MESSAGE_MAP()


void CDlgButtonCtrl::OnBnClickedCheckClickColor()
{
	BOOL bCheck = m_CheckClickColor.GetCheck();

	if (bCheck == TRUE)
	{
		m_CheckClickColor.EnableWindowsTheming(FALSE); //cpp File
		m_CheckClickColor.SetFaceColor(RGB(255, 0, 0), true); //cpp File
		m_CheckClickColor.SetTextColor(RGB(0, 0, 255)); //cpp File
	}
	else
	{
		m_CheckClickColor.EnableWindowsTheming(FALSE); //cpp File
		m_CheckClickColor.SetFaceColor(RGB(240, 240, 240), true); //cpp File
		m_CheckClickColor.SetTextColor(RGB(0, 0, 0)); //cpp File
	}

	UpdateData(FALSE);
}


void CDlgButtonCtrl::OnBnClickedBtnImgInput()
{

}

//CBitmapButton을 사용하여 비트맵 이미지를 버튼으로 사용하기.************************************************************************Start
void CDlgButtonCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.

	m_BtnImageInput.LoadBitmaps(IDB_BITMAP_TEST1, IDB_BITMAP_TEST2);	//Button 전체를 이미지로 바꿔버리는것.(미리 해놔야함, 다이얼로그 불러올때 사용자 지정 이미지가 없다면 이상해짐)
	m_BtnImageInput.SizeToContent();									//이미지 크기 만큼 알아서 출력해줌.

	m_BtnColorChange.SetImage(IDB_BITMAP_GREEN);						//이미지를 Button 안에 출력하는 것
	m_BtnColorChange.SizeToContent();									//이미지 크기 만큼 알아서 출력해줌.
}
//CBitmapButton을 사용하여 비트맵 이미지를 버튼으로 사용하기.************************************************************************End


//CMFCButton 을 사용하여 이미지를 버튼안에 출력하는 기능 ************************************************************************Start
void CDlgButtonCtrl::OnBnClickedCheckColorChange()
{
	BOOL bCheck = m_BtnColorChange.GetCheck();

	m_BtnColorChange.m_nFlatStyle = CMFCButton::BUTTONSTYLE_SEMIFLAT;
	m_BtnColorChange.SetImage(bCheck ? IDB_BITMAP_GREEN : IDB_BITMAP_RED);
	m_BtnColorChange.SetCheckedImage(bCheck ? IDB_BITMAP_GREEN : IDB_BITMAP_RED);

	m_BtnColorChange.SizeToContent();
}
//CMFCButton 을 사용하여 이미지를 버튼안에 출력하는 기능 ************************************************************************End