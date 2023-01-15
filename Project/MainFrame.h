#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	std::string VidFormats = "(*.mp4)|*.mp4";
	std::string VidPath;

	std::string FbxFormats = "(*.fbx)|*.fbx";

private:
	void OnImportVideo(wxCommandEvent& evt);
	void OnImportFbx(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};
