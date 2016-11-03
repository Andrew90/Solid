#include "stdafx.h"
#include "App.h"
#include "AddThresholdsWindow\AddThresholdsWindow.h"
#include "SolidGroupAlgoritm\SolidBase.h"
#include "MainWindow\MainWindow.h"
#include "window_tool\ItemIni.h"
#include "window_tool\Emptywindow.h"
#include "window_tool\WindowsPosition.h"
#include "App\AppBase.h"
#include "window_tool\Emptywindow.h"

namespace
{
	MainWindow &mainWindow = Singleton<MainWindow>::Instance();
}

void App::Init()
{
	AppBase().Init();

	//SolidBase().Change(Singleton<ParametersTable>::Instance().items.get<NameParam>().value);
	Singleton<ComputeSolidGroup>::Instance().Load(Singleton<ParametersTable>::Instance().items.get<NameParam>().value);
#if 1
	RECT r;
	WindowPosition::Get<MainWindow>(r);
	HWND h = WindowTemplate(&mainWindow, L"������ ���������", r.left, r.top, r.right, r.bottom);
	ShowWindow(h, SW_SHOWNORMAL);
#else
#if 1
 //  ComputeSolidGroup &sg = Singleton<ComputeSolidGroup>::Instance();
 //  double p[] = {0, 1, 2, 3, 4, 5, 6, 7};
 //  sg.AddThreshold(L"NONAME", L"File", 200, p);
 //
 //  double p1[] = {5,6,7,8,9,10,11,12};
 //  sg.AddThreshold(L"NONAME", L"File1", 300, p1);
#endif
	//AddThresholdWindow::Show();
#endif
}

void App::Destroy()
{
}

struct App::Impl
{

};

void App::PrintTopLabel(wchar_t *txt)
{	
	mainWindow.topLabelViewer.SetMessage(txt);
}

void App::UpdateMainWindow()
{
	RepaintWindow(mainWindow.hWnd);
}

