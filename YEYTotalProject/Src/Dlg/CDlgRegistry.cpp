// CDlgRegistry.cpp: 구현 파일
//

#include "../../pch.h"
#include "../../YEYTotalProject.h"
#include "CDlgRegistry.h"
#include "afxdialogex.h"


// CDlgRegistry 대화 상자

IMPLEMENT_DYNAMIC(CDlgRegistry, CDialog)

CDlgRegistry::CDlgRegistry(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_REGISTRY, pParent)
{
	m_strRegistryPath = "SOFTWARE\\TEST_YEY";
	m_strItemName = "VALUENAME";
	m_strItemValue = "C:\\YEY";
	m_strRegistryRead = "";
	m_strRegistryName2 = "";
	m_strRegiModifyPath = "";

	m_strEnvirName = "VIEW_PATH";
	m_strEnvirValue = "";
	m_strModifyEnvirValue = "";
	m_strRefreshData = "";
}

CDlgRegistry::~CDlgRegistry()
{
}

void CDlgRegistry::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_REGISTRY_PATH, m_strRegistryPath);
	DDX_Text(pDX, IDC_REGISTRY_CREATE_ITEM, m_strItemName);
	DDX_Text(pDX, IDC_REGISTRY_CREATE_ITEM2, m_strItemValue);
	DDX_Text(pDX, IDC_REGISTRY_READ_DATA, m_strRegistryRead);
	DDX_Text(pDX, IDC_REGISTRY_CREATE_ITEM3, m_strRegistryName2);
	DDX_Text(pDX, IDC_REGISTRY_CREATE_ITEM4, m_strRegiModifyPath);
	DDX_Text(pDX, IDC_ENVIRONMENT_NAME, m_strEnvirName);
	DDX_Text(pDX, IDC_ENVIRONMENT_VALUE, m_strEnvirValue);
	DDX_Text(pDX, IDC_ENVIRONMENT_VALUE_MOD, m_strModifyEnvirValue);
	DDX_Text(pDX, IDC_ENVIRONMENT_REFRESH_DATA, m_strRefreshData);
}


BEGIN_MESSAGE_MAP(CDlgRegistry, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CDlgRegistry::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_CREATE_FOLDER, &CDlgRegistry::OnBnClickedButtonCreateFolder)
	ON_BN_CLICKED(IDC_BUTTON_NEW_CREATE, &CDlgRegistry::OnBnClickedButtonNewCreate)
	ON_BN_CLICKED(IDC_BUTTON_READ, &CDlgRegistry::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY_PATH, &CDlgRegistry::OnBnClickedButtonModifyPath)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_PATH, &CDlgRegistry::OnBnClickedButtonDeletePath)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CDlgRegistry::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_READ_ENVIRVALUE, &CDlgRegistry::OnBnClickedButtonReadEnvirvalue)
	ON_BN_CLICKED(IDC_BUTTON_READ_ENVIRVALUE2, &CDlgRegistry::OnBnClickedButtonReadEnvirvalue2)
	ON_BN_CLICKED(IDC_BUTTON_READ_ENVIRVALUE3, &CDlgRegistry::OnBnClickedButtonReadEnvirvalue3)
END_MESSAGE_MAP()


// CDlgRegistry 메시지 처리기


void CDlgRegistry::OnBnClickedButtonOpen()
{
	//Registry Key 값 받아 오기******************************************************************************************************************************************
	UpdateData(TRUE);

	LSTATUS lstRes = ERROR_SUCCESS;
	lstRes = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, m_strRegistryPath, 0, KEY_ALL_ACCESS, &m_hRegKey);

	if (ERROR_SUCCESS != lstRes)
		AfxMessageBox("access Impossible and Path incorrect");
}


void CDlgRegistry::OnBnClickedButtonCreateFolder()
{
	//Registry 경로 생성******************************************************************************************************************************************
	UpdateData(TRUE);
	DWORD dwDisp = 0;
	LSTATUS lstRes = ::RegCreateKeyEx(HKEY_LOCAL_MACHINE, m_strRegistryPath, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &m_hRegKey, &dwDisp);
	if (ERROR_SUCCESS == lstRes)
	{
		AfxMessageBox(_T("Create"));
	}
	else
	{
		AfxMessageBox(_T("Create Fail"));
	}
}


void CDlgRegistry::OnBnClickedButtonNewCreate()
{
	LSTATUS lstRes = ERROR_SUCCESS;
	TCHAR atcvalue[MAX_PATH];

	ZeroMemory(atcvalue, sizeof(atcvalue));
	_tcscpy_s(atcvalue, m_strItemValue.GetLength() + 1, m_strItemValue.GetBuffer());
	lstRes = ::RegSetValueEx(m_hRegKey, m_strItemName, 0, REG_SZ, (LPBYTE)atcvalue, m_strItemName.GetLength() + 1);
}


