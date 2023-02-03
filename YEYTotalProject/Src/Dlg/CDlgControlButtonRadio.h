#pragma once


// CDlgControlButtonRadio 대화 상자

class CDlgControlButtonRadio : public CDialog
{
	DECLARE_DYNAMIC(CDlgControlButtonRadio)

public:
	CDlgControlButtonRadio(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgControlButtonRadio();

	enum { IDD = IDD_DIALOG_BTN_RADIO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CMFCButton			m_checkClickButton;
	
	afx_msg void OnBnClickedCheckChangeColor();
	
};
