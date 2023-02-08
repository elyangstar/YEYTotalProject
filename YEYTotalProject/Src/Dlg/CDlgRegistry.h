#pragma once


// CDlgRegistry 대화 상자

class CDlgRegistry : public CDialog
{
	DECLARE_DYNAMIC(CDlgRegistry)

public:
	CDlgRegistry(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgRegistry();

	enum {IDD = IDD_DLG_REGISTRY};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	HKEY	m_hRegKey;

	CString m_strRegistryPath;
	CString m_strItemName;
	CString m_strItemValue;
	CString m_strRegistryRead;
	CString m_strRegistryName2;
	CString m_strRegiModifyPath;
	CString m_strEnvirName;
	CString m_strEnvirValue;
	CString m_strModifyEnvirValue;
	afx_msg void OnBnClickedButtonOpen();
	CString m_strRefreshData;
	afx_msg void OnBnClickedButtonCreateFolder();
	afx_msg void OnBnClickedButtonNewCreate();
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedButtonModifyPath();
	afx_msg void OnBnClickedButtonDeletePath();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonReadEnvirvalue();
	afx_msg void OnBnClickedButtonReadEnvirvalue2();
	afx_msg void OnBnClickedButtonReadEnvirvalue3();
};
