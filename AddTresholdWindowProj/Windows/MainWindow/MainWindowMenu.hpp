#pragma once

#include "window_tool\message.h"
#include "window_tool\MenuApi.h"
#include "templates\templates.hpp"
#include "Dialogs\Dialogs.h"
#include "window_tool\WindowsPosition.h"
#include "Dates\SaveLoadDates.h"
#include "Dates\Compute.h"

namespace MainWindowMenu
{
	struct MainFile{};
	MENU_TEXT(L"����", TopMenu<MainFile>)
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	struct LoadDateFile__ {static void Do(HWND h)
	{
		LoadDateFile::Do(h);
		Singleton<Compute>::Instance().Recalculation();
	}};
	struct SaveDateFile{static void Do(HWND){}};
	struct Compute     {static void Do(HWND){}};
	struct MainExit
	{
		static void Do(HWND h)
		{
			TClose c = {h, WM_CLOSE, 0, 0};
			SendMessage(MESSAGE(c));
		}
	};

	MENU_ITEM(L"��������� ������", LoadDateFile__)
	MENU_ITEM(L"��������� ������", SaveDateFile)
	MENU_ITEM(L"����������", Compute)
	MENU_ITEM(L"�����", MainExit)

		template<>struct TopMenu<MainFile>
	{
		typedef TL::MkTlst<
			MenuItem<LoadDateFile__>
			, MenuItem<SaveDateFile>
			, Separator<0>
			, MenuItem<Compute>
			, Separator<1>
			, MenuItem<MainExit>
		>::Result list;
	};

	struct MainOptionTypeSize{};
	MENU_TEXT(L"����������", TopMenu<MainOptionTypeSize>)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
	struct MainCreateTypesize: AddTypeSizeDlg{};//{static void Do(HWND h){zprint("");}};
	struct MainDeleteTypeSize: DelTypeSizeDlg{};//{static void Do(HWND h){zprint("");}};
	struct MainAddItem {static void Do(HWND h){zprint("");}};
	struct MainClearCounter {static void Do(HWND h){zprint("");}};

	MENU_ITEM(L"������� ����������", MainCreateTypesize)
	MENU_ITEM(L"������� ����������", MainDeleteTypeSize)
	MENU_ITEM(L"�������� �������", MainAddItem)
	MENU_ITEM(L"�������� �������", MainClearCounter)

	template<>struct TopMenu<MainOptionTypeSize>
	{
		typedef TL::MkTlst<
			MenuItem<MainAddItem>
			, Separator<0>
			, MenuItem<MainCreateTypesize>
			, MenuItem<MainDeleteTypeSize>
			, Separator<1>
			, MenuItem<MainClearCounter>
		>::Result list;
	};

	struct MainOptionUnits {static void Do(HWND h){zprint("");}};
	struct L502ParamDlg {static void Do(HWND h){zprint("");}};
	struct CommunicationOptions {static void Do(HWND h){zprint("");}};
	struct SolenoidParametersTableDlg {static void Do(HWND h){zprint("");}};
	struct AdcInputPortsDlg {static void Do(HWND h){zprint("");}};
	struct DInputPortsDlg {static void Do(HWND h){zprint("");}};
	struct SyncroDlg {static void Do(HWND h){zprint("");}};

	MENU_TEXT(L"���������", TopMenu<MainOptionUnits>)
	MENU_ITEM(L"��������� ���������� �����"       , L502ParamDlg)	
	MENU_ITEM(L"��������� �������� �����������"   , CommunicationOptions)	
	MENU_ITEM(L"��������� ����������"             , SolenoidParametersTableDlg)
	MENU_ITEM(L"��������� ������ ���������� �����", AdcInputPortsDlg)
	MENU_ITEM(L"��������� ������ ���������� �����", DInputPortsDlg)
	MENU_ITEM(L"�������������", MenuItem<SyncroDlg>)
	MENU_ITEM(L"��������� ���������� ����", WindowPositionDlg<MainWindow>)

	template<>struct TopMenu<MainOptionUnits>
	{
		typedef TL::MkTlst<
			MenuItem<L502ParamDlg>
			, MenuItem<CommunicationOptions>	
			, MenuItem<SolenoidParametersTableDlg>
			, MenuItem<AdcInputPortsDlg>
			, MenuItem<DInputPortsDlg>
			, MenuItem<SyncroDlg>
			, Separator<1>
			, MenuItem<WindowPositionDlg<MainWindow>>
		>::Result list;
	};

	MENU_TEXT(L"� ���������", TopMenu<AboutWindow>)
	MENU_ITEM(L"� ���������", AboutWindow)

	template<>struct TopMenu<AboutWindow>
	{
		typedef TL::MkTlst<
			MenuItem<AboutWindow>
		>::Result list;
	};

	typedef TL::MkTlst<
		TopMenu<MainFile>
		, TopMenu<MainOptionTypeSize>
		, TopMenu<MainOptionUnits>
		, TopMenu<AboutWindow>
	>::Result items_list;	
}