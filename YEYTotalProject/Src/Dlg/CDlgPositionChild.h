#pragma once


// CDlgPositionChild 대화 상자

class CDlgPositionChild : public CDialog
{
	DECLARE_DYNAMIC(CDlgPositionChild)

public:
	CDlgPositionChild(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgPositionChild();

	enum { IDD = IDD_DLG_POSITION_CHILD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
