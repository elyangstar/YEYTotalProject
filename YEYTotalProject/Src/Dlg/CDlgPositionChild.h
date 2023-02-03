#pragma once


// CDlgPositionChild 대화 상자

class CDlgPositionChild : public CDialog
{
	DECLARE_DYNAMIC(CDlgPositionChild)

public:
	CDlgPositionChild(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgPositionChild();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_POSITION_CHILD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
