#include "stdafx.h"
#include "MainWindowToolBar.h"
#include "..\resource.h"
#include "templates\typelist.hpp"
#include "window_tool\InitToolbar.hpp"

#include "tools_debug\DebugMess.h"

namespace 
{
	template<int N>struct Key;

#define KEY(ID, text)template<>struct Key<ID> \
	{\
	static void Click(HWND);\
	static wchar_t *Text(){return text;}\
	};
	KEY(IDB_CycleBtn   , L"F4 ����")
	KEY(IDB_Reset      , L"F9 ����")
	KEY(IDB_QueryBtn   , L"����")
	KEY(IDB_OptionsBtn , L"�����.���.")
	KEY(IDB_arrow_down , L"F5 ����")
	KEY(IDB_arrow_up   , L"F6 ����")
	KEY(IDB_arrow_left , L"F7 �����")
	KEY(IDB_arrow_right, L"F8 Clear")
	KEY(IDB_Continue, L"F11 ����������")
#undef KEY
#define BUTTON_KEY(ID)ButtonToolbar<ID, Key<ID> > 
		typedef TL::MkTlst<
		SeparatorToolbar<0>
		, BUTTON_KEY(IDB_CycleBtn)
	//	, BUTTON_KEY(IDB_Continue)
		, BUTTON_KEY(IDB_Reset)
		, BUTTON_KEY(IDB_OptionsBtn) 		
		, SeparatorToolbar<1>
#ifdef DEBUG_ITEMS
		, BUTTON_KEY(IDB_arrow_down) 
		, BUTTON_KEY(IDB_arrow_up)
		, BUTTON_KEY(IDB_arrow_left) 
		, BUTTON_KEY(IDB_arrow_right)
		, SeparatorToolbar<2>
#endif
		>::Result tool_button_list;
#undef BUTTON_KEY
//----------------------------------------------------------------------------------
	static bool closed_packet_dialog = true;
	static bool run_once_per_sycle = false;
	void Key<IDB_CycleBtn>::Click(HWND h)
	{
		zprint("\n");	
	}
	//void Key<IDB_Continue>::Click(HWND h)
	//{
	//	zprint("\n");	
	//}
//-------------------------------------------------------------------------------
	void Key<IDB_OptionsBtn>::Click(HWND h)
	{
		zprint("\n");	
	}
//------------------------------------------------------------------------------
	void Key<IDB_arrow_down>::Click(HWND h)
	{
		zprint("\n");	
	}
//------------------------------------------------------------------------------
	void Key<IDB_arrow_up>::Click(HWND h)
	{
		zprint("\n");	
	}
//------------------------------------------------------------------------------
	void Key<IDB_arrow_left>::Click(HWND h)
	{
		zprint("\n");			
	}
//------------------------------------------------------------------------------
	void Key<IDB_arrow_right>::Click(HWND h)
	{
		zprint("\n");			
	}
//----------------------------------------------------------------------------
	void Key<IDB_Reset>::Click(HWND h)
	{
		zprint("\n");	
	}
}
//--------------------------------------------------------------------------------------------
HWND MainWindowToolBar::Init(HWND h)
{
	return hWnd = InitToolbar<tool_button_list>()(h);
}
//-------------------------------------------------------------------
void MainWindowToolBar::Size()
{
	MoveWindow(hWnd, 0, 0, 0, 0, false);
}
//----------------------------------------------------------------------------
const int MainWindowToolBar::Width()
{
	return __tool_bar_width__<tool_button_list>::value;
}
//------------------------------------------------------------------------

