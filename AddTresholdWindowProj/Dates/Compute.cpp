#include "stdafx.h"
#include "Compute.h"
#include "SolidData.h"
#include "templates\templates.hpp"
#include "SolidGroupAlgoritm\ComputeSolidGroup.h"
#include "App\App.h"
#include "ColorPanel\ColorPanel.h"

namespace
{
	SolidData &solidData = Singleton<SolidData>::Instance();
	ComputeSolidGroup &computeSolidGroup = Singleton<ComputeSolidGroup>::Instance();
}

bool Compute::SubCompute(int(&tresholds)[8], int start, int stop, double *signal, double *reference)
{
	return false;
}

void Compute::Do()
{
	//TODO ������� ���� ������
	//TODO � ������ ����� ��������� ����� ������������ �����  computeSolidGroup.currentFile
}

void Compute::Recalculation()
{
	solidData.start = int(0.1 * solidData.currentOffset);
	solidData.stop = solidData.currentOffset - solidData.start;

	double result = 0;
	wchar_t *groupName = NULL;
	unsigned color = 0;

	computeSolidGroup.Frames(
		solidData.signal
		, solidData.reference
		, solidData.start
		, solidData.stop
		, result
		, groupName
		, color
		);
	wchar_t buf[1024];
	wsprintf(buf, L"<ff00>%s<ff>������ ��������� <%6x>%s <ff>���������� <ffffff>%s"
		, computeSolidGroup.currentFile.c_str()
		, color
		, groupName
		, Wchar_from<double>(result)()
		);

	if(NULL != groupName)computeSolidGroup.currentGroupName = groupName;
	else computeSolidGroup.currentGroupName = L"";

	Singleton<L502Signal>::Instance().Set(solidData.signal, solidData.currentOffset);
	Singleton<L502Reference>::Instance().Set(solidData.reference, solidData.currentOffset);

	App::PrintTopLabel(buf);
	App::UpdateMainWindow();

	ColorPanel::SetText(groupName, color);
}
