#include "stdafx.h"
#include "Dialogs.h"
#include "App\AppBase.h"
#include "App\App.h"
#include "window_tool\WindowsPosition.h"
#include "MainWindow\MainWindow.h"
#include "ColorPanel\ColorPanel.h"

namespace
{
	 ParametersTable &params = Singleton<ParametersTable>::Instance();
}

int MessagePanel_Init()
{
	return params.items.get<MessagePanelVisible>().value
			? MFS_CHECKED
			: MFS_UNCHECKED;
}

bool OpenMessagePanel_Check()
{
	try
	{
		bool &result = params.items.get<MessagePanelVisible>().value;
		result ^= true;
		CBase base(ParametersBase().name());
		if(base.IsOpen())
		{
			Update<ParametersTable>(base).set<MessagePanelVisible>(result)
				.Where().eq<NameParam>(
				params.items.get<NameParam>().value
				).Execute();
		}
		return result;
	}
	catch(...)
	{
		return false;
	}
};

bool OpenMessagePanel::Do()
{
	bool result = OpenMessagePanel_Check();
	if(result)
	{
		ColorPanel::Open();
	}
	else
	{
		ColorPanel::Close();
	}
	return result;
}

void SaveWindowPositionDlg::Do(HWND h)
{
	WindowPositionDlg<MainWindow>::Do(h);
}


