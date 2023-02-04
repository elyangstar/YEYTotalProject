﻿#pragma once


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
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CMFCButton m_CheckClickColor;

	CMFCButton m_BtnImageInputMFCButton;

	CMFCButton m_btnRadio1;
	CMFCButton m_btnRadio2;
	CMFCButton m_btnRadio3;
	CMFCButton m_btnRadio4;

	CMFCButton m_CheckBtnChangeImage;

	CBitmapButton m_BtnImageInputBitmapButton;

	int m_nImageLocation;

	afx_msg void OnBnClickedCheckClickColor();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedCheckColorChange();
	afx_msg void OnCbnSelchangeComboImageLoc();

};