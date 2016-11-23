#pragma once

#include "window_tool\message.h"
#include "window_tool\MenuApi.h"
#include "templates\templates.hpp"
#include "Dialogs\Dialogs.h"
#include "window_tool\WindowsPosition.h"
#include "Dates\SaveLoadDates.h"
#include "Dates\Compute.h"
#include "App\App.h"

namespace MainWindowMenu
{
	struct MainFile{};
	MENU_TEXT(L"����", TopMenu<MainFile>)
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	struct LoadDateFile__ 
	{
		static void Do(HWND h)
		{
			LoadDateFile::Do(h);
			Singleton<Compute>::Instance().Recalculation();
		}
	};
	struct SaveDateFile__:  SaveDateFile{};//{static void Do(HWND){}};
	struct Compute__     
	{
		static void Do(HWND)
		{
			Singleton<Compute>::Instance().Recalculation();
		}
	};
	struct MainExit
	{
		static void Do(HWND h)
		{
			TClose c = {h, WM_CLOSE, 0, 0};
			SendMessage(MESSAGE(c));
		}
	};

	MENU_ITEM(L"��������� ������", LoadDateFile__)
	MENU_ITEM(L"��������� ������", SaveDateFile__)
	MENU_ITEM(L"����������", Compute__)
	MENU_ITEM(L"�����", MainExit)

		template<>struct TopMenu<MainFile>
	{
		typedef TL::MkTlst<
			MenuItem<LoadDateFile__>
			, MenuItem<SaveDateFile__>
			, Separator<0>
			, MenuItem<Compute__>
			, Separator<1>
			, MenuItem<MainExit>
		>::Result list;
	};

	struct MainOptionTypeSize{};
	MENU_TEXT(L"����������", TopMenu<MainOptionTypeSize>)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
	struct MainCreateTypesize: AddTypeSizeDlg{};//{static void Do(HWND h){zprint("");}};
	struct MainDeleteTypeSize: DelTypeSizeDlg{};//{static void Do(HWND h){zprint("");}};
	struct MainClearCounter {static void Do(HWND){App::ClearCounter();}};

	MENU_ITEM(L"������� ����������", MainCreateTypesize)
	MENU_ITEM(L"������� ����������", MainDeleteTypeSize)
	MENU_ITEM(L"�������� �������", MainClearCounter)

	template<>struct TopMenu<MainOptionTypeSize>
	{
		typedef TL::MkTlst<
			 MenuItem<MainCreateTypesize>
			, MenuItem<MainDeleteTypeSize>
			, Separator<1>
			, MenuItem<MainClearCounter>
		>::Result list;
	};

	struct MainOptionUnits {};//static void Do(HWND h){zprint("");}};
	//struct L502ParamDlg {static void Do(HWND h){zprint("");}};
	//struct CommunicationOptions {static void Do(HWND h){zprint("");}};

	struct SolenoidParametersTable: SolenoidParametersTableDlg{};// {static void Do(HWND h){zprint("");}};
	struct NetOptions: TcpCommunicationsDlg{};
	//struct AdcInputPortsDlg {static void Do(HWND h){zprint("");}};
	//struct DInputPortsDlg {static void Do(HWND h){zprint("");}};
	//struct SyncroDlg {static void Do(HWND h){zprint("");}};
	struct SaveWindowPosition: SaveWindowPositionDlg{};//{static void Do(HWND h){zprint("");}};
	struct MessagePanel
	{
		static void Do(HWND h)
		{
			bool x = OpenMessagePanel::Do();
			CheckMenu<MenuItem<MessagePanel>>(h, x);
		}
	};

	MENU_TEXT(L"���������", TopMenu<MainOptionUnits>)
	//MENU_ITEM(L"��������� ���������� �����"       , L502ParamDlg)	
	//MENU_ITEM(L"��������� �������� �����������"   , CommunicationOptions)	
	MENU_ITEM(L"��������� �������� �����������", NetOptions)
	MENU_ITEM(L"��������� ����������"          , SolenoidParametersTable)
	//MENU_ITEM(L"��������� ������ ���������� �����", AdcInputPortsDlg)
	//MENU_ITEM(L"��������� ������ ���������� �����", DInputPortsDlg)
	//MENU_ITEM(L"�������������", MenuItem<SyncroDlg>)
	MENU_ITEM(L"��������� ���������� ����", SaveWindowPosition)//WindowPositionDlg<MainWindow>)
	MENU_ITEM(L"������ ���������", MessagePanel)



	template<>struct TopMenu<MainOptionUnits>
	{
		typedef TL::MkTlst<
			//			MenuItem<L502ParamDlg>
			//	, MenuItem<CommunicationOptions>	
			MenuItem<NetOptions>
			, MenuItem<SolenoidParametersTable>
			//, MenuItem<AdcInputPortsDlg>
			//, MenuItem<DInputPortsDlg>
			//, MenuItem<SyncroDlg>
			, Separator<1>			
			, MenuItem<SaveWindowPosition>
			, MenuItem<MessagePanel>
		>::Result list;
	};

	template<>struct EnableMenuInit<MenuItem<MessagePanel>>
	{
		int operator()(HWND)
		{
			return InitMessagePanel::Do();
		}
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