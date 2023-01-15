#include "BSplitter.h"

void BSplitter::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);

	//wxRect sashRect = GetSashRect();

	dc.SetPen(*wxTRANSPARENT_PEN);
	dc.SetBrush(wxBrush(*wxBLACK));
	//dc.DrawRectangle(sashRect);
}
