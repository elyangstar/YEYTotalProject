// CCalendarDlg.cpp: 구현 파일
//

#include "../../pch.h"
#include "../../YEYTotalProject.h"
#include "CCalendarDlg.h"
#include "afxdialogex.h"


// CCalendarDlg 대화 상자

IMPLEMENT_DYNAMIC(CCalendarDlg, CDialog)

CCalendarDlg::CCalendarDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_CALENDAR, pParent)
{
	//m_background.CreateSolidBrush(RGB(120, 7, 200));
}

CCalendarDlg::~CCalendarDlg()
{
}

void CCalendarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MONTHCALENDAR, m_timeMC);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_datetime_picker);
	DDX_Control(pDX, IDC_EDIT_PRINTDATE, m_strPrintDateedit);
	DDX_Control(pDX, IDC_EDIT_PRINTMCDATE, m_strPrintDateMC);
}


BEGIN_MESSAGE_MAP(CCalendarDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_GET_DATE, &CCalendarDlg::OnBnClickedBtnGetDate)
	ON_BN_CLICKED(IDC_BTN_GET_MCDATE, &CCalendarDlg::OnBnClickedBtnGetMcdate)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE_COLOR, &CCalendarDlg::OnBnClickedButtonChangeColor)
	ON_BN_CLICKED(IDC_BTN_CHANGE_COLOR_CAL, &CCalendarDlg::OnBnClickedBtnChangeColorCal)
END_MESSAGE_MAP()


// CCalendarDlg 메시지 처리기
HBRUSH CCalendarDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	//pDC->SetTextColor(RGB(255, 255, 255));
	//hbr = m_background;
	return hbr;
}

//Line Caledar *****************************************************************************************************Start
void CCalendarDlg::OnBnClickedBtnGetDate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CTime sel_date;
	int sel_year, sel_month, sel_day;
	CString strValue = "";
	
	m_datetime_picker.GetTime(sel_date);
	sel_year = sel_date.GetYear();
	sel_month = sel_date.GetMonth();
	sel_day = sel_date.GetDay();

	strValue.Format("%d_%d_%d", sel_year, sel_month, sel_day);
	SetDlgItemText(IDC_EDIT_PRINTDATE, strValue);

	UpdateData(FALSE);
}

void CCalendarDlg::OnBnClickedBtnChangeColorCal()
{
	m_datetime_picker.SetMonthCalColor(MCSC_TITLEBK, RGB(0, 0, 128));
	m_datetime_picker.SetMonthCalColor(MCSC_MONTHBK, RGB(70, 170, 255));
	m_datetime_picker.SetMonthCalColor(MCSC_TEXT, RGB(250, 240, 50));
	m_datetime_picker.SetMonthCalColor(MCSC_TITLETEXT, RGB(255, 255, 0));
	m_datetime_picker.SetMonthCalColor(MCSC_BACKGROUND, RGB(190, 225, 240));
	m_datetime_picker.SetMonthCalColor(MCSC_TRAILINGTEXT, RGB(150, 200, 255));

	m_datetime_picker.SetMonthCalColor(MCSC_TITLEBK, RGB(170, 120, 5));
	m_datetime_picker.SetMonthCalColor(MCSC_MONTHBK, RGB(220, 190, 125));
	m_datetime_picker.SetMonthCalColor(MCSC_TEXT, RGB(128, 0, 0));
	m_datetime_picker.SetMonthCalColor(MCSC_TITLETEXT, RGB(220, 190, 125));
	m_datetime_picker.SetMonthCalColor(MCSC_BACKGROUND, RGB(250, 175, 10));
	m_datetime_picker.SetMonthCalColor(MCSC_TRAILINGTEXT, RGB(255, 255, 255));

	UpdateData(FALSE);
}
//Line Caledar *****************************************************************************************************END
//Month Calendar *****************************************************************************************************start
void CCalendarDlg::OnBnClickedBtnGetMcdate()
{
	/* 달력컨트롤에서 사용자가 선택한 날짜 정보 조회하기 */
	CTime currentTime;
	CString strValue;

	CMonthCalCtrl* pCalendar = (CMonthCalCtrl*)GetDlgItem(IDC_MONTHCALENDAR);
	pCalendar->GetCurSel(currentTime);

	strValue.Format("%d년 %d월 %d일", currentTime.GetYear(), currentTime.GetMonth(), currentTime.GetDay());
	SetDlgItemText(IDC_EDIT_PRINTMCDATE, strValue);

	UpdateData(false);
}

void CCalendarDlg::OnBnClickedButtonChangeColor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMonthCalCtrl* pCalendar = (CMonthCalCtrl*)GetDlgItem(IDC_MONTHCALENDAR);
	BOOL bCheckUse = FALSE;

	COLORREF cl;
	cl = RGB(GetDlgItemInt(IDC_EDIT_BG_R), GetDlgItemInt(IDC_EDIT_BG_G), GetDlgItemInt(IDC_EDIT_BG_B));
	BYTE by = GetGValue(cl);

	for (int i = 0; i < 5 ; i++)
	{
		bCheckUse = ((CButton*)GetDlgItem(IDC_RADIO_BACKGROUND + i))->GetCheck();

		if (bCheckUse == TRUE)
		{
			pCalendar->SetColor(MCSC_BACKGROUND + i, cl);
		}
	}
	
	UpdateData(FALSE);
}
//Month Calendar *****************************************************************************************************End