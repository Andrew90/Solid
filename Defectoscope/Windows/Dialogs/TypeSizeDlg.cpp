#include "stdafx.h"
#include "dialogs_tool\ParamDlg.h"
#include "dialogs_tool\ParamDlg.hpp"
#include "Dialogs.h"
#include "App\AppBase.h"
#include "App\App.h"
#include "window_tool\SelectTypeSizeList.h"
#include "App\SelectHandler.h"


namespace 
{
	PARAM_TITLE(NameParam, L"")
		template<int N>struct DlgSubItems<NameParam, Holder<N> >: EditItems<NameParam, 420>{};

	struct OkBtnX
	{
		static const int width = 120;
		static const int height = 30;
		static const int ID = IDOK;
		wchar_t *Title(){return L"���������";}
		template<class Owner>void BtnHandler(Owner &owner, HWND h)
		{
#pragma message("todo 16 11 01")
			//if(TestPassword<Owner::Base, Owner::Table>()(h))
			//{
			//	HWND hWnd = owner.items.get<DlgItem<NameParam>>().hWnd;
			//	wchar_t buf[128];
			//	GetWindowText(hWnd, buf, dimention_of(buf));
			//	if(0 == buf[0])
			//	{
			//		MessageBox(h, L"���������� ������ ������������ �����������", L"������!!!", MB_ICONERROR);
			//		return;
			//	}
			//	CBase base(Owner::Base().name());
			//	if(base.IsOpen())
			//	{
			//		NameParam n;
			//		n.value = buf;
			//		unsigned id = Select<Owner::Table>(base).eq<NameParam>(n.value).Execute();
			//		if(0 != id)
			//		{
			//			MessageBox(h, L"�������� ����������� ���� � ����", L"��������������!!!", MB_ICONWARNING);
			//			return;
			//		}
			//
			//		Owner::Table &table = Singleton<Owner::Table>::Instance();
			//		table.items.get<NameParam>().value = buf;
			//
			//		Insert_Into<Owner::Table>(table, base).Execute();
			//		CurrentID cId;
			//		cId.value = Select<Owner::Table>(base).eq<NameParam>(n.value).Execute();
			//		Update<CurrentParametersTable>(base).set<CurrentID>(cId.value).Where().ID(1).Execute();
			//		Singleton<SelectTypeSizeList>::Instance().AddMenuItem(buf);
			//
			//		EndDialog(h, TRUE);
			//	}
			//}
		}
	};
}

void AddTypeSizeDlg::Do(HWND h)
{
	TemplDialogList<ParametersBase, ParametersTable, TL::MkTlst<NameParam>::Result, TL::MkTlst<OkBtnX, CancelBtn>::Result>
		(Singleton<ParametersTable>::Instance()).Do(h, L"�������� ����������");
}

namespace
{	
	struct NameParamD : NameParam{};
	template<int N>struct DlgSubItems<NameParamD, Holder<N> >: EditReadOnlyItems<NameParamD, 420>{};

	struct ParametersTableD
	{
		typedef TL::MkTlst<	
			NameParamD
		>::Result items_list;
		typedef TL::Factory<items_list> TItems;
		TItems items;
	};

	PARAM_TITLE(NameParamD, L"")

	struct OkBtnD
	{
		static const int width = 120;
		static const int height = 30;
		static const int ID = IDOK;
		wchar_t *Title(){return L"���������";}
		template<class Owner>void BtnHandler(Owner &owner, HWND h)
		{
#pragma message("todo 16 11 01")
			//if(TestPassword<ParametersBase, ParametersTable>()(h))
			//{
			//	CBase base(Owner::Base().name());
			//	if(base.IsOpen())
			//	{
			//		NameParamD &t = owner.items.get<DlgItem<NameParamD>>().value;
			//		int count = 0;
			//		CMD(base).CommandText(L"SELECT count(NameParam) as C FROM ParametersTable").GetValue(L"C", count);
			//		if(count <= 1)
			//		{
			//			MessageBox(h, L"� ���������� ������ ���� �� ����� ������ �����������", L"��������������!!!", MB_ICONWARNING);
			//			EndDialog(h, TRUE);
			//			return;
			//		}
			//		Delete<ParametersTable>(base).eq<NameParam>(t.value).Execute();
			//		Singleton<SelectTypeSizeList>::Instance().DelMenuItem(t.value);
			//		wchar_t buf[128];
			//		CMD(base).CommandText(L"select top 1 NameParam from ParametersTable").GetValue(L"NameParam", buf);
			//		SelectHandler::Do(buf);
			//		EndDialog(h, TRUE);
			//	}
			//}
		}
	};
}

void DelTypeSizeDlg::Do(HWND h)
{
	ParametersTableD t;
	t.items.get<NameParamD>().value = Singleton<ParametersTable>::Instance().items.get<NameParam>().value;
	TemplDialog<ParametersBase, ParametersTableD, TL::MkTlst<OkBtnD, CancelBtn>::Result>(t).Do(h, L"������� ����������");
}
