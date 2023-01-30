
// YEYTotalProjectDlg.h: 헤더 파일
//
#include "CCalendarDlg.h"
#include "CDlgFileIO.h"

#pragma once
class CCalendarDlg;
class CDlgFileIO;

// CYEYTotalProjectDlg 대화 상자
class CYEYTotalProjectDlg : public CDialog
{
// 생성입니다.
public:
	CYEYTotalProjectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	virtual ~CYEYTotalProjectDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YEYTOTALPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


public:
	//Tree Ctrl*********************************************************************************
	CTreeCtrl m_TreeCtrl;
	HTREEITEM m_TreeRoot, m_hParent1, m_hParent2 ,m_hChild1, m_hChild2 , m_hSelected;
	void	TreeCtrlSetting();

	afx_msg void OnTvnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult);
	//******************************************************************************************


	//New DIALOG Creation***********************************************************************
	CCalendarDlg	*m_pDlgCalendar;
	CDlgFileIO		*m_pDlgFileIO;

	void			DialogCreation();
	void			DialogShow();
	//******************************************************************************************

};
