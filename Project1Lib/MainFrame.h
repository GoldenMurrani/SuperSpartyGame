/**
 * @file MainFrame.h
 * @author Matthew Hofmann
 *
 * The top-level (main) frame of the application
 */

#ifndef PROJECT1_MAINFRAME_H
#define PROJECT1_MAINFRAME_H

class GameView;

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame {
private:
    /// the game view of this mainframe
    GameView* mGameView;

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
public:
    void Initialize();

    void OnClose(wxCloseEvent& event);
};

#endif //PROJECT1_MAINFRAME_H
