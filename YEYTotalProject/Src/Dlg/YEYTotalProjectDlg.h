
// YEYTotalProjectDlg.h: 헤더 파일
//
#include "CCalendarDlg.h"
#include "CDlgFileIO.h"
#include "CDlgPosition.h"
#include "CDlgButtonCtrl.h"
#include "CDlgGridCtrl.h"
#include "CDlgRegistry.h"

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

	void			TreeCtrlSetting();

	afx_msg void	OnTvnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void	OnMoving(UINT fwSide, LPRECT pRect);
	afx_msg void	OnMouseMove(UINT nFlags, CPoint point);
	//******************************************************************************************


	//New DIALOG Creation***********************************************************************
	CCalendarDlg			*m_pDlgCalendar;
	CDlgFileIO				*m_pDlgFileIO;
	CDlgPosition			*m_pDlgPosition;
	CDlgButtonCtrl			*m_pDlgButtonCtrl;
	CDlgGridCtrl			*m_pDlgGridCtrl;
	CDlgRegistry			*m_pDlgRegistry;

	void			DialogCreation();
	void			DialogShow();
	//******************************************************************************************

	//Toast Test********************************************************************************
	
	//******************************************************************************************

	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	void Test();
};
