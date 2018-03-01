// [!output PROJECT_NAME].cpp :SOUI主入口源文件
//

#include "stdafx.h"
#include "MainDlg.h"

#include "SouiInit.h"

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int /*nCmdShow*/)
{
	HRESULT hRes = OleInitialize(NULL);
	SASSERT(SUCCEEDED(hRes));

	int nRet = 0;

	InitDir();
	{
		CSouiLoader Loader(hInstance);
		InitSystemRes(Loader.GetApp(), Loader.GetComMgr());
		InitUserRes(Loader.GetApp(), Loader.GetComMgr());
		nRet = Run<CMainDlg>(Loader.GetApp());
	}

	OleUninitialize();
	return nRet;
}
