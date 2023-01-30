#pragma once


// CCalendarDlg 대화 상자

class CCalendarDlg : public CDialog
{
	DECLARE_DYNAMIC(CCalendarDlg)

public:
	CCalendarDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCalendarDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_CALENDAR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBrush m_background;


	//달력 관련 데이터 처리.
	CMonthCalCtrl	m_timeMC;
	CDateTimeCtrl	m_datetime_picker;
	CEdit			m_strPrintDateedit;
	CEdit			m_strPrintDateMC;

	//Line Calendar
	afx_msg void	OnBnClickedBtnGetDate();
	afx_msg void	OnBnClickedBtnChangeColorCal();
	//Month Calendar
	afx_msg void	OnBnClickedBtnGetMcdate();
	afx_msg void	OnBnClickedButtonChangeColor();

};
