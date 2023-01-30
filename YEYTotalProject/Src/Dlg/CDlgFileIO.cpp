// CDlgFileIO.cpp: 구현 파일
//

#include "../../pch.h"
#include "../../YEYTotalProject.h"
#include "CDlgFileIO.h"
#include "afxdialogex.h"

#include <fstream>
#include <iostream>

// CDlgFileIO 대화 상자

IMPLEMENT_DYNAMIC(CDlgFileIO, CDialog)

CDlgFileIO::CDlgFileIO(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_FILEIO, pParent)
{

}

CDlgFileIO::~CDlgFileIO()
{
}

void CDlgFileIO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MULTI_SELECTED, m_listMultiSelected);
}


BEGIN_MESSAGE_MAP(CDlgFileIO, CDialog)
	ON_BN_CLICKED(IDC_BTN_OPENFILE, &CDlgFileIO::OnBnClickedBtnOpenfile)
	ON_BN_CLICKED(IDC_BTN_OPENMULTIFILE, &CDlgFileIO::OnBnClickedBtnOpenmultifile)
	ON_BN_CLICKED(IDC_BTN_SAVE_TXT, &CDlgFileIO::OnBnClickedBtnSaveTxt)
	ON_BN_CLICKED(IDC_BTN_FOLDER_PATH, &CDlgFileIO::OnBnClickedBtnFolderPath)
	ON_BN_CLICKED(IDC_BTN_OPEN_DATA, &CDlgFileIO::OnBnClickedBtnOpenData)
	ON_BN_CLICKED(IDC_BTN_WRITE_DATA, &CDlgFileIO::OnBnClickedBtnWriteData)
	ON_BN_CLICKED(IDC_BTN_WRITE_CONTINUEDATA, &CDlgFileIO::OnBnClickedBtnWriteContinuedata)
END_MESSAGE_MAP()


// CDlgFileIO 메시지 처리기

//SingleFile Open************************************************************************************************Start
void CDlgFileIO::OnBnClickedBtnOpenfile()
{
	//char szFilter[] = "Image (*.BMP, *.GIF, *.JPG) | *.BMP;*.GIF;*.JPG | All Files(*.*)|*.*||";
	//char szFilter[] = "All Files(*.*) | *.* ||";
	//CString szFilter = "Text File(*.txt) | *.txt | All Files(*.*) | *.* ||";

	//CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	CString szFilter = _T("| All Files(*.*)|*.*||");
	CFileDialog dlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
	CString strFilePath = "", strFilename = "";

	if (IDOK == dlg.DoModal()) // 대화 상자 열기
	{
		SetDlgItemText(IDC_EDIT_FILE_FULLPATH, dlg.GetPathName());
		strFilePath = dlg.GetPathName();
		SetDlgItemText(IDC_EDIT_FILE_FILEPATH, dlg.GetFileName());
		SetDlgItemText(IDC_EDIT_FILE_FILEEXT, dlg.GetFileExt());
		SetDlgItemText(IDC_EDIT_FILE_FILETITLE, dlg.GetFileTitle());
		SetDlgItemInt(IDC_EDIT_FILE_FILEREADONLY, dlg.GetReadOnlyPref());
		
		strFilename = strFilePath.Left(strFilePath.GetLength() - dlg.GetFileName().GetLength()- 1);
		SetDlgItemText(IDC_EDIT_FILE_EXCEPTEXT, strFilename);

		//파일 존재 여부 체크 함수
		SetDlgItemInt(IDC_EDIT_FILE_EXSISTCHECK, PathFileExists(dlg.GetPathName()));
	}
	
	
	//공통 경로를 체크하려면 여러 파일에 대한 경로 비교가 필요 하기때문에 그냥 알아서 처리하자...
	//PathCommonPrefix(dlg.GetFileName()); 
				   
	UpdateData(FALSE);
}
//SingleFile Open************************************************************************************************END

