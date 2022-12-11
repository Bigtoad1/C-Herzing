#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
private:
	void buttonOneClicked(wxCommandEvent& evt);
	void buttonRegClicked(wxCommandEvent& evt);
	void text1Changed(wxCommandEvent& evt);
	void text2Changed(wxCommandEvent& evt);
};