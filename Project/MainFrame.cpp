#include "MainFrame.h"
#include "wx/wx.h"
#include "wx/splitter.h"
#include "Bsplitter.h"
#include "FBXPorter.h"

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
	FileMenu->Append(wxID_OPEN);
	FileMenu->AppendSeparator();
	FileMenu->Append(wxID_SAVE);
	FileMenu->Append(wxID_SAVEAS);
	FileMenu->AppendSeparator();
	FileMenu->Append(wxID_ANY, _T("Export"));

	// Initializing Edit Menu and its Contents
	wxMenu* EditMenu = new wxMenu();
	EditMenu->Append(wxID_UNDO);
	EditMenu->Append(wxID_REDO);

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
	wxPanel* MainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1920, 1080));
	MainPanel->SetBackgroundColour(wxColor(5, 5, 5));
	
    wxPanel* TopPanel = new wxPanel(MainPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 40));
	TopPanel->SetBackgroundColour(wxColor(17, 15, 28));
	wxPanel* BottomPanel = new wxPanel(MainPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 600));
	BottomPanel->SetBackgroundColour(wxColor(5, 5, 5));

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

	// Setting Sizers to fit to the Panels
	BottomPanel->SetSizerAndFit(HSizer);
	MainPanel->SetSizerAndFit(VSizer);

	// Buttons
	// Import Button
	wxButton* ImportVideo = new wxButton(LBPanel, IMPORT_VID_ID, "Import Video", wxPoint(10, 10), wxSize(650, 600), wxNO_BORDER);
	ImportVideo->SetBackgroundColour(wxColor(15, 10, 25));
	ImportVideo->SetForegroundColour(wxColor(165, 165, 165));

	// Export Button
	wxButton* ImportFbx = new wxButton(RBPanel, IMPORT_FBX_ID, "Import Fbx", wxPoint(10, 10), wxSize(650, 600), wxNO_BORDER);
	ImportFbx->SetBackgroundColour(wxColor(15, 10, 25));
	ImportFbx->SetForegroundColour(wxColor(165, 165, 165));

}

// called for Import Button Command
void MainFrame::OnImportVideo(wxCommandEvent& evt)
{
	// called to open up a directory to choose appropriate Video Files 
	wxFileDialog VidDialog(this, "Choose a Video", "", "", VidFormats, wxFD_OPEN);
	if (VidDialog.ShowModal() == wxID_OK)
	{
		VidPath = VidDialog.GetPath();
		wxMessageBox(VidPath, "Directory");
	}
}

void MainFrame::OnImportFbx(wxCommandEvent& evt)
{
	// called to open up a directory to choose appropriate Fbx Files
	wxFileDialog FbxDialog(this, "Choose a File", "", "", FbxFormats, wxFD_OPEN);
	if (FbxDialog.ShowModal() == wxID_OK)
	{
		FBXPorter* FbxImporter = new FBXPorter;

		// Getting the path from selected file 
		wxString IPath = FbxDialog.GetPath();

		// ToUTF8 was used as other Conversions didn't work
		const char* ImportFile = IPath.ToUTF8();

		// Assigning value of Conversion to Valid as for future to check the armature
		int Valid = FbxImporter->Import(ImportFile);

		if (Valid == 1)
		{
			wxMessageBox("Corrupted File or Invalid Import File!", "Error");
		}

		// Clearing the Storage
		FbxImporter = nullptr;
		ImportFile = nullptr;
		delete FbxImporter;
		delete ImportFile;

	}
}

/*MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	// Menus
	// Initializing Menubar
	wxMenuBar* MainMenu = new wxMenuBar();
	MainMenu->SetBackgroundColour(wxColor(5, 5, 5));

	// Initializing File Menu and its Contents
	wxMenu* FileMenu = new wxMenu();
	FileMenu->Append(wxID_OPEN);
	FileMenu->AppendSeparator();
	FileMenu->Append(wxID_SAVE);
	FileMenu->Append(wxID_SAVEAS);
	FileMenu->AppendSeparator();
	FileMenu->Append(wxID_ANY, _T("Export"));

	// Initializing Edit Menu and its Contents
	wxMenu* EditMenu = new wxMenu();
	EditMenu->Append(wxID_UNDO);
	EditMenu->Append(wxID_REDO);

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
	//wxPanel* MainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1920, 1080));
	//MainPanel->SetBackgroundColour(wxColor(5, 5, 5));

	BSplitter* TopDownSplitter = new BSplitter(this);
															// wxSP_LIVE_UPDATE  | wxSP_NOBORDER); 

	/*wxPanel* TopPanel = new wxPanel(MainPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 40));
	TopPanel->SetBackgroundColour(wxColor(17, 15, 28));
	wxPanel* BottomPanel = new wxPanel(MainPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 600));
	BottomPanel->SetBackgroundColour(wxColor(5, 5, 5));*
	wxPanel* TopPanel = new wxPanel(TopDownSplitter, wxID_ANY, wxDefaultPosition, wxSize(200, 40));
	TopPanel->SetBackgroundColour(wxColor(17, 15, 28));
	wxPanel* BottomPanel = new wxPanel(TopDownSplitter);
	BottomPanel->SetBackgroundColour(wxColor(5, 5, 5));


	wxPanel* LBPanel = new wxPanel(BottomPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 600));
	LBPanel->SetBackgroundColour(wxColor(17, 15, 28));
	wxPanel* RBPanel = new wxPanel(BottomPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 600));
	RBPanel->SetBackgroundColour(wxColor(17, 15, 28));

	TopDownSplitter->SetupColours();
	TopDownSplitter->SetMinimumPaneSize(40);
	TopDownSplitter->SplitHorizontally(TopPanel, BottomPanel);
	TopDownSplitter->SetSashGravity(.1);

	// Sizers
	/*wxBoxSizer* VSizer = new wxBoxSizer(wxVERTICAL);
	VSizer->Add(TopPanel, 1, wxEXPAND | wxBOTTOM, 1.5);
	VSizer->Add(BottomPanel, 8, wxEXPAND);

	wxBoxSizer* HSizer = new wxBoxSizer(wxHORIZONTAL);
	HSizer->Add(LBPanel, 1, wxEXPAND | wxRIGHT, .75);
	HSizer->Add(RBPanel, 1, wxEXPAND | wxLEFT, .75);

	BottomPanel->SetSizerAndFit(HSizer);

	MainPanel->SetSizerAndFit(VSizer);*

	// Buttons
	// Import Button
	wxButton* ImportVideo = new wxButton(LBPanel, IMPORT_VID_ID, "Import Video", wxPoint(10, 10), wxSize(650, 600), wxNO_BORDER);
	ImportVideo->SetBackgroundColour(wxColor(15, 10, 25));
	ImportVideo->SetForegroundColour(wxColor(165, 165, 165));

	// Export Button
	wxButton* ImportFbx = new wxButton(RBPanel, IMPORT_FBX_ID, "Import FBX", wxPoint(10, 10), wxSize(650, 600), wxNO_BORDER);
	ImportFbx->SetBackgroundColour(wxColor(15, 10, 25));
	ImportFbx->SetForegroundColour(wxColor(165, 165, 165));

}*/