//Multiple File Open************************************************************************************************Start
void CDlgFileIO::OnBnClickedBtnOpenmultifile()
{
	CString szFilter = _T("| All Files(*.*)|*.*||");
	CString strFile;
	CString strFileList;

	CFileDialog dlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT, szFilter, this);

	const int c_cMaxFiles = 400 /*선택할 파일 숫자*/;	// 메모리 부족현상으로 확장 안해주면 몇개 못씀
	const int c_cbBuffSize = (c_cMaxFiles * (MAX_PATH + 1)) + 1;

	dlg.GetOFN().lpstrFile = strFileList.GetBuffer(c_cbBuffSize);
	dlg.GetOFN().nMaxFile = c_cbBuffSize;

	if (dlg.DoModal() == IDOK)
	{
		for (POSITION pos = dlg.GetStartPosition(); pos != NULL;)
		{
			// 전체삭제는 ResetContent
			strFile = dlg.GetNextPathName(pos);
			//m_TrainingList.AddString(File);

			//SetDlgItemText(IDC_EDIT_FILE_FILESTARTPOS, dlg.GetStartPosition());
			SetDlgItemText(IDC_EDIT_FILE_FILENEXTFILENAME, dlg.GetNextPathName(pos));

			m_listMultiSelected.AddString(strFile);
		}
	}
}
//Multiple File Open************************************************************************************************END


//TXT Format 변경************************************************************************************************Start
/* ANSI 텍스트 파일 
-특별한 표식이 없습니다.
* 유니코드(little endian)
파일 처음에 0xFF 0xFE 의 두바이트로 시작합니다.
* 유니코드(big endian)
파일 처음에 0xFE 0xFF 의 두바이트로 시작합니다.
* UTF - 8
파일을 덤프 해본 결과 파일 처음에 0xEF 0xBB 0xBF 의 세바이트로 시작합니다.*/

void CDlgFileIO::OnBnClickedBtnSaveTxt()
{
	BOOL bCheckUse = FALSE;
	CString szFilter = _T("| All Files(*.*)|*.*||");
	CFileDialog dlg(FALSE, "txt", "*.txt", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT |	OFN_NOCHANGEDIR, szFilter, NULL);

	if (IDOK == dlg.DoModal()) // 대화 상자 열기
	{
		for (int i = 0; i < 6; i++)
		{
			bCheckUse = ((CButton*)GetDlgItem(IDC_RADIO_TXT_FORMAT_8 + i))->GetCheck();

			CFile yourFile(dlg.GetPathName(), CFile::modeWrite | CFile::modeCreate);

			if (bCheckUse == TRUE)
			{
				CFile file;
				file.Open(dlg.GetPathName(), CFile::modeCreate | CFile::modeWrite);

				
				//Instead of writing, save data in buffer and write when buffer is full
				if (i == 0)	//UTF-8(BOM)
				{
					/*TCHAR BOM[3] = { 0xEF, 0xBB, 0xBF };*/
					char BOM[3] = { 0xEF, 0xBB, 0xBF }; //UTF-8 사용시 
					file.Write(BOM, 3);
				}
				else if (i == 1) // UTF-16 Big Endian  FE FF
				{
					char BOM[2] = { 0xFE, 0xFF};
					file.Write(BOM, 2);
				}					
				else if (i == 2) //UTF-16 Little Endian  FF FE  
				{
					char BOM[2] = { 0xFF, 0xFE};
					file.Write(BOM, 2);
				}
// 				else if (i == 3) //UTF-32 Big Endian00 00   FE FF
// 				{
// 					char BOM[4] = { 0x00, 0x00, 0xFE, 0xFF };
// 					file.Write(BOM, 4);
// 				}					
// 				else if (i == 4) //UTF-32 Little Endian  FF FE 00 00
// 				{
// 					char BOM[4] = { 0xFF, 0xFE, 0x00 , 0x00 };
// 					file.Write(BOM, 4);
// 				}	
				else if (i == 5) //UTF-8
				{
					char BOM[3] = { 0x00, 0x00, 0x00 };
					file.Write(BOM, 3);
				}
				else   
				{
					char BOM[3] = { 0x00, 0x00, 0x00 }; 
					file.Write(BOM, 3);
				}
				
				file.Close();
			}
		}
	}
}
//TXT Format 변경************************************************************************************************End

