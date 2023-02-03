#pragma once
#include "CDlgPositionChild.h"

// CDlgPosition 대화 상자
enum {eStatic = 0, eEdit , eTest};
class CDlgPosition : public CDialog
{
	DECLARE_DYNAMIC(CDlgPosition)

public:
	CDlgPosition(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgPosition();

	enum { IDD = IDD_DLG_POSITION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	
	CString			m_strMoveData;
	CString			m_strDlgSize;
	CString			m_strDlgPosition;

	CRect			m_rtWindow;
	CPoint			m_ptMouse;  //Header에 선언
	
	int				m_nMainDlgSizeX;
	int				m_nMainDlgSizeY;

	int				m_RadioIndex;
	
	int				m_nClientDlgSizeX;
	int				m_nClientDlgSizeY;
	int				m_nCtrlIndex;

	CBrush			m_BackGroundBrushColor;

	CDlgPositionChild *m_pDlgPositionChild;

	//Dialog 위치 값 MainFrame에서 받아오는함수
	void			SetWindowPosAndRect(CRect rt);
	CRect			GetWindowPosAndRect();

	//Mouse 위치 값 MainFrame에서 받아오는함수
	void			SetMousePos(CPoint pt);
	CPoint			GetMousePos();

	void			DialogPosPrint();
	void			MousePosPrint();

	afx_msg void OnPaint();

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedBtnChangeDlgSize();
	afx_msg void OnBnClickedBtnChangeDlgClientSize();

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedBtnSaveSpecificPos();
	afx_msg void OnBnClickedBtnSaveSpecificPosClient();
	afx_msg void OnBnClickedBtnChangeBackgroundColor();
	afx_msg void OnBnClickedBtnDomodalOpen();
	afx_msg void OnBnClickedBtnNewCreateOpen();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedBtnChangeTextColor();
};
