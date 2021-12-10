//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleDownTimer(TObject *Sender)
{
     if(rightPaddle -> Top < backgroundForMatch -> Top + backgroundForMatch -> Height - rightPaddle -> Height - 24)
     {
          rightPaddle -> Top += 11;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleTopTimer(TObject *Sender)
{
     if(rightPaddle -> Top > backgroundForMatch -> Top + 24)
     {
          rightPaddle -> Top -= 11;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if (Key == VK_UP) rightPaddleTop -> Enabled = true;
     if (Key == VK_DOWN) rightPaddleDown -> Enabled = true;
     if (Key == 0x41) leftPaddleTop -> Enabled = true;
     if (Key == 0x5A) leftPaddleDown -> Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if (Key == VK_UP) rightPaddleTop -> Enabled = false;
     if (Key == VK_DOWN) rightPaddleDown -> Enabled = false;
     if (Key == 0x41) leftPaddleTop -> Enabled = false;
     if (Key == 0x5A) leftPaddleDown -> Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftPaddleDownTimer(TObject *Sender)
{
     if(leftPaddle -> Top < backgroundForMatch -> Top + backgroundForMatch -> Height - leftPaddle -> Height - 24)
     {
          leftPaddle -> Top += 11;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftPaddleTopTimer(TObject *Sender)
{
     if(leftPaddle -> Top > backgroundForMatch -> Top + 24)
     {
          leftPaddle -> Top -= 11;
     }
}
//---------------------------------------------------------------------------