//폴더 경로만 따오기************************************************************************************************Start
void CDlgFileIO::OnBnClickedBtnFolderPath()
{
	BROWSEINFO BrInfo;
	TCHAR szBuffer[512];                                      // 경로저장 버퍼 

	::ZeroMemory(&BrInfo, sizeof(BROWSEINFO));
	::ZeroMemory(szBuffer, 512);

	BrInfo.hwndOwner = GetSafeHwnd();
	BrInfo.lpszTitle = _T("파일이 저장될 폴더를 선택하세요");
	BrInfo.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX | BIF_RETURNONLYFSDIRS;
	LPITEMIDLIST pItemIdList = ::SHBrowseForFolder(&BrInfo);
	::SHGetPathFromIDList(pItemIdList, szBuffer);               // 파일경로 읽어오기

		   // 경로를 가져와 사용할 경우, Edit Control 에 값 저장
	CString str;
	str.Format(_T("%s"), szBuffer);
	SetDlgItemText(IDC_EDIT_FOLDER_PATH, str);

	UpdateData(FALSE);
}
//폴더 경로만 따오기************************************************************************************************End
#include <cstdio>
//Data Load and Open************************************************************************************************Start
struct data {
	int nValue1;
	int nValue2;
	int nValue3;
	CString strValue;
};
data testdata;

void CDlgFileIO::OnBnClickedBtnOpenData()
{
	BOOL bCheckUse = FALSE;
	CString strTestFilePath1 = "./TestFolder/Test1.txt";
	CString strValue = "", strValue2 = "";
	CString strresultValue = "";
	
	for (int i = 0; i < 2; i++)
	{
		bCheckUse = ((CButton*)GetDlgItem(IDC_RADIO_LOAD_METHOD1 + i))->GetCheck();

		if (bCheckUse == TRUE)
		{
			//Method 1
			if (i == 0)
			{
				FILE* pf = fopen(strTestFilePath1, "r");
				if (pf)
				{
					char buffer[2048] = {};
					while (fgets(buffer, 2048, pf))
					{
						strValue = buffer;
					}
					SetDlgItemText(IDC_EDIT_OPEN_LOADDATA, strValue);

					fclose(pf);
				}
				else
					AfxMessageBox("Please click the Write Data Button");
			}
			//Method 2 - 하다가 말았음. 컨피그 파일처럼 가져오는것을 하려고했는데 안됨. 이유 불명.
			else
			{
				FILE* pf = fopen(strTestFilePath1, "r");
				if (pf)
				{
					char buffer[2048] = {};
					while (fgets(buffer, 2048, pf))
					{
						sscanf(buffer, "%d,%d,%d", &testdata.nValue1, &testdata.nValue2, &testdata.nValue3);//그냥 똑같은건데 밑에꺼가 안됨.
					}
					fclose(pf);
				}
				else
					AfxMessageBox("Please click the Write Data Button");

				strresultValue.Format("%d,%d,%d", testdata.nValue1, testdata.nValue2, testdata.nValue3);
				SetDlgItemText(IDC_EDIT_OPEN_LOADDATA, strresultValue);
			}

			break;
		}
	}

	if (bCheckUse == FALSE)
		AfxMessageBox("Please click the Radio Button");

}
//Data Load and Open************************************************************************************************End

void CDlgFileIO::OnBnClickedBtnWriteData()
{
	CString strTestFilePath1 = "./TestFolder/Test1.txt";

	for (int i = 0; i < 2; i++)
	{
		FILE *file = fopen(strTestFilePath1, "w");
		if (file)
		{
			fprintf(file, "%s,%s,%s\n", "Write", "Write2", "Write3");    //1. file format
			fclose(file);
		}
	}
}


void CDlgFileIO::OnBnClickedBtnWriteContinuedata()
{
	UpdateData(TRUE);
	CString strTestFilePath1 = "./TestFolder/AccumulateTest.txt";
	CString strValue = "";

	FILE *file = fopen(strTestFilePath1, "a");
	if (file)
	{
		GetDlgItemText(IDC_EDIT_ACCUMULATE_FILE, strValue);
		//YEY - 180616 레시피에 따른 공정 라인명이 별도로 필요 하기 때문에 추가.
		fprintf(file, "%s\n", strValue);    //1. file format
		fclose(file);
	}
}
