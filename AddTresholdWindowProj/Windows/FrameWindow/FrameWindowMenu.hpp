#pragma once

#include "window_tool\message.h"
#include "window_tool\MenuApi.h"
#include "templates\templates.hpp"
#include "window_tool\WindowsPosition.h"
#include "AddThresholdsWindow\AddThresholdsWindow.h"

namespace FrameWindowMenu
{
	struct MainFile{};
	MENU_TEXT(L"����", TopMenu<MainFile>)
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	struct MainExit
	{
		static void Do(HWND h)
		{
			TClose c = {h, WM_CLOSE, 0, 0};
			SendMessage(MESSAGE(c));
		}
	};	
	MENU_ITEM(L"�����", MainExit)

		template<>struct TopMenu<MainFile>
	{
		typedef TL::MkTlst<
			MenuItem<MainExit>
		>::Result list;
	};

	struct MainOptionUnits{};
	MENU_TEXT(L"���������", TopMenu<MainOptionUnits>)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	struct ThresholdsMenuItem{static void Do(HWND){AddThresholdWindow::Show();}};

	MENU_ITEM(L"������", ThresholdsMenuItem)
	MENU_ITEM(L"��������� ���������� ����", WindowPositionDlg<FrameWindow>)

	template<>struct TopMenu<MainOptionUnits>
	{
		typedef TL::MkTlst<
			MenuItem<ThresholdsMenuItem>
			, Separator<0>
			, MenuItem<WindowPositionDlg<FrameWindow>>
		>::Result list;
	};

	struct GraphUnits{};
	MENU_TEXT(L"������", TopMenu<GraphUnits>)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
    struct PointsOffsets{static void Do(HWND){}};
	struct FirstSignal{static void Do(HWND){}};

	MENU_ITEM(L"����� ��������", PointsOffsets)
	MENU_ITEM(L"��������� ������", FirstSignal)

	template<>struct TopMenu<GraphUnits>
	{
		typedef TL::MkTlst<
			MenuItem<PointsOffsets>
			, MenuItem<FirstSignal>
		>::Result list;
	};


	typedef TL::MkTlst<
		TopMenu<MainFile>
		, TopMenu<MainOptionUnits>
		, TopMenu<GraphUnits>
	>::Result items_list;	
}