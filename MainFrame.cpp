#include <wx/wx.h>
#include "frameWindow.h"
#include "AppHeader.h"
#include <fstream>

wxString userNameSet;
wxString passNameSet;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panelMain = new wxPanel(this);
	wxButton* button1 = new wxButton(panelMain, wxID_ANY, "Login", wxPoint(150, 220), wxSize(100, 35));
	wxButton* button2 = new wxButton(panelMain, wxID_ANY, "Register", wxPoint(140, 270), wxSize(125, 35));
	wxStaticText* staticDisplay = new wxStaticText(panelMain, wxID_ANY, "Avion Airlines Login", wxPoint(350, 50));
	wxStaticText* messageDisplay = new wxStaticText(panelMain, wxID_ANY, "", wxPoint(475, 150));
	wxTextCtrl* textEntry1 = new wxTextCtrl(panelMain, wxID_ANY, "UserName", wxPoint(100, 145), wxSize(200, -1));
	wxTextCtrl* textEntry2 = new wxTextCtrl(panelMain, wxID_ANY, "Password", wxPoint(100, 185), wxSize(200, -1));
	CreateStatusBar();

	button1->Bind(wxEVT_BUTTON, &MainFrame::buttonOneClicked, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::buttonRegClicked, this);
	textEntry1->Bind(wxEVT_TEXT, &MainFrame::text2Changed, this);
	textEntry2->Bind(wxEVT_TEXT, &MainFrame::text1Changed, this);
}

void MainFrame::buttonOneClicked(wxCommandEvent& evt) {
	std::ifstream userDatabase("Database1.txt");
	userDatabase.open("Database1.txt", std::ios::in);
	if (!userDatabase) {
		wxLogStatus("No User Database");
	}
	else {
		char line;
		while (1) {
			userDatabase >> line;
			if (userDatabase.eof()) { break; }

			if (line == "Username: " + userNameSet + "Password: " + passNameSet) {
				wxLogStatus("Login Success!");
			}
				
		}
	}

	userDatabase.close();
}

void MainFrame::text1Changed(wxCommandEvent& evt) {
	wxString str = wxString::Format("Password: %s", evt.GetString());
	wxLogStatus(str);
	passNameSet = str;
}

void MainFrame::text2Changed(wxCommandEvent& evt) {
	wxString str = wxString::Format("Username: %s", evt.GetString());
	wxLogStatus(str);
	userNameSet = str;
}

void MainFrame::buttonRegClicked(wxCommandEvent& evt) {
	std::ofstream userDatabase;
	userDatabase.open("Database1.txt");
	userDatabase << userNameSet << passNameSet << "\n";
	userDatabase.close();
}


void initializeFileSystem() {
	try {
		std::ifstream userDatabase ("Database1.txt");
		userDatabase.open("Database1.txt");
		userDatabase.close();
	}
	catch (...) {
		std::ofstream userDatabase;
		userDatabase.open("Database1.txt");
		userDatabase.close();
	}
}