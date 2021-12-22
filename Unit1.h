//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *backgroundForMatch;
        TShape *rightPaddle;
        TTimer *rightPaddleUp;
        TTimer *rightPaddleDown;
        TShape *leftPaddle;
        TTimer *leftPaddleDown;
        TTimer *leftPaddleUp;
        TShape *ball;
        TTimer *ballTimer;
        TLabel *difficultyLevelButton;
        TLabel *playersModeButton;
        TLabel *startButton;
        TLabel *helpButton;
        TLabel *exitButton;
        TShape *backgroundForMenu;
        TLabel *leftPoints;
        TLabel *rightPoints;
        TLabel *counter;
        TShape *background;
        void __fastcall rightPaddleDownTimer(TObject *Sender);
        void __fastcall rightPaddleUpTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall leftPaddleDownTimer(TObject *Sender);
        void __fastcall leftPaddleUpTimer(TObject *Sender);
        void __fastcall ballTimerTimer(TObject *Sender);
        void __fastcall startButtonClick(TObject *Sender);
        void __fastcall difficultyLevelButtonClick(TObject *Sender);
        void __fastcall playersModeButtonClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall exitButtonClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall helpButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
