#pragma once


// CDlgButtonCtrl 대화 상자

class CDlgButtonCtrl : public CDialog
{
	DECLARE_DYNAMIC(CDlgButtonCtrl)

public:
	CDlgButtonCtrl(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgButtonCtrl();

	enum { IDD = IDD_DLG_BUTTON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CMFCButton m_CheckClickColor;
	afx_msg void OnBnClickedCheckClickColor();
	CBitmapButton m_BtnImageInput;
	afx_msg void OnBnClickedBtnImgInput();
	afx_msg void OnPaint();

//	afx_msg void OnBnClickedCheckColorChange();
	CMFCButton m_BtnColorChange;
	afx_msg void OnBnClickedCheckColorChange();
};
