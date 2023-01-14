#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

private:
	void OnImportVideo(wxCommandEvent& evt);
	void OnImportFbx(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

