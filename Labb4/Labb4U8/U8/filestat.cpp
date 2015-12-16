
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
   #include <wx/wx.h>
#endif

#include "FileData.h"


class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};


class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void SetupMenuBar();
    void CreatePanelItems();
    void OnOpen(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxPanel *panel;
	FileData model;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "File Statistics", wxPoint(50, 50), wxSize(450, 340) );
    frame->Show( true );
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SetupMenuBar();
//    Create default panel items??
    CreateStatusBar();
    SetStatusText( "Welcome to the File Statistics!" );
}

void MyFrame::SetupMenuBar()
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_OPEN, wxT("&Open"));
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnOpen, this, wxID_OPEN);
    menuFile->Append(wxID_EXIT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnExit, this, wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnAbout, this, wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
}

void MyFrame::CreatePanelItems()
{
    //panel = new wxPanel(this);
	// Three columns with flexible width
	//wxFlexGridSizer *gs = new wxFlexGridSizer(3, ...);
	//// Add header row
	//gs->Add(new wxStaticText(panel, -1, wxT("??")), 0, wxALIGN_RIGHT);
	//gs->Add(new wxStaticText(panel, -1, wxT("??")), 0, wxALIGN_CENTER_HORIZONTAL);
	//// place filler in the last column
	//gs->Add(new wxStaticText(panel, -1, wxT("")), 0, wxALIGN_LEFT);

	// Add file stats row by row
		// Format text e.g. with wxString::Format using format codes for printf, e.g
		//	wxString::Format(wxT("%d-%d"), low)			=> "32"
		//	wxString::Format(wxT("%d-%d"), low, high)	=> "33-127"
		//	wxString::Format(wxT("%5.2f"), rate)		=> "0.93"
		//gs->Add(new wxStaticText(panel, -1, ...), 0, wxALIGN_RIGHT);
		//gs->Add(new wxStaticText(panel, -1, ...), 0, wxALIGN_RIGHT);
		//wxGauge *gauge = new wxGauge(panel, -1, 100, wxDefaultPosition, wxDefaultSize, wxGA_SMOOTH | wxGA_HORIZONTAL);
		//gauge->SetValue(100*rate+0.5);
		//gs->Add(gauge, 0, wxALIGN_RIGHT);

	//gs->SetSizeHints(panel);
	//panel->SetSizer(gs);
	//SetMinSize(wxSize(270, 220));
	//panel->Refresh();
}

void MyFrame::OnOpen(wxCommandEvent& event)
{
	wxFileDialog * openFileDialog = new wxFileDialog(this);
	if (openFileDialog->ShowModal() == wxID_OK){
		wxString fileName = openFileDialog->GetPath();
		// read the file and collect statistics
		// if read ok then create and/or update panel items
	}
//	Update();
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is the File Statistics using wxWidgets",
                  "About the File Statistics", wxOK | wxICON_INFORMATION );
}



