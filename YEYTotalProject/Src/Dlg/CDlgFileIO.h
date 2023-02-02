#pragma once

// CDlgFileIO 대화 상자

class CDlgFileIO : public CDialog
{
	DECLARE_DYNAMIC(CDlgFileIO)

public:
	CDlgFileIO(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgFileIO();

	enum { IDD = IDD_DLG_FILEIO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox		m_listMultiSelected;
	CString			m_strFileCopySrc;
	CString			m_strFileCopyDest;

	afx_msg void	OnBnClickedBtnOpenfile();
	afx_msg void	OnBnClickedBtnOpenmultifile();

	afx_msg void OnBnClickedBtnSaveTxt();
	afx_msg void OnBnClickedBtnFolderPath();
	afx_msg void OnBnClickedBtnOpenData();
	afx_msg void OnBnClickedBtnWriteData();
	afx_msg void OnBnClickedBtnWriteContinuedata();
	afx_msg void OnBnClickedBtnCopy1();
	afx_msg void OnBnClickedBtnCopy2();
};


