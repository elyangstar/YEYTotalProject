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
	m_nImageLocation = 0;
}

CDlgButtonCtrl::~CDlgButtonCtrl()
{
}

void CDlgButtonCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_CLICK_COLOR, m_CheckClickColor);
	DDX_Control(pDX, IDC_BTN_IMG_INPUT, m_BtnImageInputBitmapButton);
	DDX_Control(pDX, IDC_CHECK_COLOR_CHANGE, m_BtnImageInputMFCButton);
	DDX_CBIndex(pDX, IDC_COMBO_IMAGE_LOC, m_nImageLocation);
	DDX_Control(pDX, IDC_RADIO1, m_btnRadio1);
	DDX_Control(pDX, IDC_RADIO2, m_btnRadio2);
	DDX_Control(pDX, IDC_RADIO3, m_btnRadio3);
	DDX_Control(pDX, IDC_RADIO4, m_btnRadio4);
	DDX_Control(pDX, IDC_CHECK1, m_CheckBtnChangeImage);
}


BOOL CDlgButtonCtrl::OnInitDialog()
{
	CDialog::OnInitDialog();

	//Radio Button 사용하여 이미지 넣고 이미지 스왑.************************************************************************Start
	m_btnRadio1.m_nFlatStyle = CMFCButton::BUTTONSTYLE_SEMIFLAT;
	m_btnRadio2.m_nFlatStyle = CMFCButton::BUTTONSTYLE_SEMIFLAT;
	m_btnRadio3.m_nFlatStyle = CMFCButton::BUTTONSTYLE_SEMIFLAT;
	m_btnRadio4.m_nFlatStyle = CMFCButton::BUTTONSTYLE_SEMIFLAT;

	m_btnRadio1.SetImage(IDB_RADIO_OFF);
	m_btnRadio2.SetImage(IDB_RADIO_OFF);
	m_btnRadio3.SetImage(IDB_RADIO_OFF);
	m_btnRadio4.SetImage(IDB_RADIO_OFF);

	m_btnRadio1.SetCheckedImage(IDB_RADIO_ON);
	m_btnRadio2.SetCheckedImage(IDB_RADIO_ON);
	m_btnRadio3.SetCheckedImage(IDB_RADIO_ON);
	m_btnRadio4.SetCheckedImage(IDB_RADIO_ON);

	m_btnRadio1.SizeToContent();
	m_btnRadio2.SizeToContent();
	m_btnRadio3.SizeToContent();
	m_btnRadio4.SizeToContent();

	m_btnRadio1.SetCheck(TRUE);
	//Radio Button 사용하여 이미지 넣고 이미지 스왑.************************************************************************End

	//CBitmapButton을 사용하여 비트맵 이미지를 버튼으로 사용하기.************************************************************************Start
	m_BtnImageInputBitmapButton.LoadBitmaps(IDB_BITMAP_TEST1, IDB_BITMAP_TEST2);	//Button 전체를 이미지로 바꿔버리는것.(미리 해놔야함, 다이얼로그 불러올때 사용자 지정 이미지가 없다면 이상해짐)
	m_BtnImageInputBitmapButton.SizeToContent();									//이미지 크기 만큼 알아서 출력해줌.

	m_BtnImageInputMFCButton.SetImage(IDB_BITMAP_GREEN);						//이미지를 Button 안에 출력하는 것
	m_BtnImageInputMFCButton.SizeToContent();									//이미지 크기 만큼 알아서 출력해줌.
	//CBitmapButton을 사용하여 비트맵 이미지를 버튼으로 사용하기.************************************************************************End


	//Check Button 을 사용하여 이미지를 버튼안에 출력하고 ON & OFF에 따라 이미지 변경 기능 ************************************************************************Start
	m_CheckBtnChangeImage.SetImage(IDB_CHECK_OFF);
	m_CheckBtnChangeImage.SetCheckedImage(IDB_CHECK_ON);
	m_CheckBtnChangeImage.SizeToContent();
	m_CheckBtnChangeImage.m_nFlatStyle = CMFCButton::BUTTONSTYLE_SEMIFLAT;
	//Check Button 을 사용하여 이미지를 버튼안에 출력하고 ON & OFF에 따라 이미지 변경 기능 ************************************************************************End

	return TRUE;

}

// CDlgButtonCtrl 메시지 처리기
BEGIN_MESSAGE_MAP(CDlgButtonCtrl, CDialog)
	ON_BN_CLICKED(IDC_CHECK_CLICK_COLOR, &CDlgButtonCtrl::OnBnClickedCheckClickColor)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CHECK_COLOR_CHANGE, &CDlgButtonCtrl::OnBnClickedCheckColorChange)
	ON_CBN_SELCHANGE(IDC_COMBO_IMAGE_LOC, &CDlgButtonCtrl::OnCbnSelchangeComboImageLoc)
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

void CDlgButtonCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.


}
//CBitmapButton을 사용하여 비트맵 이미지를 버튼으로 사용하기.************************************************************************Start
void CDlgButtonCtrl::OnCbnSelchangeComboImageLoc()
{
	UpdateData(TRUE);

	switch (m_nImageLocation)
	{
	case 0:
		m_BtnImageInputMFCButton.m_bRightImage = FALSE;
		m_BtnImageInputMFCButton.m_bTopImage = FALSE;
		break;

	case 1:
		m_BtnImageInputMFCButton.m_bRightImage = TRUE;
		m_BtnImageInputMFCButton.m_bTopImage = FALSE;
		break;

	case 2:
		m_BtnImageInputMFCButton.m_bRightImage = FALSE;
		m_BtnImageInputMFCButton.m_bTopImage = TRUE;
		break;
	}

	m_BtnImageInputMFCButton.SizeToContent();
	m_BtnImageInputMFCButton.Invalidate();
}
//CBitmapButton을 사용하여 비트맵 이미지를 버튼으로 사용하기.************************************************************************End


//CMFCButton 을 사용하여 이미지를 버튼안에 출력하는 기능 ************************************************************************Start
void CDlgButtonCtrl::OnBnClickedCheckColorChange()
{
	BOOL bCheck = m_BtnImageInputMFCButton.GetCheck();
	
	m_BtnImageInputMFCButton.m_nFlatStyle = CMFCButton::BUTTONSTYLE_SEMIFLAT;
	//이미지를 없애고 싶다면 : m_BtnImageInputMFCButton.SetImage((HBITMAP) NULL);
	m_BtnImageInputMFCButton.SetImage(bCheck ? IDB_BITMAP_GREEN : IDB_BITMAP_RED);
	m_BtnImageInputMFCButton.SetCheckedImage(bCheck ? IDB_BITMAP_GREEN : IDB_BITMAP_RED);

	m_BtnImageInputMFCButton.SizeToContent();
}
//CMFCButton 을 사용하여 이미지를 버튼안에 출력하는 기능 ************************************************************************End
