#pragma once

#include <map>
#include <vector>

//hash_map�� ����ϴ� ���
//1. ���� �ڷḦ �����ϰ�, �˻� �ӵ��� ����� �Ѵ�.
//2. �ʹ� ����ϰ� �ڷḦ ����, ���� ���� �ʴ´�.
#define ITEMSEP "_" //������

#define mapIDVal std::map<CString, CString>
#define mapIDValIt mapIDVal::iterator



class AFX_EXT_CLASS CakFileDB
{
public:
	CakFileDB(void);
	~CakFileDB(void);

	void clear();

	bool SetFileName(char* filename, bool bCreateFileIfNotExist = false);
	bool WriteToFile(char* filename = NULL);
	void RemoveAllItem();

	void setWriteEnter(); //����ȭ ��ü ����
	void setWriteRelease();  //����ȭ ��ü ����

	void	SetRewriteMode(BOOL bRewrite)	{ m_bRewrite = bRewrite; }
	BOOL	GetRewriteMode()				{ return m_bRewrite; }

	//�ϳ��� �����͸� ������ ������ ��� [������ 2019/1/21]
	void GetOneItemValue(char* pFileName, char* strKey, CString* strVal, char* strDefaultVal = "");

	//���� ������
	void SetItemValue(char* strKey, char* strVal);
	void SetItemValue(char* strKey, int nVal);
	void SetItemValue(char* strKey, float fVal);
	void SetItemValue(char* strKey, double dVal);
	void SetItemValue(char* strKey, long dVal);

	void GetItemValue(char* strKey, CString* strVal, char* strDefaultVal = "");
	void GetItemValue(char* strKey, char* strVal, char* strDefaultVal = "");
	void GetItemValue(char* strKey, unsigned short* nVal, int nDefaultVal = 0);
	void GetItemValue(char* strKey, int* nVal, int nDefaultVal = 0);
	void GetItemValue(char* strKey, float* fVal, float fDefaultVal = 0);
	void GetItemValue(char* strKey, double* dVal, double dDefaultVal = 0);
	void GetItemValue(char* strKey, long* dVal, long dDefaultVal = 0);

	char* getItemPoint(char* strKey);

	//���� ������ ����
	void setItemClear(char* strKey);
	int  getItemNum(char* strKey);

	void SetItemValue(int nIndex, char* strKey, char* strVal);
	void SetItemValue(int nIndex, char* strKey, int nVal);
	void SetItemValue(int nIndex, char* strKey, float fVal);
	void SetItemValue(int nIndex, char* strKey, double dVal);

	void GetItemValue(int nIndex, char* strKey, CString* strVal, char* strDefaultVal = "");
	void GetItemValue(int nIndex, char* strKey, char* strVal, char* strDefaultVal = "");
	void GetItemValue(int nIndex, char* strKey, unsigned short* nVal, int nDefaultVal = 0);
	void GetItemValue(int nIndex, char* strKey, int* nVal, int nDefaultVal = 0);
	void GetItemValue(int nIndex, char* strKey, float* fVal, float fDefaultVal = 0);
	void GetItemValue(int nIndex, char* strKey, double* dVal, double dDefaultVal = 0);

	char* getItemPoint(int nIndex, char* strKey);




	BOOL deleteItem(char* strKey); //
	BOOL RemoveItem(char* strKey){return deleteItem(strKey);};
	int deleteItem(int nIndex); //
	BOOL	RemoveItem(int nIdx, char* szName);


protected:
	mapIDVal m_mapData;
	std::vector<mapIDValIt> m_vecOrder;

	CRITICAL_SECTION m_csAkFileDB;
	CString m_strOpenFileName;

	BOOL				m_bRewrite;
};
