#pragma once
#include "wx/wx.h"
#include "wx/Splitter.h"

class BSplitter : public wxSplitterWindow
{
public:
	BSplitter(wxWindow* parent, wxWindowID id = wxID_ANY, int sashsize = 5, const wxPoint& pos = wxDefaultPosition, 
		const wxSize& size = wxDefaultSize, long style = wxSP_3D) : wxSplitterWindow(parent, id, pos, size, style)
	{
		//SetSashSize(sashsize);
	}

	//void OnSashPositionChanged(int newSashPosition) override
	//{
		// Do something when the sash position changes
	//}

	void OnPaint(wxPaintEvent& event);

};

