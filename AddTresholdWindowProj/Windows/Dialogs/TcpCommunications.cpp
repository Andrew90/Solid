#include "stdafx.h"
#include "Dialogs.h"
#include "App/AppBase.h"
#include "DlgTemplates\ParamDlg.h"

PARAM_TITLE(PortTCP, L"���� �������� �����������")
PARAM_TITLE(AddresTCP, L"����� �������� �����������")

MIN_VALUE(PortTCP, 1024)
MAX_VALUE(PortTCP, 0XFFFF)

DO_NOT_CHECK(AddresTCP)
template<>struct DlgSubItems<AddresTCP, AddresTCP::type_value>: EditItems<AddresTCP>{};

void TcpCommunicationsDlg::Do(HWND h)
{
	if(TemplDialog<ParametersBase, TcpCommunications>(Singleton<TcpCommunications>::Instance()).Do(h, L"��������� �������� �����������"))
	{
		/*
		if(!clientTreshold.Connect(
			Singleton<TcpCommunications>::Instance().items.get<PortTCP>().value
			, Singleton<TcpCommunications>::Instance().items.get<AddresTCP>().value
			))
		{
			MessageBox(0, L"�� ���� ����������� � ������� �������", L"������ !!!", MB_ICONERROR);
		}
		*/
	}
}