void CDlgRegistry::OnBnClickedButtonRead()
{
	//Registry 읽기******************************************************************************************************************************************
	LSTATUS lstRes = ERROR_SUCCESS;
	DWORD dwBufSiz = 0;
	TCHAR atcvalue[MAX_PATH];
	ZeroMemory(atcvalue, sizeof(atcvalue));
	lstRes = ::RegQueryValueEx(m_hRegKey, m_strItemName, NULL, NULL, NULL, &dwBufSiz);

	if (ERROR_SUCCESS == lstRes)
	{
		TCHAR atcvalue[MAX_PATH];
		ZeroMemory(atcvalue, sizeof(atcvalue));
		lstRes = ::RegQueryValueEx(m_hRegKey, m_strItemName, NULL, NULL, (LPBYTE)atcvalue, &dwBufSiz);
		m_strItemValue.Format(_T("%s"), atcvalue);

		if (ERROR_SUCCESS != lstRes)
			AfxMessageBox("Read Fail");
	}

	m_strRegistryRead = m_strItemValue;
	m_strRegistryName2 = m_strItemName;
	UpdateData(FALSE);
}


void CDlgRegistry::OnBnClickedButtonModifyPath()
{
	//Registry 수정******************************************************************************************************************************************
	UpdateData(TRUE);
	LSTATUS lstRes = ERROR_SUCCESS;
	TCHAR atcvalue[MAX_PATH];
	ZeroMemory(atcvalue, sizeof(atcvalue));
	_tcscpy_s(atcvalue, m_strRegiModifyPath.GetLength() + 1, m_strRegiModifyPath.GetBuffer());
	lstRes = ::RegSetValueEx(m_hRegKey, m_strItemName, 0, REG_SZ, (LPBYTE)atcvalue, m_strRegiModifyPath.GetLength() + 1);

	UpdateData(FALSE);
}


void CDlgRegistry::OnBnClickedButtonDeletePath()
{
	//Registry Delete******************************************************************************************************************************************
	LSTATUS lstRes;

	if (NULL != m_hRegKey)
	{
		lstRes = ::RegDeleteValue(m_hRegKey, m_strItemName);
	}
}


void CDlgRegistry::OnBnClickedButtonClose()
{
	//Registry Close******************************************************************************************************************************************
	LSTATUS lstRes = ERROR_SUCCESS;
	if (NULL != m_hRegKey)
	{
		lstRes = ::RegCloseKey(m_hRegKey);
		m_hRegKey = NULL;
	}
}


void CDlgRegistry::OnBnClickedButtonReadEnvirvalue()
{
	UpdateData(TRUE);
	CString strEnvironmentPath = "System\\CurrentControlSet\\Control\\Session Manager\\Environment";

	LSTATUS lstRes = ERROR_SUCCESS;
	lstRes = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, strEnvironmentPath, 0, KEY_ALL_ACCESS, &m_hRegKey);
	if (ERROR_SUCCESS != lstRes)
	{
		AfxMessageBox(_T("open Fail"));
	}

	//Registry 읽기******************************************************************************************************************************************
	DWORD dwBufSiz = 0;
	TCHAR atcvalue[MAX_PATH];
	ZeroMemory(atcvalue, sizeof(atcvalue));
	lstRes = ::RegQueryValueEx(m_hRegKey, m_strEnvirName, NULL, NULL, NULL, &dwBufSiz);
	if (ERROR_SUCCESS == lstRes)
	{
		TCHAR atcvalue[MAX_PATH];
		ZeroMemory(atcvalue, sizeof(atcvalue));
		lstRes = ::RegQueryValueEx(m_hRegKey, m_strEnvirName, NULL, NULL, (LPBYTE)atcvalue, &dwBufSiz);
		m_strEnvirValue.Format(_T("%s"), atcvalue);

		if (ERROR_SUCCESS != lstRes)
			AfxMessageBox("Read Fail");
	}

	UpdateData(FALSE);
}


void CDlgRegistry::OnBnClickedButtonReadEnvirvalue2()
{
	UpdateData(TRUE);

	LSTATUS lstRes = ERROR_SUCCESS;
	TCHAR atcvalue[MAX_PATH];
	ZeroMemory(atcvalue, sizeof(atcvalue));
	_tcscpy_s(atcvalue, m_strModifyEnvirValue.GetLength() + 1, m_strModifyEnvirValue.GetBuffer());
	lstRes = ::RegSetValueEx(m_hRegKey, m_strEnvirName, 0, REG_SZ, (LPBYTE)atcvalue, m_strModifyEnvirValue.GetLength() + 1);

	UpdateData(FALSE);
}


void CDlgRegistry::OnBnClickedButtonReadEnvirvalue3()
{
	//Registry 읽기******************************************************************************************************************************************
	DWORD dwBufSiz = 0;
	TCHAR atcvalue[MAX_PATH];
	ZeroMemory(atcvalue, sizeof(atcvalue));
	LSTATUS lstRes = ::RegQueryValueEx(m_hRegKey, m_strEnvirName, NULL, NULL, NULL, &dwBufSiz);
	if (ERROR_SUCCESS == lstRes)
	{
		TCHAR atcvalue[MAX_PATH];
		ZeroMemory(atcvalue, sizeof(atcvalue));
		lstRes = ::RegQueryValueEx(m_hRegKey, m_strEnvirName, NULL, NULL, (LPBYTE)atcvalue, &dwBufSiz);
		m_strRefreshData.Format(_T("%s"), atcvalue);

		if (ERROR_SUCCESS != lstRes)
			AfxMessageBox("Read Fail");
	}

	UpdateData(FALSE);
}
