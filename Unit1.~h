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
        TTimer *rightPaddleTop;
        TTimer *rightPaddleDown;
        TShape *leftPaddle;
        TTimer *leftPaddleDown;
        TTimer *leftPaddleTop;
        TShape *ball;
        TTimer *ballTimer;
        void __fastcall rightPaddleDownTimer(TObject *Sender);
        void __fastcall rightPaddleTopTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall leftPaddleDownTimer(TObject *Sender);
        void __fastcall leftPaddleTopTimer(TObject *Sender);
        void __fastcall ballTimerTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
