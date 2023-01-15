#include "_3DAPE.h"
#include "MainFrame.h"
#include "wx/wx.h"

wxIMPLEMENT_APP(_3DAPE);

bool _3DAPE::OnInit()
{
	MainFrame* mainFrame = new MainFrame("3D APE");
	mainFrame->SetBackgroundColour(wxColor(5, 5, 5));
	mainFrame->Layout();
	mainFrame->Show();
	mainFrame->SetClientSize(950, 550);
	mainFrame->Center();
	return true;
}
