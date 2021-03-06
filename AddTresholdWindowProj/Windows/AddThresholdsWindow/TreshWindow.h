#pragma once

#include <windows.h>
#include "window_tool\message.h"
#include "window_tool\TEvent.h"
//#include "App/AppBase.h"
#include "SolidGroupAlgoritm\SolidBase.h"
//#include "templates\templates.hpp"
#include "DlgTemplates\ParamDlg.hpp"

class TreshWindow
{	
public:
	class OkBtn: TEvent
	{
		friend TreshWindow;
		TreshWindow *owner;
		void Do(TCommand &);
	};

	class CancelBtn: TEvent
	{
		void Do(TCommand &);
	};
	static const int width = 300;
	int height;
	typedef TL::CreateNumList<Offset, 0, ComputeSolidGroup::count_points - 1>::Result offset_list;
	TL::Factory<offset_list> items;
	typedef TL::TypeToTypeLst<
		offset_list
		, DlgItem
	>::Result dlg_list;
	TL::Factory<dlg_list> dlg_items;
public:
	HWND hWnd;
	OkBtn okBtn;
	CancelBtn cancelBtn;
	//void operator()(TSize &);
	TreshWindow();//: dlg_items(items){}
	void operator()(TCommand &);
	void operator()(TGetMinMaxInfo &);
	LRESULT operator()(TCreate &);
//	void operator()(TLButtonDown &);
	static void Show();
};