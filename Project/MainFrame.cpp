#include "MainFrame.h"
#include "wx/wx.h"
#include "wx/splitter.h"

// IDs stored in an enum
enum IDs
{
	IMPORT_VID_ID = 2,
	IMPORT_FBX_ID = 3
};

// Event Handlers
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(IMPORT_VID_ID, MainFrame::OnImportVideo)
	EVT_BUTTON(IMPORT_FBX_ID, MainFrame::OnImportFbx)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    // Menus
	// Initializing Menubar
	wxMenuBar* MainMenu = new wxMenuBar();

	// Initializing File Menu and its Contents
	wxMenu* FileMenu = new wxMenu();
	FileMenu->Append(wxID_ANY, _T("Open"));
	FileMenu->Append(wxID_ANY, _T("Export"));

	// Initializing Edit Menu and its Contents
	wxMenu* EditMenu = new wxMenu();
	EditMenu->Append(wxID_ANY, _T("Undo"));
	EditMenu->Append(wxID_ANY, _T("Presets"));

	// Initializing Select Menu and its Contents
	wxMenu* SelectMenu = new wxMenu();

	// Initializing View Menu and its Contents
	wxMenu* ViewMenu = new wxMenu();

	// Initializing View Menu and its Contents
	wxMenu* HelpMenu = new wxMenu();

	// Assigning all the Menus to the Menu Bar
	MainMenu->Append(FileMenu, _T("File"));
	MainMenu->Append(EditMenu, _T("Edit"));
	MainMenu->Append(SelectMenu, _T("Select"));
	MainMenu->Append(ViewMenu, _T("View"));
	MainMenu->Append(HelpMenu, _T("Help"));
	SetMenuBar(MainMenu);


	// Panels
	// Main Panel
	wxPanel* MainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	MainPanel->SetBackgroundColour(wxColor(5, 5, 5));
	//wxSplitterWindow* TopDownSplitter = new wxSplitterWindow(this);

	wxPanel* TopPanel = new wxPanel(MainPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 40));
	TopPanel->SetBackgroundColour(wxColor(17, 15, 28));
	wxPanel* BottomPanel = new wxPanel(MainPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 600));
	BottomPanel->SetBackgroundColour(wxColor(5, 5, 5));

	//TopDownSplitter->SplitHorizontally(TopPanel, BottomPanel);

	wxPanel* LBPanel = new wxPanel(BottomPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 600));
	LBPanel->SetBackgroundColour(wxColor(17, 15, 28));
	wxPanel* RBPanel = new wxPanel(BottomPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 600));
	RBPanel->SetBackgroundColour(wxColor(17, 15, 28));

	// Sizers
	wxBoxSizer* VSizer = new wxBoxSizer(wxVERTICAL);
	VSizer->Add(TopPanel, 1, wxEXPAND | wxBOTTOM, 1.5); 
	VSizer->Add(BottomPanel, 8, wxEXPAND);

	wxBoxSizer* HSizer = new wxBoxSizer(wxHORIZONTAL);
	HSizer->Add(LBPanel, 1, wxEXPAND | wxRIGHT, .75);
	HSizer->Add(RBPanel, 1, wxEXPAND | wxLEFT, .75);

	BottomPanel->SetSizerAndFit(HSizer);

	MainPanel->SetSizerAndFit(VSizer);

	// Buttons
	// Import Button
	wxButton* ImportVideo = new wxButton(LBPanel, IMPORT_VID_ID, "Click To Add", wxPoint(10, 10), wxSize(650, 600), wxNO_BORDER);
	ImportVideo->SetBackgroundColour(wxColor(15, 10, 25));
	ImportVideo->SetForegroundColour(wxColor(165, 165, 165));

	// Export Button
	wxButton* ImportFbx = new wxButton(RBPanel, IMPORT_FBX_ID, "Click To Add", wxPoint(10, 10), wxSize(650, 600), wxNO_BORDER);
	ImportFbx->SetBackgroundColour(wxColor(15, 10, 25));
	ImportFbx->SetForegroundColour(wxColor(165, 165, 165));

	/*wxBoxSizer* LBSizer = new wxBoxSizer(wxHORIZONTAL);
	LBSizer->Add(ImportVideo, 1, wxEXPAND | wxALL, 5);
	LBPanel->SetSizerAndFit(LBSizer);

	wxBoxSizer* RBSizer = new wxBoxSizer(wxHORIZONTAL);
	RBSizer->Add(ImportFbx, 1, wxEXPAND | wxALL, 5);
	RBPanel->SetSizerAndFit(RBSizer);*/

}

// called for Import Button Command
void MainFrame::OnImportVideo(wxCommandEvent& evt)
{
	wxLogMessage("Import Video");
}

void MainFrame::OnImportFbx(wxCommandEvent& evt)
{
	wxLogMessage("Import FBX");
}

