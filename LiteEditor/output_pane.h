//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah                            
// file name            : output_pane.h              
//                                                                          
// -------------------------------------------------------------------------
// A                                                                        
//              _____           _      _     _ _                            
//             /  __ \         | |    | |   (_) |                           
//             | /  \/ ___   __| | ___| |    _| |_ ___                      
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )                     
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/                     
//              \____/\___/ \__,_|\___\_____/_|\__\___|                     
//                                                                          
//                                                  F i l e                 
//                                                                          
//    This program is free software; you can redistribute it and/or modify  
//    it under the terms of the GNU General Public License as published by  
//    the Free Software Foundation; either version 2 of the License, or     
//    (at your option) any later version.                                   
//                                                                          
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
 #ifndef OUTPUT_PANE_H
#define OUTPUT_PANE_H


#include "wx/panel.h"
#include "wx/wxscintilla.h"
#include "shelltab.h"
#include "map"

class OutputPane;
class ShellWindow;
class BuildTab;
class FindResultsTab;
class FindResultsContainer;
class ReplaceInFilesPanel;
class Notebook;
class TaskPanel;

/**
 * \ingroup LiteEditor
 * This class represents the default bottom pane in the editor
 *
 * \date 04-14-2007
 *
 * \author Eran
 *
 * \par license
 * This code is absolutely free to use and modify. The code is provided "as is" with
 * no expressed or implied warranty. The author accepts no liability if it causes
 * any damage to your computer, causes your pet to fall ill, increases baldness
 * or makes your car start emitting strange noises when you start it up.
 * This code has no bugs, just undocumented features!
 * 
 * \todo 
 *
 * \bug 
 *
 */
class OutputPane : public wxPanel 
{
public:
	static const wxString FIND_IN_FILES_WIN;
	static const wxString BUILD_WIN;
	static const wxString OUTPUT_WIN;
	static const wxString OUTPUT_DEBUG;
	static const wxString REPLACE_IN_FILES;
	static const wxString TASKS;
	static const wxString TRACE_TAB;

	Notebook *m_book;
	wxString m_caption;
	ShellTab *m_outputWind;
	wxLog *m_logTargetOld;
	ShellTab *m_outputDebug;
	BuildTab *m_buildWin;
	FindResultsContainer *m_findResultsTab;
	ReplaceInFilesPanel *m_replaceResultsTab;
	TaskPanel *m_taskPanel;
	int m_fifTabToUse;
	
private:
	void CreateGUIControls();
	
public:
	/**
	 * Return the index of a given window by its caption
	 */
	int CaptionToIndex(const wxString &caption);

	/**
	 * Destructor
	 * \param parent parent window for this pane
	 * \param caption the caption
	 */
	OutputPane(wxWindow *parent, const wxString &caption);

	/**
	 * Destructor
	 */
	virtual ~OutputPane();

	//-----------------------------------------------
	// Setters/Getters
	//-----------------------------------------------
	Notebook *GetNotebook() { return m_book; }
	const wxString &GetCaption() const { return m_caption; }
	void SelectTab(const wxString &tabName);
	
	//return the underlying windows holded under this pane
	ShellWindow *GetOutputWindow() {return m_outputWind->GetShell();}
	ShellWindow *GetDebugWindow() {return m_outputDebug->GetShell();}
	BuildTab *GetBuildTab() {return m_buildWin;}
	FindResultsTab *GetFindResultsTab();
	ReplaceInFilesPanel *GetReplaceResultsTab(){return m_replaceResultsTab;}
	void SetFindResultsTab(int which);
	
	DECLARE_EVENT_TABLE()
	virtual void OnPaint(wxPaintEvent &e);
	virtual void OnEraseBg(wxEraseEvent &e);
	virtual void OnSize(wxSizeEvent &e);
};

#endif // OUTPUT_PANE_H
