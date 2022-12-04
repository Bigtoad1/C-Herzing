#include <wx/wx.h>
#include "frameWindow.h"
#include "AppHeader.h"

enum IDs {
	BUTTON_ID = 2,
	TEXT1_ID = 3,
	TEXT2_ID = 4
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_ID, MainFrame::buttonOneClicked)
	EVT_TEXT(TEXT1_ID, MainFrame::text1Changed)
	EVT_TEXT(TEXT2_ID, MainFrame::text2Changed)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panelMain = new wxPanel(this);
	wxButton* button1 = new wxButton(panelMain, BUTTON_ID, "Login", wxPoint(150, 220), wxSize(100, 35));
	wxStaticText* staticDisplay = new wxStaticText(panelMain, wxID_ANY, "Avion Airlines Login", wxPoint(350, 50));
	wxTextCtrl* textEntry1 = new wxTextCtrl(panelMain, TEXT2_ID, "UserName", wxPoint(100, 145), wxSize(200, -1));
	wxTextCtrl* textEntry2 = new wxTextCtrl(panelMain, TEXT1_ID, "Password", wxPoint(100, 185), wxSize(200, -1));
	CreateStatusBar();
}

void MainFrame::buttonOneClicked(wxCommandEvent& evt) {
	wxLogStatus("Button Clicked");
}

void MainFrame::text1Changed(wxCommandEvent& evt) {
	wxString str = wxString::Format("Password: %s", evt.GetString());
	wxLogStatus(str);
}

void MainFrame::text2Changed(wxCommandEvent& evt) {
	wxString str = wxString::Format("Username: %s", evt.GetString());
	wxLogStatus(str);
}