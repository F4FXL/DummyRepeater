/*
 *   Copyright (C) 2010 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "DummyRepeaterBleepSet.h"

const unsigned int BORDER_SIZE   = 5U;
const unsigned int CONTROL_WIDTH = 200U;

CDummyRepeaterBleepSet::CDummyRepeaterBleepSet(wxWindow* parent, int id, const wxString& title, BLEEP_TYPE bleepType, BLEEP_MODE bleepMode, unsigned int volume) :
wxPanel(parent, id),
m_title(title),
m_bleepType(NULL)
{
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	m_bleepMode = new wxChoice(this,  wxID_ANY, wxDefaultPosition, wxSize(CONTROL_WIDTH, -1));
	m_bleepMode->Append("Off");
	m_bleepMode->Append("DStar");
	m_bleepMode->Append("Radio");
	m_bleepMode->Append("DStar + Radio");
	m_bleepMode->SetSelection(bleepMode);
	
	m_bleepType = new wxChoice(this,  wxID_ANY, wxDefaultPosition, wxSize(CONTROL_WIDTH, -1));
	m_bleepType->Append("IC91 Like");
	m_bleepType->Append("Quindar");
	m_bleepType->SetSelection(bleepType);

	if(volume < 0) volume = 0;
	if(volume > 100) volume = 100;
	m_volume = new wxSlider(this, -1, volume, 0, 100, wxDefaultPosition, wxSize(CONTROL_WIDTH, -1), wxSL_HORIZONTAL | wxSL_LABELS);

	sizer->Add(m_bleepMode, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);
	sizer->Add(m_bleepType, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);
	sizer->Add(m_volume, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	SetAutoLayout(true);

	sizer->Fit(this);
	sizer->SetSizeHints(this);

	SetSizer(sizer);
}


CDummyRepeaterBleepSet::~CDummyRepeaterBleepSet()
{
}

BLEEP_MODE CDummyRepeaterBleepSet::getBleepMode() const
{
	switch(m_bleepMode->GetSelection())
	{
		case 0:
			return BLM_OFF;
		case 1:
			return BLM_DSTAR;
		case 2:
			return BLM_RADIO;
		case 3:
			return BLM_DSTAR_RADIO;
		default:
			return BLM_DSTAR;
	}
}

BLEEP_TYPE CDummyRepeaterBleepSet::getBleepType() const
{
	switch (m_bleepType->GetSelection())
	{
		case 1:
			return BLT_QUINDAR;
		
		default:
			return BLT_IC91;
	}
}

unsigned int CDummyRepeaterBleepSet::getBleepVolume() const
{
	return m_volume->GetValue();
}

