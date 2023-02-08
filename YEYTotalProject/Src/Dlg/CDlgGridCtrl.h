#pragma once
#include "GridControl/GridCtrl.h"
#include "GridControl/NewCellTypes/GridCellCombo.h"
#include "GridControl/NewCellTypes/GridCellCheck.h"

// CDlgGridCtrl 대화 상자

class CDlgGridCtrl : public CDialog
{
	DECLARE_DYNAMIC(CDlgGridCtrl)

public:
	CDlgGridCtrl(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgGridCtrl();

	enum { IDD = IDD_DIALOG_GRIDCTRL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	void	initGridCtrl();
	void	inputGridCtrl();

	DECLARE_MESSAGE_MAP()
	
	void SetGridNewRowCount();
public:
	CGridCtrl	m_GridCtrl;
	int			m_nGridCtrlRowCount;
	
	virtual BOOL OnInitDialog();
	void		 FillGridData();
	afx_msg void OnBnClickedBtnSaveCsvfile();
	afx_msg void OnBnClickedBtnLoadCsvfile();

	afx_msg void OnEnChangeGridRowCount();
	afx_msg void OnBnClickedBtnSaveHm();
	afx_msg void OnBnClickedBtnLoadHm();
	afx_msg void OnBnClickedBtnFindData();
};
