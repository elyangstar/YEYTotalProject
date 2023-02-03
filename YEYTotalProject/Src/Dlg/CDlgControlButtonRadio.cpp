// CDlgControlButtonRadio.cpp: 구현 파일
//

#include "../../pch.h"
#include "../../YEYTotalProject.h"
#include "CDlgControlButtonRadio.h"
#include "afxdialogex.h"


// CDlgControlButtonRadio 대화 상자

IMPLEMENT_DYNAMIC(CDlgControlButtonRadio, CDialog)

CDlgControlButtonRadio::CDlgControlButtonRadio(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_BTN_RADIO, pParent)
{
	//m_btnImage.LoadBitmaps(IDB_REDBUTTON, IDB_GREENBUTTO);

}

CDlgControlButtonRadio::~CDlgControlButtonRadio()
{
}

void CDlgControlButtonRadio::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
// 	DDX_Control(pDX, IDC_CHECK_CHANGE_COLOR, m_checkClickButton);
// 	DDX_Control(pDX, IDC_BTN_IMG_SWIPE, m_btnImgSwipe);
// 	DDX_Control(pDX, IDC_BUTTON_IMAGE, m_btnImage);
}


BEGIN_MESSAGE_MAP(CDlgControlButtonRadio, CDialog)
	ON_BN_CLICKED(IDC_CHECK_CHANGE_COLOR, &CDlgControlButtonRadio::OnBnClickedCheckChangeColor)
	ON_BN_CLICKED(IDC_BTN_IMG_SWIPE, &CDlgControlButtonRadio::OnBnClickedBtnImgSwipe)
	ON_BN_CLICKED(IDC_BUTTON_IMAGE, &CDlgControlButtonRadio::OnBnClickedButtonImage)
END_MESSAGE_MAP()

BOOL CDlgControlButtonRadio::OnInitDialog()
{
	return FALSE;
}

//Checkbox를 사용하여 버튼 클릭되면 눌리고 다시 클릭하면 눌림이 해제되는것을 만들었다. ********************************************Start
//1. Check 박스를 생성한다.
//2. check button 속성 Push Like을 True 로 변경하면 일반 버튼처럼 변견된다.
//3. 그리고, Button의 멤버 변수 선언시 CMFCButton 으로 설정하여 변수를 만들고 아래와같이 진행하면 버튼이 눌리고 안눌리고를 할수 있다.
void CDlgControlButtonRadio::OnBnClickedCheckChangeColor()
{
	BOOL bCheck = m_checkClickButton.GetCheck();

	if (bCheck == TRUE)
	{
		m_checkClickButton.EnableWindowsTheming(FALSE); //cpp File
		m_checkClickButton.SetFaceColor(RGB(255, 0, 0), true); //cpp File
		m_checkClickButton.SetTextColor(RGB(0, 0, 255)); //cpp File
	}
	else
	{
		m_checkClickButton.GetCheck();
		m_checkClickButton.EnableWindowsTheming(FALSE); //cpp File
		m_checkClickButton.SetFaceColor(RGB(240, 240, 240), true); //cpp File
		m_checkClickButton.SetTextColor(RGB(0, 0, 0)); //cpp File
	}
	
	UpdateData(FALSE);
}

//Checkbox를 사용하여 버튼 클릭되면 눌리고 다시 클릭하면 눌림이 해제되는것을 만들었다. ********************************************End

void CDlgControlButtonRadio::OnBnClickedBtnImgSwipe()
{
	BOOL bCheck = m_btnImgSwipe.GetCheck();

	m_btnImgSwipe.m_nFlatStyle = CMFCButton::BUTTONSTYLE_SEMIFLAT;
	m_btnImgSwipe.SetImage(bCheck ? IDB_REDBUTTON : IDB_GREENBUTTO);
	m_btnImgSwipe.SizeToContent();
}


void CDlgControlButtonRadio::OnBnClickedButtonImgChange()
{
// 	BOOL bCheck = 1;// m_BtnChangeColor.GetCheck();
// 
// 	m_BtnChangeColor.LoadBitmaps(IDB_REDBUTTON , IDB_GREENBUTTO);
// 	m_BtnChangeColor.SizeToContent();
// 	//m_BtnChangeColor.SizeToContent();

}

// 
// void CDlgControlButtonRadio::OnBnClickedButton1()
// {
// 	BOOL bCheck = 1;// m_BtnChangeColor.GetCheck();
// 	m_btn1.SizeToContent();
// 	//m_btn1.LoadBitmaps(IDB_REDBUTTON , IDB_GREENBUTTO);
// 
// }


void CDlgControlButtonRadio::OnBnClickedButtonImage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
